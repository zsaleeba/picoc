#include <stdio.h>

#include "picoc.h"

/* parameter passing area */
struct Value *Parameter[PARAMETER_MAX];
int ParameterUsed = 0;
struct Value *ReturnValue;

/* local prototypes */
int ParseIntExpression(struct LexState *Lexer, int RunIt);
int ParseStatement(struct LexState *Lexer, int RunIt);
int ParseArguments(struct LexState *Lexer, int RunIt);


/* initialise the parser */
void ParseInit()
{
    VariableInit();
    IntrinsicInit(&GlobalTable);
    TypeInit();
}

/* parse a parameter list, defining parameters as local variables in the current scope */
void ParseParameterList(struct LexState *CallLexer, struct LexState *FuncLexer, int RunIt)
{
    struct ValueType *Typ;
    Str Identifier;
    enum LexToken Token = LexGetPlainToken(FuncLexer);  /* open bracket */
    int ParamCount;
    
    for (ParamCount = 0; ParamCount < ParameterUsed; ParamCount++)
    {
        TypeParse(FuncLexer, &Typ, &Identifier);
        if (Identifier.Len != 0)
        {   /* there's an identifier */
            if (RunIt)
            {
                if (Parameter[ParamCount]->Typ != Typ)
                    ProgramFail(CallLexer, "parameter %d has the wrong type", ParamCount+1);
                    
                VariableDefine(FuncLexer, &Identifier, Parameter[ParamCount]);
            }
        }
    
        Token = LexGetPlainToken(FuncLexer);
        if (ParamCount < ParameterUsed-1 && Token != TokenComma)
                ProgramFail(FuncLexer, "comma expected");
    }
    
    if (Token != TokenCloseBracket)
        ProgramFail(FuncLexer, "')' expected");
        
    if (ParameterUsed == 0)
        Token = LexGetPlainToken(FuncLexer);
    
    if (Token != TokenCloseBracket)
        ProgramFail(CallLexer, "wrong number of arguments");
}

/* do a function call */
void ParseFunctionCall(struct LexState *Lexer, struct Value **Result, int ResultOnHeap, Str *FuncName, int RunIt)
{
    enum LexToken Token = LexGetPlainToken(Lexer);    /* open bracket */
    
    /* parse arguments */
    ParameterUsed = 0;
    do {
        if (ParseExpression(Lexer, &Parameter[ParameterUsed], FALSE, RunIt))
        {
            if (RunIt && ParameterUsed >= PARAMETER_MAX)
                ProgramFail(Lexer, "too many arguments");
                
            ParameterUsed++;
            Token = LexGetPlainToken(Lexer);
            if (Token != TokenComma && Token != TokenCloseBracket)
                ProgramFail(Lexer, "comma expected");
        }
        else
        {
            Token = LexGetPlainToken(Lexer);
            if (!TokenCloseBracket)
                ProgramFail(Lexer, "bad argument");
        }
    } while (Token != TokenCloseBracket);
    
    if (RunIt) 
    {
        struct LexState FuncLexer;
        struct ValueType *ReturnType;
        struct Value *FuncValue;
        Str FuncName;
        int Count;
        
        VariableGet(Lexer, &FuncName, &FuncValue);
        if ((*Result)->Typ->Base != TypeFunction)
            ProgramFail(Lexer, "not a function - can't call");
        
        VariableStackFrameAdd(Lexer);
        if (FuncValue->Val->Lexer.Line >= 0)
            FuncLexer = FuncValue->Val->Lexer;
        else
            IntrinsicGetLexer(&FuncLexer, FuncValue->Val->Lexer.Line);

        TypeParse(&FuncLexer, &ReturnType, &FuncName);  /* get the return type */
        *Result = VariableAllocValueFromType(Lexer, ReturnType, ResultOnHeap);
        ParseParameterList(Lexer, &FuncLexer, TRUE);    /* parameters */
        if (FuncValue->Val->Lexer.Line >= 0)
        { /* run a user-defined function */
            if (LexPeekPlainToken(&FuncLexer) != TokenLeftBrace || !ParseStatement(&FuncLexer, TRUE))
                ProgramFail(&FuncLexer, "function body expected");
        
            if (ReturnType != (*Result)->Typ)
                ProgramFail(&FuncLexer, "bad return value");
        }
        else
            IntrinsicCall(Lexer, *Result, ReturnType, (*Result)->Val->Lexer.Line);
        
        VariableStackFramePop(Lexer);
            
        for (Count = ParameterUsed-1; Count >= 0; Count--)  /* free stack space used by parameters */
            VariableStackPop(Lexer, Parameter[Count]);
    }
}

/* parse a single value */
int ParseValue(struct LexState *Lexer, struct Value **Result, int ResultOnHeap, int RunIt)
{
    struct LexState PreState = *Lexer;
    struct Value *LexValue;
    int IntValue;
    enum LexToken Token = LexGetToken(Lexer, &LexValue);
    
    switch (Token)
    {
        case TokenIntegerConstant: case TokenCharacterConstant: case TokenFPConstant: case TokenStringConstant:
            *Result = VariableAllocValueAndCopy(Lexer, LexValue, ResultOnHeap);
            break;
        
        case TokenMinus:  case TokenUnaryExor: case TokenUnaryNot:
            IntValue = ParseIntExpression(Lexer, RunIt);
            if (RunIt)
            {
                *Result = VariableAllocValueFromType(Lexer, &IntType, ResultOnHeap);
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
            if (!ParseExpression(Lexer, Result, ResultOnHeap, RunIt))
                ProgramFail(Lexer, "invalid expression");
            
            if (LexGetPlainToken(Lexer) != TokenCloseBracket)
                ProgramFail(Lexer, "')' expected");
            break;
                
        case TokenAsterisk:
        case TokenAmpersand:
            ProgramFail(Lexer, "not implemented");

        case TokenIdentifier:
            if (LexPeekPlainToken(Lexer) == TokenOpenBracket)
                ParseFunctionCall(Lexer, Result, ResultOnHeap, &LexValue->Val->String, RunIt);
            else
            {
                if (RunIt)
                {
                    struct Value *IdentValue;
                    VariableGet(Lexer, &LexValue->Val->String, &IdentValue);
                    if (IdentValue->Typ->Base == TypeMacro)
                    {
                        struct LexState MacroLexer = IdentValue->Val->Lexer;
                        
                        if (!ParseExpression(&MacroLexer, Result, ResultOnHeap, TRUE))
                            ProgramFail(&MacroLexer, "expression expected");
                    }
                    else if (!ISVALUETYPE(IdentValue->Typ))
                        ProgramFail(Lexer, "bad variable type");
                }
            }
            break;
            
        default:
            *Lexer = PreState;
            return FALSE;
    }
    
    return TRUE;
}

struct Value *ParsePushFP(struct LexState *Lexer, int ResultOnHeap, double NewFP)
{
    struct Value *Val = VariableAllocValueFromType(Lexer, &FPType, ResultOnHeap);
    Val->Val->FP = NewFP;
    return Val;
}

struct Value *ParsePushInt(struct LexState *Lexer, int ResultOnHeap, int NewInt)
{
    struct Value *Val = VariableAllocValueFromType(Lexer, &IntType, ResultOnHeap);
    Val->Val->Integer = NewInt;
    return Val;
}

/* parse an expression. operator precedence is not supported */
int ParseExpression(struct LexState *Lexer, struct Value **Result, int ResultOnHeap, int RunIt)
{
    struct Value *CurrentValue;
    struct Value *TotalValue;
    
    if (!ParseValue(Lexer, &TotalValue, ResultOnHeap, RunIt))
        return FALSE;
    
    while (TRUE)
    {
        enum LexToken Token = LexPeekPlainToken(Lexer);
        switch (Token)
        {
            case TokenPlus: case TokenMinus: case TokenAsterisk: case TokenSlash:
            case TokenEquality: case TokenLessThan: case TokenGreaterThan:
            case TokenLessEqual: case TokenGreaterEqual: case TokenLogicalAnd:
            case TokenLogicalOr: case TokenAmpersand: case TokenArithmeticOr: 
            case TokenArithmeticExor: case TokenDot:
                LexGetPlainToken(Lexer);
                break;
                        
            case TokenAssign: case TokenAddAssign: case TokenSubtractAssign:
                LexGetPlainToken(Lexer);
                if (!ParseExpression(Lexer, &CurrentValue, ResultOnHeap, RunIt))
                    ProgramFail(Lexer, "expression expected");
                
                if (RunIt)
                {
                    if (CurrentValue->Typ->Base != TypeInt || TotalValue->Typ->Base != TypeInt)
                        ProgramFail(Lexer, "can't assign");

                    switch (Token)
                    {
                        case TokenAddAssign: TotalValue->Val->Integer += CurrentValue->Val->Integer; break;
                        case TokenSubtractAssign: TotalValue->Val->Integer -= CurrentValue->Val->Integer; break;
                        default: TotalValue->Val->Integer = CurrentValue->Val->Integer; break;
                    }
                    VariableStackPop(Lexer, CurrentValue);
                }
                // fallthrough
            
            default:
                if (RunIt)
                    *Result = TotalValue;
                return TRUE;
        }
        
        if (!ParseValue(Lexer, &CurrentValue, ResultOnHeap, RunIt))
            return FALSE;

        if (RunIt)
        {
            if (CurrentValue->Typ->Base == TypeFP || TotalValue->Typ->Base == TypeFP)
            {
                double FPTotal, FPCurrent;

                if (CurrentValue->Typ->Base != TypeFP || TotalValue->Typ->Base != TypeFP)
                { /* convert both to floating point */
                    if (CurrentValue->Typ->Base == TypeInt)
                        FPCurrent = (double)CurrentValue->Val->Integer;
                    else if (CurrentValue->Typ->Base == TypeFP)
                        FPCurrent = CurrentValue->Val->FP;
                    else
                        ProgramFail(Lexer, "bad type for operator");
                        
                    if (TotalValue->Typ->Base == TypeInt)
                        FPTotal = (double)TotalValue->Val->Integer;
                    else if (TotalValue->Typ->Base == TypeFP)
                        FPTotal = TotalValue->Val->FP;
                    else
                        ProgramFail(Lexer, "bad type for operator");
                }

                VariableStackPop(Lexer, CurrentValue);
                VariableStackPop(Lexer, TotalValue);
                
                switch (Token)
                {
                    case TokenPlus:         TotalValue = ParsePushFP(Lexer, ResultOnHeap, FPTotal + FPCurrent); break;
                    case TokenMinus:        TotalValue = ParsePushFP(Lexer, ResultOnHeap, FPTotal - FPCurrent); break;
                    case TokenAsterisk:     TotalValue = ParsePushFP(Lexer, ResultOnHeap, FPTotal * FPCurrent); break;
                    case TokenSlash:        TotalValue = ParsePushFP(Lexer, ResultOnHeap, FPTotal / FPCurrent); break;
                    case TokenEquality:     TotalValue = ParsePushInt(Lexer, ResultOnHeap, FPTotal == FPCurrent); break;
                    case TokenLessThan:     TotalValue = ParsePushInt(Lexer, ResultOnHeap, FPTotal < FPCurrent); break;
                    case TokenGreaterThan:  TotalValue = ParsePushInt(Lexer, ResultOnHeap, FPTotal > FPCurrent); break;
                    case TokenLessEqual:    TotalValue = ParsePushInt(Lexer, ResultOnHeap, FPTotal <= FPCurrent); break;
                    case TokenGreaterEqual: TotalValue = ParsePushInt(Lexer, ResultOnHeap, FPTotal >= FPCurrent); break;
                    case TokenLogicalAnd: case TokenLogicalOr: case TokenAmpersand: case TokenArithmeticOr: case TokenArithmeticExor: ProgramFail(Lexer, "bad type for operator"); break;
                    case TokenDot: ProgramFail(Lexer, "operator not supported"); break;
                    default: break;
                }
            }
            else
            {
                if (CurrentValue->Typ->Base != TypeInt || TotalValue->Typ->Base != TypeInt)
                    ProgramFail(Lexer, "bad operand types");
            
                /* integer arithmetic */
                switch (Token)
                {
                    case TokenPlus: TotalValue->Val->Integer += CurrentValue->Val->Integer; break;
                    case TokenMinus: TotalValue->Val->Integer -= CurrentValue->Val->Integer; break;
                    case TokenAsterisk: TotalValue->Val->Integer *= CurrentValue->Val->Integer; break;
                    case TokenSlash: TotalValue->Val->Integer /= CurrentValue->Val->Integer; break;
                    case TokenEquality: TotalValue->Val->Integer = TotalValue->Val->Integer == CurrentValue->Val->Integer; break;
                    case TokenLessThan: TotalValue->Val->Integer = TotalValue->Val->Integer < CurrentValue->Val->Integer; break;
                    case TokenGreaterThan: TotalValue->Val->Integer = TotalValue->Val->Integer > CurrentValue->Val->Integer; break;
                    case TokenLessEqual: TotalValue->Val->Integer = TotalValue->Val->Integer <= CurrentValue->Val->Integer; break;
                    case TokenGreaterEqual: TotalValue->Val->Integer = TotalValue->Val->Integer >= CurrentValue->Val->Integer; break;
                    case TokenLogicalAnd: TotalValue->Val->Integer = TotalValue->Val->Integer && CurrentValue->Val->Integer; break;
                    case TokenLogicalOr: TotalValue->Val->Integer = TotalValue->Val->Integer || CurrentValue->Val->Integer; break;
                    case TokenAmpersand: TotalValue->Val->Integer = TotalValue->Val->Integer & CurrentValue->Val->Integer; break;
                    case TokenArithmeticOr: TotalValue->Val->Integer = TotalValue->Val->Integer | CurrentValue->Val->Integer; break;
                    case TokenArithmeticExor: TotalValue->Val->Integer = TotalValue->Val->Integer ^ CurrentValue->Val->Integer; break;
                    case TokenDot: ProgramFail(Lexer, "operator not supported"); break;
                    default: break;
                }
            }
            VariableStackPop(Lexer, CurrentValue);
            *Result = TotalValue;
        }
    }
    
    return TRUE;
}

/* parse an expression. operator precedence is not supported */
int ParseIntExpression(struct LexState *Lexer, int RunIt)
{
    struct Value *Val;
    int Result = 0;
    
    if (!ParseExpression(Lexer, &Val, FALSE, RunIt))
        ProgramFail(Lexer, "expression expected");
    
    if (RunIt)
    { 
        if (Val->Typ->Base != TypeInt)
            ProgramFail(Lexer, "integer value expected");
    
        Result = Val->Val->Integer;
        VariableStackPop(Lexer, Val);
    }
    
    return Result;
}

/* parse a function definition and store it for later */
void ParseFunctionDefinition(struct LexState *Lexer, Str *Identifier, struct LexState *PreState)
{
    struct Value *FuncValue = VariableAllocValueAndData(Lexer, sizeof(struct LexState), TRUE);

    FuncValue->Val->Lexer = *PreState;
    LexGetPlainToken(Lexer);
    if (LexGetPlainToken(Lexer) != TokenCloseBracket || LexPeekPlainToken(Lexer) != TokenLeftBrace)
        ProgramFail(Lexer, "bad function definition");
    
    if (!ParseStatement(Lexer, FALSE))
        ProgramFail(Lexer, "function definition expected");
    
    FuncValue->Val->Lexer.End = Lexer->Pos;
    FuncValue->Typ = &FunctionType;
    
    if (!TableSet(&GlobalTable, Identifier, FuncValue))
        ProgramFail(Lexer, "'%S' is already defined", Identifier);
}

/* parse a #define macro definition and store it for later */
void ParseMacroDefinition(struct LexState *Lexer)
{
    struct Value *MacroName;
    struct Value *MacroValue = VariableAllocValueAndData(Lexer, sizeof(struct LexState), TRUE);

    if (LexGetToken(Lexer, &MacroName) != TokenIdentifier)
        ProgramFail(Lexer, "identifier expected");
    
    MacroValue->Val->Lexer = *Lexer;
    LexToEndOfLine(Lexer);
    MacroValue->Val->Lexer.End = Lexer->Pos;
    MacroValue->Typ = &MacroType;
    
    if (!TableSet(&GlobalTable, &MacroName->Val->String, MacroValue))
        ProgramFail(Lexer, "'%S' is already defined", &MacroName->Val->String);
}

void ParseFor(struct LexState *Lexer, int RunIt)
{
    int Condition;
    struct LexState PreConditional;
    struct LexState PreIncrement;
    struct LexState PreStatement;
    struct LexState After;

    if (LexGetPlainToken(Lexer) != TokenOpenBracket)
        ProgramFail(Lexer, "'(' expected");
                        
    if (!ParseStatement(Lexer, RunIt))
        ProgramFail(Lexer, "statement expected");
    
    PreConditional = *Lexer;
    Condition = ParseIntExpression(Lexer, RunIt);
    
    if (LexGetPlainToken(Lexer) != TokenSemicolon)
        ProgramFail(Lexer, "';' expected");
    
    PreIncrement = *Lexer;
    ParseStatement(Lexer, FALSE);
    
    if (LexGetPlainToken(Lexer) != TokenCloseBracket)
        ProgramFail(Lexer, "')' expected");
    
    PreStatement = *Lexer;
    if (!ParseStatement(Lexer, RunIt && Condition))
        ProgramFail(Lexer, "statement expected");
    
    After = *Lexer;
    
    while (Condition && RunIt)
    {
        *Lexer = PreIncrement;
        ParseStatement(Lexer, TRUE);
                        
        *Lexer = PreConditional;
        Condition = ParseIntExpression(Lexer, RunIt);
        
        if (Condition)
        {
            *Lexer = PreStatement;
            ParseStatement(Lexer, TRUE);
        }
    }
    
    *Lexer = After;
}

/* parse a statement */
int ParseStatement(struct LexState *Lexer, int RunIt)
{
    struct Value *CValue;
    int Condition;
    struct LexState PreState = *Lexer;
    Str Identifier;
    struct ValueType *Typ;
    enum LexToken Token = LexGetPlainToken(Lexer);
    
    switch (Token)
    {
        case TokenEOF:
            return FALSE;
            
        case TokenIdentifier: 
            *Lexer = PreState;
            ParseExpression(Lexer, &CValue, FALSE, RunIt);
            if (RunIt) VariableStackPop(Lexer, CValue);
            break;
            
        case TokenLeftBrace:
            while (ParseStatement(Lexer, RunIt))
            {}
            
            if (LexGetPlainToken(Lexer) != TokenRightBrace)
                ProgramFail(Lexer, "'}' expected");
            break;
            
        case TokenIf:
            Condition = ParseIntExpression(Lexer, RunIt);
            
            if (!ParseStatement(Lexer, RunIt && Condition))
                ProgramFail(Lexer, "statement expected");
            
            if (LexPeekPlainToken(Lexer) == TokenElse)
            {
                LexGetPlainToken(Lexer);
                if (!ParseStatement(Lexer, RunIt && !Condition))
                    ProgramFail(Lexer, "statement expected");
            }
            break;
        
        case TokenWhile:
            {
                struct LexState PreConditional = *Lexer;
                do
                {
                    *Lexer = PreConditional;
                    Condition = ParseIntExpression(Lexer, RunIt);
                
                    if (!ParseStatement(Lexer, RunIt && Condition))
                        ProgramFail(Lexer, "statement expected");
                        
                } while (RunIt && Condition);                
            }
            break;
                
        case TokenDo:
            {
                struct LexState PreStatement = *Lexer;
                do
                {
                    *Lexer = PreStatement;
                    if (!ParseStatement(Lexer, RunIt))
                        ProgramFail(Lexer, "statement expected");
                        
                    Condition = ParseIntExpression(Lexer, RunIt);
                
                } while (Condition && RunIt);           
            }
            break;
                
        case TokenFor:
            ParseFor(Lexer, RunIt);
            break;

        case TokenSemicolon: break;

        case TokenIntType:
        case TokenCharType:
        case TokenFloatType:
        case TokenDoubleType:
        case TokenVoidType:
            *Lexer = PreState;
            TypeParse(Lexer, &Typ, &Identifier);
            if (Identifier.Len == 0)
                ProgramFail(Lexer, "identifier expected");
                
            /* handle function definitions */
            if (LexPeekPlainToken(Lexer) == TokenOpenBracket)
                ParseFunctionDefinition(Lexer, &Identifier, &PreState);
            else
                VariableDefine(Lexer, &Identifier, VariableAllocValueFromType(Lexer, Typ, FALSE));
            break;
        
        case TokenHashDefine:
            ParseMacroDefinition(Lexer);
            break;
            
        case TokenHashInclude:
        {
            struct Value *LexerValue;
            if (LexGetToken(Lexer, &LexerValue) != TokenStringConstant)
                ProgramFail(Lexer, "\"filename.h\" expected");
            
            ScanFile(&LexerValue->Val->String);
            LexToEndOfLine(Lexer);
            break;
        }

        case TokenSwitch:
        case TokenCase:
        case TokenBreak:
        case TokenReturn:
        case TokenDefault:
            ProgramFail(Lexer, "not implemented yet");
            break;
            
        default:
            *Lexer = PreState;
            return FALSE;
    }
    
    return TRUE;
}

/* quick scan a source file for definitions */
void Parse(const Str *FileName, const Str *Source, int RunIt)
{
    struct LexState Lexer;
    
    LexInit(&Lexer, Source, FileName, 1);
    
    while (ParseStatement(&Lexer, RunIt))
    {}
    
    if (Lexer.Pos != Lexer.End)
        ProgramFail(&Lexer, "parse error");
}
