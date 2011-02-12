#include "picoc.h"

/* some basic types */
struct ValueType UberType;
struct ValueType IntType;
struct ValueType ShortType;
struct ValueType CharType;
struct ValueType LongType;
struct ValueType UnsignedIntType;
struct ValueType UnsignedShortType;
struct ValueType UnsignedLongType;
#ifndef NO_FP
struct ValueType FPType;
#endif
struct ValueType VoidType;
struct ValueType TypeType;
struct ValueType FunctionType;
struct ValueType MacroType;
struct ValueType EnumType;
struct ValueType *CharPtrType;
struct ValueType *CharPtrPtrType;
struct ValueType *CharArrayType;
struct ValueType *VoidPtrType;


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
        case TypePointer:   Sizeof = sizeof(void *); break;
        case TypeArray:     Sizeof = ArraySize * ParentType->Sizeof; break;
        case TypeEnum:      Sizeof = sizeof(int); break;
        default:            Sizeof = 0; break;      /* structs and unions will get bigger when we add members to them */
    }

    return TypeAdd(Parser, ParentType, Base, ArraySize, Identifier, Sizeof);
}

/* stack space used by a value */
int TypeStackSizeValue(struct Value *Val)
{
    if (Val != NULL && Val->ValOnStack)
        return TypeSizeValue(Val);
    else
        return 0;
}

/* memory used by a value */
int TypeSizeValue(struct Value *Val)
{
    if (IS_INTEGER_NUMERIC(Val))
        return sizeof(ALIGN_TYPE);     /* allow some extra room for type extension */
    else if (Val->Typ->Base != TypeArray)
        return Val->Typ->Sizeof;
    else
        return Val->Typ->FromType->Sizeof * Val->Typ->ArraySize;
}

/* memory used by a variable given its type and array size */
int TypeSize(struct ValueType *Typ, int ArraySize, int Compact)
{
    if (IS_INTEGER_NUMERIC_TYPE(Typ) && !Compact)
        return sizeof(ALIGN_TYPE);     /* allow some extra room for type extension */
    else if (Typ->Base != TypeArray)
        return Typ->Sizeof;
    else
        return Typ->FromType->Sizeof * ArraySize;
}

/* memory used by the base (non-array) type of a type. This is used for alignment. */
int TypeSizeAlignment(struct ValueType *Typ)
{
    if (Typ->Base == TypeArray)
        return sizeof(ALIGN_TYPE);
    else
        return Typ->Sizeof;
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
    TypeAddBaseType(&ShortType, TypeShort, sizeof(short));
    TypeAddBaseType(&CharType, TypeChar, sizeof(unsigned char));
    TypeAddBaseType(&LongType, TypeLong, sizeof(long));
    TypeAddBaseType(&UnsignedIntType, TypeUnsignedInt, sizeof(unsigned int));
    TypeAddBaseType(&UnsignedShortType, TypeUnsignedShort, sizeof(unsigned short));
    TypeAddBaseType(&UnsignedLongType, TypeUnsignedLong, sizeof(unsigned long));
    TypeAddBaseType(&VoidType, TypeVoid, 0);
    TypeAddBaseType(&FunctionType, TypeFunction, sizeof(int));
    TypeAddBaseType(&MacroType, TypeMacro, sizeof(int));
#ifndef NO_FP
    TypeAddBaseType(&FPType, TypeFP, sizeof(double));
    TypeAddBaseType(&TypeType, Type_Type, sizeof(double));  /* must be large enough to cast to a double */
#else
    TypeAddBaseType(&TypeType, Type_Type, sizeof(struct ValueType *));
#endif
    CharArrayType = TypeAdd(NULL, &CharType, TypeArray, 0, StrEmpty, sizeof(char));
    CharPtrType = TypeAdd(NULL, &CharType, TypePointer, 0, StrEmpty, sizeof(void *));
    CharPtrPtrType = TypeAdd(NULL, CharPtrType, TypePointer, 0, StrEmpty, sizeof(void *));
    VoidPtrType = TypeAdd(NULL, &VoidType, TypePointer, 0, StrEmpty, sizeof(void *));
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
                HeapFreeMem(SubType->Members);
            }

            /* free this node */
            HeapFreeMem(SubType);
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
    int AlignBoundary;
    
    if (LexGetToken(Parser, &LexValue, TRUE) != TokenIdentifier)
        ProgramFail(Parser, "struct/union name required");
    
    *Typ = TypeGetMatching(Parser, &UberType, IsStruct ? TypeStruct : TypeUnion, 0, LexValue->Val->Identifier);

    Token = LexGetToken(Parser, NULL, FALSE);
    if (Token != TokenLeftBrace)
    { 
        /* use the already defined structure */
        if ((*Typ)->Members == NULL)
            ProgramFail(Parser, "structure '%s' isn't defined", LexValue->Val->Identifier);
            
        return;
    }
    
    if (TopStackFrame != NULL)
        ProgramFail(Parser, "struct/union definitions can only be globals");
        
    LexGetToken(Parser, NULL, TRUE);    
    (*Typ)->Members = VariableAlloc(Parser, sizeof(struct Table) + STRUCT_TABLE_SIZE * sizeof(struct TableEntry), TRUE);
    (*Typ)->Members->HashTable = (struct TableEntry **)((char *)(*Typ)->Members + sizeof(struct Table));
    TableInitTable((*Typ)->Members, (struct TableEntry **)((char *)(*Typ)->Members + sizeof(struct Table)), STRUCT_TABLE_SIZE, TRUE);
    
    do {
        TypeParse(Parser, &MemberType, &MemberIdentifier);
        if (MemberType == NULL || MemberIdentifier == NULL)
            ProgramFail(Parser, "invalid type in struct");
        
        MemberValue = VariableAllocValueAndData(Parser, sizeof(int), FALSE, NULL, TRUE);
        MemberValue->Typ = MemberType;
        if (IsStruct)
        { 
            /* allocate this member's location in the struct */
            AlignBoundary = TypeSizeAlignment(MemberValue->Typ);
            if (((*Typ)->Sizeof & (AlignBoundary-1)) != 0)
                (*Typ)->Sizeof += AlignBoundary - ((*Typ)->Sizeof & (AlignBoundary-1));
                
            MemberValue->Val->Integer = (*Typ)->Sizeof;
            (*Typ)->Sizeof += TypeSizeValue(MemberValue);
        }
        else
        { 
            /* union members always start at 0, make sure it's big enough to hold the largest member */
            MemberValue->Val->Integer = 0;
            if (MemberValue->Typ->Sizeof > (*Typ)->Sizeof)
                (*Typ)->Sizeof = TypeSizeValue(MemberValue);
        }
        
        if (!TableSet((*Typ)->Members, MemberIdentifier, MemberValue, Parser->Line, Parser->CharacterPos))
            ProgramFail(Parser, "member '%s' already defined", &MemberIdentifier);
            
        if (LexGetToken(Parser, NULL, TRUE) != TokenSemicolon)
            ProgramFail(Parser, "semicolon expected");
                    
    } while (LexGetToken(Parser, NULL, FALSE) != TokenRightBrace);
    
    LexGetToken(Parser, NULL, TRUE);
}

/* create a system struct which has no user-visible members */
struct ValueType *TypeCreateOpaqueStruct(struct ParseState *Parser, const char *StructName, int Size)
{
    struct ValueType *Typ = TypeGetMatching(Parser, &UberType, TypeStruct, 0, StructName);
    
    /* create the (empty) table */
    Typ->Members = VariableAlloc(Parser, sizeof(struct Table) + STRUCT_TABLE_SIZE * sizeof(struct TableEntry), TRUE);
    Typ->Members->HashTable = (struct TableEntry **)((char *)Typ->Members + sizeof(struct Table));
    TableInitTable(Typ->Members, (struct TableEntry **)((char *)Typ->Members + sizeof(struct Table)), STRUCT_TABLE_SIZE, TRUE);
    Typ->Sizeof = Size;
    
    return Typ;
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
    
    if (LexGetToken(Parser, &LexValue, TRUE) != TokenIdentifier)
        ProgramFail(Parser, "enum name required");
    
    *Typ = &IntType;
    EnumType = TypeGetMatching(Parser, &UberType, TypeEnum, 0, LexValue->Val->Identifier);
    Token = LexGetToken(Parser, NULL, FALSE);
    if (Token != TokenLeftBrace)
    { 
        /* use the already defined enum */
        if ((*Typ)->Members == NULL)
            ProgramFail(Parser, "enum '%s' isn't defined", LexValue->Val->Identifier);
            
        return;
    }
    
    if (TopStackFrame != NULL)
        ProgramFail(Parser, "enum definitions can only be globals");
        
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
        
        VariableDefine(Parser, EnumIdentifier, &InitValue, NULL, FALSE);
            
        Token = LexGetToken(Parser, NULL, TRUE);
        if (Token != TokenComma && Token != TokenRightBrace)
            ProgramFail(Parser, "comma expected");
        
        EnumValue++;
                    
    } while (Token == TokenComma);
}

/* parse a type - just the basic type */
int TypeParseFront(struct ParseState *Parser, struct ValueType **Typ)
{
    struct ParseState Before;
    struct Value *LexerValue;
    enum LexToken Token;
    int Unsigned = FALSE;
    struct Value *VarValue;
    *Typ = NULL;

    /* ignore leading type qualifiers */
    ParserCopy(&Before, Parser);
    Token = LexGetToken(Parser, &LexerValue, TRUE);
    while (Token == TokenStaticType || Token == TokenRegisterType  || Token == TokenExternType)
        Token = LexGetToken(Parser, &LexerValue, TRUE);
        
    /* handle signed/unsigned with no trailing type */
    if (Token == TokenSignedType || Token == TokenUnsignedType)
    {
        enum LexToken FollowToken = LexGetToken(Parser, &LexerValue, FALSE);
        Unsigned = (Token == TokenUnsignedType);
        
        if (FollowToken != TokenIntType && FollowToken != TokenLongType && FollowToken != TokenShortType && FollowToken != TokenCharType)
        {
            if (Token == TokenUnsignedType)
                *Typ = &UnsignedIntType;
            else
                *Typ = &IntType;
            
            return TRUE;
        }
        
        Token = LexGetToken(Parser, &LexerValue, TRUE);
    }
    
    switch (Token)
    {
        case TokenIntType: *Typ = Unsigned ? &UnsignedIntType : &IntType; break;
        case TokenShortType: *Typ = Unsigned ? &UnsignedShortType : &ShortType; break;
        case TokenCharType: *Typ = &CharType; break;
        case TokenLongType: *Typ = Unsigned ? &UnsignedLongType : &LongType; break;
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
        
        case TokenIdentifier:
            /* we already know it's a typedef-defined type because we got here */
            VariableGet(Parser, LexerValue->Val->Identifier, &VarValue);
            *Typ = VarValue->Val->Typ;
            break;

        default: ParserCopy(Parser, &Before); return FALSE;
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
        ParserCopy(&Before, Parser);
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
                
            default: ParserCopy(Parser, &Before); Done = TRUE; break;
        }
    }
    
    if (*Typ == NULL)
        ProgramFail(Parser, "bad type declaration");

    if (*Identifier != StrEmpty)
    { 
        /* parse stuff after the identifier */
        Done = FALSE;
        while (!Done)
        {
            Before = *Parser;
            switch (LexGetToken(Parser, NULL, TRUE))
            {
                case TokenLeftSquareBracket:
                    {
                        enum RunMode OldMode = Parser->Mode;
                        int ArraySize;
                        Parser->Mode = RunModeRun;
                        ArraySize = ExpressionParseInt(Parser);
                        Parser->Mode = OldMode;
                        
                        if (LexGetToken(Parser, NULL, TRUE) != TokenRightSquareBracket)
                            ProgramFail(Parser, "']' expected");
                            
                        *Typ = TypeGetMatching(Parser, *Typ, TypeArray, ArraySize, StrEmpty);
                    }
                    break;
                    
#if 0
                case TokenOpenBracket:
                    break;  /* XXX - finish this */
#endif
                
                default: ParserCopy(Parser, &Before); Done = TRUE; break;
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

