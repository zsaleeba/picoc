#include <stdio.h>
#include <string.h>

#include "picoc.h"

/* the table of global definitions */
struct Table GlobalTable;
struct TableEntry GlobalHashTable[GLOBAL_TABLE_SIZE];


/* local prototypes */
int ParseExpression(struct LexState *Lexer, struct Value *Result);
void ParseIntExpression(struct LexState *Lexer, struct Value *Result);


/* initialise the parser */
void ParseInit()
{
    TableInit(&GlobalTable, &GlobalHashTable[0], "global", GLOBAL_TABLE_SIZE);
}

/* define a variable */
void VariableDefine(struct LexState *Lexer, const Str *Ident, enum ValueType Typ)
{
    struct Value NewValue;
    
    memset(&NewValue, '\0', sizeof(NewValue));
    NewValue.Typ = Typ;
    if (!TableSet(&GlobalTable, Ident, &NewValue, FALSE))
        ProgramFail(Lexer, "'%S' is already defined", Ident);
}

/* set the value of a variable */
void VariableSet(struct LexState *Lexer, Str *Ident, struct Value *Val)
{
    if (!TableSet(&GlobalTable, Ident, Val, TRUE))
        ProgramFail(Lexer, "'%S' is undefined", Ident);
}

/* get the value of a variable. must be defined */
void VariableGet(struct LexState *Lexer, Str *Ident, struct Value *Val)
{
    struct Value *ValPos;
    
    if (!TableGet(&GlobalTable, Ident, &ValPos))
        ProgramFail(Lexer, "'%S' is undefined", Ident);

    *Val = *ValPos;
}

/* parse a single value */
int ParseValue(struct LexState *Lexer, struct Value *Result)
{
    struct LexState PreState = *Lexer;
    enum LexToken Token = LexGetToken(Lexer);
    
    switch (Token)
    {
        case TokenIntegerConstant: case TokenCharacterConstant: case TokenStringConstant: 
            Result->Typ = TypeInt;
            Result->Val = Lexer->Value;
            if (Token == TokenStringConstant)
                Result->Typ = TypeString;
            break;
        
        case TokenMinus:  case TokenUnaryExor: case TokenUnaryNot:
            ParseIntExpression(Lexer, Result);
                
            switch(Token)
            {
                case TokenMinus: Result->Val.Integer = -(Result->Val.Integer); break;
                case TokenUnaryExor: Result->Val.Integer = ~(Result->Val.Integer); break;
                case TokenUnaryNot: Result->Val.Integer = !(Result->Val.Integer); break;
                default: break;
            }
            break;

        case TokenOpenBracket:
            if (!ParseExpression(Lexer, Result))
                ProgramFail(Lexer, "invalid expression");
            
            if (LexGetToken(Lexer) != TokenCloseBracket)
                ProgramFail(Lexer, "')' expected");
            break;
                
        case TokenAsterisk:
        case TokenAmpersand:
            ProgramFail(Lexer, "not implemented");

        case TokenIdentifier:
            VariableGet(Lexer, &Lexer->Value.String, Result);
            break;
            
        default:
            *Lexer = PreState;
            break;
    }
    
    return TRUE;
}

/* parse an expression. operator precedence is not supported */
int ParseExpression(struct LexState *Lexer, struct Value *Result)
{
    struct Value CurrentValue;
    struct Value TotalValue;
    
    if (!ParseValue(Lexer, &TotalValue))
        return FALSE;
    
    while (TRUE)
    {
        enum LexToken Token = LexPeekToken(Lexer);
        switch (Token)
        {
            case TokenPlus: case TokenMinus: case TokenAsterisk: case TokenSlash:
            case TokenEquality: case TokenLessThan: case TokenGreaterThan:
            case TokenLessEqual: case TokenGreaterEqual: case TokenLogicalAnd:
            case TokenLogicalOr: case TokenArithmeticOr: case TokenArithmeticExor:
            case TokenDot:
                LexGetToken(Lexer);
                break;
            
            default:
                *Result = TotalValue;
                return TRUE;
        }
        
        if (!ParseValue(Lexer, &CurrentValue))
            return FALSE;
        
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
            case TokenLessEqual: TotalValue.Val.Integer = TotalValue.Val.Integer <= CurrentValue.Val.Integer; break;
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
    
    return TRUE;
}

/* parse an expression. operator precedence is not supported */
void ParseIntExpression(struct LexState *Lexer, struct Value *Result)
{
    if (!ParseExpression(Lexer, Result))
        ProgramFail(Lexer, "expression expected");
    
    if (Result->Typ != TypeInt)
        ProgramFail(Lexer, "integer value expected");
}

/* parse a statement which starts with an identifier - either an function or an assignment */
int ParseIdentStatement(struct LexState *Lexer, int RunIt)
{
    /* XXX */
    return FALSE;
}

/* parse a statement */
int ParseStatement(struct LexState *Lexer, int RunIt)
{
    struct Value Conditional;
    struct LexState PreState = *Lexer;
    enum LexToken Token = LexGetToken(Lexer);
    
    switch (Token)
    {
        case TokenIdentifier: 
            ParseIdentStatement(&PreState, RunIt);
            break;
            
        case TokenLeftBrace:
            while (ParseStatement(Lexer, RunIt))
            {}
            
            if (LexGetToken(Lexer) != TokenRightBrace)
                ProgramFail(Lexer, "'}' expected");
            break;
            
        case TokenIf:
            ParseIntExpression(Lexer, &Conditional);
            
            if (!ParseStatement(Lexer, RunIt && Conditional.Val.Integer))
                ProgramFail(Lexer, "statement expected");
            
            if (LexPeekToken(Lexer) == TokenElse)
            {
                LexGetToken(Lexer);
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
                    ParseIntExpression(Lexer, &Conditional);
                
                    if (!ParseStatement(Lexer, RunIt && Conditional.Val.Integer))
                        ProgramFail(Lexer, "statement expected");
                        
                } while (Conditional.Val.Integer && RunIt);                
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
                        
                    ParseIntExpression(Lexer, &Conditional);
                
                } while (Conditional.Val.Integer && RunIt);           
            }
            break;
                
        case TokenFor:
            {
                struct LexState PreConditional;
                struct LexState PreIncrement;
                struct LexState PreStatement;
                struct LexState After;

                if (LexGetToken(Lexer) != TokenOpenBracket)
                    ProgramFail(Lexer, "'(' expected");
                                    
                if (!ParseStatement(Lexer, RunIt))
                    ProgramFail(Lexer, "statement expected");
                
                PreConditional = *Lexer;
                ParseIntExpression(Lexer, &Conditional);
                
                if (LexGetToken(Lexer) != TokenSemicolon)
                    ProgramFail(Lexer, "';' expected");
                
                PreIncrement = *Lexer;
                ParseStatement(Lexer, FALSE);
                
                if (LexGetToken(Lexer) != TokenCloseBracket)
                    ProgramFail(Lexer, "')' expected");
                
                PreStatement = *Lexer;
                if (!ParseStatement(Lexer, Conditional.Val.Integer && RunIt))
                    ProgramFail(Lexer, "statement expected");
                
                After = *Lexer;
                
                while (Conditional.Val.Integer && RunIt)
                {
                    *Lexer = PreIncrement;
                    ParseStatement(Lexer, TRUE);
                                    
                    *Lexer = PreConditional;
                    ParseIntExpression(Lexer, &Conditional);
                    
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
            if (LexGetToken(Lexer) != TokenIdentifier)
                ProgramFail(Lexer, "identifier expected");
                
            VariableDefine(Lexer, &Lexer->Value.String, (Token == TokenVoidType) ? TypeVoid : TypeInt);
            break;
            
        default:
            *Lexer = PreState;
            return FALSE;
    }
    
    return TRUE;
}

/* parse and run some code */
void ParseRun(const Str *FileName, const Str *Source, int LineNo)
{
    struct LexState Lexer;
    
    LexInit(&Lexer, Source, FileName, 1);

    while (ParseStatement(&Lexer, TRUE))
    {}
}

/* quick scan a source file for definitions */
void ParseScan(const Str *FileName, const Str *Source)
{
    enum LexToken Token;
    struct LexState Lexer;
    
    LexInit(&Lexer, Source, FileName, 1);
    
    while ( (Token = LexGetToken(&Lexer)) != TokenEOF)
    {
        /* do parsey things here */
        StrPrintf("token %d\n", (int)Token);
    }
}

void ParseCallFunction(const Str *FuncIdent, int argc, char **argv)
{
}



