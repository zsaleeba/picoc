#include "picoc.h"

#ifdef FANCY_ERROR_REPORTING
void PrintSourceTextErrorLine(const char *FileName, const char *SourceText, int Line, int CharacterPos)
{
    int LineCount;
    const char *LinePos;
    const char *CPos;
    int CCount;
    
    if (SourceText != NULL)
    {
        /* find the source line */
        for (LinePos = SourceText, LineCount = 1; *LinePos != '\0' && LineCount < Line; LinePos++)
        {
            if (*LinePos == '\n')
                LineCount++;
        }
        
        /* display the line */
        for (CPos = LinePos; *CPos != '\n' && *CPos != '\0'; CPos++)
            PrintCh(*CPos, &CStdOut);
        PrintCh('\n', &CStdOut);
        
        /* display the error position */
        for (CPos = LinePos, CCount = 0; *CPos != '\n' && *CPos != '\0' && (CCount < CharacterPos || *CPos == ' '); CPos++, CCount++)
        {
            if (*CPos == '\t')
                PrintCh('\t', &CStdOut);
            else
                PrintCh(' ', &CStdOut);
        }
    }
    else
    {
        /* assume we're in interactive mode - try to make the arrow match up with the input text */
        for (CCount = 0; CCount < CharacterPos + strlen(INTERACTIVE_PROMPT_STATEMENT); CCount++)
            PrintCh(' ', &CStdOut);
    }
    PlatformPrintf("^\n%s:%d: ", FileName, Line, CharacterPos);
    
}
#endif

/* exit with a message */
void ProgramFail(struct ParseState *Parser, const char *Message, ...)
{
    va_list Args;

    if (Parser != NULL)
#ifdef FANCY_ERROR_REPORTING
        PrintSourceTextErrorLine(Parser->FileName, Parser->SourceText, Parser->Line, Parser->CharacterPos);
#else
        PlatformPrintf("%s:%d: ", Parser->FileName, Parser->Line);   
#endif
        
    va_start(Args, Message);
    PlatformVPrintf(Message, Args);
    va_end(Args);
    PlatformPrintf("\n");
    PlatformExit(1);
}

/* like ProgramFail() but gives descriptive error messages for assignment */
void AssignFail(struct ParseState *Parser, const char *Format, struct ValueType *Type1, struct ValueType *Type2, int Num1, int Num2, const char *FuncName, int ParamNo)
{
    if (Parser != NULL)
#ifdef FANCY_ERROR_REPORTING
        PrintSourceTextErrorLine(Parser->FileName, Parser->SourceText, Parser->Line, Parser->CharacterPos);
#else
        PlatformPrintf("%s:%d: ", Parser->FileName, Parser->Line);   
#endif
        
    PlatformPrintf("can't %s ", (FuncName == NULL) ? "assign" : "set");   
        
    if (Type1 != NULL)
        PlatformPrintf(Format, Type1, Type2);
    else
        PlatformPrintf(Format, Num1, Num2);
    
    if (FuncName != NULL)
        PlatformPrintf(" in argument %d of call to %s()", ParamNo, FuncName);
        
    ProgramFail(NULL, "");
}

/* exit lexing with a message */
void LexFail(struct LexState *Lexer, const char *Message, ...)
{
    va_list Args;

#ifdef FANCY_ERROR_REPORTING
    PrintSourceTextErrorLine(Lexer->FileName, Lexer->SourceText, Lexer->Line, Lexer->CharacterPos);
#else
    PlatformPrintf("%s:%d: ", Lexer->FileName, Lexer->Line);  
#endif

    va_start(Args, Message);
    PlatformVPrintf(Message, Args);
    va_end(Args);
    PlatformPrintf("\n");
    PlatformExit(1);
}

/* printf for compiler error reporting */
void PlatformPrintf(const char *Format, ...)
{
    va_list Args;
    
    va_start(Args, Format);
    PlatformVPrintf(Format, Args);
    va_end(Args);
}

void PlatformVPrintf(const char *Format, va_list Args)
{
    const char *FPos;
    
    for (FPos = Format; *FPos != '\0'; FPos++)
    {
        if (*FPos == '%')
        {
            FPos++;
            switch (*FPos)
            {
            case 's': PrintStr(va_arg(Args, char *), &CStdOut); break;
            case 'd': PrintInt(va_arg(Args, int), 0, FALSE, FALSE, &CStdOut); break;
            case 'c': PrintCh(va_arg(Args, int), &CStdOut); break;
            case 't': PrintType(va_arg(Args, struct ValueType *), &CStdOut); break;
#ifndef NO_FP
            case 'f': PrintFP(va_arg(Args, double), &CStdOut); break;
#endif
            case '%': PrintCh('%', &CStdOut); break;
            case '\0': FPos--; break;
            }
        }
        else
            PrintCh(*FPos, &CStdOut);
    }
}
