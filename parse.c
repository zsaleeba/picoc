#include <stdio.h>
#include <string.h>

#include "picoc.h"

/* the table of global definitions */
struct Table GlobalTable;
struct TableEntry GlobalHashTable[GLOBAL_TABLE_SIZE];

/* the table of function definitions */
struct LexState FunctionStore[FUNCTION_STORE_MAX];
int FunctionStoreUsed = 0;

/* the stack */
struct StackFrame Stack[STACK_MAX];
int StackUsed = 0;

/* parameter passing area */
struct Value Parameter[PARAMETER_MAX];
int ParameterUsed = 0;
struct Value ReturnValue;

/* local prototypes */
int ParseExpression(struct LexState *Lexer, struct Value *Result, int RunIt);
void ParseIntExpression(struct LexState *Lexer, struct Value *Result, int RunIt);
int ParseStatement(struct LexState *Lexer, int RunIt);
int ParseArguments(struct LexState *Lexer, int RunIt);


/* initialise the parser */
void ParseInit()
{
    TableInit(&GlobalTable, &GlobalHashTable[0], GLOBAL_TABLE_SIZE);
}

/* define a variable */
void VariableDefine(struct LexState *Lexer, const Str *Ident, struct Value *InitValue)
{
    if (!TableSet((StackUsed == 0) ? &GlobalTable : &Stack[StackUsed-1].LocalTable, Ident, InitValue))
        ProgramFail(Lexer, "'%S' is already defined", Ident);
}

/* get the value of a variable. must be defined */
void VariableGet(struct LexState *Lexer, Str *Ident, struct Value *Val, struct Value **LVal)
{
    int Frame;
    
    for (Frame = StackUsed-1; Frame >= 0; Frame--)
    {
        if (TableGet(&Stack[Frame].LocalTable, Ident, LVal))
        {
            *Val = **LVal;
            return;
        }
    }
    
    if (!TableGet(&GlobalTable, Ident, LVal))
        ProgramFail(Lexer, "'%S' is undefined", Ident);

    *Val = **LVal;
}

/* add a stack frame when doing a function call */
void StackFrameAdd(struct LexState *Lexer)
{
    struct StackFrame *NewFrame = &Stack[StackUsed];
    
    if (StackUsed >= STACK_MAX)
        ProgramFail(Lexer, "too many nested function calls");
        
    NewFrame->ReturnLex = *Lexer;
    TableInit(&NewFrame->LocalTable, &NewFrame->LocalHashTable[0], LOCAL_TABLE_SIZE);
    StackUsed++;
}

/* parse a type specification */
int ParseType(struct LexState *Lexer, enum ValueType *Typ)
{
    struct LexState Before = *Lexer;
    enum LexToken Token = LexGetPlainToken(Lexer);
    switch (Token)
    {
        case TokenIntType: case TokenCharType: *Typ = TypeInt; return TRUE;
        case TokenVoidType: *Typ = TypeVoid; return TRUE;
        default: *Lexer = Before; return FALSE;
    }
}

/* parse a parameter list, defining parameters as local variables in the current scope */
void ParseParameterList(struct LexState *CallLexer, struct LexState *FuncLexer, int RunIt)
{
    enum ValueType Typ;
    union AnyValue Identifier;
    enum LexToken Token = TokenNone;
    int ParamCount;
    
    ParamCount = 0;
    while (ParamCount < ParameterUsed && Token != TokenCloseBracket)
    {
        ParseType(FuncLexer, &Typ);
        Token = LexGetToken(FuncLexer, &Identifier);
        if (Token != TokenCloseBracket)
        {
            if (Token != TokenIdentifier)
                ProgramFail(FuncLexer, "invalid parameter");
                
            if (RunIt)
            {
                if (Parameter[ParamCount].Typ != Typ)
                    ProgramFail(CallLexer, "parameter %d has the wrong type", ParamCount+1);
                    
                VariableDefine(FuncLexer, &Identifier.String, &Parameter[ParamCount]);
                ParamCount++;
            }

            Token = LexGetPlainToken(FuncLexer);
        }
        
        if (Token != TokenComma && Token != TokenCloseBracket)
            ProgramFail(FuncLexer, "comma expected");
    }
    
    if (ParamCount != 0 || Token != TokenCloseBracket)
        ProgramFail(CallLexer, "wrong number of arguments");
}

/* do a function call */
void ParseFunctionCall(struct LexState *Lexer, struct Value *Result, Str *FuncName, int RunIt)
{
    enum LexToken Token = LexGetPlainToken(Lexer);    /* open bracket */
    
    /* parse arguments */
    ParameterUsed = 0;
    do {
        if (ParseExpression(Lexer, &Parameter[ParameterUsed], RunIt))
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
            if (TokenCloseBracket)
                ProgramFail(Lexer, "bad argument");
        }
    } while (Token != TokenCloseBracket);
    
    if (RunIt) 
    {
        struct LexState FuncLexer;
        enum ValueType ReturnType;
        struct Value *LValue;
        
        VariableGet(Lexer, FuncName, Result, &LValue);
        if (Result->Typ != TypeFunction)
            ProgramFail(Lexer, "not a function - can't call");
            
        StackFrameAdd(Lexer);
        FuncLexer = FunctionStore[Result->Val.Integer];
        ParseType(&FuncLexer, &ReturnType);             /* return type */
        Result->Typ = TypeVoid;
        LexGetPlainToken(&FuncLexer);                   /* function name again */
        ParseParameterList(Lexer, &FuncLexer, TRUE);    /* parameters */
        if (LexPeekPlainToken(&FuncLexer) != TokenLeftBrace || !ParseStatement(&FuncLexer, TRUE))
            ProgramFail(&FuncLexer, "function body expected");
        
        if (ReturnType != Result->Typ)
            ProgramFail(&FuncLexer, "bad return value");
    }
}

/* parse a single value */
int ParseValue(struct LexState *Lexer, struct Value *Result, struct Value **LValue, int RunIt)
{
    struct LexState PreState = *Lexer;
    enum LexToken Token = LexGetToken(Lexer, &Result->Val);
    *LValue = NULL;
    
    switch (Token)
    {
        case TokenIntegerConstant: case TokenCharacterConstant: case TokenStringConstant: 
            Result->Typ = TypeInt;
            if (Token == TokenStringConstant)
                Result->Typ = TypeString;
            break;
        
        case TokenMinus:  case TokenUnaryExor: case TokenUnaryNot:
            ParseIntExpression(Lexer, Result, RunIt);
                
            if (RunIt)
            {
                switch(Token)
                {
                    case TokenMinus: Result->Val.Integer = -(Result->Val.Integer); break;
                    case TokenUnaryExor: Result->Val.Integer = ~(Result->Val.Integer); break;
                    case TokenUnaryNot: Result->Val.Integer = !(Result->Val.Integer); break;
                    default: break;
                }
            }
            break;

        case TokenOpenBracket:
            if (!ParseExpression(Lexer, Result, RunIt))
                ProgramFail(Lexer, "invalid expression");
            
            if (LexGetPlainToken(Lexer) != TokenCloseBracket)
                ProgramFail(Lexer, "')' expected");
            break;
                
        case TokenAsterisk:
        case TokenAmpersand:
            ProgramFail(Lexer, "not implemented");

        case TokenIdentifier:
            if (LexPeekPlainToken(Lexer) == TokenOpenBracket)
                ParseFunctionCall(Lexer, Result, &Result->Val.String, RunIt);
            else
            {
                if (RunIt)
                    VariableGet(Lexer, &Result->Val.String, Result, LValue);
            }
            break;
            
        default:
            *Lexer = PreState;
            return FALSE;
    }
    
    return TRUE;
}

/* parse an expression. operator precedence is not supported */
int ParseExpression(struct LexState *Lexer, struct Value *Result, int RunIt)
{
    struct Value CurrentValue;
    struct Value *CurrentLValue;
    struct Value TotalValue;
    struct Value *TotalLValue;
    
    if (!ParseValue(Lexer, &TotalValue, &TotalLValue, RunIt))
        return FALSE;
    
    while (TRUE)
    {
        enum LexToken Token = LexPeekToken(Lexer, &CurrentValue.Val);
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
                if (!ParseExpression(Lexer, &CurrentValue, RunIt))
                    ProgramFail(Lexer, "expression expected");
                
                if (RunIt)
                {
                    if (CurrentValue.Typ != TypeInt || TotalValue.Typ != TypeInt)
                        ProgramFail(Lexer, "can't assign");

                    switch (Token)
                    {
                        case TokenAddAssign: TotalValue.Val.Integer += CurrentValue.Val.Integer; break;
                        case TokenSubtractAssign: TotalValue.Val.Integer -= CurrentValue.Val.Integer; break;
                        default: TotalValue.Val.Integer = CurrentValue.Val.Integer; printf("---> %d\n", TotalValue.Val.Integer); break;
                    }
                    *TotalLValue = TotalValue;
                }
                // fallthrough
            
            default:
                if (RunIt)
                    *Result = TotalValue;
                return TRUE;
        }
        
        if (!ParseValue(Lexer, &CurrentValue, &CurrentLValue, RunIt))
            return FALSE;

        if (RunIt)
        {
            if (CurrentValue.Typ != TypeInt || TotalValue.Typ != TypeInt)
                ProgramFail(Lexer, "bad operand types");
        
            switch (Token)
            {
                case TokenPlus: TotalValue.Val.Integer += CurrentValue.Val.Integer; break;
                case TokenMinus: TotalValue.Val.Integer -= CurrentValue.Val.Integer; break;
                case TokenAsterisk: TotalValue.Val.Integer *= CurrentValue.Val.Integer; break;
                case TokenSlash: TotalValue.Val.Integer /= CurrentValue.Val.Integer; break;
                case TokenEquality: TotalValue.Val.Integer = TotalValue.Val.Integer == CurrentValue.Val.Integer; break;
                case TokenLessThan: TotalValue.Val.Integer = TotalValue.Val.Integer < CurrentValue.Val.Integer; break;
                case TokenGreaterThan: TotalValue.Val.Integer = TotalValue.Val.Integer > CurrentValue.Val.Integer; break;
                case TokenLessEqual: printf("compare %d <= %d\n", TotalValue.Val.Integer, CurrentValue.Val.Integer); TotalValue.Val.Integer = TotalValue.Val.Integer <= CurrentValue.Val.Integer; break;
                case TokenGreaterEqual: TotalValue.Val.Integer = TotalValue.Val.Integer >= CurrentValue.Val.Integer; break;
                case TokenLogicalAnd: TotalValue.Val.Integer = TotalValue.Val.Integer && CurrentValue.Val.Integer; break;
                case TokenLogicalOr: TotalValue.Val.Integer = TotalValue.Val.Integer || CurrentValue.Val.Integer; break;
                case TokenAmpersand: TotalValue.Val.Integer = TotalValue.Val.Integer & CurrentValue.Val.Integer; break;
                case TokenArithmeticOr: TotalValue.Val.Integer = TotalValue.Val.Integer | CurrentValue.Val.Integer; break;
                case TokenArithmeticExor: TotalValue.Val.Integer = TotalValue.Val.Integer ^ CurrentValue.Val.Integer; break;
                case TokenDot: ProgramFail(Lexer, "operator not supported"); break;
                default: break;
            }
        }
    }
    
    return TRUE;
}

/* parse an expression. operator precedence is not supported */
void ParseIntExpression(struct LexState *Lexer, struct Value *Result, int RunIt)
{
    if (!ParseExpression(Lexer, Result, RunIt))
        ProgramFail(Lexer, "expression expected");
    
    if (RunIt && Result->Typ != TypeInt)
        ProgramFail(Lexer, "integer value expected");
}

/* parse a function definition and store it for later */
void ParseFunctionDefinition(struct LexState *Lexer, Str *Identifier, struct LexState *PreState)
{
    struct Value FuncValue;

    if (FunctionStoreUsed >= FUNCTION_STORE_MAX)
        ProgramFail(Lexer, "too many functions defined");
    FunctionStore[FunctionStoreUsed] = *PreState;
    
    LexGetPlainToken(Lexer);
    if (LexGetPlainToken(Lexer) != TokenCloseBracket || LexPeekToken(Lexer, &FuncValue.Val) != TokenLeftBrace)
        ProgramFail(Lexer, "bad function definition");
    
    if (!ParseStatement(Lexer, FALSE))
        ProgramFail(Lexer, "function definition expected");
    
    FunctionStore[FunctionStoreUsed].End = Lexer->Pos;
    FuncValue.Typ = TypeFunction;
    FuncValue.Val.Integer = FunctionStoreUsed;
    FunctionStoreUsed++;
    
    if (!TableSet(&GlobalTable, Identifier, &FuncValue))
        ProgramFail(Lexer, "'%S' is already defined", Identifier);
}

/* parse a statement */
int ParseStatement(struct LexState *Lexer, int RunIt)
{
    struct Value Conditional;
    struct LexState PreState = *Lexer;
    union AnyValue LexerValue;
    enum ValueType Typ;
    enum LexToken Token = LexGetToken(Lexer, &LexerValue);
    
    printf("Token=%d\n", (int)Token);
    
    switch (Token)
    {
        case TokenEOF:
            return FALSE;
            
        case TokenIdentifier: 
            *Lexer = PreState;
            ParseExpression(Lexer, &Conditional, RunIt);
            break;
            
        case TokenLeftBrace:
            while (ParseStatement(Lexer, RunIt))
            {}
            
            if (LexGetPlainToken(Lexer) != TokenRightBrace)
                ProgramFail(Lexer, "'}' expected");
            break;
            
        case TokenIf:
            ParseIntExpression(Lexer, &Conditional, RunIt);
            
            if (!ParseStatement(Lexer, RunIt && Conditional.Val.Integer))
                ProgramFail(Lexer, "statement expected");
            
            if (LexPeekToken(Lexer, &LexerValue) == TokenElse)
            {
                LexGetToken(Lexer, &LexerValue);
                if (!ParseStatement(Lexer, RunIt && !Conditional.Val.Integer))
                    ProgramFail(Lexer, "statement expected");
            }
            break;
        
        case TokenWhile:
            {
                struct LexState PreConditional = *Lexer;
                do
                {
                    *Lexer = PreConditional;
                    ParseIntExpression(Lexer, &Conditional, RunIt);
                
                    if (!ParseStatement(Lexer, RunIt && Conditional.Val.Integer))
                        ProgramFail(Lexer, "statement expected");
                        
                } while (RunIt && Conditional.Val.Integer);                
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
                        
                    ParseIntExpression(Lexer, &Conditional, RunIt);
                
                } while (Conditional.Val.Integer && RunIt);           
            }
            break;
                
        case TokenFor:
            {
                struct LexState PreConditional;
                struct LexState PreIncrement;
                struct LexState PreStatement;
                struct LexState After;

                if (LexGetToken(Lexer, &LexerValue) != TokenOpenBracket)
                    ProgramFail(Lexer, "'(' expected");
                                    
                if (!ParseStatement(Lexer, RunIt))
                    ProgramFail(Lexer, "statement expected");
                
                PreConditional = *Lexer;
                ParseIntExpression(Lexer, &Conditional, RunIt);
                
                if (LexGetToken(Lexer, &LexerValue) != TokenSemicolon)
                    ProgramFail(Lexer, "';' expected");
                
                PreIncrement = *Lexer;
                ParseStatement(Lexer, FALSE);
                
                if (LexGetToken(Lexer, &LexerValue) != TokenCloseBracket)
                    ProgramFail(Lexer, "')' expected");
                
                PreStatement = *Lexer;
                if (!ParseStatement(Lexer, RunIt && Conditional.Val.Integer))
                    ProgramFail(Lexer, "statement expected");
                
                After = *Lexer;
                
                while (Conditional.Val.Integer && RunIt)
                {
                    *Lexer = PreIncrement;
                    ParseStatement(Lexer, TRUE);
                                    
                    *Lexer = PreConditional;
                    ParseIntExpression(Lexer, &Conditional, RunIt);
                    
                    if (Conditional.Val.Integer)
                    {
                        *Lexer = PreStatement;
                        ParseStatement(Lexer, TRUE);
                    }
                }
                
                *Lexer = After;
            }
            break;

        case TokenSemicolon: break;

        case TokenIntType:
        case TokenCharType:
        case TokenVoidType:
            *Lexer = PreState;
            ParseType(Lexer, &Typ);
            if (LexGetToken(Lexer, &LexerValue) != TokenIdentifier)
                ProgramFail(Lexer, "identifier expected");
                
            /* handle function definitions */
            if (LexPeekPlainToken(Lexer) == TokenOpenBracket)
                ParseFunctionDefinition(Lexer, &LexerValue.String, &PreState);
            else
            {
                struct Value InitValue;
                InitValue.Val.Integer = 0;
                InitValue.Typ = Typ;
                VariableDefine(Lexer, &LexerValue.String, &InitValue);
            }
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

