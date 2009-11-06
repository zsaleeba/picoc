#include "picoc.h"


/* whether evaluation is left to right for a given precedence level */
#define IS_LEFT_TO_RIGHT(p) ((p) != 2 && (p) != 3 && (p) != 14)
#define BRACKET_PRECEDENCE 20
#define IS_TYPE_TOKEN(t) ((t) >= TokenIntType && (t) <= TokenEnumType)

#ifdef DEBUG_EXPRESSIONS
#define debugf printf
#else
void debugf(char *Format, ...)
{
}
#endif

/* local prototypes */
enum OperatorOrder
{
    OrderNone,
    OrderPrefix,
    OrderInfix,
    OrderPostfix
};

/* a stack of expressions we use in evaluation */
struct ExpressionStack
{
    struct ExpressionStack *Next;       /* the next lower item on the stack */
    struct Value *Val;                  /* the value for this stack node */
    enum LexToken Op;                   /* the operator */
    short unsigned int Precedence;      /* the operator precedence of this node */
    unsigned char Order;                /* the evaluation order of this operator */
};

/* operator precedence definitions */
struct OpPrecedence
{
    unsigned int PrefixPrecedence:4;
    unsigned int PostfixPrecedence:4;
    unsigned int InfixPrecedence:4;
    char *Name;
};

/* NOTE: the order of this array must correspond exactly to the order of these tokens in enum LexToken */
static struct OpPrecedence OperatorPrecedence[] =
{
    /* TokenNone, */ { 0, 0, 0, "none" },
    /* TokenComma, */ { 0, 0, 0, "," },
    /* TokenAssign, */ { 0, 0, 2, "=" }, /* TokenAddAssign, */ { 0, 0, 2, "+=" }, /* TokenSubtractAssign, */ { 0, 0, 2, "-=" }, 
    /* TokenMultiplyAssign, */ { 0, 0, 2, "*=" }, /* TokenDivideAssign, */ { 0, 0, 2, "/=" }, /* TokenModulusAssign, */ { 0, 0, 2, "%=" },
    /* TokenShiftLeftAssign, */ { 0, 0, 2, "<<=" }, /* TokenShiftRightAssign, */ { 0, 0, 2, ">>=" }, /* TokenArithmeticAndAssign, */ { 0, 0, 2, "&=" }, 
    /* TokenArithmeticOrAssign, */ { 0, 0, 2, "|=" }, /* TokenArithmeticExorAssign, */ { 0, 0, 2, "^=" },
    /* TokenQuestionMark, */ { 0, 0, 3, "?" }, /* TokenColon, */ { 0, 0, 3, ":" },
    /* TokenLogicalOr, */ { 0, 0, 4, "||" },
    /* TokenLogicalAnd, */ { 0, 0, 5, "&&" },
    /* TokenArithmeticOr, */ { 0, 0, 6, "|" },
    /* TokenArithmeticExor, */ { 0, 0, 7, "^" },
    /* TokenAmpersand, */ { 14, 0, 8, "&" },
    /* TokenEqual, */  { 0, 0, 9, "==" }, /* TokenNotEqual, */ { 0, 0, 9, "!=" },
    /* TokenLessThan, */ { 0, 0, 10, "<" }, /* TokenGreaterThan, */ { 0, 0, 10, ">" }, /* TokenLessEqual, */ { 0, 0, 10, "<=" }, /* TokenGreaterEqual, */ { 0, 0, 10, ">=" },
    /* TokenShiftLeft, */ { 0, 0, 11, "<<" }, /* TokenShiftRight, */ { 0, 0, 11, ">>" },
    /* TokenPlus, */ { 14, 0, 12, "+" }, /* TokenMinus, */ { 14, 0, 12, "-" },
    /* TokenAsterisk, */ { 14, 0, 13, "*" }, /* TokenSlash, */ { 0, 0, 13, "/" }, /* TokenModulus, */ { 0, 0, 13, "%" },
    /* TokenIncrement, */ { 14, 15, 0, "++" }, /* TokenDecrement, */ { 14, 15, 0, "--" }, /* TokenUnaryNot, */ { 14, 0, 0, "!" }, /* TokenUnaryExor, */ { 14, 0, 0, "~" }, /* TokenSizeof, */ { 14, 0, 0, "sizeof" }, /* TokenCast, */ { 14, 0, 0, "cast" },
    /* TokenLeftSquareBracket, */ { 0, 0, 15, "[" }, /* TokenRightSquareBracket, */ { 0, 15, 0, "]" }, /* TokenDot, */ { 0, 0, 15, "." }, /* TokenArrow, */ { 0, 0, 15, "->" },
    /* TokenOpenBracket, */ { 15, 0, 0, "(" }, /* TokenCloseBracket, */ { 0, 15, 0, ")" }
};

void ExpressionParseFunctionCall(struct ParseState *Parser, struct ExpressionStack **StackTop, const char *FuncName);

#ifdef DEBUG_EXPRESSIONS
/* show the contents of the expression stack */
void ExpressionStackShow(struct ExpressionStack *StackTop)
{
    printf("Expression stack [0x%lx,0x%lx]: ", (long)HeapStackTop, (long)StackTop);
    
    while (StackTop != NULL)
    {
        if (StackTop->Order == OrderNone)
        { 
            /* it's a value */
            if (StackTop->Val->IsLValue)
                printf("lvalue=");
            else
                printf("value=");
                
            switch (StackTop->Val->Typ->Base)
            {
                case TypeVoid:      printf("void"); break;
                case TypeInt:       printf("%d:int", StackTop->Val->Val->Integer); break;
                case TypeShort:     printf("%d:short", StackTop->Val->Val->ShortInteger); break;
                case TypeChar:      printf("%d:char", StackTop->Val->Val->Character); break;
                case TypeFP:        printf("%f:fp", StackTop->Val->Val->FP); break;
                case TypeFunction:  printf("%s:function", StackTop->Val->Val->Identifier); break;
                case TypeMacro:     printf("%s:macro", StackTop->Val->Val->Identifier); break;
                case TypePointer:
                    if (StackTop->Val->Val->NativePointer == NULL)
                        printf("ptr(NULL)");
                    else if (StackTop->Val->Typ->FromType->Base == TypeChar)
                        printf("\"%s\":string", (char *)StackTop->Val->Val->NativePointer);
                    else
                        printf("ptr(0x%lx)", (long)StackTop->Val->Val->NativePointer); 
                    break;
                case TypeArray:     printf("array"); break;
                case TypeStruct:    printf("%s:struct", StackTop->Val->Val->Identifier); break;
                case TypeUnion:     printf("%s:union", StackTop->Val->Val->Identifier); break;
                case TypeEnum:      printf("%s:enum", StackTop->Val->Val->Identifier); break;
                case Type_Type:     PrintType(StackTop->Val->Val->Typ, &CStdOut); printf(":type"); break;
                default:            printf("unknown"); break;
            }
            printf("[0x%lx,0x%lx]", (long)StackTop, (long)StackTop->Val);
        }
        else
        { 
            /* it's an operator */
            printf("op='%s' %s %d", OperatorPrecedence[(int)StackTop->Op].Name, 
                (StackTop->Order == OrderPrefix) ? "prefix" : ((StackTop->Order == OrderPostfix) ? "postfix" : "infix"), 
                StackTop->Precedence);
            printf("[0x%lx]", (long)StackTop);
        }
        
        StackTop = StackTop->Next;
        if (StackTop != NULL)
            printf(", ");
    }
    
    printf("\n");
}
#endif

int ExpressionCoerceInteger(struct Value *Val)
{
    switch (Val->Typ->Base)
    {
        case TypeInt:             return (int)Val->Val->Integer;
        case TypeChar:            return (int)Val->Val->Character;
        case TypeShort:           return (int)Val->Val->ShortInteger;
        case TypeUnsignedInt:     return (int)Val->Val->UnsignedInteger;
        case TypeUnsignedShort:   return (int)Val->Val->UnsignedShortInteger;
        case TypePointer:         return (int)Val->Val->NativePointer;
#ifndef NO_FP
        case TypeFP:              return (int)Val->Val->FP;
#endif
        default:                  return 0;
    }
}

unsigned int ExpressionCoerceUnsignedInteger(struct Value *Val)
{
    switch (Val->Typ->Base)
    {
        case TypeInt:             return (unsigned int)Val->Val->Integer;
        case TypeChar:            return (unsigned int)Val->Val->Character;
        case TypeShort:           return (unsigned int)Val->Val->ShortInteger;
        case TypeUnsignedInt:     return (unsigned int)Val->Val->UnsignedInteger;
        case TypeUnsignedShort:   return (unsigned int)Val->Val->UnsignedShortInteger;
        case TypePointer:         return (unsigned int)Val->Val->NativePointer;
#ifndef NO_FP
        case TypeFP:              return (unsigned int)Val->Val->FP;
#endif
        default:                  return 0;
    }
}

double ExpressionCoerceFP(struct Value *Val)
{
    switch (Val->Typ->Base)
    {
        case TypeInt:             return (double)Val->Val->Integer;
        case TypeChar:            return (double)Val->Val->Character;
        case TypeShort:           return (double)Val->Val->ShortInteger;
        case TypeUnsignedInt:     return (double)Val->Val->UnsignedInteger;
        case TypeUnsignedShort:   return (double)Val->Val->UnsignedShortInteger;
#ifndef NO_FP
        case TypeFP:              return (double)Val->Val->FP;
#endif
        default:                  return 0;
    }
}

/* assign an integer value */
int ExpressionAssignInt(struct ParseState *Parser, struct Value *DestValue, int FromInt, int After)
{
    int Result;
    
    if (!DestValue->IsLValue) 
        ProgramFail(Parser, "can't assign to this"); 
    
    if (After)
        Result = ExpressionCoerceInteger(DestValue);
    else
        Result = FromInt;

    switch (DestValue->Typ->Base)
    {
        case TypeInt:           DestValue->Val->Integer = FromInt; break;
        case TypeShort:         DestValue->Val->ShortInteger = (short)FromInt; break;
        case TypeChar:          DestValue->Val->Character = (unsigned char)FromInt; break;
        case TypeUnsignedInt:   DestValue->Val->UnsignedInteger = (unsigned int)FromInt; break;
        case TypeUnsignedShort: DestValue->Val->UnsignedShortInteger = (unsigned short)FromInt; break;
        default: break;
    }
    return Result;
}

#ifndef NO_FP
/* assign a floating point value */
double ExpressionAssignFP(struct ParseState *Parser, struct Value *DestValue, double FromFP)
{
    if (!DestValue->IsLValue) 
        ProgramFail(Parser, "can't assign to this"); 
    
    DestValue->Val->FP = FromFP;
    return FromFP;
}
#endif

/* push a node on to the expression stack */
void ExpressionStackPushValueNode(struct ParseState *Parser, struct ExpressionStack **StackTop, struct Value *ValueLoc)
{
    struct ExpressionStack *StackNode = VariableAlloc(Parser, sizeof(struct ExpressionStack), FALSE);
    StackNode->Next = *StackTop;
    StackNode->Val = ValueLoc;
    *StackTop = StackNode;
#ifdef FANCY_ERROR_MESSAGES
    StackNode->Line = Parser->Line;
    StackNode->CharacterPos = Parser->CharacterPos;
#endif
#ifdef DEBUG_EXPRESSIONS
    ExpressionStackShow(*StackTop);
#endif
}

/* push a blank value on to the expression stack by type */
struct Value *ExpressionStackPushValueByType(struct ParseState *Parser, struct ExpressionStack **StackTop, struct ValueType *PushType)
{
    struct Value *ValueLoc = VariableAllocValueFromType(Parser, PushType, FALSE, NULL, FALSE);
    ExpressionStackPushValueNode(Parser, StackTop, ValueLoc);
    
    return ValueLoc;
}

/* push a value on to the expression stack */
void ExpressionStackPushValue(struct ParseState *Parser, struct ExpressionStack **StackTop, struct Value *PushValue)
{
    struct Value *ValueLoc = VariableAllocValueAndCopy(Parser, PushValue, FALSE);
    ExpressionStackPushValueNode(Parser, StackTop, ValueLoc);
}

void ExpressionStackPushLValue(struct ParseState *Parser, struct ExpressionStack **StackTop, struct Value *PushValue, int Offset)
{
    struct Value *ValueLoc = VariableAllocValueShared(Parser, PushValue);
    ValueLoc->Val = (void *)((char *)ValueLoc->Val + Offset);
    ExpressionStackPushValueNode(Parser, StackTop, ValueLoc);
}

void ExpressionStackPushDereference(struct ParseState *Parser, struct ExpressionStack **StackTop, struct Value *DereferenceValue)
{
    struct Value *DerefVal;
    int Offset;
    struct ValueType *DerefType;
    int DerefIsLValue;
    void *DerefDataLoc = VariableDereferencePointer(Parser, DereferenceValue, &DerefVal, &Offset, &DerefType, &DerefIsLValue);
    struct Value *ValueLoc = VariableAllocValueFromExistingData(Parser, DerefType, (union AnyValue *)DerefDataLoc, DerefIsLValue, DerefVal);
    ExpressionStackPushValueNode(Parser, StackTop, ValueLoc);
}

void ExpressionPushInt(struct ParseState *Parser, struct ExpressionStack **StackTop, int IntValue)
{
    struct Value *ValueLoc = VariableAllocValueFromType(Parser, &IntType, FALSE, NULL, FALSE);
    ValueLoc->Val->Integer = IntValue;
    ExpressionStackPushValueNode(Parser, StackTop, ValueLoc);
}

#ifndef NO_FP
void ExpressionPushFP(struct ParseState *Parser, struct ExpressionStack **StackTop, double FPValue)
{
    struct Value *ValueLoc = VariableAllocValueFromType(Parser, &FPType, FALSE, NULL, FALSE);
    ValueLoc->Val->FP = FPValue;
    ExpressionStackPushValueNode(Parser, StackTop, ValueLoc);
}
#endif

/* assign to a pointer */
void ExpressionAssignToPointer(struct ParseState *Parser, struct Value *ToValue, struct Value *FromValue, const char *FuncName, int ParamNo, int AllowPointerCoercion)
{
    struct ValueType *PointedToType = ToValue->Typ->FromType;
    
    if (FromValue->Typ == ToValue->Typ || FromValue->Typ == VoidPtrType || (ToValue->Typ == VoidPtrType && FromValue->Typ->Base == TypePointer))
        ToValue->Val->NativePointer = FromValue->Val->NativePointer;      /* plain old pointer assignment */
        
    else if (FromValue->Typ->Base == TypeArray && (PointedToType == FromValue->Typ->FromType || ToValue->Typ == VoidPtrType))
    {
        /* the form is: blah *x = array of blah */
        ToValue->Val->NativePointer = (void *)&FromValue->Val->ArrayMem[0];
    }
    else if (FromValue->Typ->Base == TypePointer && FromValue->Typ->FromType->Base == TypeArray && 
               (PointedToType == FromValue->Typ->FromType->FromType || ToValue->Typ == VoidPtrType) )
    {
        /* the form is: blah *x = pointer to array of blah */
        ToValue->Val->NativePointer = VariableDereferencePointer(Parser, FromValue, NULL, NULL, NULL, NULL);
    }
    else if (IS_NUMERIC_COERCIBLE(FromValue) && ExpressionCoerceInteger(FromValue) == 0)
    {
        /* null pointer assignment */
        ToValue->Val->NativePointer = NULL;
    }
    else if (AllowPointerCoercion && IS_NUMERIC_COERCIBLE(FromValue))
    {
        /* assign integer to native pointer */
        ToValue->Val->NativePointer = (void *)ExpressionCoerceUnsignedInteger(FromValue);
    }
    else
        AssignFail(Parser, "%t from %t", ToValue->Typ, FromValue->Typ, 0, 0, FuncName, ParamNo); 
}

/* assign any kind of value */
void ExpressionAssign(struct ParseState *Parser, struct Value *DestValue, struct Value *SourceValue, int Force, const char *FuncName, int ParamNo, int AllowPointerCoercion)
{
    if (!DestValue->IsLValue && !Force) 
        AssignFail(Parser, "not an lvalue", NULL, NULL, 0, 0, FuncName, ParamNo); 

    if (IS_NUMERIC_COERCIBLE(DestValue) && !IS_NUMERIC_COERCIBLE_PLUS_POINTERS(SourceValue, AllowPointerCoercion))
        AssignFail(Parser, "%t from %t", DestValue->Typ, SourceValue->Typ, 0, 0, FuncName, ParamNo); 

    switch (DestValue->Typ->Base)
    {
        case TypeInt:           DestValue->Val->Integer = ExpressionCoerceInteger(SourceValue); break;
        case TypeShort:         DestValue->Val->ShortInteger = ExpressionCoerceInteger(SourceValue); break;
        case TypeChar:          DestValue->Val->Character = ExpressionCoerceUnsignedInteger(SourceValue); break;
        case TypeUnsignedInt:   DestValue->Val->UnsignedInteger = ExpressionCoerceUnsignedInteger(SourceValue); break;
        case TypeUnsignedShort: DestValue->Val->UnsignedShortInteger = ExpressionCoerceUnsignedInteger(SourceValue); break;

#ifndef NO_FP
        case TypeFP:
            if (!IS_NUMERIC_COERCIBLE_PLUS_POINTERS(SourceValue, AllowPointerCoercion)) 
                AssignFail(Parser, "%t from %t", DestValue->Typ, SourceValue->Typ, 0, 0, FuncName, ParamNo); 
            
            DestValue->Val->FP = ExpressionCoerceFP(SourceValue);
            break;
#endif
        case TypePointer:
            ExpressionAssignToPointer(Parser, DestValue, SourceValue, FuncName, ParamNo, AllowPointerCoercion);
            break;
        
        case TypeArray:
            if (DestValue->Typ != SourceValue->Typ)
                AssignFail(Parser, "%t from %t", DestValue->Typ, SourceValue->Typ, 0, 0, FuncName, ParamNo); 
            
            if (DestValue->Typ->ArraySize != SourceValue->Typ->ArraySize)
                AssignFail(Parser, "from an array of size %d to one of size %d", NULL, NULL, DestValue->Typ->ArraySize, SourceValue->Typ->ArraySize, FuncName, ParamNo);
            
            memcpy((void *)DestValue->Val, (void *)SourceValue->Val, TypeSizeValue(DestValue));
            break;
        
        case TypeStruct:
        case TypeUnion:
            if (DestValue->Typ != SourceValue->Typ)
                AssignFail(Parser, "%t from %t", DestValue->Typ, SourceValue->Typ, 0, 0, FuncName, ParamNo); 
            
            memcpy((void *)DestValue->Val, (void *)SourceValue->Val, TypeSizeValue(SourceValue));
            break;
        
        default:
            AssignFail(Parser, "%t", DestValue->Typ, NULL, 0, 0, FuncName, ParamNo); 
            break;
    }
}

/* evaluate a prefix operator */
void ExpressionPrefixOperator(struct ParseState *Parser, struct ExpressionStack **StackTop, enum LexToken Op, struct Value *TopValue)
{
    struct Value *Result;

    if (Parser->Mode != RunModeRun)
    {
        /* we're not running it so just return 0 */
        ExpressionPushInt(Parser, StackTop, 0);
        return;
    }
    
    debugf("ExpressionPrefixOperator()\n");
    switch (Op)
    {
        case TokenAmpersand:
            if (!TopValue->IsLValue)
                ProgramFail(Parser, "can't get the address of this");

            Result = VariableAllocValueFromType(Parser, TypeGetMatching(Parser, TopValue->Typ, TypePointer, 0, StrEmpty), FALSE, NULL, FALSE);
            Result->Val->NativePointer = TopValue->Val;
            ExpressionStackPushValueNode(Parser, StackTop, Result);
            break;

        case TokenAsterisk:
            ExpressionStackPushDereference(Parser, StackTop, TopValue);
            break;
        
        case TokenSizeof:
            /* return the size of the argument */
            if (TopValue->Typ == &TypeType)
                ExpressionPushInt(Parser, StackTop, TypeSize(TopValue->Val->Typ, TopValue->Val->Typ->ArraySize, TRUE));
            else
                ExpressionPushInt(Parser, StackTop, TypeSize(TopValue->Typ, TopValue->Typ->ArraySize, TRUE));
            break;
        
        case TokenLeftSquareBracket:
            /* XXX */
            ProgramFail(Parser, "not supported");
            break;
        
        case TokenOpenBracket:
            /* XXX - cast */
            ProgramFail(Parser, "not supported");
            break;

        default:
            /* an arithmetic operator */
#ifndef NO_FP
            if (TopValue->Typ == &FPType)
            {
                /* floating point prefix arithmetic */
                double ResultFP;
                switch (Op)
                {
                    case TokenPlus:         ResultFP = TopValue->Val->FP; break;
                    case TokenMinus:        ResultFP = -TopValue->Val->FP; break;
                    default:                ProgramFail(Parser, "invalid operation"); break;
                }
                
                ExpressionPushFP(Parser, StackTop, ResultFP);
            }
            else 
#endif
            if (IS_NUMERIC_COERCIBLE(TopValue))
            {
                /* integer prefix arithmetic */
                int ResultInt = 0;
                int TopInt = ExpressionCoerceInteger(TopValue);
                switch (Op)
                {
                    case TokenPlus:         ResultInt = TopInt; break;
                    case TokenMinus:        ResultInt = -TopInt; break;
                    case TokenIncrement:    ResultInt = ExpressionAssignInt(Parser, TopValue, TopInt+1, FALSE); break;
                    case TokenDecrement:    ResultInt = ExpressionAssignInt(Parser, TopValue, TopInt-1, FALSE); break;
                    case TokenUnaryNot:     ResultInt = !TopInt; break;
                    case TokenUnaryExor:    ResultInt = ~TopInt; break;
                    default:                ProgramFail(Parser, "invalid operation"); break;
                }

                ExpressionPushInt(Parser, StackTop, ResultInt);
            }
            else if (TopValue->Typ->Base == TypePointer)
            {
                /* pointer prefix arithmetic */
                int Size = TypeSize(TopValue->Typ->FromType, 0, TRUE);
                struct Value *StackValue;
                if (TopValue->Val->NativePointer == NULL)
                    ProgramFail(Parser, "invalid use of a NULL pointer");
                
                if (!TopValue->IsLValue) 
                    ProgramFail(Parser, "can't assign to this"); 
                    
                switch (Op)
                {
                    case TokenIncrement:    TopValue->Val->NativePointer = (void *)((char *)TopValue->Val->NativePointer + Size); break;
                    case TokenDecrement:    TopValue->Val->NativePointer = (void *)((char *)TopValue->Val->NativePointer - Size); break;
                    default:                ProgramFail(Parser, "invalid operation"); break;
                }

                StackValue = ExpressionStackPushValueByType(Parser, StackTop, TopValue->Typ);
                StackValue->Val->NativePointer = TopValue->Val->NativePointer;
            }
            else
                ProgramFail(Parser, "invalid operation");
            break;
    }
}

/* evaluate a postfix operator */
void ExpressionPostfixOperator(struct ParseState *Parser, struct ExpressionStack **StackTop, enum LexToken Op, struct Value *TopValue)
{
    if (Parser->Mode != RunModeRun)
    {
        /* we're not running it so just return 0 */
        ExpressionPushInt(Parser, StackTop, 0);
        return;
    }
    
    debugf("ExpressionPostfixOperator()\n");
    if (IS_NUMERIC_COERCIBLE(TopValue))
    {
        int ResultInt = 0;
        int TopInt = ExpressionCoerceInteger(TopValue);
        switch (Op)
        {
            case TokenIncrement:            ResultInt = ExpressionAssignInt(Parser, TopValue, TopInt+1, TRUE); break;
            case TokenDecrement:            ResultInt = ExpressionAssignInt(Parser, TopValue, TopInt-1, TRUE); break;
            case TokenRightSquareBracket:   ProgramFail(Parser, "not supported"); break;  /* XXX */
            case TokenCloseBracket:         ProgramFail(Parser, "not supported"); break;  /* XXX */
            default:                        ProgramFail(Parser, "invalid operation"); break;
        }
    
        ExpressionPushInt(Parser, StackTop, ResultInt);
    }
    else if (TopValue->Typ->Base == TypePointer)
    {
        /* pointer postfix arithmetic */
        int Size = TypeSize(TopValue->Typ->FromType, 0, TRUE);
        struct Value *StackValue;
        void *OrigPointer = TopValue->Val->NativePointer;
        
        if (TopValue->Val->NativePointer == NULL)
            ProgramFail(Parser, "invalid use of a NULL pointer");
            
        if (!TopValue->IsLValue) 
            ProgramFail(Parser, "can't assign to this"); 
        
        switch (Op)
        {
            case TokenIncrement:    TopValue->Val->NativePointer = (void *)((char *)TopValue->Val->NativePointer + Size); break;
            case TokenDecrement:    TopValue->Val->NativePointer = (void *)((char *)TopValue->Val->NativePointer - Size); break;
            default:                ProgramFail(Parser, "invalid operation"); break;
        }
        
        StackValue = ExpressionStackPushValueByType(Parser, StackTop, TopValue->Typ);
        StackValue->Val->NativePointer = OrigPointer;
    }
    else
        ProgramFail(Parser, "invalid operation");
}

/* evaluate an infix operator */
void ExpressionInfixOperator(struct ParseState *Parser, struct ExpressionStack **StackTop, enum LexToken Op, struct Value *BottomValue, struct Value *TopValue)
{
    int ResultInt = 0;
    struct Value *StackValue;
    void *NativePointer;
    
    if (Parser->Mode != RunModeRun)
    {
        /* we're not running it so just return 0 */
        ExpressionPushInt(Parser, StackTop, 0);
        return;
    }
    
    debugf("ExpressionInfixOperator()\n");
    if (BottomValue == NULL || TopValue == NULL)
        ProgramFail(Parser, "invalid expression");
        
    if (Op == TokenLeftSquareBracket)
    { 
        /* array index */
        int ArrayIndex;
        struct Value *Result;
        
        if (!IS_NUMERIC_COERCIBLE(TopValue))
            ProgramFail(Parser, "array index must be an integer");
        
        ArrayIndex = ExpressionCoerceInteger(TopValue);

        /* make the array element result */
        switch (BottomValue->Typ->Base)
        {
            case TypeArray:   Result = VariableAllocValueFromExistingData(Parser, BottomValue->Typ->FromType, (union AnyValue *)(&BottomValue->Val->ArrayMem[0] + TypeSize(BottomValue->Typ->FromType, 0, TRUE) * ArrayIndex), BottomValue->IsLValue, BottomValue->LValueFrom); break;
            case TypePointer: Result = VariableAllocValueFromExistingData(Parser, BottomValue->Typ->FromType, (union AnyValue *)((char *)BottomValue->Val->NativePointer + TypeSize(BottomValue->Typ->FromType, 0, TRUE) * ArrayIndex), BottomValue->IsLValue, BottomValue->LValueFrom); break;
            default:          ProgramFail(Parser, "this %t is not an array", BottomValue->Typ);
        }
        
        ExpressionStackPushValueNode(Parser, StackTop, Result);
    }
#ifndef NO_FP
    else if ( (TopValue->Typ == &FPType && BottomValue->Typ == &FPType) ||
              (TopValue->Typ == &FPType && IS_NUMERIC_COERCIBLE(BottomValue)) ||
              (IS_NUMERIC_COERCIBLE(TopValue) && BottomValue->Typ == &FPType) )
    {
        /* floating point infix arithmetic */
        int ResultIsInt = FALSE;
        double ResultFP = 0.0;
        double TopFP = (TopValue->Typ == &FPType) ? TopValue->Val->FP : (double)ExpressionCoerceInteger(TopValue);
        double BottomFP = (BottomValue->Typ == &FPType) ? BottomValue->Val->FP : (double)ExpressionCoerceInteger(BottomValue);

        switch (Op)
        {
            case TokenAssign:               ResultFP = ExpressionAssignFP(Parser, BottomValue, TopFP); break;
            case TokenAddAssign:            ResultFP = ExpressionAssignFP(Parser, BottomValue, BottomFP + TopFP); break;
            case TokenSubtractAssign:       ResultFP = ExpressionAssignFP(Parser, BottomValue, BottomFP - TopFP); break;
            case TokenMultiplyAssign:       ResultFP = ExpressionAssignFP(Parser, BottomValue, BottomFP * TopFP); break;
            case TokenDivideAssign:         ResultFP = ExpressionAssignFP(Parser, BottomValue, BottomFP / TopFP); break;
            case TokenEqual:                ResultInt = BottomFP == TopFP; ResultIsInt = TRUE; break;
            case TokenNotEqual:             ResultInt = BottomFP != TopFP; ResultIsInt = TRUE; break;
            case TokenLessThan:             ResultInt = BottomFP < TopFP; ResultIsInt = TRUE; break;
            case TokenGreaterThan:          ResultInt = BottomFP > TopFP; ResultIsInt = TRUE; break;
            case TokenLessEqual:            ResultInt = BottomFP <= TopFP; ResultIsInt = TRUE; break;
            case TokenGreaterEqual:         ResultInt = BottomFP >= TopFP; ResultIsInt = TRUE; break;
            case TokenPlus:                 ResultFP = BottomFP + TopFP; break;
            case TokenMinus:                ResultFP = BottomFP - TopFP; break;
            case TokenAsterisk:             ResultFP = BottomFP * TopFP; break;
            case TokenSlash:                ResultFP = BottomFP / TopFP; break;
            default:                        ProgramFail(Parser, "invalid operation"); break;
        }

        if (ResultIsInt)
            ExpressionPushInt(Parser, StackTop, ResultInt);
        else
            ExpressionPushFP(Parser, StackTop, ResultFP);
    }
#endif
    else if (IS_NUMERIC_COERCIBLE(TopValue) && IS_NUMERIC_COERCIBLE(BottomValue))
    { 
        /* integer operation */
        int TopInt = ExpressionCoerceInteger(TopValue);
        int BottomInt = ExpressionCoerceInteger(BottomValue);
        switch (Op)
        {
            case TokenAssign:               ResultInt = ExpressionAssignInt(Parser, BottomValue, TopInt, FALSE); break;
            case TokenAddAssign:            ResultInt = ExpressionAssignInt(Parser, BottomValue, BottomInt + TopInt, FALSE); break;
            case TokenSubtractAssign:       ResultInt = ExpressionAssignInt(Parser, BottomValue, BottomInt - TopInt, FALSE); break;
            case TokenMultiplyAssign:       ResultInt = ExpressionAssignInt(Parser, BottomValue, BottomInt * TopInt, FALSE); break;
            case TokenDivideAssign:         ResultInt = ExpressionAssignInt(Parser, BottomValue, BottomInt / TopInt, FALSE); break;
#ifndef NO_MODULUS
            case TokenModulusAssign:        ResultInt = ExpressionAssignInt(Parser, BottomValue, BottomInt % TopInt, FALSE); break;
#endif
            case TokenShiftLeftAssign:      ResultInt = ExpressionAssignInt(Parser, BottomValue, BottomInt << TopInt, FALSE); break;
            case TokenShiftRightAssign:     ResultInt = ExpressionAssignInt(Parser, BottomValue, BottomInt >> TopInt, FALSE); break;
            case TokenArithmeticAndAssign:  ResultInt = ExpressionAssignInt(Parser, BottomValue, BottomInt & TopInt, FALSE); break;
            case TokenArithmeticOrAssign:   ResultInt = ExpressionAssignInt(Parser, BottomValue, BottomInt | TopInt, FALSE); break;
            case TokenArithmeticExorAssign: ResultInt = ExpressionAssignInt(Parser, BottomValue, BottomInt ^ TopInt, FALSE); break;
            case TokenQuestionMark:         ProgramFail(Parser, "not supported"); break; /* XXX */
            case TokenColon:                ProgramFail(Parser, "not supported"); break; /* XXX */
            case TokenLogicalOr:            ResultInt = BottomInt || TopInt; break;
            case TokenLogicalAnd:           ResultInt = BottomInt && TopInt; break;
            case TokenArithmeticOr:         ResultInt = BottomInt | TopInt; break;
            case TokenArithmeticExor:       ResultInt = BottomInt ^ TopInt; break;
            case TokenAmpersand:            ResultInt = BottomInt & TopInt; break;
            case TokenEqual:                ResultInt = BottomInt == TopInt; break;
            case TokenNotEqual:             ResultInt = BottomInt != TopInt; break;
            case TokenLessThan:             ResultInt = BottomInt < TopInt; break;
            case TokenGreaterThan:          ResultInt = BottomInt > TopInt; break;
            case TokenLessEqual:            ResultInt = BottomInt <= TopInt; break;
            case TokenGreaterEqual:         ResultInt = BottomInt >= TopInt; break;
            case TokenShiftLeft:            ResultInt = BottomInt << TopInt; break;
            case TokenShiftRight:           ResultInt = BottomInt << TopInt; break;
            case TokenPlus:                 ResultInt = BottomInt + TopInt; break;
            case TokenMinus:                ResultInt = BottomInt - TopInt; break;
            case TokenAsterisk:             ResultInt = BottomInt * TopInt; break;
            case TokenSlash:                ResultInt = BottomInt / TopInt; break;
#ifndef NO_MODULUS
            case TokenModulus:              ResultInt = BottomInt % TopInt; break;
#endif
            default:                        ProgramFail(Parser, "invalid operation"); break;
        }
        
        ExpressionPushInt(Parser, StackTop, ResultInt);
    }
    else if (BottomValue->Typ->Base == TypePointer && IS_NUMERIC_COERCIBLE(TopValue))
    {
        /* pointer/integer infix arithmetic */
        int TopInt = ExpressionCoerceInteger(TopValue);

        if (Op == TokenEqual || Op == TokenNotEqual)
        {
            /* comparison to a NULL pointer */
            if (TopInt != 0) 
                ProgramFail(Parser, "invalid operation");
            
            if (Op == TokenEqual)
                ExpressionPushInt(Parser, StackTop, BottomValue->Val->NativePointer == NULL);
            else
                ExpressionPushInt(Parser, StackTop, BottomValue->Val->NativePointer != NULL);
        }
        else if (Op == TokenPlus || Op == TokenMinus)
        {
            /* pointer arithmetic */
            int Size = TypeSize(BottomValue->Typ->FromType, 0, TRUE);
            
            NativePointer = BottomValue->Val->NativePointer;
            if (NativePointer == NULL)
                ProgramFail(Parser, "invalid use of a NULL pointer");
            
            if (Op == TokenPlus)
                NativePointer = (void *)((char *)NativePointer + TopInt * Size);
            else
                NativePointer = (void *)((char *)NativePointer - TopInt * Size);
            
            StackValue = ExpressionStackPushValueByType(Parser, StackTop, BottomValue->Typ);
            StackValue->Val->NativePointer = NativePointer;
        }
        else if (Op == TokenAssign && TopInt == 0)
        {
            /* assign a NULL pointer */
            HeapUnpopStack(sizeof(struct Value));   /* XXX - possible bug if lvalue is a temp value and takes more than sizeof(struct Value) */
            ExpressionAssign(Parser, BottomValue, TopValue, FALSE, NULL, 0, FALSE);
            ExpressionStackPushValueNode(Parser, StackTop, BottomValue);
        }
        else
            ProgramFail(Parser, "invalid operation");
    }
    else if (BottomValue->Typ->Base == TypePointer && TopValue->Typ->Base == TypePointer && Op != TokenAssign)
    {
        /* pointer/pointer operations */
        char *TopLoc = (char *)TopValue->Val->NativePointer;
        char *BottomLoc = (char *)BottomValue->Val->NativePointer;
        
        switch (Op)
        {
            case TokenEqual:                ExpressionPushInt(Parser, StackTop, BottomLoc == TopLoc); break;
            case TokenNotEqual:             ExpressionPushInt(Parser, StackTop, BottomLoc != TopLoc); break;
            case TokenMinus:                ExpressionPushInt(Parser, StackTop, BottomLoc - TopLoc); break;
            default:                        ProgramFail(Parser, "invalid operation"); break;
        }
    }
    else if (Op == TokenAssign)
    {
        /* assign a non-numeric type */
        HeapUnpopStack(sizeof(struct Value));   /* XXX - possible bug if lvalue is a temp value and takes more than sizeof(struct Value) */
        ExpressionAssign(Parser, BottomValue, TopValue, FALSE, NULL, 0, FALSE);
        ExpressionStackPushValueNode(Parser, StackTop, BottomValue);
    }
    else if (Op == TokenCast)
    {
        /* cast a value to a different type */   /* XXX - possible bug if the destination type takes more than sizeof(struct Value) + sizeof(struct ValueType *) */
        struct Value *ValueLoc = ExpressionStackPushValueByType(Parser, StackTop, BottomValue->Val->Typ);
        ExpressionAssign(Parser, ValueLoc, TopValue, TRUE, NULL, 0, TRUE);
    }
    else
        ProgramFail(Parser, "invalid operation");
}

/* take the contents of the expression stack and compute the top until there's nothing greater than the given precedence */
void ExpressionStackCollapse(struct ParseState *Parser, struct ExpressionStack **StackTop, int Precedence)
{
    int FoundPrecedence = Precedence;
    struct Value *TopValue;
    struct Value *BottomValue;
    struct ExpressionStack *TopStackNode = *StackTop;
    struct ExpressionStack *TopOperatorNode;
    
    debugf("ExpressionStackCollapse(%d):\n", Precedence);
#ifdef DEBUG_EXPRESSIONS
    ExpressionStackShow(*StackTop);
#endif
    while (TopStackNode != NULL && TopStackNode->Next != NULL && FoundPrecedence >= Precedence)
    {
        /* find the top operator on the stack */
        if (TopStackNode->Order == OrderNone)
            TopOperatorNode = TopStackNode->Next;
        else
            TopOperatorNode = TopStackNode;
        
        FoundPrecedence = TopOperatorNode->Precedence;
        
        /* does it have a high enough precedence? */
        if (FoundPrecedence >= Precedence && TopOperatorNode != NULL)
        {
            /* execute this operator */
            switch (TopOperatorNode->Order)
            {
                case OrderPrefix:
                    /* prefix evaluation */
                    debugf("prefix evaluation\n");
                    TopValue = TopStackNode->Val;
                    
                    /* pop the value and then the prefix operator - assume they'll still be there until we're done */
                    HeapPopStack(TopOperatorNode, sizeof(struct ExpressionStack)*2 + sizeof(struct Value) + TypeStackSizeValue(TopValue));
                    *StackTop = TopOperatorNode->Next;
                    
                    /* do the prefix operation */
                    ExpressionPrefixOperator(Parser, StackTop, TopOperatorNode->Op, TopValue);
                    break;
                
                case OrderPostfix:
                    /* postfix evaluation */
                    debugf("postfix evaluation\n");
                    TopValue = TopStackNode->Next->Val;
                    
                    /* pop the postfix operator and then the value - assume they'll still be there until we're done */
                    HeapPopStack(TopValue, sizeof(struct ExpressionStack)*2 + sizeof(struct Value) + TypeStackSizeValue(TopValue));
                    *StackTop = TopStackNode->Next->Next;

                    /* do the postfix operation */
                    ExpressionPostfixOperator(Parser, StackTop, TopOperatorNode->Op, TopValue);
                    break;
                
                case OrderInfix:
                    /* infix evaluation */
                    debugf("infix evaluation\n");
                    TopValue = TopStackNode->Val;
                    if (TopValue != NULL)
                    {
                        BottomValue = TopOperatorNode->Next->Val;
                        
                        /* pop a value, the operator and another value - assume they'll still be there until we're done */
                        HeapPopStack(BottomValue, sizeof(struct ExpressionStack)*3 + sizeof(struct Value)*2 + TypeStackSizeValue(TopValue) + TypeStackSizeValue(BottomValue));
                        *StackTop = TopOperatorNode->Next->Next;
                        
                        /* do the infix operation */
                        ExpressionInfixOperator(Parser, StackTop, TopOperatorNode->Op, BottomValue, TopValue);
                    }
                    else
                        FoundPrecedence = -1;
                    break;

                case OrderNone:
                    /* this should never happen */
                    assert(TopOperatorNode->Order != OrderNone);
                    break;
            }
        }
#ifdef DEBUG_EXPRESSIONS
        ExpressionStackShow(*StackTop);
#endif
        TopStackNode = *StackTop;
    }
    debugf("ExpressionStackCollapse() finished\n");
#ifdef DEBUG_EXPRESSIONS
    ExpressionStackShow(*StackTop);
#endif
}

/* push an operator on to the expression stack */
void ExpressionStackPushOperator(struct ParseState *Parser, struct ExpressionStack **StackTop, enum OperatorOrder Order, enum LexToken Token, int Precedence)
{
    struct ExpressionStack *StackNode = VariableAlloc(Parser, sizeof(struct ExpressionStack), FALSE);
    StackNode->Next = *StackTop;
    StackNode->Order = Order;
    StackNode->Op = Token;
    StackNode->Precedence = Precedence;
    *StackTop = StackNode;
    debugf("ExpressionStackPushOperator()\n");
#ifdef FANCY_ERROR_MESSAGES
    StackNode->Line = Parser->Line;
    StackNode->CharacterPos = Parser->CharacterPos;
#endif
#ifdef DEBUG_EXPRESSIONS
    ExpressionStackShow(*StackTop);
#endif
}

/* do the '.' and '->' operators */
void ExpressionGetStructElement(struct ParseState *Parser, struct ExpressionStack **StackTop, enum LexToken Token)
{
    struct Value *Ident;
    
    /* get the identifier following the '.' or '->' */
    if (LexGetToken(Parser, &Ident, TRUE) != TokenIdentifier)
        ProgramFail(Parser, "need an structure or union member after '%s'", (Token == TokenDot) ? "." : "->");

    if (Parser->Mode == RunModeRun)
    { 
        /* look up the struct element */
        struct Value *ParamVal = (*StackTop)->Val;
        struct Value *StructVal = ParamVal;
        struct ValueType *StructType = ParamVal->Typ;
        char *DerefDataLoc = (char *)ParamVal->Val;
        struct Value *MemberValue;
        struct Value *Result;

        /* if we're doing '->' dereference the struct pointer first */
        if (Token == TokenArrow)
            DerefDataLoc = VariableDereferencePointer(Parser, ParamVal, &StructVal, NULL, &StructType, NULL);
        
        if (StructType->Base != TypeStruct && StructType->Base != TypeUnion)
            ProgramFail(Parser, "can't use '%s' on something that's not a struct or union %s : it's a %t", (Token == TokenDot) ? "." : "->", (Token == TokenArrow) ? "pointer" : "", ParamVal->Typ);
            
        if (!TableGet(StructType->Members, Ident->Val->Identifier, &MemberValue))
            ProgramFail(Parser, "doesn't have a member called '%s'", Ident->Val->Identifier);
        
        /* pop the value - assume it'll still be there until we're done */
        HeapPopStack(ParamVal, sizeof(struct ExpressionStack) + sizeof(struct Value) + TypeStackSizeValue(StructVal));
        *StackTop = (*StackTop)->Next;
        
        /* make the result value for this member only */
        Result = VariableAllocValueFromExistingData(Parser, MemberValue->Typ, (void *)(DerefDataLoc + MemberValue->Val->Integer), TRUE, (StructVal != NULL) ? StructVal->LValueFrom : NULL);
        ExpressionStackPushValueNode(Parser, StackTop, Result);
    }
}

/* parse an expression with operator precedence */
int ExpressionParse(struct ParseState *Parser, struct Value **Result)
{
    struct Value *LexValue;
    int PrefixState = TRUE;
    int Done = FALSE;
    int BracketPrecedence = 0;
    int LocalPrecedence;
    int Precedence = 0;
    struct ExpressionStack *StackTop = NULL;
    int TernaryDepth = 0;
    
    debugf("ExpressionParse():\n");
    do
    {
        struct ParseState PreState = *Parser;
        enum LexToken Token = LexGetToken(Parser, &LexValue, TRUE);
        if ( ( ( (int)Token > TokenComma && (int)Token <= (int)TokenOpenBracket) || 
               (Token == TokenCloseBracket && BracketPrecedence != 0)) &&
             (Token != TokenColon || TernaryDepth != 0) )
        { 
            /* it's an operator with precedence */
            if (PrefixState)
            { 
                /* expect a prefix operator */
                if (OperatorPrecedence[(int)Token].PrefixPrecedence == 0)
                    ProgramFail(Parser, "operator not expected here");
                
                LocalPrecedence = OperatorPrecedence[(int)Token].PrefixPrecedence;
                Precedence = BracketPrecedence + LocalPrecedence;

                if (Token == TokenOpenBracket)
                { 
                    /* it's either a new bracket level or a cast */
                    enum LexToken BracketToken = LexGetToken(Parser, &LexValue, FALSE);
                    if (IS_TYPE_TOKEN(BracketToken))
                    {
                        /* it's a cast - get the new type */
                        struct ValueType *CastType;
                        char *CastIdentifier;
                        struct Value *CastTypeValue;
                        
                        TypeParse(Parser, &CastType, &CastIdentifier);
                        if (LexGetToken(Parser, &LexValue, TRUE) != TokenCloseBracket)
                            ProgramFail(Parser, "brackets not closed");
                        
                        /* scan and collapse the stack to the precedence of this infix cast operator, then push */
                        Precedence = BracketPrecedence + OperatorPrecedence[(int)TokenCast].PrefixPrecedence;

                        ExpressionStackCollapse(Parser, &StackTop, Precedence+1);
                        CastTypeValue = VariableAllocValueFromType(Parser, &TypeType, FALSE, NULL, FALSE);
                        CastTypeValue->Val->Typ = CastType;
                        ExpressionStackPushValueNode(Parser, &StackTop, CastTypeValue);
                        ExpressionStackPushOperator(Parser, &StackTop, OrderInfix, TokenCast, Precedence);
                    }
                    else
                    {
                        /* boost the bracket operator precedence */
                        BracketPrecedence += BRACKET_PRECEDENCE;
                    }
                }
                else
                { 
                    /* scan and collapse the stack to the precedence of this operator, then push */
                    ExpressionStackCollapse(Parser, &StackTop, Precedence);
                    ExpressionStackPushOperator(Parser, &StackTop, OrderPrefix, Token, Precedence);
                }
            }
            else
            { 
                /* expect an infix or postfix operator */
                if (OperatorPrecedence[(int)Token].PostfixPrecedence != 0)
                {
                    switch (Token)
                    {
                        case TokenCloseBracket:
                        case TokenRightSquareBracket:
                            if (BracketPrecedence == 0)
                            { 
                                /* assume this bracket is after the end of the expression */
                                *Parser = PreState;
                                Done = TRUE;
                            }
                            else
                                BracketPrecedence -= BRACKET_PRECEDENCE;
                            break;
                    
                        default:
                            /* scan and collapse the stack to the precedence of this operator, then push */
                            Precedence = BracketPrecedence + OperatorPrecedence[(int)Token].PostfixPrecedence;
                            ExpressionStackCollapse(Parser, &StackTop, Precedence);
                            ExpressionStackPushOperator(Parser, &StackTop, OrderPostfix, Token, Precedence);
                            break;
                    }
                }
                else if (OperatorPrecedence[(int)Token].InfixPrecedence != 0)
                { 
                    /* scan and collapse the stack, then push */
                    if (Token == TokenDot || Token == TokenArrow)
                        ExpressionGetStructElement(Parser, &StackTop, Token); /* this operator is followed by a struct element so handle it as a special case */
                    else
                    { 
                        /* a standard infix operator */
                        Precedence = BracketPrecedence + OperatorPrecedence[(int)Token].InfixPrecedence;
                        
                        /* for right to left order, only go down to the next higher precedence so we evaluate it in reverse order */
                        /* for left to right order, collapse down to this precedence so we evaluate it in forward order */
                        if (IS_LEFT_TO_RIGHT(OperatorPrecedence[(int)Token].InfixPrecedence))
                            ExpressionStackCollapse(Parser, &StackTop, Precedence);
                        else
                            ExpressionStackCollapse(Parser, &StackTop, Precedence+1);

                        ExpressionStackPushOperator(Parser, &StackTop, OrderInfix, Token, Precedence);
                        PrefixState = TRUE;
                    }

                    /* treat an open square bracket as an infix array index operator followed by an open bracket */
                    if (Token == TokenLeftSquareBracket)
                    { 
                        /* boost the bracket operator precedence, then push */
                        BracketPrecedence += BRACKET_PRECEDENCE;
                    }
                }
                else
                    ProgramFail(Parser, "operator not expected here");
            }
        }
        else if (Token == TokenIdentifier)
        { 
            /* it's a variable, function or a macro */
            if (!PrefixState)
                ProgramFail(Parser, "identifier not expected here");
                
            if (LexGetToken(Parser, NULL, FALSE) == TokenOpenBracket)
                ExpressionParseFunctionCall(Parser, &StackTop, LexValue->Val->Identifier);
            else
            {
                if (Parser->Mode == RunModeRun)
                {
                    struct Value *VariableValue = NULL;
                    
                    VariableGet(Parser, LexValue->Val->Identifier, &VariableValue);
                    if (VariableValue->Typ->Base == TypeMacro)
                    {
                        /* evaluate a macro as a kind of simple subroutine */
                        struct ParseState MacroParser = VariableValue->Val->Parser;
                        struct Value *MacroResult;
                        
                        if (!ExpressionParse(&MacroParser, &MacroResult) || LexGetToken(&MacroParser, NULL, FALSE) != TokenEndOfFunction)
                            ProgramFail(&MacroParser, "expression expected");
                        
                        ExpressionStackPushValueNode(Parser, &StackTop, MacroResult);
                    }
                    else if (VariableValue->Typ == TypeVoid)
                        ProgramFail(Parser, "a void value isn't much use here");
                    else
                        ExpressionStackPushLValue(Parser, &StackTop, VariableValue, 0); /* it's a value variable */
                }
                else /* push a dummy value */
                    ExpressionPushInt(Parser, &StackTop, 0);
            }

            PrefixState = FALSE;
        }
        else if ((int)Token > TokenCloseBracket && (int)Token <= TokenCharacterConstant)
        { 
            /* it's a value of some sort, push it */
            if (!PrefixState)
                ProgramFail(Parser, "value not expected here");
                
            PrefixState = FALSE;
            ExpressionStackPushValue(Parser, &StackTop, LexValue);
        }
        else if (IS_TYPE_TOKEN(Token))
        {
            /* it's a type. push it on the stack like a value. this is used in sizeof() */
            struct ValueType *Typ;
            char *Identifier;
            struct Value *TypeValue;
            
            if (!PrefixState)
                ProgramFail(Parser, "type not expected here");
                
            PrefixState = FALSE;
            *Parser = PreState;
            TypeParse(Parser, &Typ, &Identifier);
            TypeValue = VariableAllocValueFromType(Parser, &TypeType, FALSE, NULL, FALSE);
            TypeValue->Val->Typ = Typ;
            ExpressionStackPushValueNode(Parser, &StackTop, TypeValue);
        }
        else
        { 
            /* it isn't a token from an expression */
            *Parser = PreState;
            Done = TRUE;
        }
        
    } while (!Done);
    
    /* check that brackets have been closed */
    if (BracketPrecedence > 0)
        ProgramFail(Parser, "brackets not closed");
        
    /* scan and collapse the stack to precedence 0 */
    ExpressionStackCollapse(Parser, &StackTop, 0);
    
    /* fix up the stack and return the result if we're in run mode */
    if (StackTop != NULL)
    {
        /* all that should be left is a single value on the stack */
        if (Parser->Mode == RunModeRun)
        {
            if (StackTop->Order != OrderNone || StackTop->Next != NULL)
                ProgramFail(Parser, "invalid expression");
                
            *Result = StackTop->Val;
            HeapPopStack(StackTop, sizeof(struct ExpressionStack));
        }
        else
            HeapPopStack(StackTop->Val, sizeof(struct ExpressionStack) + sizeof(struct Value) + TypeStackSizeValue(StackTop->Val));
    }
    
    debugf("ExpressionParse() done\n\n");
#ifdef DEBUG_EXPRESSIONS
    ExpressionStackShow(StackTop);
#endif
    return StackTop != NULL;
}


/* do a function call */
void ExpressionParseFunctionCall(struct ParseState *Parser, struct ExpressionStack **StackTop, const char *FuncName)
{
    struct Value *ReturnValue = NULL;
    struct Value *FuncValue;
    struct Value *Param;
    struct Value **ParamArray = NULL;
    int ArgCount;
    enum LexToken Token = LexGetToken(Parser, NULL, TRUE);    /* open bracket */
    
    if (Parser->Mode == RunModeRun) 
    { 
        /* get the function definition */
        VariableGet(Parser, FuncName, &FuncValue);
        if (FuncValue->Typ->Base != TypeFunction)
            ProgramFail(Parser, "%t is not a function - can't call", FuncValue->Typ);
    
        ExpressionStackPushValueByType(Parser, StackTop, FuncValue->Val->FuncDef.ReturnType);
        ReturnValue = (*StackTop)->Val;
        HeapPushStackFrame();
        ParamArray = HeapAllocStack(sizeof(struct Value *) * FuncValue->Val->FuncDef.NumParams);    
        if (ParamArray == NULL)
            ProgramFail(Parser, "out of memory");
    }
    else
        ExpressionPushInt(Parser, StackTop, 0);
        
    /* parse arguments */
    ArgCount = 0;
    do {
        if (Parser->Mode == RunModeRun && ArgCount < FuncValue->Val->FuncDef.NumParams)
            ParamArray[ArgCount] = VariableAllocValueFromType(Parser, FuncValue->Val->FuncDef.ParamType[ArgCount], FALSE, NULL, FALSE);
        
        if (ExpressionParse(Parser, &Param))
        {
            if (Parser->Mode == RunModeRun)
            { 
                if (ArgCount < FuncValue->Val->FuncDef.NumParams)
                {
                    ExpressionAssign(Parser, ParamArray[ArgCount], Param, TRUE, FuncName, ArgCount+1, FALSE);
                    VariableStackPop(Parser, Param);
                }
                else
                {
                    if (!FuncValue->Val->FuncDef.VarArgs)
                        ProgramFail(Parser, "too many arguments to %s()", FuncName);
                }
            }
            
            ArgCount++;
            Token = LexGetToken(Parser, NULL, TRUE);
            if (Token != TokenComma && Token != TokenCloseBracket)
                ProgramFail(Parser, "comma expected");
        }
        else
        { 
            /* end of argument list? */
            Token = LexGetToken(Parser, NULL, TRUE);
            if (!TokenCloseBracket)
                ProgramFail(Parser, "bad argument");
        }
        
    } while (Token != TokenCloseBracket);
    
    if (Parser->Mode == RunModeRun) 
    { 
        /* run the function */
        if (ArgCount < FuncValue->Val->FuncDef.NumParams)
            ProgramFail(Parser, "not enough arguments to '%s'", FuncName);
        
        if (FuncValue->Val->FuncDef.Intrinsic == NULL)
        { 
            /* run a user-defined function */
            struct ParseState FuncParser = FuncValue->Val->FuncDef.Body;
            int Count;
            
            VariableStackFrameAdd(Parser, FuncValue->Val->FuncDef.Intrinsic ? FuncValue->Val->FuncDef.NumParams : 0);
            TopStackFrame->NumParams = ArgCount;
            TopStackFrame->ReturnValue = ReturnValue;
            for (Count = 0; Count < FuncValue->Val->FuncDef.NumParams; Count++)
                VariableDefine(Parser, FuncValue->Val->FuncDef.ParamName[Count], ParamArray[Count], NULL, TRUE);
                
            if (ParseStatement(&FuncParser) != ParseResultOk)
                ProgramFail(&FuncParser, "function body expected");
        
            if (FuncValue->Val->FuncDef.ReturnType != &VoidType && FuncParser.Mode == RunModeRun)
                ProgramFail(&FuncParser, "no value returned from a function returning %t", FuncValue->Val->FuncDef.ReturnType);

            VariableStackFramePop(Parser);
        }
        else
            FuncValue->Val->FuncDef.Intrinsic(Parser, ReturnValue, ParamArray, ArgCount);

        HeapPopStackFrame();
    }
}

/* parse an expression. operator precedence is not supported */
int ExpressionParseInt(struct ParseState *Parser)
{
    struct Value *Val;
    int Result = 0;
    
    if (!ExpressionParse(Parser, &Val))
        ProgramFail(Parser, "expression expected");
    
    if (Parser->Mode == RunModeRun)
    { 
        if (!IS_NUMERIC_COERCIBLE(Val))
            ProgramFail(Parser, "integer value expected instead of %t", Val->Typ);
    
        Result = ExpressionCoerceInteger(Val);
        VariableStackPop(Parser, Val);
    }
    
    return Result;
}

