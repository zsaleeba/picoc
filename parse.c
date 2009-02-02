#include <stdio.h>

#include "picoc.h"

/* parameter passing area */
struct Value *Parameter[PARAMETER_MAX];
int ParameterUsed = 0;
struct Value *ReturnValue;

/* local prototypes */
int ParseIntExpression(struct ParseState *Parser, int RunIt);
int ParseStatement(struct ParseState *Parser, int RunIt);
int ParseArguments(struct ParseState *Parser, int RunIt);


/* initialise the parser */
void ParseInit()
{
    StrInit();
    VariableInit();
    IntrinsicInit(&GlobalTable);
    TypeInit();
}

/* do a function call */
void ParseFunctionCall(struct ParseState *Parser, struct Value **Result, int ResultOnHeap, const char *FuncName, int RunIt)
{
    struct Value *FuncValue;
    enum LexToken Token = LexGetToken(Parser, NULL, TRUE);    /* open bracket */
    
    if (RunIt) 
    { /* get the function definition */
        VariableGet(Parser, FuncName, &FuncValue);
        if (FuncValue->Typ->Base != TypeFunction)
            ProgramFail(Parser, "not a function - can't call");
    }
        
    /* parse arguments */
    ParameterUsed = 0;
    do {
        if (ParseExpression(Parser, &Parameter[ParameterUsed], FALSE, RunIt))
        {
            if (RunIt && FuncValue->Val->FuncDef.ParamType[ParameterUsed] != Parameter[ParameterUsed]->Typ)
                ProgramFail(Parser, "parameter %d to %s is the wrong type", ParameterUsed, FuncName);
                
            ParameterUsed++;
            if (RunIt && ParameterUsed >= FuncValue->Val->FuncDef.NumParams)
                ProgramFail(Parser, "too many arguments");
                
            Token = LexGetToken(Parser, NULL, TRUE);
            if (Token != TokenComma && Token != TokenCloseBracket)
                ProgramFail(Parser, "comma expected");
        }
        else
        {
            Token = LexGetToken(Parser, NULL, TRUE);
            if (!TokenCloseBracket)
                ProgramFail(Parser, "bad argument");
        }
    } while (Token != TokenCloseBracket);
    
    if (RunIt) 
    { /* run the function */
        int Count;
        
        VariableStackFrameAdd(Parser);

        *Result = VariableAllocValueFromType(Parser, FuncValue->Val->FuncDef.ReturnType, ResultOnHeap);
        if (FuncValue->Val->FuncDef.Intrinsic == NULL)
        { /* run a user-defined function */
            struct ParseState FuncParser = FuncValue->Val->FuncDef.Body;
            
            for (Count = 0; Count < ParameterUsed; Count++)
                VariableDefine(Parser, FuncValue->Val->FuncDef.ParamName[Count], Parameter[Count]);
            
            if (!ParseStatement(&FuncParser, TRUE))
                ProgramFail(&FuncParser, "function body expected");
        
            if (FuncValue->Val->FuncDef.ReturnType != (*Result)->Typ)
                ProgramFail(&FuncParser, "bad type of return value");
        }
        else
            FuncValue->Val->FuncDef.Intrinsic();
        
        VariableStackFramePop(Parser);
            
        for (Count = ParameterUsed-1; Count >= 0; Count--)  /* free stack space used by parameters */
            VariableStackPop(Parser, Parameter[Count]);
    }
}

/* parse a single value */
int ParseValue(struct ParseState *Parser, struct Value **Result, int ResultOnHeap, int RunIt)
{
    struct ParseState PreState = *Parser;
    struct Value *LexValue;
    int IntValue;
    enum LexToken Token = LexGetToken(Parser, &LexValue, TRUE);
    
    switch (Token)
    {
        case TokenIntegerConstant: case TokenCharacterConstant: case TokenFPConstant: case TokenStringConstant:
            *Result = VariableAllocValueAndCopy(Parser, LexValue, ResultOnHeap);
            break;
        
        case TokenMinus:  case TokenUnaryExor: case TokenUnaryNot:
            IntValue = ParseIntExpression(Parser, RunIt);
            if (RunIt)
            {
                *Result = VariableAllocValueFromType(Parser, &IntType, ResultOnHeap);
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
            if (!ParseExpression(Parser, Result, ResultOnHeap, RunIt))
                ProgramFail(Parser, "invalid expression");
            
            if (LexGetToken(Parser, NULL, TRUE) != TokenCloseBracket)
                ProgramFail(Parser, "')' expected");
            break;
                
        case TokenAsterisk:
        case TokenAmpersand:
            ProgramFail(Parser, "not implemented");

        case TokenIdentifier:
            if (LexGetToken(Parser, NULL, FALSE) == TokenOpenBracket)
                ParseFunctionCall(Parser, Result, ResultOnHeap, LexValue->Val->String, RunIt);
            else
            {
                if (RunIt)
                {
                    struct Value *IdentValue;
                    VariableGet(Parser, LexValue->Val->String, &IdentValue);
                    if (IdentValue->Typ->Base == TypeMacro)
                    {
                        struct ParseState MacroLexer = IdentValue->Val->Parser;
                        
                        if (!ParseExpression(&MacroLexer, Result, ResultOnHeap, TRUE))
                            ProgramFail(&MacroLexer, "expression expected");
                    }
                    else if (!ISVALUETYPE(IdentValue->Typ))
                        ProgramFail(Parser, "bad variable type");
                }
            }
            break;
            
        default:
            *Parser = PreState;
            return FALSE;
    }
    
    return TRUE;
}

struct Value *ParsePushFP(struct ParseState *Parser, int ResultOnHeap, double NewFP)
{
    struct Value *Val = VariableAllocValueFromType(Parser, &FPType, ResultOnHeap);
    Val->Val->FP = NewFP;
    return Val;
}

struct Value *ParsePushInt(struct ParseState *Parser, int ResultOnHeap, int NewInt)
{
    struct Value *Val = VariableAllocValueFromType(Parser, &IntType, ResultOnHeap);
    Val->Val->Integer = NewInt;
    return Val;
}

/* parse an expression. operator precedence is not supported */
int ParseExpression(struct ParseState *Parser, struct Value **Result, int ResultOnHeap, int RunIt)
{
    struct Value *CurrentValue;
    struct Value *TotalValue;
    
    if (!ParseValue(Parser, &TotalValue, ResultOnHeap, RunIt))
        return FALSE;
    
    while (TRUE)
    {
        enum LexToken Token = LexGetToken(Parser, NULL, FALSE);
        switch (Token)
        {
            case TokenPlus: case TokenMinus: case TokenAsterisk: case TokenSlash:
            case TokenEquality: case TokenLessThan: case TokenGreaterThan:
            case TokenLessEqual: case TokenGreaterEqual: case TokenLogicalAnd:
            case TokenLogicalOr: case TokenAmpersand: case TokenArithmeticOr: 
            case TokenArithmeticExor: case TokenDot:
                LexGetToken(Parser, NULL, TRUE);
                break;
                        
            case TokenAssign: case TokenAddAssign: case TokenSubtractAssign:
                LexGetToken(Parser, NULL, TRUE);
                if (!ParseExpression(Parser, &CurrentValue, ResultOnHeap, RunIt))
                    ProgramFail(Parser, "expression expected");
                
                if (RunIt)
                {
                    if (CurrentValue->Typ->Base != TypeInt || TotalValue->Typ->Base != TypeInt)
                        ProgramFail(Parser, "can't assign");

                    switch (Token)
                    {
                        case TokenAddAssign: TotalValue->Val->Integer += CurrentValue->Val->Integer; break;
                        case TokenSubtractAssign: TotalValue->Val->Integer -= CurrentValue->Val->Integer; break;
                        default: TotalValue->Val->Integer = CurrentValue->Val->Integer; break;
                    }
                    VariableStackPop(Parser, CurrentValue);
                }
                // fallthrough
            
            default:
                if (RunIt)
                    *Result = TotalValue;
                return TRUE;
        }
        
        if (!ParseValue(Parser, &CurrentValue, ResultOnHeap, RunIt))
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
                    case TokenPlus:         TotalValue = ParsePushFP(Parser, ResultOnHeap, FPTotal + FPCurrent); break;
                    case TokenMinus:        TotalValue = ParsePushFP(Parser, ResultOnHeap, FPTotal - FPCurrent); break;
                    case TokenAsterisk:     TotalValue = ParsePushFP(Parser, ResultOnHeap, FPTotal * FPCurrent); break;
                    case TokenSlash:        TotalValue = ParsePushFP(Parser, ResultOnHeap, FPTotal / FPCurrent); break;
                    case TokenEquality:     TotalValue = ParsePushInt(Parser, ResultOnHeap, FPTotal == FPCurrent); break;
                    case TokenLessThan:     TotalValue = ParsePushInt(Parser, ResultOnHeap, FPTotal < FPCurrent); break;
                    case TokenGreaterThan:  TotalValue = ParsePushInt(Parser, ResultOnHeap, FPTotal > FPCurrent); break;
                    case TokenLessEqual:    TotalValue = ParsePushInt(Parser, ResultOnHeap, FPTotal <= FPCurrent); break;
                    case TokenGreaterEqual: TotalValue = ParsePushInt(Parser, ResultOnHeap, FPTotal >= FPCurrent); break;
                    case TokenLogicalAnd: case TokenLogicalOr: case TokenAmpersand: case TokenArithmeticOr: case TokenArithmeticExor: ProgramFail(Parser, "bad type for operator"); break;
                    case TokenDot: ProgramFail(Parser, "operator not supported"); break;
                    default: break;
                }
            }
            else
            {
                if (CurrentValue->Typ->Base != TypeInt || TotalValue->Typ->Base != TypeInt)
                    ProgramFail(Parser, "bad operand types");
            
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
                    case TokenDot: ProgramFail(Parser, "operator not supported"); break;
                    default: break;
                }
            }
            VariableStackPop(Parser, CurrentValue);
            *Result = TotalValue;
        }
    }
    
    return TRUE;
}

/* parse an expression. operator precedence is not supported */
int ParseIntExpression(struct ParseState *Parser, int RunIt)
{
    struct Value *Val;
    int Result = 0;
    
    if (!ParseExpression(Parser, &Val, FALSE, RunIt))
        ProgramFail(Parser, "expression expected");
    
    if (RunIt)
    { 
        if (Val->Typ->Base != TypeInt)
            ProgramFail(Parser, "integer value expected");
    
        Result = Val->Val->Integer;
        VariableStackPop(Parser, Val);
    }
    
    return Result;
}

/* parse a function definition and store it for later */
struct Value *ParseFunctionDefinition(struct ParseState *Parser, struct ValueType *ReturnType, const char *Identifier, int IsPrototype)
{
    struct ValueType *ParamType;
    const char *ParamIdentifier;
    enum LexToken Token;
    struct Value *FuncValue;
    struct ParseState ParamParser;
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
    
    FuncValue = VariableAllocValueAndData(Parser, sizeof(struct FuncDef) + sizeof(struct ValueType *) * ParamCount + sizeof(const char *) * ParamCount, TRUE);
    FuncValue->Typ = &FunctionType;
    FuncValue->Val->FuncDef.ReturnType = ReturnType;
    FuncValue->Val->FuncDef.NumParams = ParamCount;
    FuncValue->Val->FuncDef.ParamType = (void *)FuncValue->Val + sizeof(struct FuncDef);
    FuncValue->Val->FuncDef.ParamName = (void *)FuncValue->Val->FuncDef.ParamType + sizeof(struct ValueType *) * ParamCount;
    FuncValue->Val->FuncDef.Body = *Parser;
   
    for (ParamCount = 0; ParamCount < FuncValue->Val->FuncDef.NumParams; ParamCount++)
    { /* harvest the parameters into the function definition */
        TypeParse(&ParamParser, &ParamType, &ParamIdentifier);
        FuncValue->Val->FuncDef.ParamType[ParamCount] = ParamType;
        FuncValue->Val->FuncDef.ParamName[ParamCount] = ParamIdentifier;
        
        Token = LexGetToken(&ParamParser, NULL, TRUE);
        if (Token != TokenComma)
            ProgramFail(&ParamParser, "comma expected");
    }
    
    if (!IsPrototype)
    {
        if (LexGetToken(Parser, NULL, FALSE) != TokenLeftBrace)
            ProgramFail(Parser, "bad function definition");
        
        if (!ParseStatement(Parser, FALSE))
            ProgramFail(Parser, "function definition expected");
    }
        
    if (!TableSet(&GlobalTable, Identifier, FuncValue))
        ProgramFail(Parser, "'%s' is already defined", Identifier);
    
    return FuncValue;
}

/* parse a #define macro definition and store it for later */
void ParseMacroDefinition(struct ParseState *Parser)
{
    struct Value *MacroName;
    struct Value *MacroValue = VariableAllocValueAndData(Parser, sizeof(struct ParseState), TRUE);

    if (LexGetToken(Parser, &MacroName, TRUE) != TokenIdentifier)
        ProgramFail(Parser, "identifier expected");
    
    MacroValue->Val->Parser = *Parser;
    MacroValue->Typ = &MacroType;
    
    if (!TableSet(&GlobalTable, MacroName->Val->String, MacroValue))
        ProgramFail(Parser, "'%s' is already defined", &MacroName->Val->String);
}

void ParseFor(struct ParseState *Parser, int RunIt)
{
    int Condition;
    struct ParseState PreConditional;
    struct ParseState PreIncrement;
    struct ParseState PreStatement;
    struct ParseState After;

    if (LexGetToken(Parser, NULL, TRUE) != TokenOpenBracket)
        ProgramFail(Parser, "'(' expected");
                        
    if (!ParseStatement(Parser, RunIt))
        ProgramFail(Parser, "statement expected");
    
    PreConditional = *Parser;
    Condition = ParseIntExpression(Parser, RunIt);
    
    if (LexGetToken(Parser, NULL, TRUE) != TokenSemicolon)
        ProgramFail(Parser, "';' expected");
    
    PreIncrement = *Parser;
    ParseStatement(Parser, FALSE);
    
    if (LexGetToken(Parser, NULL, TRUE) != TokenCloseBracket)
        ProgramFail(Parser, "')' expected");
    
    PreStatement = *Parser;
    if (!ParseStatement(Parser, RunIt && Condition))
        ProgramFail(Parser, "statement expected");
    
    After = *Parser;
    
    while (Condition && RunIt)
    {
        *Parser = PreIncrement;
        ParseStatement(Parser, TRUE);
                        
        *Parser = PreConditional;
        Condition = ParseIntExpression(Parser, RunIt);
        
        if (Condition)
        {
            *Parser = PreStatement;
            ParseStatement(Parser, TRUE);
        }
    }
    
    *Parser = After;
}

/* parse a statement */
int ParseStatement(struct ParseState *Parser, int RunIt)
{
    struct Value *CValue;
    int Condition;
    struct ParseState PreState = *Parser;
    const char *Identifier;
    struct ValueType *Typ;
    enum LexToken Token = LexGetToken(Parser, NULL, TRUE);
    
    switch (Token)
    {
        case TokenEOF:
            return FALSE;
            
        case TokenIdentifier: 
            *Parser = PreState;
            ParseExpression(Parser, &CValue, FALSE, RunIt);
            if (RunIt) VariableStackPop(Parser, CValue);
            break;
            
        case TokenLeftBrace:
            while (ParseStatement(Parser, RunIt))
            {}
            
            if (LexGetToken(Parser, NULL, TRUE) != TokenRightBrace)
                ProgramFail(Parser, "'}' expected");
            break;
            
        case TokenIf:
            Condition = ParseIntExpression(Parser, RunIt);
            
            if (!ParseStatement(Parser, RunIt && Condition))
                ProgramFail(Parser, "statement expected");
            
            if (LexGetToken(Parser, NULL, FALSE) == TokenElse)
            {
                LexGetToken(Parser, NULL, TRUE);
                if (!ParseStatement(Parser, RunIt && !Condition))
                    ProgramFail(Parser, "statement expected");
            }
            break;
        
        case TokenWhile:
            {
                struct ParseState PreConditional = *Parser;
                do
                {
                    *Parser = PreConditional;
                    Condition = ParseIntExpression(Parser, RunIt);
                
                    if (!ParseStatement(Parser, RunIt && Condition))
                        ProgramFail(Parser, "statement expected");
                        
                } while (RunIt && Condition);                
            }
            break;
                
        case TokenDo:
            {
                struct ParseState PreStatement = *Parser;
                do
                {
                    *Parser = PreStatement;
                    if (!ParseStatement(Parser, RunIt))
                        ProgramFail(Parser, "statement expected");
                        
                    Condition = ParseIntExpression(Parser, RunIt);
                
                } while (Condition && RunIt);           
            }
            break;
                
        case TokenFor:
            ParseFor(Parser, RunIt);
            break;

        case TokenSemicolon: break;

        case TokenIntType:
        case TokenCharType:
        case TokenFloatType:
        case TokenDoubleType:
        case TokenVoidType:
            *Parser = PreState;
            TypeParse(Parser, &Typ, &Identifier);
            if (Identifier == StrEmpty)
                ProgramFail(Parser, "identifier expected");
                
            /* handle function definitions */
            if (LexGetToken(Parser, NULL, FALSE) == TokenOpenBracket)
                ParseFunctionDefinition(Parser, Typ, Identifier, FALSE);
            else
                VariableDefine(Parser, Identifier, VariableAllocValueFromType(Parser, Typ, FALSE));
            break;
        
        case TokenHashDefine:
            ParseMacroDefinition(Parser);
            break;
            
        case TokenHashInclude:
        {
            struct Value *LexerValue;
            if (LexGetToken(Parser, &LexerValue, TRUE) != TokenStringConstant)
                ProgramFail(Parser, "\"filename.h\" expected");
            
            ScanFile(LexerValue->Val->String);
            break;
        }

        case TokenSwitch:
        case TokenCase:
        case TokenBreak:
        case TokenReturn:
        case TokenDefault:
            ProgramFail(Parser, "not implemented yet");
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
    
    void *Tokens = LexAnalyse(FileName, Source, SourceLen); // XXX - some better way of storing tokenised input?
    LexInitParser(&Parser, Tokens, FileName, 1);

    while (ParseStatement(&Parser, RunIt))
    {}
    
    if (LexGetToken(&Parser, NULL, FALSE) != TokenEOF)
        ProgramFail(&Parser, "parse error");
}
