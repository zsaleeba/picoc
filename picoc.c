#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "picoc.h"

/* all platform-dependent code is in this file */

void ProgramFail(struct ParseState *Parser, const char *Message, ...)
{
    va_list Args;

    if (Parser != NULL)
        IntrinsicHostPrintf("%s:%d: ", Parser->FileName, Parser->Line);   
        
    va_start(Args, Message);
    IntrinsicHostVPrintf(Message, Args);
    IntrinsicHostPrintf("\n");
    exit(1);
}

/* exit with a message */
void LexFail(struct LexState *Lexer, const char *Message, ...)
{
    va_list Args;

    IntrinsicHostPrintf("%s:%d: ", Lexer->FileName, Lexer->Line);      
    va_start(Args, Message);
    IntrinsicHostVPrintf(Message, Args);
    IntrinsicHostPrintf("\n");
    exit(1);
}

/* read a file into memory */
char *ReadFile(const char *FileName)
{
    struct stat FileInfo;
    char *ReadText;
    FILE *InFile;
    
    if (stat(FileName, &FileInfo))
        ProgramFail(NULL, "can't read file %s\n", FileName);
    
    ReadText = malloc(FileInfo.st_size + 1);
    if (ReadText == NULL)
        ProgramFail(NULL, "out of memory\n");
        
    InFile = fopen(FileName, "r");
    if (InFile == NULL)
        ProgramFail(NULL, "can't read file %s\n", FileName);
    
    if (fread(ReadText, 1, FileInfo.st_size, InFile) != FileInfo.st_size)
        ProgramFail(NULL, "can't read file %s\n", FileName);

    ReadText[FileInfo.st_size] = '\0';
    fclose(InFile);
    
    return ReadText;    
}

/* read and scan a file for definitions */
void ScanFile(const char *FileName)
{
    char *SourceStr = ReadFile(FileName);
    Parse(FileName, SourceStr, strlen(SourceStr), TRUE);
    free(SourceStr);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        ProgramFail(NULL, "Format: picoc <program.c> <args>...\n");
    
    HeapInit();
    TableInit();
    VariableInit();
    LexInit();
    ParseInit();
    
    ScanFile(argv[1]);
    
    return 0;
}
