#include <stdio.h>

#include "picoc.h"

/* the table of global definitions */
struct Table GlobalTable;
struct TableEntry GlobalHashTable[GLOBAL_TABLE_SIZE];



void ParseInit()
{
    TableInit(&GlobalTable, &GlobalHashTable[0], "global", GLOBAL_TABLE_SIZE);
}

/* parse and run some code */
void ParseRun(const Str *FileName, const Str *Source, int LineNo)
{
    enum LexToken Token;
    struct LexState Lexer;
    int ParseDepth = 0;
    int IntValue;
    
    LexInit(&Lexer, Source, FileName, 1);
    
    while ( (Token = LexGetToken(&Lexer)) != TokenEOF)
    {
        /* do parsey things here */
        StrPrintf("token %d\n", (int)Token);
        
        switch (ParseDepth)
        {
        case 0: /* top level */
            if (Token == XXX
            break;
        
        case X: /* primary expression */
            switch (Token)
            {
                case TokenIdentifier:       IntValue = XXX; GoUp = TRUE; break;
                case TokenIntegerConstant:  IntValue = Lexer->Value.Integer; GoUp = TRUE; break;
                case TokenStringConstant:   StringValue = Lexer->Value.String; GoUp = TRUE; break;
                case TokenOpenBracket:
        }
    }
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



