#include "picoc.h"


/* exit with a message */
void ProgramFail(struct ParseState *Parser, const char *Message, ...)
{
    va_list Args;

    if (Parser != NULL)
        PlatformPrintf("%s:%d: ", Parser->FileName, Parser->Line);   
        
    va_start(Args, Message);
    PlatformVPrintf(Message, Args);
    PlatformPrintf("\n");
    PlatformExit(1);
}

/* exit lexing with a message */
void LexFail(struct LexState *Lexer, const char *Message, ...)
{
    va_list Args;

    PlatformPrintf("%s:%d: ", Lexer->FileName, Lexer->Line);      
    va_start(Args, Message);
    PlatformVPrintf(Message, Args);
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
            case 's': PrintStr(va_arg(Args, char *), PlatformPutc); break;
            case 'd': PrintInt(va_arg(Args, int), PlatformPutc); break;
            case 'c': PlatformPutc(va_arg(Args, int)); break;
#ifndef NO_FP
            case 'f': PrintFP(va_arg(Args, double), PlatformPutc); break;
#endif
            case '%': PlatformPutc('%'); break;
            case '\0': FPos--; break;
            }
        }
        else
            PlatformPutc(*FPos);
    }
}
