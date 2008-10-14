#include <stdio.h>

#include "picoc.h"

/* the table of global definitions */
struct Table GlobalTable;
struct TableEntry GlobalHashTable[GLOBAL_TABLE_SIZE];



void ParseInit()
{
    TableInit(&GlobalTable, &GlobalHashTable[0], "global", GLOBAL_TABLE_SIZE);
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
        printf("token %d\n", (int)Token);
    }
}


void ParseCallFunction(const Str *FuncIdent, int argc, char **argv)
{
}



