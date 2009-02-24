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

/* memory used by a value */
int TypeSizeValue(struct Value *Val)
{
    if (Val->Typ->Base != TypeArray)
        return Val->Typ->Sizeof;
    else
        return sizeof(struct ArrayValue) + Val->Typ->FromType->Sizeof * Val->Val->Array.Size;
}

/* memory used by a variable given its type and array size */
int TypeSize(struct ValueType *Typ, int ArraySize)
{
    if (Typ->Base != TypeArray)
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
        
        MemberValue = VariableAllocValueAndData(Parser, sizeof(int), FALSE, TRUE);
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

/* parse a type */
void TypeParse(struct ParseState *Parser, struct ValueType **Typ, char **Identifier)
{
    struct ParseState Before;
    enum LexToken Token;
    struct Value *LexValue;
    int Done = FALSE;
    *Typ = NULL;
    *Identifier = StrEmpty;
    
    while (!Done)
    {
        Before = *Parser;
        Token = LexGetToken(Parser, &LexValue, TRUE);
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
                        int ArraySize = ParseIntExpression(Parser);
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
