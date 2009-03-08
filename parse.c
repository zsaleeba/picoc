#include "picoc.h"

/* local prototypes */
int ParseArguments(struct ParseState *Parser, int RunIt);
int ParseStatementMaybeRun(struct ParseState *Parser, int Condition);
void ParseFunctionCall(struct ParseState *Parser, struct Value **Result, const char *FuncName);

#if 1
/* parse a single value */
int ParseValue(struct ParseState *Parser, struct Value **Result)
{
    struct ParseState PreState = *Parser;
    struct Value *LexValue;
    int IntValue;
    enum LexToken Token = LexGetToken(Parser, &LexValue, TRUE);
    struct Value *LocalLValue = NULL;
    struct ValueType *VType;
    int Success = TRUE;
    
    switch (Token)
    {
        case TokenIntegerConstant: case TokenCharacterConstant: case TokenFPConstant: case TokenStringConstant:
            *Result = VariableAllocValueAndCopy(Parser, LexValue, FALSE);
            break;
        
        case TokenMinus:  case TokenUnaryExor: case TokenUnaryNot:
            IntValue = ParseIntExpression(Parser);
            if (Parser->Mode == RunModeRun)
            {
                *Result = VariableAllocValueFromType(Parser, &IntType, FALSE, NULL);
                switch(Token)
                {
                    case TokenMinus: (*Result)->Val->Integer = -IntValue; break;
                    case TokenUnaryExor: (*Result)->Val->Integer = ~IntValue; break;
                    case TokenUnaryNot: (*Result)->Val->Integer = !IntValue; break;
                    default: break;
                }
            }
            break;

        case TokenOpenBracket:
            if (!ParseExpression(Parser, Result))
                ProgramFail(Parser, "invalid expression");
            
            if (LexGetToken(Parser, NULL, TRUE) != TokenCloseBracket)
                ProgramFail(Parser, "')' expected");
            break;
                
        case TokenAsterisk:
            if (!ParseExpression(Parser, Result))
                ProgramFail(Parser, "invalid expression");
            
            if ((*Result)->Typ->Base != TypePointer)
                ProgramFail(Parser, "can't dereference this non-pointer");
            
            LocalLValue = (*Result)->Val->Pointer.Segment;
            VariableStackPop(Parser, *Result);
#if 0
            *Result = VariableAllocValueAndCopy(struct ParseState *Parser, struct Value *FromValue, int OnHeap)
            *Result = VariableAllocValueFromExistingData(Parser, (*Result)->Typ->FromType, (void *)LocalLValue->Val + LocalLValue->Val->Pointer.Segment, 
                            LocalLValue->IsLValue, FromValue->IsLValue ? FromValue : NULL);
#endif
            *Result = VariableAllocValueShared(Parser, LocalLValue);
            break;

        case TokenAmpersand:
            if (!ParseValue(Parser, Result) || !(*Result)->IsLValue)
                ProgramFail(Parser, "can't get the address of this");
            
            VType = (*Result)->Typ;
            LocalLValue = (*Result)->LValueFrom;
            VariableStackPop(Parser, *Result);
            *Result = VariableAllocValueFromType(Parser, TypeGetMatching(Parser, VType, TypePointer, 0, StrEmpty), FALSE, NULL);
            (*Result)->Val->Pointer.Segment = LocalLValue;
            (*Result)->Val->Pointer.Data.Offset = (void *)(*Result)->Val - (void *)(*Result)->LValueFrom;
            break;
            
        case TokenIdentifier:
            if (LexGetToken(Parser, NULL, FALSE) == TokenOpenBracket)
                ParseFunctionCall(Parser, Result, LexValue->Val->Identifier);
            else
            {
                if (Parser->Mode == RunModeRun)
                {
                    VariableGet(Parser, LexValue->Val->Identifier, &LocalLValue);
                    if (LocalLValue->Typ->Base == TypeMacro)
                    {
                        struct ParseState MacroParser = LocalLValue->Val->Parser;
                        
                        if (!ParseExpression(&MacroParser, Result) || LexGetToken(&MacroParser, NULL, FALSE) != TokenEndOfFunction)
                            ProgramFail(&MacroParser, "expression expected");
                    }
                    else if (LocalLValue->Typ == TypeVoid)
                        ProgramFail(Parser, "a void value isn't much use here");
                    else
                    { /* it's a value variable */
                        *Result = VariableAllocValueShared(Parser, LocalLValue);
                    }
                }
                
                /* see if there's a postfix operator */
                Token = LexGetToken(Parser, &LexValue, FALSE);
                if (Token == TokenIncrement || Token == TokenDecrement)
                { /* it's a postincrement or postdecrement */
                    LexGetToken(Parser, &LexValue, TRUE);
                    if (Parser->Mode == RunModeRun)
                    {
                        if (!(*Result)->IsLValue || (*Result)->Typ->Base != TypeInt) 
                            ProgramFail(Parser, "can't %s this", (Token == TokenIncrement) ? "increment" : "decrement");
                            
                        if (Token == TokenIncrement)
                            (*Result)->Val->Integer++;
                        else
                            (*Result)->Val->Integer--;
                    }
                }
                else if (Token == TokenLeftSquareBracket)
                { /* array access */
                    LexGetToken(Parser, &LexValue, TRUE);
                    IntValue = ParseIntExpression(Parser);
                    if (LexGetToken(Parser, &LexValue, TRUE) != TokenRightSquareBracket)
                        ProgramFail(Parser, "expected ']'");
                    
                    if (Parser->Mode == RunModeRun)
                    { /* look up the array element */
                        if ((*Result)->Typ->Base != TypeArray)
                            ProgramFail(Parser, "not an array");
                        
                        if (IntValue < 0 || IntValue >= (*Result)->Val->Array.Size)
                            ProgramFail(Parser, "illegal array index");
                        
                        VariableStackPop(Parser, *Result);
                        *Result = VariableAllocValueFromExistingData(Parser, (*Result)->Typ->FromType, (union AnyValue *)((*Result)->Val->Array.Data + TypeSize((*Result)->Typ->FromType, 0) * IntValue), (*Result)->IsLValue, (*Result)->LValueFrom);
                    }
                }
            }
            break;
            
        default:
            *Parser = PreState;
            Success = FALSE;
            break;
    }
    
    return Success;
}

#ifndef NO_FP
struct Value *ParsePushFP(struct ParseState *Parser, double NewFP)
{
    struct Value *Val = VariableAllocValueFromType(Parser, &FPType, FALSE, NULL);
    Val->Val->FP = NewFP;
    return Val;
}
#endif

struct Value *ParsePushInt(struct ParseState *Parser, int NewInt)
{
    struct Value *Val = VariableAllocValueFromType(Parser, &IntType, FALSE, NULL);
    Val->Val->Integer = NewInt;
    return Val;
}

/* parse an expression. operator precedence is not supported */
int ParseExpression(struct ParseState *Parser, struct Value **Result)
{
    struct Value *CurrentValue;
    struct Value *TotalValue;
    
    if (!ParseValue(Parser, &TotalValue))
        return FALSE;
    
    while (TRUE)
    {
        enum LexToken Token = LexGetToken(Parser, NULL, FALSE);
        switch (Token)
        {
            case TokenPlus: case TokenMinus: case TokenAsterisk: case TokenSlash:
            case TokenEqual: case TokenLessThan: case TokenGreaterThan:
            case TokenLessEqual: case TokenGreaterEqual: case TokenLogicalAnd:
            case TokenLogicalOr: case TokenAmpersand: case TokenArithmeticOr: 
            case TokenArithmeticExor: 
                LexGetToken(Parser, NULL, TRUE);
                break;
            
            case TokenDot:
            {
                struct Value *Ident;
                
                LexGetToken(Parser, NULL, TRUE);
                if (LexGetToken(Parser, &Ident, TRUE) != TokenIdentifier)
                    ProgramFail(Parser, "need an structure or union member after '.'");

                if (Parser->Mode == RunModeRun)
                {                
                    void *TotalValueData = (void *)TotalValue->Val;

                    if (TotalValue->Typ->Base != TypeStruct && TotalValue->Typ->Base != TypeUnion)
                        ProgramFail(Parser, "can't use '.' on something that's not a struct or union");
                        
                    if (!TableGet(TotalValue->Typ->Members, Ident->Val->Identifier, &CurrentValue))
                        ProgramFail(Parser, "structure doesn't have a member called '%s'", Ident->Val->Identifier);
                    
                    VariableStackPop(Parser, TotalValue);
                    TotalValue = VariableAllocValueFromExistingData(Parser, CurrentValue->Typ, TotalValueData + CurrentValue->Val->Integer, TRUE, TotalValue->LValueFrom);
                }
                continue;
            }
            case TokenAssign: 
                LexGetToken(Parser, NULL, TRUE);
            
                if (!ParseExpression(Parser, &CurrentValue))
                    ProgramFail(Parser, "expression expected");
                    
                if (Parser->Mode == RunModeRun)
                { /* do the assignment */
                    if (!TotalValue->IsLValue)
                        ProgramFail(Parser, "can't assign to this");

                    if (CurrentValue->Typ != TotalValue->Typ)
                        ProgramFail(Parser, "can't assign incompatible types");

                    if (TotalValue->Typ->Base != TypeArray)
                        memcpy(TotalValue->Val, CurrentValue->Val, TotalValue->Typ->Sizeof);
                    else
                    { /* array assignment */
                        if (TotalValue->Val->Array.Size != CurrentValue->Val->Array.Size)
                            ProgramFail(Parser, "incompatible array sizes in assignment");
                        
                        //memcpy(TotalValue->Val->Array.Data, CurrentValue->Val->Array.Data, CurrentValue->Typ->Sizeof * CurrentValue->Val->Array.Size);
                    }
                    VariableStackPop(Parser, CurrentValue);
                    *Result = TotalValue;
                }
                return TRUE;
                
            case TokenAddAssign: case TokenSubtractAssign:
                LexGetToken(Parser, NULL, TRUE);
            
                if (!ParseExpression(Parser, &CurrentValue))
                    ProgramFail(Parser, "expression expected");
                
                if (Parser->Mode == RunModeRun)
                { /* do the assignment */
                    if (!TotalValue->IsLValue)
                        ProgramFail(Parser, "can't assign");

                    if (CurrentValue->Typ->Base == TypeInt && TotalValue->Typ->Base == TypeInt)
                    {
                        switch (Token)
                        {
                            case TokenAddAssign: TotalValue->Val->Integer += CurrentValue->Val->Integer; break;
                            case TokenSubtractAssign: TotalValue->Val->Integer -= CurrentValue->Val->Integer; break;
                            default: break;
                        }
                        VariableStackPop(Parser, CurrentValue);
                    }
#ifndef NO_FP
                    else if (CurrentValue->Typ->Base == TypeFP && TotalValue->Typ->Base == TypeFP)
                    {
                        switch (Token)
                        {
                            case TokenAddAssign: TotalValue->Val->FP += CurrentValue->Val->FP; break;
                            case TokenSubtractAssign: TotalValue->Val->FP -= CurrentValue->Val->FP; break;
                            default: break;
                        }
                        VariableStackPop(Parser, CurrentValue);
                    }
#endif
                    else
                        ProgramFail(Parser, "can't operate and assign these types");
                }
                // fallthrough
            
            default:
                if (Parser->Mode == RunModeRun)
                    *Result = TotalValue;
                return TRUE;
        }
        
        if (!ParseValue(Parser, &CurrentValue))
            return FALSE;

        if (Parser->Mode == RunModeRun)
        {
#ifndef NO_FP
            if (CurrentValue->Typ->Base == TypeFP || TotalValue->Typ->Base == TypeFP)
            { /* floating point expression */
                double FPTotal, FPCurrent, FPResult;

                if (CurrentValue->Typ->Base != TypeFP || TotalValue->Typ->Base != TypeFP)
                { /* convert both to floating point */
                    if (CurrentValue->Typ->Base == TypeInt)
                        FPCurrent = (double)CurrentValue->Val->Integer;
                    else if (CurrentValue->Typ->Base == TypeFP)
                        FPCurrent = CurrentValue->Val->FP;
                    else
                        ProgramFail(Parser, "bad type for operator");
                        
                    if (TotalValue->Typ->Base == TypeInt)
                        FPTotal = (double)TotalValue->Val->Integer;
                    else if (TotalValue->Typ->Base == TypeFP)
                        FPTotal = TotalValue->Val->FP;
                    else
                        ProgramFail(Parser, "bad type for operator");
                }

                VariableStackPop(Parser, CurrentValue);
                VariableStackPop(Parser, TotalValue);
                
                switch (Token)
                {
                    case TokenPlus:         FPResult = FPTotal + FPCurrent; break;
                    case TokenMinus:        FPResult = FPTotal - FPCurrent; break;
                    case TokenAsterisk:     FPResult = FPTotal * FPCurrent; break;
                    case TokenSlash:        FPResult = FPTotal / FPCurrent; break;
                    case TokenEqual:        FPResult = FPTotal == FPCurrent; break;
                    case TokenLessThan:     FPResult = FPTotal < FPCurrent; break;
                    case TokenGreaterThan:  FPResult = FPTotal > FPCurrent; break;
                    case TokenLessEqual:    FPResult = FPTotal <= FPCurrent; break;
                    case TokenGreaterEqual: FPResult = FPTotal >= FPCurrent; break;
                    case TokenLogicalAnd: case TokenLogicalOr: case TokenAmpersand: case TokenArithmeticOr: case TokenArithmeticExor: ProgramFail(Parser, "bad type for operator"); break;
                    default: break;
                }
                TotalValue = ParsePushFP(Parser, FPResult);
            }
            else
#endif
            { /* integer expression */
                int IntX, IntY, IntResult;
                
                if (CurrentValue->Typ->Base != TypeInt || TotalValue->Typ->Base != TypeInt)
                    ProgramFail(Parser, "bad operand types");
            
                IntX = TotalValue->Val->Integer;
                IntY = CurrentValue->Val->Integer;
                VariableStackPop(Parser, CurrentValue);
                VariableStackPop(Parser, TotalValue);
                
                /* integer arithmetic */
                switch (Token)
                {
                    case TokenPlus:             IntResult = IntX + IntY; break;
                    case TokenMinus:            IntResult = IntX - IntY; break;
                    case TokenAsterisk:         IntResult = IntX * IntY; break;
                    case TokenSlash:            IntResult = IntX / IntY; break;
                    case TokenEqual:            IntResult = IntX == IntY; break;
                    case TokenLessThan:         IntResult = IntX < IntY; break;
                    case TokenGreaterThan:      IntResult = IntX > IntY; break;
                    case TokenLessEqual:        IntResult = IntX <= IntY; break;
                    case TokenGreaterEqual:     IntResult = IntX >= IntY; break;
                    case TokenLogicalAnd:       IntResult = IntX && IntY; break;
                    case TokenLogicalOr:        IntResult = IntX || IntY; break;
                    case TokenAmpersand:        IntResult = IntX & IntY; break;
                    case TokenArithmeticOr:     IntResult = IntX | IntY; break;
                    case TokenArithmeticExor:   IntResult = IntX ^ IntY; break;
                    default: break;
                }
                TotalValue = ParsePushInt(Parser, IntResult);
            }
            
            *Result = TotalValue;
        }
    }
    
    return TRUE;
}
#else

/* operator precedence definitions */
struct OpPrecedence
{
    unsigned char PrefixPrecedence:4;
    unsigned char PostfixPrecedence:4;
    unsigned char InfixPrecedence:4;
};

static struct OpPrecedence OperatorPrecedence[] =
{
    /* TokenComma, */ { 0, 0, 1 },
    /* TokenAssign, */ { 0, 0, 2 }, /* TokenAddAssign, */ { 0, 0, 2 }, /* TokenSubtractAssign, */ { 0, 0, 2 }, 
    /* TokenMultiplyAssign, */ { 0, 0, 2 }, /* TokenDivideAssign, */ { 0, 0, 2 }, /* TokenModulusAssign, */ { 0, 0, 2 },
    /* TokenShiftLeftAssign, */ { 0, 0, 2 }, /* TokenShiftRightAssign, */ { 0, 0, 2 }, /* TokenArithmeticAndAssign, */ { 0, 0, 2 }, 
    /* TokenArithmeticOrAssign, */ { 0, 0, 2 }, /* TokenArithmeticExorAssign, */ { 0, 0, 2 },
    /* TokenQuestionMark, */ { 0, 0, 3 }, /* TokenColon, */ { 0, 0, 3 },
    /* TokenLogicalOr, */ { 0, 0, 4 },
    /* TokenLogicalAnd, */ { 0, 0, 5 },
    /* TokenArithmeticOr, */ { 0, 0, 6 },
    /* TokenTilde, */ { 0, 0, 7 },
    /* TokenAmpersand, */ { 14, 0, 8 },
    /* TokenEqual, TokenNotEqual, */ { 0, 0, 9 },
    /* TokenLessThan, */ { 0, 0, 10 }, /* TokenGreaterThan, */ { 0, 0, 10 }, /* TokenLessEqual, */ { 0, 0, 10 }, /* TokenGreaterEqual, */ { 0, 0, 10 },
    /* TokenShiftLeft, */ { 0, 0, 11 }, /* TokenShiftRight, */ { 0, 0, 11 },
    /* TokenPlus, */ { 14, 0, 12 }, /* TokenMinus, */ { 14, 0, 12 },
    /* TokenAsterisk, */ { 14, 0, 13 }, /* TokenSlash, */ { 0, 0, 13 }, /* TokenModulus, */ { 0, 0, 13 },
    /* TokenIncrement, */ { 14, 15, 0 }, /* TokenDecrement, */ { 14, 15, 0 }, /* TokenUnaryNot, */ { 14, 0, 0 }, /* TokenUnaryExor, */ { 14, 0, 0 }, /* TokenSizeof, */ { 14, 0, 0 },
    /* TokenLeftSquareBracket, */ { 15, 0, 0 }, /* TokenRightSquareBracket, */ { 0, 15, 0 }, /* TokenDot, */ { 0, 0, 15 }, /* TokenArrow, */ { 0, 0, 15 },
    /* TokenOpenBracket, */ { 15, 0, 0 }, /* TokenCloseBracket, */ { 0, 15, 0 }
};

/* parse an expression with operator precedence */
int ParseExpression(struct ParseState *Parser, struct Value **Result)
{
    struct Value *LexValue;
    bool PrefixState = false;
    bool Done = false;
    int BracketPrecedence = 0;
    int Precedence = 0;
    
    do
    {
        enum LexToken Token = LexGetToken(Parser, &LexValue, TRUE);
        if ((int)Token <= (int)TokenCloseBracket)
        { /* it's an operator with precedence */
            if (PrefixState)
            { /* expect a prefix operator */
                if (OperatorPrecedence[(int)Token].PrefixPrecedence == 0)
                    ProgramFail(Parser, "operator not expected here");
                
                if (Parser->Mode == RunModeRun)
                {   
                    if (Token == TokenOpenBracket || Token == TokenLeftSquareBracket)
                    {
                        /* boost the bracket operator precedence */
                        BracketPrecedence += BRACKET_PREDECENCE;
                        /* push the operator */
                    }
                    else
                    {
                        /* scan and collapse the stack to the precedence of this operator */
                        /* push the operator */
                    }
                }
            }
            else
            { /* expect an infix or postfix operator */
                if (OperatorPrecedence[(int)Token].PostfixPrecedence != 0)
                {
                    switch (Token)
                    {
                        case TokenCloseBracket:
                            if (BracketPrecedence == 0)
                            { /* assume this bracket is after the end of the expression */
                                /* scan and collapse the stack to precedence 0 */
                                Done = true;
                            }
                            else
                                BracketPrecedence -= BRACKET_PRECEDENCE;
                            break;
                    
                        case TokenRightSquareBracket:
                            if (BracketPrecedence == 0)
                                ProgramFail(Parser, "no matching open square bracket");

                            /* scan and collapse the stack to bracket precedence */
                            BracketPrecedence -= BRACKET_PRECEDENCE;
                            
                            /* apply the array index operator */
                            break;

                        default:
                            /* scan and collapse the stack to the precedence of this operator */
                            /* push the operator */
                            break;
                    }
                }
                else if (OperatorPrecedence[(int)Token].InfixPrecedence != 0)
                {
                    /* scan and collapse the stack to the precedence of this operator */
                    /* push the operator */
                    PrefixState = true;
                }
                else
                    ProgramFail(Parser, "operator not expected here");
            }
        }
        else if ((int)Token <= (int)TokenCharacterConstant)
        { /* it's a value of some sort */
            if (!PrefixState)
                ProgramFail(Parser, "value not expected here");
                
            PrefixState = false;
            if (Parser->Mode == RunModeRun)
            {
                /* push the value */
            }
        }
        else
        { /* it isn't a token from an expression */
            /* scan and collapse the stack to precedence 0 */
            Done = true;
        }
        
    } while (!Done);
}
#endif

/* parse an expression. operator precedence is not supported */
int ParseIntExpression(struct ParseState *Parser)
{
    struct Value *Val;
    int Result = 0;
    
    if (!ParseExpression(Parser, &Val))
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

/* do a function call */
void ParseFunctionCall(struct ParseState *Parser, struct Value **Result, const char *FuncName)
{
    struct Value *FuncValue;
    struct Value *Param;
    struct Value **ParamArray;
    int ArgCount;
    enum LexToken Token = LexGetToken(Parser, NULL, TRUE);    /* open bracket */
    
    if (Parser->Mode == RunModeRun) 
    { /* get the function definition */
        VariableGet(Parser, FuncName, &FuncValue);
        if (FuncValue->Typ->Base != TypeFunction)
            ProgramFail(Parser, "not a function - can't call");
    
        *Result = VariableAllocValueFromType(Parser, FuncValue->Val->FuncDef.ReturnType, FALSE, NULL);
        HeapPushStackFrame();
        ParamArray = HeapAllocStack(sizeof(struct Value *) * FuncValue->Val->FuncDef.NumParams);
        if (ParamArray == NULL)
            ProgramFail(Parser, "out of memory");
    }
        
    /* parse arguments */
    ArgCount = 0;
    do {
        if (ParseExpression(Parser, &Param))
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
        { /* end of argument list? */
            Token = LexGetToken(Parser, NULL, TRUE);
            if (!TokenCloseBracket)
                ProgramFail(Parser, "bad argument");
        }
    } while (Token != TokenCloseBracket);
    
    if (Parser->Mode == RunModeRun) 
    { /* run the function */
        if (ArgCount < FuncValue->Val->FuncDef.NumParams)
            ProgramFail(Parser, "not enough arguments to '%s'", FuncName);
        
        if (FuncValue->Val->FuncDef.Intrinsic == NULL)
        { /* run a user-defined function */
            struct ParseState FuncParser = FuncValue->Val->FuncDef.Body;
            int Count;
            
            VariableStackFrameAdd(Parser, FuncValue->Val->FuncDef.Intrinsic ? FuncValue->Val->FuncDef.NumParams : 0);
            TopStackFrame->NumParams = ArgCount;
            TopStackFrame->ReturnValue = *Result;
            for (Count = 0; Count < FuncValue->Val->FuncDef.NumParams; Count++)
                VariableDefine(Parser, FuncValue->Val->FuncDef.ParamName[Count], ParamArray[Count]);
                
            if (!ParseStatement(&FuncParser))
                ProgramFail(&FuncParser, "function body expected");
        
            if (FuncValue->Val->FuncDef.ReturnType != (*Result)->Typ)
                ProgramFail(&FuncParser, "bad type of return value");

            VariableStackFramePop(Parser);
        }
        else
            FuncValue->Val->FuncDef.Intrinsic(Parser, *Result, ParamArray, ArgCount);

        HeapPopStackFrame();
    }
}

/* parse a function definition and store it for later */
struct Value *ParseFunctionDefinition(struct ParseState *Parser, struct ValueType *ReturnType, char *Identifier, int IsPrototype)
{
    struct ValueType *ParamType;
    char *ParamIdentifier;
    enum LexToken Token;
    struct Value *FuncValue;
    struct ParseState ParamParser;
    struct ParseState FuncBody;
    int ParamCount = 0;

    LexGetToken(Parser, NULL, TRUE);  /* open bracket */
    ParamParser = *Parser;
    Token = LexGetToken(Parser, NULL, TRUE);
    if (Token != TokenCloseBracket && Token != TokenEOF)
    { /* count the number of parameters */
        ParamCount++;
        while ((Token = LexGetToken(Parser, NULL, TRUE)) != TokenCloseBracket && Token != TokenEOF)
        { 
            if (Token == TokenComma)
                ParamCount++;
        } 
    }
    if (ParamCount > PARAMETER_MAX)
        ProgramFail(Parser, "too many parameters");
    
    FuncValue = VariableAllocValueAndData(Parser, sizeof(struct FuncDef) + sizeof(struct ValueType *) * ParamCount + sizeof(const char *) * ParamCount, FALSE, NULL, TRUE);
    FuncValue->Typ = &FunctionType;
    FuncValue->Val->FuncDef.ReturnType = ReturnType;
    FuncValue->Val->FuncDef.NumParams = ParamCount;
    FuncValue->Val->FuncDef.VarArgs = FALSE;
    FuncValue->Val->FuncDef.ParamType = (void *)FuncValue->Val + sizeof(struct FuncDef);
    FuncValue->Val->FuncDef.ParamName = (void *)FuncValue->Val->FuncDef.ParamType + sizeof(struct ValueType *) * ParamCount;
   
    for (ParamCount = 0; ParamCount < FuncValue->Val->FuncDef.NumParams; ParamCount++)
    { /* harvest the parameters into the function definition */
        if (ParamCount == FuncValue->Val->FuncDef.NumParams-1 && LexGetToken(&ParamParser, NULL, FALSE) == TokenEllipsis)
        { /* ellipsis at end */
            FuncValue->Val->FuncDef.NumParams--;
            FuncValue->Val->FuncDef.VarArgs = TRUE;
            break;
        }
        else
        { /* add a parameter */
            TypeParse(&ParamParser, &ParamType, &ParamIdentifier);
            FuncValue->Val->FuncDef.ParamType[ParamCount] = ParamType;
            FuncValue->Val->FuncDef.ParamName[ParamCount] = ParamIdentifier;
        }
        
        Token = LexGetToken(&ParamParser, NULL, TRUE);
        if (Token != TokenComma && ParamCount < FuncValue->Val->FuncDef.NumParams-1)
            ProgramFail(&ParamParser, "comma expected");
    }
    
    if (!IsPrototype)
    {
        if (LexGetToken(Parser, NULL, FALSE) != TokenLeftBrace)
            ProgramFail(Parser, "bad function definition");
        
        FuncBody = *Parser;
        if (!ParseStatementMaybeRun(Parser, FALSE))
            ProgramFail(Parser, "function definition expected");

        FuncValue->Val->FuncDef.Body = FuncBody;
        FuncValue->Val->FuncDef.Body.Pos = LexCopyTokens(&FuncBody, Parser);
    }
        
    if (!TableSet(&GlobalTable, Identifier, FuncValue))
        ProgramFail(Parser, "'%s' is already defined", Identifier);
    
    return FuncValue;
}

/* declare a variable or function */
void ParseDeclaration(struct ParseState *Parser, enum LexToken Token)
{
    char *Identifier;
    struct ValueType *BasicType;
    struct ValueType *Typ;
    struct Value *CValue;

    TypeParseFront(Parser, &BasicType);
    do
    {
        TypeParseIdentPart(Parser, BasicType, &Typ, &Identifier);
        if (Token == TokenVoidType && Identifier != StrEmpty)
            ProgramFail(Parser, "can't define a void variable");
            
        if ((Token != TokenVoidType && Token != TokenStructType && Token != TokenUnionType) && Identifier == StrEmpty)
            ProgramFail(Parser, "identifier expected");
            
        if (Identifier != StrEmpty)
        {
            /* handle function definitions */
            if (LexGetToken(Parser, NULL, FALSE) == TokenOpenBracket)
                ParseFunctionDefinition(Parser, Typ, Identifier, FALSE);
            else
            {
                if (LexGetToken(Parser, NULL, FALSE) != TokenAssign)
                    VariableDefine(Parser, Identifier, VariableAllocValueFromType(Parser, Typ, TRUE, NULL));
                else
                { /* we're assigning an initial value */
                    LexGetToken(Parser, NULL, TRUE);
                    if (!ParseExpression(Parser, &CValue))
                        ProgramFail(Parser, "expression expected");
                        
                    VariableDefine(Parser, Identifier, CValue);
                    if (Parser->Mode == RunModeRun)
                        VariableStackPop(Parser, CValue);
                }
            }
        }
        
        Token = LexGetToken(Parser, NULL, FALSE);
        if (Token == TokenComma)
            LexGetToken(Parser, NULL, TRUE);
            
    } while (Token == TokenComma);
}

/* parse a #define macro definition and store it for later */
void ParseMacroDefinition(struct ParseState *Parser)
{
    struct Value *MacroName;
    struct Value *MacroValue = VariableAllocValueAndData(Parser, sizeof(struct ParseState), FALSE, NULL, TRUE);

    if (LexGetToken(Parser, &MacroName, TRUE) != TokenIdentifier)
        ProgramFail(Parser, "identifier expected");
    
    MacroValue->Val->Parser = *Parser;
    MacroValue->Typ = &MacroType;
    LexToEndOfLine(Parser);
    MacroValue->Val->Parser.Pos = LexCopyTokens(&MacroValue->Val->Parser, Parser);
    
    if (!TableSet(&GlobalTable, MacroName->Val->Identifier, MacroValue))
        ProgramFail(Parser, "'%s' is already defined", &MacroName->Val->Identifier);
}

/* copy where we're at in the parsing */
void ParserCopyPos(struct ParseState *To, struct ParseState *From)
{
    To->Pos = From->Pos;
    To->Line = From->Line;
}

/* parse a "for" statement */
void ParseFor(struct ParseState *Parser)
{
    int Condition;
    struct ParseState PreConditional;
    struct ParseState PreIncrement;
    struct ParseState PreStatement;
    struct ParseState After;

    if (LexGetToken(Parser, NULL, TRUE) != TokenOpenBracket)
        ProgramFail(Parser, "'(' expected");
                        
    if (!ParseStatement(Parser))
        ProgramFail(Parser, "statement expected");
    
    if (LexGetToken(Parser, NULL, TRUE) != TokenSemicolon)
        ProgramFail(Parser, "';' expected");
    
    ParserCopyPos(&PreConditional, Parser);
    Condition = ParseIntExpression(Parser);
    
    if (LexGetToken(Parser, NULL, TRUE) != TokenSemicolon)
        ProgramFail(Parser, "';' expected");
    
    ParserCopyPos(&PreIncrement, Parser);
    ParseStatementMaybeRun(Parser, FALSE);
    
    if (LexGetToken(Parser, NULL, TRUE) != TokenCloseBracket)
        ProgramFail(Parser, "')' expected");
    
    ParserCopyPos(&PreStatement, Parser);
    if (!ParseStatementMaybeRun(Parser, Condition))
        ProgramFail(Parser, "statement expected");
    
    if (Parser->Mode == RunModeContinue)
        Parser->Mode = RunModeRun;
        
    ParserCopyPos(&After, Parser);
        
    while (Condition && Parser->Mode == RunModeRun)
    {
        ParserCopyPos(Parser, &PreIncrement);
        ParseStatement(Parser);
                        
        ParserCopyPos(Parser, &PreConditional);
        Condition = ParseIntExpression(Parser);
        
        if (Condition)
        {
            ParserCopyPos(Parser, &PreStatement);
            ParseStatement(Parser);
            
            if (Parser->Mode == RunModeContinue)
                Parser->Mode = RunModeRun;                
        }
    }
    
    if (Parser->Mode == RunModeBreak)
        Parser->Mode = RunModeRun;
        
    ParserCopyPos(Parser, &After);
}

/* parse a statement, but only run it if Condition is TRUE */
int ParseStatementMaybeRun(struct ParseState *Parser, int Condition)
{
    if (Parser->Mode != RunModeSkip && !Condition)
    {
        enum RunMode OldMode = Parser->Mode;
        Parser->Mode = RunModeSkip;
        int Result = ParseStatement(Parser);
        Parser->Mode = OldMode;
        return Result;
    }
    else
        return ParseStatement(Parser);
}

/* parse a block of code and return what mode it returned in */
enum RunMode ParseBlock(struct ParseState *Parser, int AbsorbOpenBrace, int Condition)
{
    if (AbsorbOpenBrace && LexGetToken(Parser, NULL, TRUE) != TokenLeftBrace)
        ProgramFail(Parser, "'{' expected");
    
    if (Parser->Mode != RunModeSkip && !Condition)
    { /* condition failed - skip this block instead */
        enum RunMode OldMode = Parser->Mode;
        Parser->Mode = RunModeSkip;
        while (ParseStatement(Parser))
        {}
        Parser->Mode = OldMode;
    }
    else
    { /* just run it in its current mode */
        while (ParseStatement(Parser))
        {}
    }
    
    if (LexGetToken(Parser, NULL, TRUE) != TokenRightBrace)
        ProgramFail(Parser, "'}' expected");
        
    return Parser->Mode;
}

/* parse a statement */
int ParseStatement(struct ParseState *Parser)
{
    struct Value *CValue;
    int Condition;
    struct ParseState PreState = *Parser;
    enum LexToken Token = LexGetToken(Parser, NULL, TRUE);
    
    switch (Token)
    {
        case TokenEOF:
            return FALSE;
            
        case TokenIdentifier: 
            *Parser = PreState;
            ParseExpression(Parser, &CValue);
            if (Parser->Mode == RunModeRun) 
                VariableStackPop(Parser, CValue);
            break;
            
        case TokenLeftBrace:
            ParseBlock(Parser, FALSE, TRUE);
            break;
            
        case TokenIf:
            if (LexGetToken(Parser, NULL, TRUE) != TokenOpenBracket)
                ProgramFail(Parser, "'(' expected");
                
            Condition = ParseIntExpression(Parser);
            
            if (LexGetToken(Parser, NULL, TRUE) != TokenCloseBracket)
                ProgramFail(Parser, "')' expected");

            if (!ParseStatementMaybeRun(Parser, Condition))
                ProgramFail(Parser, "statement expected");
            
            if (LexGetToken(Parser, NULL, FALSE) == TokenElse)
            {
                LexGetToken(Parser, NULL, TRUE);
                if (!ParseStatementMaybeRun(Parser, !Condition))
                    ProgramFail(Parser, "statement expected");
            }
            break;
        
        case TokenWhile:
            {
                struct ParseState PreConditional;
                ParserCopyPos(&PreConditional, Parser);
                do
                {
                    ParserCopyPos(Parser, &PreConditional);
                    Condition = ParseIntExpression(Parser);
                    ParseBlock(Parser, TRUE, Condition);
                    if (Parser->Mode == RunModeContinue)
                        Parser->Mode = RunModeRun;
                    
                } while (Parser->Mode == RunModeRun && Condition);
                
                if (Parser->Mode == RunModeBreak)
                    Parser->Mode = RunModeRun;
            }
            break;
                
        case TokenDo:
            {
                struct ParseState PreStatement;
                ParserCopyPos(&PreStatement, Parser);
                do
                {
                    ParserCopyPos(Parser, &PreStatement);
                    ParseBlock(Parser, TRUE, TRUE);
                    if (Parser->Mode == RunModeContinue)
                        Parser->Mode = RunModeRun;

                    if (LexGetToken(Parser, NULL, TRUE) != TokenWhile)
                        ProgramFail(Parser, "'while' expected");
                    
                    Condition = ParseIntExpression(Parser);
                
                } while (Condition && Parser->Mode == RunModeRun);           
                
                if (Parser->Mode == RunModeBreak)
                    Parser->Mode = RunModeRun;
            }
            break;
                
        case TokenFor:
            ParseFor(Parser);
            break;

        case TokenSemicolon: break;

        case TokenIntType:
        case TokenCharType:
        case TokenFloatType:
        case TokenDoubleType:
        case TokenVoidType:
        case TokenStructType:
        case TokenUnionType:
            *Parser = PreState;
            ParseDeclaration(Parser, Token);
            break;
        
        case TokenHashDefine:
            ParseMacroDefinition(Parser);
            break;
            
        case TokenHashInclude:
        {
            struct Value *LexerValue;
            if (LexGetToken(Parser, &LexerValue, TRUE) != TokenStringConstant)
                ProgramFail(Parser, "\"filename.h\" expected");
            
            //ScanFile(LexerValue->Val->String); // XXX - need to dereference char * here
            break;
        }

        case TokenSwitch:
            if (LexGetToken(Parser, NULL, TRUE) != TokenOpenBracket)
                ProgramFail(Parser, "'(' expected");
                
            Condition = ParseIntExpression(Parser);
            
            if (LexGetToken(Parser, NULL, TRUE) != TokenCloseBracket)
                ProgramFail(Parser, "')' expected");
            
            if (LexGetToken(Parser, NULL, FALSE) != TokenLeftBrace)
                ProgramFail(Parser, "'{' expected");
            
            { /* new block so we can store parser state */
                enum RunMode OldMode = Parser->Mode;
                int OldSearchLabel = Parser->SearchLabel;
                Parser->Mode = RunModeCaseSearch;
                Parser->SearchLabel = Condition;
                
                ParseBlock(Parser, TRUE, TRUE);
                
                Parser->Mode = OldMode;
                Parser->SearchLabel = OldSearchLabel;
            }
            break;

        case TokenCase:
            if (Parser->Mode == RunModeCaseSearch)
            {
                Parser->Mode = RunModeRun;
                Condition = ParseIntExpression(Parser);
                Parser->Mode = RunModeCaseSearch;
            }
            else
                Condition = ParseIntExpression(Parser);
                
            if (LexGetToken(Parser, NULL, TRUE) != TokenColon)
                ProgramFail(Parser, "':' expected");
            
            if (Parser->Mode == RunModeCaseSearch && Condition == Parser->SearchLabel)
                Parser->Mode = RunModeRun;
            break;
            
        case TokenDefault:
            if (LexGetToken(Parser, NULL, TRUE) != TokenColon)
                ProgramFail(Parser, "':' expected");
            
            if (Parser->Mode == RunModeCaseSearch)
                Parser->Mode = RunModeRun;
            break;

        case TokenBreak:
            if (Parser->Mode == RunModeRun)
                Parser->Mode = RunModeBreak;
            break;
            
        case TokenContinue:
            if (Parser->Mode == RunModeRun)
                Parser->Mode = RunModeContinue;
            break;
            
        case TokenReturn:
            if (Parser->Mode == RunModeRun)
            {
                if (!ParseExpression(Parser, &CValue) && TopStackFrame->ReturnValue->Typ->Base != TypeVoid)
                    ProgramFail(Parser, "value required in return");
                    
                if (CValue->Typ != TopStackFrame->ReturnValue->Typ)
                    ProgramFail(Parser, "wrong return type");
                    
                // XXX - make assignment a separate function
                // XXX - also arrays need cleverer assignment
                memcpy(TopStackFrame->ReturnValue->Val, CValue->Val, TypeSizeValue(CValue));
                Parser->Mode = RunModeReturn;
            }
            break;
            
        default:
            *Parser = PreState;
            return FALSE;
    }
    
    return TRUE;
}

/* quick scan a source file for definitions */
void Parse(const char *FileName, const char *Source, int SourceLen, int RunIt)
{
    struct ParseState Parser;
    
    void *Tokens = LexAnalyse(FileName, Source, SourceLen, NULL);
    LexInitParser(&Parser, Tokens, FileName, 1, RunIt);

    while (ParseStatement(&Parser))
    {}
    
    if (LexGetToken(&Parser, NULL, FALSE) != TokenEOF)
        ProgramFail(&Parser, "parse error");
    
    HeapFree(Tokens);
}

/* parse interactively */
void ParseInteractive()
{
    struct ParseState Parser;
    int Ok;
    
    LexInitParser(&Parser, NULL, StrEmpty, 1, TRUE);
    PlatformSetExitPoint();
    LexInteractiveClear(&Parser);

    do
    {
        LexInteractiveStatementPrompt();
        Ok = ParseStatement(&Parser);
        LexInteractiveCompleted(&Parser);
        
    } while (Ok);
    
    PlatformPrintf("\n");
}
