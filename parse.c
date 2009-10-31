#include "picoc.h"

/* a chunk of heap-allocated tokens we should cleanup when we're done */
static void *CleanupTokens = NULL;

/* deallocate any memory */
void ParseCleanup()
{
    if (CleanupTokens != NULL)
        HeapFreeMem(CleanupTokens);
}

/* parse a statement, but only run it if Condition is TRUE */
enum ParseResult ParseStatementMaybeRun(struct ParseState *Parser, int Condition)
{
    if (Parser->Mode != RunModeSkip && !Condition)
    {
        enum RunMode OldMode = Parser->Mode;
        int Result;
        Parser->Mode = RunModeSkip;
        Result = ParseStatement(Parser);
        Parser->Mode = OldMode;
        return Result;
    }
    else
        return ParseStatement(Parser);
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

    if (TopStackFrame != NULL)
        ProgramFail(Parser, "nested function definitions are not allowed");
        
    LexGetToken(Parser, NULL, TRUE);  /* open bracket */
    ParamParser = *Parser;
    Token = LexGetToken(Parser, NULL, TRUE);
    if (Token != TokenCloseBracket && Token != TokenEOF)
    { 
        /* count the number of parameters */
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
    FuncValue->Val->FuncDef.ParamType = (struct ValueType **)((char *)FuncValue->Val + sizeof(struct FuncDef));
    FuncValue->Val->FuncDef.ParamName = (char **)((char *)FuncValue->Val->FuncDef.ParamType + sizeof(struct ValueType *) * ParamCount);
   
    for (ParamCount = 0; ParamCount < FuncValue->Val->FuncDef.NumParams; ParamCount++)
    { 
        /* harvest the parameters into the function definition */
        if (ParamCount == FuncValue->Val->FuncDef.NumParams-1 && LexGetToken(&ParamParser, NULL, FALSE) == TokenEllipsis)
        { 
            /* ellipsis at end */
            FuncValue->Val->FuncDef.NumParams--;
            FuncValue->Val->FuncDef.VarArgs = TRUE;
            break;
        }
        else
        { 
            /* add a parameter */
            TypeParse(&ParamParser, &ParamType, &ParamIdentifier);
            FuncValue->Val->FuncDef.ParamType[ParamCount] = ParamType;
            FuncValue->Val->FuncDef.ParamName[ParamCount] = ParamIdentifier;
        }
        
        Token = LexGetToken(&ParamParser, NULL, TRUE);
        if (Token != TokenComma && ParamCount < FuncValue->Val->FuncDef.NumParams-1)
            ProgramFail(&ParamParser, "comma expected");
    }
    
    if (FuncValue->Val->FuncDef.NumParams != 0 && Token != TokenCloseBracket && Token != TokenComma && Token != TokenEllipsis)
        ProgramFail(&ParamParser, "bad parameter");
    
    if (!IsPrototype)
    {
        if (LexGetToken(Parser, NULL, FALSE) != TokenLeftBrace)
            ProgramFail(Parser, "bad function definition");
        
        FuncBody = *Parser;
        if (ParseStatementMaybeRun(Parser, FALSE) != ParseResultOk)
            ProgramFail(Parser, "function definition expected");

        FuncValue->Val->FuncDef.Body = FuncBody;
        FuncValue->Val->FuncDef.Body.Pos = LexCopyTokens(&FuncBody, Parser);
    }
        
    if (!TableSet(&GlobalTable, Identifier, FuncValue))
        ProgramFail(Parser, "'%s' is already defined", Identifier);
    
    return FuncValue;
}

/* declare a variable or function */
int ParseDeclaration(struct ParseState *Parser, enum LexToken Token)
{
    char *Identifier;
    struct ValueType *BasicType;
    struct ValueType *Typ;
    struct Value *CValue;
    struct Value *NewVariable;

    TypeParseFront(Parser, &BasicType);
    do
    {
        TypeParseIdentPart(Parser, BasicType, &Typ, &Identifier);
        if ((Token != TokenVoidType && Token != TokenStructType && Token != TokenUnionType && Token != TokenEnumType) && Identifier == StrEmpty)
            ProgramFail(Parser, "identifier expected");
            
        if (Identifier != StrEmpty)
        {
            /* handle function definitions */
            if (LexGetToken(Parser, NULL, FALSE) == TokenOpenBracket)
            {
                ParseFunctionDefinition(Parser, Typ, Identifier, FALSE);
                return FALSE;
            }
            else
            {
                if (Typ == &VoidType && Identifier != StrEmpty)
                    ProgramFail(Parser, "can't define a void variable");
                    
                if (Parser->Mode == RunModeRun)
                    NewVariable = VariableDefine(Parser, Identifier, NULL, Typ, TRUE);
                
                if (LexGetToken(Parser, NULL, FALSE) == TokenAssign)
                {
                    /* we're assigning an initial value */
                    LexGetToken(Parser, NULL, TRUE);
                    if (!ExpressionParse(Parser, &CValue))
                        ProgramFail(Parser, "expression expected");
                        
                    if (Parser->Mode == RunModeRun)
                    {
                        ExpressionAssign(Parser, NewVariable, CValue, FALSE, NULL, 0, FALSE);
                        VariableStackPop(Parser, CValue);
                    }
                }
            }
        }
        
        Token = LexGetToken(Parser, NULL, FALSE);
        if (Token == TokenComma)
            LexGetToken(Parser, NULL, TRUE);
            
    } while (Token == TokenComma);
    
    return TRUE;
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
#ifdef FANCY_ERROR_REPORTING
    To->CharacterPos = From->CharacterPos;
#endif
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
                        
    if (ParseStatement(Parser) != ParseResultOk)
        ProgramFail(Parser, "statement expected");
    
    ParserCopyPos(&PreConditional, Parser);
    Condition = ExpressionParseInt(Parser);
    
    if (LexGetToken(Parser, NULL, TRUE) != TokenSemicolon)
        ProgramFail(Parser, "';' expected");
    
    ParserCopyPos(&PreIncrement, Parser);
    ParseStatementMaybeRun(Parser, FALSE);
    
    if (LexGetToken(Parser, NULL, TRUE) != TokenCloseBracket)
        ProgramFail(Parser, "')' expected");
    
    ParserCopyPos(&PreStatement, Parser);
    if (ParseStatementMaybeRun(Parser, Condition) != ParseResultOk)
        ProgramFail(Parser, "statement expected");
    
    if (Parser->Mode == RunModeContinue)
        Parser->Mode = RunModeRun;
        
    ParserCopyPos(&After, Parser);
        
    while (Condition && Parser->Mode == RunModeRun)
    {
        ParserCopyPos(Parser, &PreIncrement);
        ParseStatement(Parser);
                        
        ParserCopyPos(Parser, &PreConditional);
        Condition = ExpressionParseInt(Parser);
        
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

/* parse a block of code and return what mode it returned in */
enum RunMode ParseBlock(struct ParseState *Parser, int AbsorbOpenBrace, int Condition)
{
    if (AbsorbOpenBrace && LexGetToken(Parser, NULL, TRUE) != TokenLeftBrace)
        ProgramFail(Parser, "'{' expected");
    
    if (Parser->Mode != RunModeSkip && !Condition)
    { 
        /* condition failed - skip this block instead */
        enum RunMode OldMode = Parser->Mode;
        Parser->Mode = RunModeSkip;
        while (ParseStatement(Parser) == ParseResultOk)
        {}
        Parser->Mode = OldMode;
    }
    else
    { 
        /* just run it in its current mode */
        while (ParseStatement(Parser) == ParseResultOk)
        {}
    }
    
    if (LexGetToken(Parser, NULL, TRUE) != TokenRightBrace)
        ProgramFail(Parser, "'}' expected");
        
    return Parser->Mode;
}

/* parse a statement */
enum ParseResult ParseStatement(struct ParseState *Parser)
{
    struct Value *CValue;
    struct Value *LexerValue;
    int Condition;
    int CheckTrailingSemicolon = TRUE;
    struct ParseState PreState = *Parser;
    enum LexToken Token = LexGetToken(Parser, NULL, TRUE);
    
    switch (Token)
    {
        case TokenEOF:
            return ParseResultEOF;
            
        case TokenIdentifier: 
        case TokenAsterisk: 
            *Parser = PreState;
            ExpressionParse(Parser, &CValue);
            if (Parser->Mode == RunModeRun) 
                VariableStackPop(Parser, CValue);
            break;
            
        case TokenLeftBrace:
            ParseBlock(Parser, FALSE, TRUE);
            CheckTrailingSemicolon = FALSE;
            break;
            
        case TokenIf:
            if (LexGetToken(Parser, NULL, TRUE) != TokenOpenBracket)
                ProgramFail(Parser, "'(' expected");
                
            Condition = ExpressionParseInt(Parser);
            
            if (LexGetToken(Parser, NULL, TRUE) != TokenCloseBracket)
                ProgramFail(Parser, "')' expected");

            if (ParseStatementMaybeRun(Parser, Condition) != ParseResultOk)
                ProgramFail(Parser, "statement expected");
            
            if (LexGetToken(Parser, NULL, FALSE) == TokenElse)
            {
                LexGetToken(Parser, NULL, TRUE);
                if (ParseStatementMaybeRun(Parser, !Condition) != ParseResultOk)
                    ProgramFail(Parser, "statement expected");
            }
            CheckTrailingSemicolon = FALSE;
            break;
        
        case TokenWhile:
            {
                struct ParseState PreConditional;

                if (LexGetToken(Parser, NULL, TRUE) != TokenOpenBracket)
                    ProgramFail(Parser, "'(' expected");
                    
                ParserCopyPos(&PreConditional, Parser);
                do
                {
                    ParserCopyPos(Parser, &PreConditional);
                    Condition = ExpressionParseInt(Parser);
                    if (LexGetToken(Parser, NULL, TRUE) != TokenCloseBracket)
                        ProgramFail(Parser, "')' expected");
                    
                    if (ParseStatementMaybeRun(Parser, Condition) != ParseResultOk)
                        ProgramFail(Parser, "statement expected");
                    
                    if (Parser->Mode == RunModeContinue)
                        Parser->Mode = RunModeRun;
                    
                } while (Parser->Mode == RunModeRun && Condition);
                
                if (Parser->Mode == RunModeBreak)
                    Parser->Mode = RunModeRun;

                CheckTrailingSemicolon = FALSE;
            }
            break;
                
        case TokenDo:
            {
                struct ParseState PreStatement;
                ParserCopyPos(&PreStatement, Parser);
                do
                {
                    ParserCopyPos(Parser, &PreStatement);
                    if (ParseStatement(Parser) != ParseResultOk)
                        ProgramFail(Parser, "statement expected");
                
                    if (Parser->Mode == RunModeContinue)
                        Parser->Mode = RunModeRun;

                    if (LexGetToken(Parser, NULL, TRUE) != TokenWhile)
                        ProgramFail(Parser, "'while' expected");
                    
                    if (LexGetToken(Parser, NULL, TRUE) != TokenOpenBracket)
                        ProgramFail(Parser, "'(' expected");
                        
                    Condition = ExpressionParseInt(Parser);
                    if (LexGetToken(Parser, NULL, TRUE) != TokenCloseBracket)
                        ProgramFail(Parser, "')' expected");
                    
                } while (Condition && Parser->Mode == RunModeRun);           
                
                if (Parser->Mode == RunModeBreak)
                    Parser->Mode = RunModeRun;
            }
            break;
                
        case TokenFor:
            ParseFor(Parser);
            CheckTrailingSemicolon = FALSE;
            break;

        case TokenSemicolon: break;

        case TokenIntType:
        case TokenShortType:
        case TokenCharType:
        case TokenFloatType:
        case TokenDoubleType:
        case TokenVoidType:
        case TokenStructType:
        case TokenUnionType:
        case TokenEnumType:
        case TokenSignedType:
        case TokenUnsignedType:
            *Parser = PreState;
            CheckTrailingSemicolon = ParseDeclaration(Parser, Token);
            break;
        
        case TokenHashDefine:
            ParseMacroDefinition(Parser);
            CheckTrailingSemicolon = FALSE;
            break;
            
#ifndef NO_HASH_INCLUDE
        case TokenHashInclude:
            if (LexGetToken(Parser, &LexerValue, TRUE) != TokenStringConstant)
                ProgramFail(Parser, "\"filename.h\" expected");
            
#ifndef NATIVE_POINTERS
            PlatformScanFile(LexerValue->Val->Pointer.Segment->Val->Array.Data);
#else
            PlatformScanFile((char *)LexerValue->Val->NativePointer);
#endif
            CheckTrailingSemicolon = FALSE;
            break;
#endif

        case TokenSwitch:
            if (LexGetToken(Parser, NULL, TRUE) != TokenOpenBracket)
                ProgramFail(Parser, "'(' expected");
                
            Condition = ExpressionParseInt(Parser);
            
            if (LexGetToken(Parser, NULL, TRUE) != TokenCloseBracket)
                ProgramFail(Parser, "')' expected");
            
            if (LexGetToken(Parser, NULL, FALSE) != TokenLeftBrace)
                ProgramFail(Parser, "'{' expected");
            
            { 
                /* new block so we can store parser state */
                enum RunMode OldMode = Parser->Mode;
                int OldSearchLabel = Parser->SearchLabel;
                Parser->Mode = RunModeCaseSearch;
                Parser->SearchLabel = Condition;
                
                ParseBlock(Parser, TRUE, TRUE);
                
                Parser->Mode = OldMode;
                Parser->SearchLabel = OldSearchLabel;
            }

            CheckTrailingSemicolon = FALSE;
            break;

        case TokenCase:
            if (Parser->Mode == RunModeCaseSearch)
            {
                Parser->Mode = RunModeRun;
                Condition = ExpressionParseInt(Parser);
                Parser->Mode = RunModeCaseSearch;
            }
            else
                Condition = ExpressionParseInt(Parser);
                
            if (LexGetToken(Parser, NULL, TRUE) != TokenColon)
                ProgramFail(Parser, "':' expected");
            
            if (Parser->Mode == RunModeCaseSearch && Condition == Parser->SearchLabel)
                Parser->Mode = RunModeRun;

            CheckTrailingSemicolon = FALSE;
            break;
            
        case TokenDefault:
            if (LexGetToken(Parser, NULL, TRUE) != TokenColon)
                ProgramFail(Parser, "':' expected");
            
            if (Parser->Mode == RunModeCaseSearch)
                Parser->Mode = RunModeRun;
                
            CheckTrailingSemicolon = FALSE;
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
                if (!ExpressionParse(Parser, &CValue) && TopStackFrame->ReturnValue->Typ->Base != TypeVoid)
                    ProgramFail(Parser, "value required in return");
                    
                if (TopStackFrame->ReturnValue->Typ->Base != TypeVoid)
                {
                    ExpressionAssign(Parser, TopStackFrame->ReturnValue, CValue, TRUE, NULL, 0, FALSE);
                    VariableStackPop(Parser, CValue);
                }
                
                Parser->Mode = RunModeReturn;
            }
            else
                ExpressionParse(Parser, &CValue);
            break;
        
        case TokenDelete:
        {
            /* try it as a function or variable name to delete */
            if (LexGetToken(Parser, &LexerValue, TRUE) != TokenIdentifier)
                ProgramFail(Parser, "identifier expected");
                
            if (Parser->Mode == RunModeRun)
            { 
                /* delete this variable or function */
                CValue = TableDelete(&GlobalTable, LexerValue->Val->Identifier);

                if (CValue == NULL)
                    ProgramFail(Parser, "'%s' is not defined", LexerValue->Val->Identifier);
                
                VariableFree(CValue);
            }
            break;
        }
        
        default:
            *Parser = PreState;
            return ParseResultError;
    }
    
    if (CheckTrailingSemicolon && LexGetToken(Parser, NULL, FALSE) == TokenSemicolon)
        LexGetToken(Parser, NULL, TRUE);
    
    return ParseResultOk;
}

/* quick scan a source file for definitions */
void Parse(const char *FileName, const char *Source, int SourceLen, int RunIt)
{
    struct ParseState Parser;
    enum ParseResult Ok;
    
    void *OldCleanupTokens = CleanupTokens;
    void *Tokens = LexAnalyse(FileName, Source, SourceLen, NULL);
    if (OldCleanupTokens == NULL)
        CleanupTokens = Tokens;

    LexInitParser(&Parser, Source, Tokens, FileName, RunIt);

    do {
        Ok = ParseStatement(&Parser);
    } while (Ok == ParseResultOk);
    
    if (Ok == ParseResultError)
        ProgramFail(&Parser, "parse error");
    
    HeapFreeMem(Tokens);
    if (OldCleanupTokens == NULL)
        CleanupTokens = NULL;
}

/* parse interactively */
void ParseInteractive()
{
    struct ParseState Parser;
    enum ParseResult Ok;
    
    PlatformPrintf(INTERACTIVE_PROMPT_START);
    LexInitParser(&Parser, NULL, NULL, StrEmpty, TRUE);
    PlatformSetExitPoint();
    LexInteractiveClear(&Parser);

    do
    {
        LexInteractiveStatementPrompt();
        Ok = ParseStatement(&Parser);
        LexInteractiveCompleted(&Parser);
        
    } while (Ok == ParseResultOk);
    
    if (Ok == ParseResultError)
        ProgramFail(&Parser, "parse error");
    
    PlatformPrintf("\n");
}
