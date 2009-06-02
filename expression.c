#include "picoc.h"


/* whether evaluation is left to right for a given precedence level */
#define IS_LEFT_TO_RIGHT(p) ((p) != 2 && (p) != 3 && (p) != 14)
#define BRACKET_PRECEDENCE 20

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
    union
    {
        struct Value *Val;              /* the value for this stack node */
        enum LexToken Op;               /* the operator */
    } p;
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
    /* TokenIncrement, */ { 14, 15, 0, "++" }, /* TokenDecrement, */ { 14, 15, 0, "--" }, /* TokenUnaryNot, */ { 14, 0, 0, "!" }, /* TokenUnaryExor, */ { 14, 0, 0, "~" }, /* TokenSizeof, */ { 14, 0, 0, "sizeof" },
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
            if (StackTop->p.Val->IsLValue)
                printf("lvalue=");
            else
                printf("value=");
                
            switch (StackTop->p.Val->Typ->Base)
            {
                case TypeVoid:      printf("void"); break;
                case TypeInt: case TypeChar: printf("%d:int", StackTop->p.Val->Val->Integer); break;
                case TypeFP:        printf("%f:fp", StackTop->p.Val->Val->FP); break;
                case TypeFunction:  printf("%s:function", StackTop->p.Val->Val->Identifier); break;
                case TypeMacro:     printf("%s:macro", StackTop->p.Val->Val->Identifier); break;
                case TypePointer:
                    if (StackTop->p.Val->Typ->FromType->Base == TypeChar)
                        printf("\"%s\":string", (char *)StackTop->p.Val->Val->Pointer.Segment->Val->Array.Data);
                    else
                        printf("ptr(0x%lx,%d)", (long)StackTop->p.Val->Val->Pointer.Segment, StackTop->p.Val->Val->Pointer.Offset); 
                    break;
                case TypeArray:     printf("array"); break;
                case TypeStruct:    printf("%s:struct", StackTop->p.Val->Val->Identifier); break;
                case TypeUnion:     printf("%s:union", StackTop->p.Val->Val->Identifier); break;
                case TypeEnum:      printf("%s:enum", StackTop->p.Val->Val->Identifier); break;
                default:            printf("unknown"); break;
            }
            printf("[0x%lx,0x%lx]", (long)StackTop, (long)StackTop->p.Val);
        }
        else
        { /* it's an operator */
            printf("op='%s' %s %d", OperatorPrecedence[(int)StackTop->p.Op].Name, 
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

/* assign an integer value */
int ExpressionAssignInt(struct ParseState *Parser, struct Value *DestValue, int FromInt, int After)
{
    int Result;
    
    if (!DestValue->IsLValue) 
        ProgramFail(Parser, "can't assign to this"); 
    
    if (After)
        Result = DestValue->Val->Integer;
    else
        Result = FromInt;

    DestValue->Val->Integer = FromInt;
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
    StackNode->p.Val = ValueLoc;
    *StackTop = StackNode;
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
    void *DerefDataLoc = VariableDereferencePointer(Parser, DereferenceValue, &DerefVal, &Offset, &DerefType);
    struct Value *ValueLoc = VariableAllocValueFromExistingData(Parser, DerefType, (union AnyValue *)DerefDataLoc, DerefVal->IsLValue, DerefVal);
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

/* assign to a pointer, leaving a value on the expression stack */
void ExpressionAssignToPointer(struct ParseState *Parser, struct Value *ToValue, struct Value *FromValue)
{
    struct ValueType *PointedToType = ToValue->Typ->FromType;
    struct Value *DerefVal = NULL;
    int DerefOffset;
    
    if (FromValue->Typ == ToValue->Typ)
    {
#ifndef NATIVE_POINTERS
        ToValue->Val->Pointer = FromValue->Val->Pointer;      /* plain old pointer assignment */
#else
        ToValue->Val->NativePointer = FromValue->Val->NativePointer;      /* plain old pointer assignment */
#endif
    }
        
    else if (FromValue->Typ->Base == TypeArray && PointedToType == FromValue->Typ->FromType)
    {
        /* the form is: blah *x = array of blah */
#ifndef NATIVE_POINTERS
        ToValue->Val->Pointer.Segment = FromValue;
        ToValue->Val->Pointer.Offset = 0;
        DerefVal = FromValue;
#else
        ToValue->Val->NativePointer = FromValue;
#endif
    }
    else if (FromValue->Typ->Base == TypePointer && FromValue->Typ->FromType->Base == TypeArray && PointedToType == FromValue->Typ->FromType->FromType)
    {
        /* the form is: blah *x = pointer to array of blah */
        struct ValueType *DerefType;
        
        VariableDereferencePointer(Parser, FromValue, &DerefVal, &DerefOffset, &DerefType);
#ifndef NATIVE_POINTERS
        ToValue->Val->Pointer.Segment = DerefVal;
        ToValue->Val->Pointer.Offset = DerefOffset;
#else
        ToValue->Val->NativePointer = DerefVal;
#endif
    }
    else if (IS_NUMERIC_COERCIBLE(FromValue) && COERCE_INTEGER(FromValue) == 0)
    {
        /* null pointer assignment */
#ifndef NATIVE_POINTERS
        ToValue->Val->Pointer.Segment = NULL;
        ToValue->Val->Pointer.Offset = 0;
#else
        ToValue->Val->NativePointer = NULL;
#endif
    }
    else
        ProgramFail(Parser, "can't set a %t from a %t", ToValue->Typ, FromValue->Typ); 
}

/* assign any kind of value */
void ExpressionAssign(struct ParseState *Parser, struct Value *DestValue, struct Value *SourceValue, int Force)
{
    if (!DestValue->IsLValue && !Force) 
        ProgramFail(Parser, "can't set this"); 

    switch (DestValue->Typ->Base)
    {
        case TypeInt:
            if (!IS_NUMERIC_COERCIBLE(SourceValue)) 
                ProgramFail(Parser, "can't set a %t from a %t", DestValue->Typ, SourceValue->Typ); 
            
            DestValue->Val->Integer = COERCE_INTEGER(SourceValue);
            break;

        case TypeChar:
            if (!IS_NUMERIC_COERCIBLE(SourceValue)) 
                ProgramFail(Parser, "can't set a %t from a %t", DestValue->Typ, SourceValue->Typ); 
            
            DestValue->Val->Character = COERCE_INTEGER(SourceValue);
            break;
#ifndef NO_FP
        case TypeFP:
            if (!IS_NUMERIC_COERCIBLE(SourceValue)) 
                ProgramFail(Parser, "can't set a %t from a %t", DestValue->Typ, SourceValue->Typ); 
            
            DestValue->Val->FP = COERCE_FP(SourceValue);
            break;
#endif
        case TypePointer:
            ExpressionAssignToPointer(Parser, DestValue, SourceValue);
            break;
        
        case TypeArray:
            if (DestValue->Typ != SourceValue->Typ)
                ProgramFail(Parser, "can't set a %t from a %t", DestValue->Typ, SourceValue->Typ); 
            
            if (DestValue->Val->Array.Size != SourceValue->Val->Array.Size)
                ProgramFail(Parser, "can't assign from an array of size %d to one of size %d", SourceValue->Val->Array.Size, DestValue->Val->Array.Size);
            
            memcpy((void *)DestValue->Val->Array.Data, (void *)SourceValue->Val->Array.Data, DestValue->Val->Array.Size);
            break;
        
        case TypeStruct:
        case TypeUnion:
            if (DestValue->Typ != SourceValue->Typ)
                ProgramFail(Parser, "can't set a %t from a %t", DestValue->Typ, SourceValue->Typ); 
            
            memcpy((void *)DestValue->Val, (void *)SourceValue->Val, TypeSizeValue(SourceValue));
            break;
        
        default:
            ProgramFail(Parser, "can't set a %t", DestValue->Typ);
            break;
    }
}

/* evaluate a prefix operator */
void ExpressionPrefixOperator(struct ParseState *Parser, struct ExpressionStack **StackTop, enum LexToken Op, struct Value *TopValue)
{
    struct Value *TempLValue;
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

            TempLValue = TopValue->LValueFrom;
            assert(TempLValue != NULL);
            Result = VariableAllocValueFromType(Parser, TypeGetMatching(Parser, TopValue->Typ, TypePointer, 0, StrEmpty), FALSE, NULL, FALSE);
#ifndef NATIVE_POINTERS
            Result->Val->Pointer.Segment = TempLValue;
            if (Result->LValueFrom != NULL)
                Result->Val->Pointer.Offset = (char *)Result->Val - (char *)Result->LValueFrom;
#else
            Result->Val->NativePointer = TempLValue;
#endif                
            ExpressionStackPushValueNode(Parser, StackTop, Result);
            break;

        case TokenAsterisk:
            ExpressionStackPushDereference(Parser, StackTop, TopValue);
            break;
        
        case TokenSizeof:
            /* XXX */
            break;
        
        case TokenLeftSquareBracket:
            /* XXX */
            break;
        
        case TokenOpenBracket:
            /* XXX - cast */
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
                int TopInt = COERCE_INTEGER(TopValue);
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
#ifndef NATIVE_POINTERS
                int OrigOffset = TopValue->Val->Pointer.Offset;

                if (TopValue->Val->Pointer.Segment == NULL)
                    ProgramFail(Parser, "invalid use of a NULL pointer");
                
                if (!TopValue->IsLValue) 
                    ProgramFail(Parser, "can't assign to this"); 

                switch (Op)
                {
                    case TokenIncrement:    TopValue->Val->Pointer.Offset += Size; break;
                    case TokenDecrement:    TopValue->Val->Pointer.Offset -= Size; break;
                    default:                ProgramFail(Parser, "invalid operation"); break;
                }

                /* check pointer bounds */
                if (TopValue->Val->Pointer.Offset < 0 || TopValue->Val->Pointer.Offset > TypeLastAccessibleOffset(TopValue->Val->Pointer.Segment))
                    TopValue->Val->Pointer.Offset = OrigOffset;

                StackValue = ExpressionStackPushValueByType(Parser, StackTop, TopValue->Typ);
                StackValue->Val->Pointer = TopValue->Val->Pointer;
#else
                if (TopValue->Val->NativePointer == NULL)
                    ProgramFail(Parser, "invalid use of a NULL pointer");
                
                if (!TopValue->IsLValue) 
                    ProgramFail(Parser, "can't assign to this"); 
                    
                switch (Op)
                {
                    case TokenIncrement:    TopValue->Val->NativePointer += Size; break;
                    case TokenDecrement:    TopValue->Val->NativePointer -= Size; break;
                    default:                ProgramFail(Parser, "invalid operation"); break;
                }

                StackValue = ExpressionStackPushValueByType(Parser, StackTop, TopValue->Typ);
                StackValue->Val->NativePointer = TopValue->Val->NativePointer;
#endif
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
        int TopInt = COERCE_INTEGER(TopValue);
        switch (Op)
        {
            case TokenIncrement:            ResultInt = ExpressionAssignInt(Parser, TopValue, TopInt+1, TRUE); break;
            case TokenDecrement:            ResultInt = ExpressionAssignInt(Parser, TopValue, TopInt-1, TRUE); break;
            case TokenRightSquareBracket:   break;  /* XXX */
            case TokenCloseBracket:         break;  /* XXX */
            default:                        ProgramFail(Parser, "invalid operation"); break;
        }
    
        ExpressionPushInt(Parser, StackTop, ResultInt);
    }
    else if (TopValue->Typ->Base == TypePointer)
    {
        /* pointer postfix arithmetic */
        int Size = TypeSize(TopValue->Typ->FromType, 0, TRUE);
        struct Value *StackValue;
#ifndef NATIVE_POINTERS
        struct PointerValue OrigPointer = TopValue->Val->Pointer;
        
        if (TopValue->Val->Pointer.Segment == NULL)
            ProgramFail(Parser, "invalid use of a NULL pointer");
            
        if (!TopValue->IsLValue) 
            ProgramFail(Parser, "can't assign to this"); 
        
        switch (Op)
        {
            case TokenIncrement:    TopValue->Val->Pointer.Offset += Size; break;
            case TokenDecrement:    TopValue->Val->Pointer.Offset -= Size; break;
            default:                ProgramFail(Parser, "invalid operation"); break;
        }
        
        /* check pointer bounds */
        if (TopValue->Val->Pointer.Offset < 0)
            TopValue->Val->Pointer.Offset = 0;
        else if (TopValue->Val->Pointer.Offset > TypeLastAccessibleOffset(TopValue->Val->Pointer.Segment))
            TopValue->Val->Pointer.Offset = TypeLastAccessibleOffset(TopValue->Val->Pointer.Segment);

        StackValue = ExpressionStackPushValueByType(Parser, StackTop, TopValue->Typ);
        StackValue->Val->Pointer = OrigPointer;
#else
        void *OrigPointer = TopValue->Val->NativePointer;
        
        if (TopValue->Val->NativePointer == NULL)
            ProgramFail(Parser, "invalid use of a NULL pointer");
            
        if (!TopValue->IsLValue) 
            ProgramFail(Parser, "can't assign to this"); 
        
        switch (Op)
        {
            case TokenIncrement:    TopValue->Val->NativePointer += Size; break;
            case TokenDecrement:    TopValue->Val->NativePointer -= Size; break;
            default:                ProgramFail(Parser, "invalid operation"); break;
        }
        
        StackValue = ExpressionStackPushValueByType(Parser, StackTop, TopValue->Typ);
        StackValue->Val->NativePointer = OrigPointer;
#endif
    }
    else
        ProgramFail(Parser, "invalid operation");
}

/* evaluate an infix operator */
void ExpressionInfixOperator(struct ParseState *Parser, struct ExpressionStack **StackTop, enum LexToken Op, struct Value *BottomValue, struct Value *TopValue)
{
    int ResultInt = 0;
    struct Value *StackValue;
#ifndef NATIVE_POINTERS
    struct PointerValue Pointer;
#else
    void *NativePointer;
#endif

    if (Parser->Mode != RunModeRun)
    {
        /* we're not running it so just return 0 */
        ExpressionPushInt(Parser, StackTop, 0);
        return;
    }
    
    debugf("ExpressionInfixOperator()\n");
    if (Op == TokenLeftSquareBracket)
    { 
        /* array index */
        int ArrayIndex;
        struct Value *Result;
        
        if (BottomValue->Typ->Base != TypeArray)
            ProgramFail(Parser, "this %t is not an array", BottomValue->Typ);
        
        if (!IS_NUMERIC_COERCIBLE(TopValue))
            ProgramFail(Parser, "array index must be an integer");
        
        ArrayIndex = COERCE_INTEGER(TopValue);
        if (ArrayIndex < 0 || ArrayIndex >= BottomValue->Val->Array.Size)
            ProgramFail(Parser, "illegal array index %d [0..%d]", ArrayIndex, BottomValue->Val->Array.Size-1);
        
        /* make the array element result */
        Result = VariableAllocValueFromExistingData(Parser, BottomValue->Typ->FromType, (union AnyValue *)((char *)BottomValue->Val->Array.Data + TypeSize(BottomValue->Typ->FromType, 0, FALSE) * ArrayIndex), BottomValue->IsLValue, BottomValue->LValueFrom);
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
        double TopFP = (TopValue->Typ == &FPType) ? TopValue->Val->FP : (double)COERCE_INTEGER(TopValue);
        double BottomFP = (BottomValue->Typ == &FPType) ? BottomValue->Val->FP : (double)COERCE_INTEGER(BottomValue);

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
        int TopInt = COERCE_INTEGER(TopValue);
        int BottomInt = COERCE_INTEGER(BottomValue);
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
            case TokenQuestionMark:         break; /* XXX */
            case TokenColon:                break; /* XXX */
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
        int TopInt = COERCE_INTEGER(TopValue);

        if (Op == TokenEqual || Op == TokenNotEqual)
        {
            /* comparison to a NULL pointer */
            if (TopInt != 0) 
                ProgramFail(Parser, "invalid operation");
            
#ifndef NATIVE_POINTERS
            if (Op == TokenEqual)
                ExpressionPushInt(Parser, StackTop, BottomValue->Val->Pointer.Segment == NULL);
            else
                ExpressionPushInt(Parser, StackTop, BottomValue->Val->Pointer.Segment != NULL);
#else
            if (Op == TokenEqual)
                ExpressionPushInt(Parser, StackTop, BottomValue->Val->NativePointer == NULL);
            else
                ExpressionPushInt(Parser, StackTop, BottomValue->Val->NativePointer != NULL);
#endif
        }
        else if (Op == TokenPlus || Op == TokenMinus)
        {
            /* pointer arithmetic */
            int Size = TypeSize(BottomValue->Typ->FromType, 0, TRUE);
            
#ifndef NATIVE_POINTERS
            Pointer = BottomValue->Val->Pointer;
            if (Pointer.Segment == NULL)
                ProgramFail(Parser, "invalid use of a NULL pointer");
            
            if (Op == TokenPlus)
                Pointer.Offset += TopInt * Size;
            else
                Pointer.Offset -= TopInt * Size;
            
            /* check pointer bounds */
            if (Pointer.Offset < 0 || Pointer.Offset > TypeLastAccessibleOffset(Pointer.Segment))
                Pointer.Offset = BottomValue->Val->Pointer.Offset;
            
            StackValue = ExpressionStackPushValueByType(Parser, StackTop, BottomValue->Typ);
            StackValue->Val->Pointer = Pointer;
#else
            NativePointer = BottomValue->Val->NativePointer;
            if (NativePointer == NULL)
                ProgramFail(Parser, "invalid use of a NULL pointer");
            
            if (Op == TokenPlus)
                NativePointer += TopInt * Size;
            else
                NativePointer -= TopInt * Size;
            
            StackValue = ExpressionStackPushValueByType(Parser, StackTop, BottomValue->Typ);
            StackValue->Val->NativePointer = NativePointer;
#endif
        }
        else if (Op == TokenAssign && TopInt == 0)
        {
            /* assign a NULL pointer */
            HeapUnpopStack(sizeof(struct Value));   /* XXX - possible bug if lvalue is a temp value and takes more than sizeof(struct Value) */
            ExpressionAssign(Parser, BottomValue, TopValue, FALSE);
            ExpressionStackPushValueNode(Parser, StackTop, BottomValue);
        }
        else
            ProgramFail(Parser, "invalid operation");
    }
    else if (BottomValue->Typ->Base == TypePointer && TopValue->Typ->Base == TypePointer && Op != TokenAssign)
    {
        /* pointer/pointer operations */
#ifndef NATIVE_POINTERS
        char *TopLoc = (char *)TopValue->Val->Pointer.Segment->Val + TopValue->Val->Pointer.Offset;
        char *BottomLoc = (char *)BottomValue->Val->Pointer.Segment->Val + BottomValue->Val->Pointer.Offset;
#else
        char *TopLoc = (char *)TopValue->Val->NativePointer;
        char *BottomLoc = (char *)BottomValue->Val->NativePointer;
#endif
        
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
        ExpressionAssign(Parser, BottomValue, TopValue, FALSE);
        ExpressionStackPushValueNode(Parser, StackTop, BottomValue);
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
    
    debugf("ExpressionStackCollapse():\n");
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
                    TopValue = TopStackNode->p.Val;
                    
                    /* pop the value and then the prefix operator - assume they'll still be there until we're done */
                    HeapPopStack(TopOperatorNode, sizeof(struct ExpressionStack)*2 + sizeof(struct Value) + TypeStackSizeValue(TopValue));
                    *StackTop = TopOperatorNode->Next;
                    
                    /* do the prefix operation */
                    ExpressionPrefixOperator(Parser, StackTop, TopOperatorNode->p.Op, TopValue);
                    break;
                
                case OrderPostfix:
                    /* postfix evaluation */
                    debugf("postfix evaluation\n");
                    TopValue = TopStackNode->Next->p.Val;
                    
                    /* pop the postfix operator and then the value - assume they'll still be there until we're done */
                    HeapPopStack(TopValue, sizeof(struct ExpressionStack)*2 + sizeof(struct Value) + TypeStackSizeValue(TopValue));
                    *StackTop = TopStackNode->Next->Next;

                    /* do the postfix operation */
                    ExpressionPostfixOperator(Parser, StackTop, TopOperatorNode->p.Op, TopValue);
                    break;
                
                case OrderInfix:
                    /* infix evaluation */
                    debugf("infix evaluation\n");
                    TopValue = TopStackNode->p.Val;
                    BottomValue = TopOperatorNode->Next->p.Val;
                    
                    /* pop a value, the operator and another value - assume they'll still be there until we're done */
                    HeapPopStack(BottomValue, sizeof(struct ExpressionStack)*3 + sizeof(struct Value)*2 + TypeStackSizeValue(TopValue) + TypeStackSizeValue(BottomValue));
                    *StackTop = TopOperatorNode->Next->Next;
                    
                    /* do the infix operation */
                    ExpressionInfixOperator(Parser, StackTop, TopOperatorNode->p.Op, BottomValue, TopValue);
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
    StackNode->p.Op = Token;
    StackNode->Precedence = Precedence;
    *StackTop = StackNode;
    debugf("ExpressionStackPushOperator()\n");
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
        struct Value *ParamVal = (*StackTop)->p.Val;
        struct Value *StructVal = ParamVal;
        int StructOffset = 0;
        struct ValueType *StructType = ParamVal->Typ;
        char *DerefDataLoc = (char *)ParamVal->Val;
        struct Value *MemberValue;
        struct Value *Result;

        /* if we're doing '->' dereference the struct pointer first */
        if (Token == TokenArrow)
            DerefDataLoc = VariableDereferencePointer(Parser, ParamVal, &StructVal, &StructOffset, &StructType);
        
        if (StructType->Base != TypeStruct && StructType->Base != TypeUnion)
            ProgramFail(Parser, "can't use '%s' on something that's not a struct or union %s : it's a %t", (Token == TokenDot) ? "." : "->", (Token == TokenArrow) ? "pointer" : "", ParamVal->Typ);
            
        if (!TableGet(StructType->Members, Ident->Val->Identifier, &MemberValue))
            ProgramFail(Parser, "doesn't have a member called '%s'", Ident->Val->Identifier);
        
        /* pop the value - assume it'll still be there until we're done */
        HeapPopStack(ParamVal, sizeof(struct ExpressionStack) + sizeof(struct Value) + TypeStackSizeValue(StructVal));
        *StackTop = (*StackTop)->Next;
        
        /* make the result value for this member only */
        Result = VariableAllocValueFromExistingData(Parser, MemberValue->Typ, (void *)(DerefDataLoc + MemberValue->Val->Integer), TRUE, StructVal->LValueFrom);
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
                    /* boost the bracket operator precedence, then push */
                    BracketPrecedence += BRACKET_PRECEDENCE;
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
                
            *Result = StackTop->p.Val;
            HeapPopStack(StackTop, sizeof(struct ExpressionStack));
        }
        else
            HeapPopStack(StackTop->p.Val, sizeof(struct ExpressionStack) + sizeof(struct Value) + TypeStackSizeValue(StackTop->p.Val));
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
        ReturnValue = (*StackTop)->p.Val;
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
                    ExpressionAssign(Parser, ParamArray[ArgCount], Param, TRUE);
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
                
            if (!ParseStatement(&FuncParser))
                ProgramFail(&FuncParser, "function body expected");
        
            if (FuncValue->Val->FuncDef.ReturnType != ReturnValue->Typ)
                ProgramFail(&FuncParser, "return value is %t instead of %t", ReturnValue->Typ, FuncValue->Val->FuncDef.ReturnType);

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
    
        Result = COERCE_INTEGER(Val);
        VariableStackPop(Parser, Val);
    }
    
    return Result;
}

