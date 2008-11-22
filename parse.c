#include <stdio.h>

#include "picoc.h"

/* the table of global definitions */
struct Table GlobalTable;
struct TableEntry GlobalHashTable[GLOBAL_TABLE_SIZE];



void ParseInit()
{
    TableInit(&GlobalTable, &GlobalHashTable[0], "global", GLOBAL_TABLE_SIZE);
}

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
            if (!ParseExpression(Lexer, Result))
                ProgramFail(Lexer, "invalid expression");
            
            switch(Token)
            {
                case TokenMinus: Result = -Result; break;
                case TokenUnaryExor: Result = ~Result; break;
                case TokenUnaryNot: Result = !Result; break;
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
            ReadVariable(XXX);
            break;
            
        default:
            *Lexer = PreState;
            break;
    }
    
    return TRUE;
}

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
        }
    }
    
    return TRUE;
}


int ParseStatement(struct LexState *Lexer, int RunIt)
{
    int Conditional;
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
            if (!ParseIntExpression(Lexer, &Conditional))
                ProgramFail(Lexer, "expression expected");
            
            if (!ParseStatement(Lexer, RunIt && Conditional))
                ProgramFail(Lexer, "statement expected");
            
            if (LexPeekToken(Lexer) == TokenElse)
            {
                LexGetToken(Lexer);
                if (!ParseStatement(Lexer, RunIt && !Conditional))
                    ProgramFail(Lexer, "statement expected");
            }
            break;
        
        case TokenWhile:
            {
                struct LexState PreConditional = *Lexer;
                do
                {
                    *Lexer = PreConditional;
                    if (!ParseIntExpression(Lexer, &Conditional))
                        ProgramFail(Lexer, "expression expected");
                
                    if (!ParseStatement(Lexer, RunIt && Conditional))
                        ProgramFail(Lexer, "statement expected");
                        
                } while (Conditional && RunIt);                
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
                        
                    if (!ParseIntExpression(Lexer, &Conditional))
                        ProgramFail(Lexer, "expression expected");
                
                } while (Conditional && RunIt);           
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
                if (!ParseIntExpression(Lexer, &Conditional))
                    ProgramFail(Lexer, "expression expected");
                
                if (LexGetToken(Lexer) != TokenSemicolon)
                    ProgramFail(Lexer, "';' expected");
                
                PreIncrement = *Lexer;
                ParseStatement(Lexer, FALSE);
                
                if (LexGetToken(Lexer) != TokenCloseBracket)
                    ProgramFail(Lexer, "')' expected");
                
                PreStatement = *Lexer;
                if (!ParseStatement(Lexer, Conditional && RunIt))
                    ProgramFail(Lexer, "statement expected");
                
                After = *Lexer;
                
                while (Conditional && RunIt)
                {
                    *Lexer = PreIncrement;
                    ParseStatement(Lexer, TRUE);
                                    
                    *Lexer = PreConditional;
                    ParseIntExpression(Lexer, &Conditional);
                    
                    if (Conditional)
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
                
            DeclareVariable(Lexer, Lexer->Value.String);
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
    enum LexToken Token;
    struct LexState Lexer;
    
    LexInit(&Lexer, Source, FileName, 1);

    while (ParseStatement(Lexer, TRUE))
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



