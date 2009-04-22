#include "picoc.h"

/* some basic types */
struct ValueType UberType;
struct ValueType IntType;
struct ValueType CharType;
struct ValueType WordType;
#ifndef NO_FP
struct ValueType FPType;
#endif
struct ValueType VoidType;
struct ValueType FunctionType;
struct ValueType MacroType;
struct ValueType EnumType;
struct ValueType Type_Type;
struct ValueType *CharPtrType;
struct ValueType *CharArrayType;


/* add a new type to the set of types we know about */
struct ValueType *TypeAdd(struct ParseState *Parser, struct ValueType *ParentType, enum BaseType Base, int ArraySize, const char *Identifier, int Sizeof)
{
    struct ValueType *NewType = VariableAlloc(Parser, sizeof(struct ValueType), TRUE);
    NewType->Base = Base;
    NewType->ArraySize = ArraySize;
    NewType->Sizeof = Sizeof;
    NewType->Identifier = Identifier;
    NewType->Members = NULL;
    NewType->FromType = ParentType;
    NewType->DerivedTypeList = NULL;
    NewType->OnHeap = TRUE;
    NewType->Next = ParentType->DerivedTypeList;
    ParentType->DerivedTypeList = NewType;
    
    return NewType;
}

/* given a parent type, get a matching derived type and make one if necessary */
struct ValueType *TypeGetMatching(struct ParseState *Parser, struct ValueType *ParentType, enum BaseType Base, int ArraySize, const char *Identifier)
{
    int Sizeof;
    struct ValueType *ThisType = ParentType->DerivedTypeList;
    while (ThisType != NULL && (ThisType->Base != Base || ThisType->ArraySize != ArraySize || ThisType->Identifier != Identifier))
        ThisType = ThisType->Next;
    
    if (ThisType != NULL)
        return ThisType;
        
    switch (Base)
    {
        case TypePointer:   Sizeof = sizeof(struct PointerValue); break;
        case TypeArray:     Sizeof = sizeof(struct ArrayValue) + ArraySize * ParentType->Sizeof; break;
        case TypeEnum:      Sizeof = sizeof(int); break;
        default:            Sizeof = 0; break;      /* structs and unions will get bigger when we add members to them */
    }

    return TypeAdd(Parser, ParentType, Base, ArraySize, Identifier, Sizeof);
}

/* stack space used by a value */
int TypeStackSizeValue(struct Value *Val)
{
    if (Val->ValOnStack)
        return TypeSizeValue(Val); // XXX - doesn't handle passing system-memory arrays by value correctly
    else
        return 0;
}

/* memory used by a value */
int TypeSizeValue(struct Value *Val)
{
    if (Val->Typ->Base == TypeChar)
        return sizeof(int);     /* allow some extra room for type extension to int */
    else if (Val->Typ->Base != TypeArray)
        return Val->Typ->Sizeof;
    else
        return sizeof(struct ArrayValue) + Val->Typ->FromType->Sizeof * Val->Val->Array.Size;
}

/* the last accessible offset of a value */
int TypeLastAccessibleOffset(struct Value *Val)
{
    if (Val->Typ->Base != TypeArray)
        return 0;
    else
        return Val->Typ->FromType->Sizeof * (Val->Val->Array.Size-1);
}

/* memory used by a variable given its type and array size */
int TypeSize(struct ValueType *Typ, int ArraySize)
{
    if (Typ->Base == TypeChar)
        return sizeof(int);     /* allow some extra room for type extension to int */
    else if (Typ->Base != TypeArray)
        return Typ->Sizeof;
    else
        return sizeof(struct ArrayValue) + Typ->FromType->Sizeof * ArraySize;
}

/* add a base type */
void TypeAddBaseType(struct ValueType *TypeNode, enum BaseType Base, int Sizeof)
{
    TypeNode->Base = Base;
    TypeNode->ArraySize = 0;
    TypeNode->Sizeof = Sizeof;
    TypeNode->Identifier = StrEmpty;
    TypeNode->Members = NULL;
    TypeNode->FromType = NULL;
    TypeNode->DerivedTypeList = NULL;
    TypeNode->OnHeap = FALSE;
    TypeNode->Next = UberType.DerivedTypeList;
    UberType.DerivedTypeList = TypeNode;
}

/* initialise the type system */
void TypeInit()
{
    UberType.DerivedTypeList = NULL;
    TypeAddBaseType(&IntType, TypeInt, sizeof(int));
#ifndef NO_FP
    TypeAddBaseType(&FPType, TypeFP, sizeof(double));
#endif
    TypeAddBaseType(&VoidType, TypeVoid, 0);
    TypeAddBaseType(&FunctionType, TypeFunction, sizeof(int));
    TypeAddBaseType(&MacroType, TypeMacro, sizeof(int));
    TypeAddBaseType(&Type_Type, TypeType, sizeof(struct ValueType *));
    TypeAddBaseType(&CharType, TypeChar, sizeof(char));
    CharPtrType = TypeAdd(NULL, &CharType, TypePointer, 0, StrEmpty, sizeof(struct PointerValue));
    CharArrayType = TypeAdd(NULL, &CharType, TypeArray, 0, StrEmpty, sizeof(char));
}

/* deallocate heap-allocated types */
void TypeCleanupNode(struct ValueType *Typ)
{
    struct ValueType *SubType;
    struct ValueType *NextSubType;
    
    /* clean up and free all the sub-nodes */
    for (SubType = Typ->DerivedTypeList; SubType != NULL; SubType = NextSubType)
    {
        NextSubType = SubType->Next;
        TypeCleanupNode(SubType);
        if (SubType->OnHeap)
        {
            /* if it's a struct or union deallocate all the member values */
            if (SubType->Members != NULL)
            {
                VariableTableCleanup(SubType->Members);
                HeapFree(SubType->Members);
            }

            /* free this node */
            HeapFree(SubType);
        }
    }
}

void TypeCleanup()
{
    TypeCleanupNode(&UberType);
}

/* parse a struct or union declaration */
void TypeParseStruct(struct ParseState *Parser, struct ValueType **Typ, int IsStruct)
{
    struct Value *LexValue;
    struct ValueType *MemberType;
    char *MemberIdentifier;
    struct Value *MemberValue;
    enum LexToken Token;
    
    if (TopStackFrame != NULL)
        ProgramFail(Parser, "struct/union definitions can only be globals");
        
    if (LexGetToken(Parser, &LexValue, TRUE) != TokenIdentifier)
        ProgramFail(Parser, "struct/union name required");
    
    *Typ = TypeGetMatching(Parser, &UberType, IsStruct ? TypeStruct : TypeUnion, 0, LexValue->Val->Identifier);

    Token = LexGetToken(Parser, NULL, FALSE);
    if (Token != TokenLeftBrace)
    { /* use the already defined structure */
        if ((*Typ)->Members == NULL)
            ProgramFail(Parser, "structure '%s' isn't defined", LexValue->Val->Identifier);
            
        return;
    }
    
    LexGetToken(Parser, NULL, TRUE);    
    (*Typ)->Members = VariableAlloc(Parser, sizeof(struct Table) + STRUCT_TABLE_SIZE * sizeof(struct TableEntry), TRUE);
    (*Typ)->Members->HashTable = (void *)(*Typ)->Members + sizeof(struct Table);
    TableInitTable((*Typ)->Members, (void *)(*Typ)->Members + sizeof(struct Table), STRUCT_TABLE_SIZE, TRUE);
    
    do {
        TypeParse(Parser, &MemberType, &MemberIdentifier);
        if (MemberType == NULL || MemberIdentifier == NULL)
            ProgramFail(Parser, "invalid type in struct");
        
        MemberValue = VariableAllocValueAndData(Parser, sizeof(int), FALSE, NULL, TRUE);
        MemberValue->Typ = MemberType;
        if (IsStruct)
        { /* allocate this member's location in the struct */
            MemberValue->Val->Integer = (*Typ)->Sizeof;
            (*Typ)->Sizeof += MemberValue->Typ->Sizeof;
        }
        else
        { /* union members always start at 0, make sure it's big enough to hold the largest member */
            MemberValue->Val->Integer = 0;
            if (MemberValue->Typ->Sizeof > (*Typ)->Sizeof)
                (*Typ)->Sizeof = MemberValue->Typ->Sizeof;
        }
        
        if (!TableSet((*Typ)->Members, MemberIdentifier, MemberValue))
            ProgramFail(Parser, "member '%s' already defined", &MemberIdentifier);
            
        if (LexGetToken(Parser, NULL, TRUE) != TokenSemicolon)
            ProgramFail(Parser, "semicolon expected");
                    
    } while (LexGetToken(Parser, NULL, FALSE) != TokenRightBrace);
    
    LexGetToken(Parser, NULL, TRUE);
}

/* parse an enum declaration */
void TypeParseEnum(struct ParseState *Parser, struct ValueType **Typ)
{
    struct Value *LexValue;
    struct Value InitValue;
    enum LexToken Token;
    struct ValueType *EnumType;
    int EnumValue = 0;
    char *EnumIdentifier;
    
    if (TopStackFrame != NULL)
        ProgramFail(Parser, "enum definitions can only be globals");
        
    if (LexGetToken(Parser, &LexValue, TRUE) != TokenIdentifier)
        ProgramFail(Parser, "enum name required");
    
    *Typ = &IntType;
    EnumType = TypeGetMatching(Parser, &UberType, TypeEnum, 0, LexValue->Val->Identifier);
    Token = LexGetToken(Parser, NULL, FALSE);
    if (Token != TokenLeftBrace)
    { /* use the already defined enum */
        if ((*Typ)->Members == NULL)
            ProgramFail(Parser, "enum '%s' isn't defined", LexValue->Val->Identifier);
            
        return;
    }
    
    LexGetToken(Parser, NULL, TRUE);    
    (*Typ)->Members = &GlobalTable;
    memset((void *)&InitValue, '\0', sizeof(struct Value));
    InitValue.Typ = &IntType;
    InitValue.Val = (union AnyValue *)&EnumValue;
    do {
        if (LexGetToken(Parser, &LexValue, TRUE) != TokenIdentifier)
            ProgramFail(Parser, "identifier expected");
        
        EnumIdentifier = LexValue->Val->Identifier;
        if (LexGetToken(Parser, NULL, FALSE) == TokenAssign)
        {
            LexGetToken(Parser, NULL, TRUE);
            EnumValue = ExpressionParseInt(Parser);
        }
        
        VariableDefine(Parser, EnumIdentifier, &InitValue);
            
        Token = LexGetToken(Parser, NULL, TRUE);
        if (Token != TokenComma && Token != TokenRightBrace)
            ProgramFail(Parser, "comma expected");
        
        EnumValue++;
                    
    } while (Token == TokenComma);
}

/* parse a type - just the basic type */
int TypeParseFront(struct ParseState *Parser, struct ValueType **Typ)
{
    struct ParseState Before = *Parser;
    enum LexToken Token = LexGetToken(Parser, NULL, TRUE);
    *Typ = NULL;

    switch (Token)
    {
        case TokenIntType: case TokenLongType: case TokenShortType: *Typ = &IntType; break;
        case TokenCharType: *Typ = &CharType; break;
#ifndef NO_FP
        case TokenFloatType: case TokenDoubleType: *Typ = &FPType; break;
#endif
        case TokenVoidType: *Typ = &VoidType; break;
        
        case TokenStructType: case TokenUnionType: 
            if (*Typ != NULL)
                ProgramFail(Parser, "bad type declaration");
                
            TypeParseStruct(Parser, Typ, Token == TokenStructType);
            break;

        case TokenEnumType:
            if (*Typ != NULL)
                ProgramFail(Parser, "bad type declaration");
                
            TypeParseEnum(Parser, Typ);
            break;

        default: *Parser = Before; return FALSE;
    }
    
    return TRUE;
}

/* parse a type - the part which is repeated with each identifier in a declaration list */
void TypeParseIdentPart(struct ParseState *Parser, struct ValueType *BasicTyp, struct ValueType **Typ, char **Identifier)
{
    struct ParseState Before;
    enum LexToken Token;
    struct Value *LexValue;
    int Done = FALSE;
    *Typ = BasicTyp;
    *Identifier = StrEmpty;
    
    while (!Done)
    {
        Before = *Parser;
        Token = LexGetToken(Parser, &LexValue, TRUE);
        switch (Token)
        {
            case TokenOpenBracket:
                if (*Typ != NULL)
                    ProgramFail(Parser, "bad type declaration");
                
                TypeParse(Parser, Typ, Identifier);
                if (LexGetToken(Parser, NULL, TRUE) != TokenCloseBracket)
                    ProgramFail(Parser, "')' expected");
                break;
                
            case TokenAsterisk:
                if (*Typ == NULL)
                    ProgramFail(Parser, "bad type declaration");

                *Typ = TypeGetMatching(Parser, *Typ, TypePointer, 0, StrEmpty);
                break;
            
            case TokenIdentifier:
                if (*Typ == NULL || *Identifier != StrEmpty)
                    ProgramFail(Parser, "bad type declaration");
                
                *Identifier = LexValue->Val->Identifier;
                Done = TRUE;
                break;
                
            default: *Parser = Before; Done = TRUE; break;
        }
    }
    
    if (*Typ == NULL)
        ProgramFail(Parser, "bad type declaration");

    if (*Identifier != StrEmpty)
    { /* parse stuff after the identifier */
        Done = FALSE;
        while (!Done)
        {
            Before = *Parser;
            switch (LexGetToken(Parser, NULL, TRUE))
            {
                case TokenLeftSquareBracket:
                    {
                        enum RunMode OldMode = Parser->Mode;
                        Parser->Mode = RunModeRun;
                        int ArraySize = ExpressionParseInt(Parser);
                        Parser->Mode = OldMode;
                        
                        if (LexGetToken(Parser, NULL, TRUE) != TokenRightSquareBracket)
                            ProgramFail(Parser, "']' expected");
                            
                        *Typ = TypeGetMatching(Parser, *Typ, TypeArray, ArraySize, StrEmpty);
                    }
                    break;
                    
//                case TokenOpenBracket:
//                    break;  // XXX - finish this
                
                default: *Parser = Before; Done = TRUE; break;
            }
        }
    }    
}

/* parse a type - a complete declaration including identifier */
void TypeParse(struct ParseState *Parser, struct ValueType **Typ, char **Identifier)
{
    struct ValueType *BasicType;
    
    TypeParseFront(Parser, &BasicType);
    TypeParseIdentPart(Parser, BasicType, Typ, Identifier);
}

