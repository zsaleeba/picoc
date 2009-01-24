#include "picoc.h"

/* some basic types */
struct ValueType UberType;
struct ValueType IntType;
struct ValueType CharType;
struct ValueType StringType;
struct ValueType FPType;
struct ValueType VoidType;
struct ValueType FunctionType;
struct ValueType MacroType;
struct ValueType EnumType;
struct ValueType Type_Type;


/* add a new type to the set of types we know about */
struct ValueType *TypeAdd(struct LexState *Lexer, struct ValueType *ParentType, enum BaseType Base, int ArraySize, Str *Identifier, int Sizeof)
{
    struct ValueType *NewType = VariableAlloc(Lexer, sizeof(struct ValueType));
    NewType->Base = Base;
    NewType->ArraySize = ArraySize;
    NewType->Sizeof = Sizeof;
    StrCopy(&NewType->Identifier, Identifier);
    NewType->Members = NULL;
    NewType->FromType = ParentType;
    NewType->DerivedTypeList = NULL;
    NewType->Next = ParentType->DerivedTypeList;
    ParentType->DerivedTypeList = NewType;
    
    return NewType;
}

/* given a parent type, get a matching derived type and make one if necessary */
struct ValueType *TypeGetMatching(struct LexState *Lexer, struct ValueType *ParentType, enum BaseType Base, int ArraySize, Str *Identifier)
{
    int Sizeof;
    struct ValueType *ThisType = ParentType->DerivedTypeList;
    while (ThisType != NULL && (ThisType->Base != Base || ThisType->ArraySize != ArraySize || !StrEqual(&ThisType->Identifier, Identifier)))
        ThisType = ThisType->Next;
    
    if (ThisType != NULL)
        return ThisType;
        
    switch (Base)
    {
        case TypePointer:   Sizeof = sizeof(struct PointerValue); break;
        case TypeArray:     Sizeof = ArraySize * ParentType->Sizeof; break;
        case TypeEnum:      Sizeof = sizeof(int); break;
        default:            Sizeof = 0; break;      /* structs and unions will get bigger when we add members to them */
    }

    return TypeAdd(Lexer, ParentType, Base, ArraySize, Identifier, Sizeof);
}

/* add a base type */
void TypeAddBaseType(struct ValueType *TypeNode, enum BaseType Base, int Sizeof)
{
    TypeNode->Base = Base;
    TypeNode->ArraySize = 0;
    TypeNode->Sizeof = Sizeof;
    StrFromC(&TypeNode->Identifier, "");
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
    TypeAddBaseType(&CharType, TypeChar, sizeof(char));
    TypeAddBaseType(&StringType, TypeString, sizeof(Str));
    TypeAddBaseType(&FPType, TypeFP, sizeof(double));
    TypeAddBaseType(&VoidType, TypeVoid, 0);
    TypeAddBaseType(&FunctionType, TypeFunction, sizeof(int));
    TypeAddBaseType(&MacroType, TypeMacro, sizeof(int));
    TypeAddBaseType(&Type_Type, TypeType, sizeof(struct ValueType *));
}

/* parse a struct or union declaration */
void TypeParseStruct(struct LexState *Lexer, struct ValueType **Typ, int IsStruct)
{
    union AnyValue LexValue;
    int TotalSize = 0;
    struct ValueType *MemberType;
    Str MemberIdentifier;
    struct Value *MemberValue;
    
    if (LexGetToken(Lexer, &LexValue) != TokenIdentifier)
        ProgramFail(Lexer, "struct/union name required");
    
    if (LexGetPlainToken(Lexer) != TokenOpenBrace)
        ProgramFail(Lexer, "'{' expected");
    
    if (StackLevel != 0)
        ProgramFail(Lexer, "struct/union definitions can only be globals");
        
    *Typ = TypeGetMatching(Lexer, &UberType, IsStruct ? TypeStruct : TypeUnion, 0, &LexValue.String);
    (*Typ)->Members = VariableAlloc(sizeof(struct Table) + STRUCT_TABLE_SIZE * sizeof(struct TableEntry));
    (*Typ)->Members->HashTable = (struct Table *)((void *)(*Typ)->Members + sizeof(struct Table));
    
    do {
        TypeParse(Lexer, &MemberType, &MemberIdentifier);
        
        MemberValue = VariableAllocValueAndData(Lexer, sizeof(int));
        MemberValue->MustFree = TRUE;
        MemberValue->Typ = &MemberType;
        if (IsStruct)
        { /* allocate this member's location in the struct */
            MemberValue->Value->Integer = (*Typ)->Sizeof;
            (*Typ)->Sizeof += MemberValue->Typ->Sizeof;
        }
        else
        { /* union members always start at 0, make sure it's big enough to hold the largest member */
            MemberValue->Value->Integer = 0;
            if (MemberValue->Typ->Sizeof > (*Typ)->Sizeof)
                (*Typ)->Sizeof = MemberValue->Typ->Sizeof;
        }
        
        if (!TableSet((*Typ)->Members, &MemberIdentifier, MemberValue))
            ProgramFail(Lexer, "member '%S' already defined", &MemberIdentifier);
                    
    } while (LexPeekPlainToken(Lexer) != TokenCloseBrace);
    
    LexGetPlainToken(Lexer);
}

/* parse a type */
void TypeParse(struct LexState *Lexer, struct ValueType **Typ, Str *Identifier)
{
    struct LexState Before;
    struct LexToken Token;
    union AnyValue LexValue;
    struct Value ArraySize;
    int Done = FALSE;
    *Typ = NULL;
    
    while (!Done)
    {
        Before = *Lexer;
        Token = LexGetToken(Lexer, &LexValue);
        switch (Token)
        {
            case TokenIntType: case TokenLongType: case TokenShortType: *Typ = &IntType; break;
            case TokenCharType: *Typ = &CharType; break;
            case TokenFloatType: case TokenDoubleType: *Typ = &FPType; break;
            case TokenVoidType: *Typ = &VoidType; break;
            
            case TokenStructType: case TokenUnionType: 
                if (*Typ != NULL)
                    ProgramFail(Lexer, "bad type declaration");
                    
                TypeParseStruct(Lexer, Typ, Token == TokenStructType);
                break;

            case TokenOpenBracket:
                if (*Typ != NULL)
                    ProgramFail(Lexer, "bad type declaration");
                
                TypeParseDeclarator(Lexer, Typ, Identifier);
                if (LexGetTokenOnly(Lexer) != TokenCloseBracket)
                    ProgramFail(Lexer, "')' expected");
                break;
                
            case TokenAsterisk:
                if (*Typ == NULL)
                    ProgramFail(Lexer, "bad type declaration");

                *Typ = TypeGetMatching(Lexer, *Typ, TypePointer, 0);
                break;
            
            case TokenIdentifier:
                if (*Typ == NULL || Identifier->Length != 0)
                    ProgramFail(Lexer, "bad type declaration");
                
                *Identifier = LexValue.String;
                Done = TRUE;
                break;
                
            default: *Lexer = Before; Done = TRUE; break;
        }
    }
    
    if (*Typ == NULL)
        ProgramFail(Lexer, "bad type declaration");

    if (Identifier->Length != 0)
    { /* parse stuff after the identifier */
        Done = FALSE;
        while (!Done)
        {
            Before = *Lexer;
            switch (LexGetTokenOnly(Lexer))
            {
                case TokenOpenSquareBracket:
                    {
                        struct Value ArraySize;
                        union AnyValue ArraySizeAnyValue;
                        ArraySize->Val = &ArraySizeAnyValue;
                        if (!ParseExpression(Lexer, &ArraySize, TRUE))
                            ArraySize->Val->Integer = 0;

                        if (LexGetTokenOnly(Lexer) != TokenCloseSquareBracket)
                            ProgramFail(Lexer, "']' expected");
                            
                        *Typ = TypeGetMatching(Lexer, *Typ, TypeArray, ArraySize->Val->Integer);
                    }
                    break;
                    
                case TokenOpenBracket:
                    break;  // XXX - finish this
                
                default: *Lexer = Before; Done = TRUE; break;
            }
        }
    }    
}
