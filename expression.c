#include "picoc.h"


/* whether evaluation is left to right for a given precedence level */
#define IS_LEFT_TO_RIGHT(p) ((p) != 2 && (p) != 3 && (p) != 14)
#ifndef NO_FP
#define IS_INTEGER_COERCIBLE(v) ((v)->Typ->Base == TypeInt || (v)->Typ->Base == TypeFP || (v)->Typ->Base == TypeChar)
#define COERCE_INTEGER(v) (((v)->Typ->Base == TypeFP) ? (int)(v)->Val->FP : (v)->Val->Integer)
#else
#define IS_INTEGER_COERCIBLE(v) ((v)->Typ->Base == TypeInt || (v)->Typ->Base == TypeChar)
#define COERCE_INTEGER(v) ((v)->Val->Integer)
#endif

/* helper macros for assignment */
#define ASSIGN_INT(d,s) { if (!(d)->IsLValue) ProgramFail(Parser, "can't assign to this"); ResultInt = (s); (d)->Val->Integer = ResultInt; }
#define ASSIGN_INT_AFTER(d,s) { if (!(d)->IsLValue) ProgramFail(Parser, "can't assign to this"); ResultInt = (d)->Val->Integer; (d)->Val->Integer = (s); }
#define ASSIGN_FP(d,s) { if (!(d)->IsLValue) ProgramFail(Parser, "can't assign to this"); ResultFP = (s); (d)->Val->FP = ResultFP; }

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
    unsigned char PrefixPrecedence:4;
    unsigned char PostfixPrecedence:4;
    unsigned char InfixPrecedence:4;
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
    debugf("ExpressionStackPushValueByType()\n");
    struct Value *ValueLoc = VariableAllocValueFromType(Parser, PushType, FALSE, NULL);
    ExpressionStackPushValueNode(Parser, StackTop, ValueLoc);
    
    return ValueLoc;
}

/* push a value on to the expression stack */
void ExpressionStackPushValue(struct ParseState *Parser, struct ExpressionStack **StackTop, struct Value *PushValue)
{
    debugf("ExpressionStackPushValue()\n");
    struct Value *ValueLoc = VariableAllocValueAndCopy(Parser, PushValue, FALSE);
    ExpressionStackPushValueNode(Parser, StackTop, ValueLoc);
}

void ExpressionStackPushLValue(struct ParseState *Parser, struct ExpressionStack **StackTop, struct Value *PushValue)
{
    debugf("ExpressionStackPushLValue()\n");
    struct Value *ValueLoc = VariableAllocValueShared(Parser, PushValue);
    ExpressionStackPushValueNode(Parser, StackTop, ValueLoc);
}

void ExpressionPushInt(struct ParseState *Parser, struct ExpressionStack **StackTop, int IntValue)
{
    debugf("ExpressionPushInt()\n");
    struct Value *ValueLoc = VariableAllocValueFromType(Parser, &IntType, FALSE, NULL);
    ValueLoc->Val->Integer = IntValue;
    ExpressionStackPushValueNode(Parser, StackTop, ValueLoc);
}

#ifndef NO_FP
void ExpressionPushFP(struct ParseState *Parser, struct ExpressionStack **StackTop, double FPValue)
{
    debugf("ExpressionPushFP()\n");
    struct Value *ValueLoc = VariableAllocValueFromType(Parser, &FPType, FALSE, NULL);
    ValueLoc->Val->FP = FPValue;
    ExpressionStackPushValueNode(Parser, StackTop, ValueLoc);
}
#endif

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
            Result = VariableAllocValueFromType(Parser, TypeGetMatching(Parser, TopValue->Typ, TypePointer, 0, StrEmpty), FALSE, NULL);
            Result->Val->Pointer.Segment = TempLValue;
            Result->Val->Pointer.Offset = (void *)Result->Val - (void *)Result->LValueFrom;
            ExpressionStackPushValueNode(Parser, StackTop, Result);
            break;

        case TokenAsterisk:
            if (TopValue->Typ->Base != TypePointer)
                ProgramFail(Parser, "can't dereference this non-pointer");
            
            // XXX - should also do offset + checks
            ExpressionStackPushLValue(Parser, StackTop, TopValue->Val->Pointer.Segment);
            break;
        
        case TokenSizeof:
            // XXX
            break;
        
        case TokenLeftSquareBracket:
            // XXX
            break;
        
        case TokenOpenBracket:
            // XXX - cast
            break;

        default:
            /* an arithmetic operator */
            if (IS_INTEGER_COERCIBLE(TopValue))
            {
                /* integer prefix arithmetic */
                int ResultInt = 0;
                int TopInt = COERCE_INTEGER(TopValue);
                switch (Op)
                {
                    case TokenPlus:         ResultInt = TopInt; break;
                    case TokenMinus:        ResultInt = -TopInt; break;
                    case TokenIncrement:    ASSIGN_INT(TopValue, TopInt+1); break;
                    case TokenDecrement:    ASSIGN_INT(TopValue, TopInt-1); break;
                    case TokenUnaryNot:     ResultInt = !TopInt; break;
                    case TokenUnaryExor:    ResultInt = ~TopInt; break;
                    default:                ProgramFail(Parser, "invalid operation"); break;
                }

                ExpressionPushInt(Parser, StackTop, ResultInt);
            }
#ifndef NO_FP
            else if (TopValue->Typ == &FPType)
            {
                /* floating point prefix arithmetic */
                double ResultFP;
                switch (Op)
                {
                    case TokenPlus:         ResultFP = TopValue->Val->FP; break;
                    case TokenMinus:        ResultFP = -TopValue->Val->FP; break;
                    default:                ProgramFail(Parser, "invalid operation"); break;
                }
            }
#endif
#if 0
XXX - finish this
            else
            {
                /* pointer prefix arithmetic */
                int TopInt = COERCE_INTEGER(TopValue);
            }
#endif
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
    if (IS_INTEGER_COERCIBLE(TopValue))
    {
        int ResultInt = 0;
        int TopInt = COERCE_INTEGER(TopValue);
        switch (Op)
        {
            case TokenIncrement:            ASSIGN_INT_AFTER(TopValue, TopInt+1); break;
            case TokenDecrement:            ASSIGN_INT_AFTER(TopValue, TopInt+1); break;
            case TokenRightSquareBracket:   break;  // XXX
            case TokenCloseBracket:         break;  // XXX
            default:                        ProgramFail(Parser, "invalid operation"); break;
        }
    
        ExpressionPushInt(Parser, StackTop, ResultInt);
    }
}

/* evaluate an infix operator */
void ExpressionInfixOperator(struct ParseState *Parser, struct ExpressionStack **StackTop, enum LexToken Op, struct Value *BottomValue, struct Value *TopValue)
{
    int ResultInt = 0;

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
            ProgramFail(Parser, "not an array");
        
        if (!IS_INTEGER_COERCIBLE(TopValue))
            ProgramFail(Parser, "array index must be an integer");
        
        ArrayIndex = COERCE_INTEGER(TopValue);
        if (ArrayIndex < 0 || ArrayIndex >= BottomValue->Val->Array.Size)
            ProgramFail(Parser, "illegal array index %d [0..%d]", ArrayIndex, BottomValue->Val->Array.Size-1);
        
        /* make the array element result */
        Result = VariableAllocValueFromExistingData(Parser, BottomValue->Typ->FromType, (union AnyValue *)(BottomValue->Val->Array.Data + TypeSize(BottomValue->Typ->FromType, 0) * ArrayIndex), BottomValue->IsLValue, BottomValue->LValueFrom);
        ExpressionStackPushValueNode(Parser, StackTop, Result);
    }
    else if (IS_INTEGER_COERCIBLE(TopValue) && IS_INTEGER_COERCIBLE(BottomValue))
    { 
        /* integer operation */
        int TopInt = COERCE_INTEGER(TopValue);
        int BottomInt = COERCE_INTEGER(BottomValue);
        switch (Op)
        {
            case TokenAssign:               ASSIGN_INT(BottomValue, TopInt); break;
            case TokenAddAssign:            ASSIGN_INT(BottomValue, BottomInt + TopInt); break;
            case TokenSubtractAssign:       ASSIGN_INT(BottomValue, BottomInt - TopInt); break;
            case TokenMultiplyAssign:       ASSIGN_INT(BottomValue, BottomInt * TopInt); break;
            case TokenDivideAssign:         ASSIGN_INT(BottomValue, BottomInt / TopInt); break;
#ifndef NO_MODULUS
            case TokenModulusAssign:        ASSIGN_INT(BottomValue, BottomInt % TopInt); break;
#endif
            case TokenShiftLeftAssign:      ASSIGN_INT(BottomValue, BottomInt << TopInt); break;
            case TokenShiftRightAssign:     ASSIGN_INT(BottomValue, BottomInt >> TopInt); break;
            case TokenArithmeticAndAssign:  ASSIGN_INT(BottomValue, BottomInt & TopInt); break;
            case TokenArithmeticOrAssign:   ASSIGN_INT(BottomValue, BottomInt | TopInt); break;
            case TokenArithmeticExorAssign: ASSIGN_INT(BottomValue, BottomInt ^ TopInt); break;
            case TokenQuestionMark:         break; // XXX
            case TokenColon:                break; // XXX
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
#ifndef NO_FP
    else if ( (TopValue->Typ == &FPType && BottomValue->Typ == &FPType) ||
              (TopValue->Typ == &FPType && IS_INTEGER_COERCIBLE(BottomValue)) ||
              (IS_INTEGER_COERCIBLE(TopValue) && BottomValue->Typ == &FPType) )
    {
        /* floating point infix arithmetic */
        int ResultIsInt = FALSE;
        double ResultFP = 0.0;
        double TopFP = (TopValue->Typ == &FPType) ? TopValue->Val->FP : (double)COERCE_INTEGER(TopValue);
        double BottomFP = (BottomValue->Typ == &FPType) ? BottomValue->Val->FP : (double)COERCE_INTEGER(BottomValue);

        switch (Op)
        {
            case TokenAssign:               ASSIGN_FP(BottomValue, TopFP); break;
            case TokenAddAssign:            ASSIGN_FP(BottomValue, BottomFP + TopFP); break;
            case TokenSubtractAssign:       ASSIGN_FP(BottomValue, BottomFP - TopFP); break;
            case TokenMultiplyAssign:       ASSIGN_FP(BottomValue, BottomFP * TopFP); break;
            case TokenDivideAssign:         ASSIGN_FP(BottomValue, BottomFP / TopFP); break;
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
    else if (BottomValue->Typ->Base == TypePointer && IS_INTEGER_COERCIBLE(TopValue))
    {
        /* pointer/integer infix arithmetic */
        int TopInt = COERCE_INTEGER(TopValue);
        struct PointerValue Pointer;
        struct Value *StackValue;

        if (Op == TokenEqual || Op == TokenNotEqual)
        {
            /* comparison to a NULL pointer */
            if (TopInt != 0) 
                ProgramFail(Parser, "invalid operation");
            
            if (Op == TokenEqual)
                ExpressionPushInt(Parser, StackTop, BottomValue->Val->Pointer.Segment == NULL);
            else
                ExpressionPushInt(Parser, StackTop, BottomValue->Val->Pointer.Segment != NULL);
        }
        else if (Op == TokenPlus || Op == TokenMinus)
        {
            /* pointer arithmetic */
            int Size = TypeSize(BottomValue->Typ->FromType, 0);
            
            Pointer = BottomValue->Val->Pointer;
            if (Pointer.Segment == NULL)
                ProgramFail(Parser, "invalid use of a NULL pointer");
            
            if (Op == TokenPlus)
                Pointer.Offset += TopInt * Size;
            else
                Pointer.Offset -= TopInt * Size;
            
            /* check pointer bounds */
            if (Pointer.Offset < 0 || Pointer.Offset > TypeSizeValue(BottomValue->Val->Pointer.Segment) - Size)
                Pointer.Offset = BottomValue->Val->Pointer.Offset;
            
            StackValue = ExpressionStackPushValueByType(Parser, StackTop, BottomValue->Typ);
            StackValue->Val->Pointer = Pointer;
        }
        else if (Op == TokenAssign && TopInt == 0)
        {
            /* assign a NULL pointer */
            if (!BottomValue->IsLValue) 
                ProgramFail(Parser, "can't assign to this"); 
            
            ExpressionStackPushValueByType(Parser, StackTop, BottomValue->Typ);
        }
        else
            ProgramFail(Parser, "invalid operation");
    }
    else if (Op == TokenAssign)
    {
        /* assign a non-numeric type */
        if (!BottomValue->IsLValue) 
            ProgramFail(Parser, "can't assign to this"); 
        
        if (BottomValue->Typ != TopValue->Typ)
            ProgramFail(Parser, "can't assign to a different type of variable");
            
        memcpy((void *)BottomValue->Val, (void *)TopValue->Val, TypeSizeValue(TopValue));  // XXX - need to handle arrays
        ExpressionStackPushValue(Parser, StackTop, TopValue);
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
        struct Value *MemberValue;
        struct Value *Result;

        if (Token == TokenArrow)
        {
            /* dereference the struct pointer first */
            if (StructVal->Typ->Base != TypePointer)
                ProgramFail(Parser, "can't dereference this non-pointer");
            
            // XXX - should also do offset + checks
            StructVal = ParamVal->Val->Pointer.Segment;
        }
        
        if (StructVal->Typ->Base != TypeStruct && StructVal->Typ->Base != TypeUnion)
            ProgramFail(Parser, "can't use '%s' on something that's not a struct or union %s", (Token == TokenDot) ? "." : "->", (Token == TokenArrow) ? "pointer" : "");
            
        if (!TableGet(StructVal->Typ->Members, Ident->Val->Identifier, &MemberValue))
            ProgramFail(Parser, "doesn't have a member called '%s'", Ident->Val->Identifier);
        
        /* pop the value - assume it'll still be there until we're done */
        HeapPopStack(ParamVal, sizeof(struct ExpressionStack) + sizeof(struct Value) + TypeStackSizeValue(StructVal));
        *StackTop = (*StackTop)->Next;
        
        /* make the result value for this member only */
        Result = VariableAllocValueFromExistingData(Parser, MemberValue->Typ, (void *)StructVal->Val + MemberValue->Val->Integer, TRUE, StructVal->LValueFrom);
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
            if (Token == TokenColon)
                printf("It's a colon\n");
                
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
                    // XXX ExpressionStackPushOperator(Parser, &StackTop, OrderPrefix, Token, Precedence);
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
                        // XXX ExpressionStackPushOperator(Parser, &StackTop, OrderPrefix, Token, Precedence);
                    }
                }
                else
                    ProgramFail(Parser, "operator not expected here");
            }
        }
        else if (Token == TokenIdentifier)
        { 
            /* it's a variable, function or a macro */
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
                        ExpressionStackPushLValue(Parser, &StackTop, VariableValue); /* it's a value variable */
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
            *Result = StackTop->p.Val;
            HeapPopStack(StackTop, sizeof(struct ExpressionStack));
        }
        else
            HeapPopStack(StackTop->p.Val, sizeof(struct ExpressionStack) + sizeof(struct Value) + TypeStackSizeValue(StackTop->p.Val));
    }
    
    debugf("ExpressionParse() done\n");
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
            ProgramFail(Parser, "not a function - can't call");
    
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
        if (ExpressionParse(Parser, &Param))
        {
            if (Parser->Mode == RunModeRun)
            { 
                if (ArgCount >= FuncValue->Val->FuncDef.NumParams)
                {
                    if (!FuncValue->Val->FuncDef.VarArgs)
                        ProgramFail(Parser, "too many arguments to %s()", FuncName);
                }
                else
                {
                    if (FuncValue->Val->FuncDef.ParamType[ArgCount] != Param->Typ)
                        ProgramFail(Parser, "parameter %d to %s() is the wrong type", ArgCount+1, FuncName);
                }
                
                if (ArgCount < FuncValue->Val->FuncDef.NumParams)
                    ParamArray[ArgCount] = Param;
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
                VariableDefine(Parser, FuncValue->Val->FuncDef.ParamName[Count], ParamArray[Count]);
                
            if (!ParseStatement(&FuncParser))
                ProgramFail(&FuncParser, "function body expected");
        
            if (FuncValue->Val->FuncDef.ReturnType != ReturnValue->Typ)
                ProgramFail(&FuncParser, "bad type of return value");

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
        if (Val->Typ->Base != TypeInt)
            ProgramFail(Parser, "integer value expected");
    
        Result = Val->Val->Integer;
        VariableStackPop(Parser, Val);
    }
    
    return Result;
}

