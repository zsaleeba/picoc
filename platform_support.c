#include "picoc.h"

#ifdef UNIX_HOST
/* a source file we need to clean up */
static char *CleanupText = NULL;

/* deallocate any storage */
void PlatformCleanup()
{
    if (CleanupText != NULL)
        HeapFree(CleanupText);
}

/* get a line of interactive input */
char *PlatformGetLine(char *Buf, int MaxLen)
{
    fflush(stdout);
    return fgets(Buf, MaxLen, stdin);
}

/* write a character to the console */
void PlatformPutc(unsigned char OutCh)
{
    putchar(OutCh);
}

/* read a file into memory */
char *PlatformReadFile(const char *FileName)
{
    struct stat FileInfo;
    char *ReadText;
    FILE *InFile;
    int BytesRead;
    
    if (stat(FileName, &FileInfo))
        ProgramFail(NULL, "can't read file %s\n", FileName);
    
    ReadText = malloc(FileInfo.st_size + 1);
    if (ReadText == NULL)
        ProgramFail(NULL, "out of memory\n");
        
    InFile = fopen(FileName, "r");
    if (InFile == NULL)
        ProgramFail(NULL, "can't read file %s\n", FileName);
    
    BytesRead = fread(ReadText, 1, FileInfo.st_size, InFile);
    if (BytesRead == 0)
        ProgramFail(NULL, "can't read file %s\n", FileName);

    ReadText[BytesRead] = '\0';
    fclose(InFile);
    
    return ReadText;    
}

/* read and scan a file for definitions */
void PlatformScanFile(const char *FileName)
{
    char *SourceStr = PlatformReadFile(FileName);
    char *OrigCleanupText = CleanupText;
    if (CleanupText == NULL)
        CleanupText = SourceStr;

    Parse(FileName, SourceStr, strlen(SourceStr), TRUE);
    free(SourceStr);

    if (OrigCleanupText == NULL)
        CleanupText = NULL;
}

/* mark where to end the program for platforms which require this */
static jmp_buf ExitBuf;
int PlatformSetExitPoint()
{
    return setjmp(ExitBuf);
}

/* exit the program */
void PlatformExit()
{
    longjmp(ExitBuf, 1);
}
#endif

#ifdef SURVEYOR_HOST

/* deallocate any storage */
void PlatformCleanup()
{
}

/* get a line of interactive input */
char *PlatformGetLine(char *Buf, int MaxLen)
{
    int ix;
    char ch, *cp;
    
    ix = 0;
    cp = Buf;
    while (ix++ < MaxLen) {
        ch = getch();
        if (ch == 0x1B) { // ESC character - exit
            printf("leaving picoC\n\r");
            return NULL;
        }
        if (ch == '\n') {
            *cp++ = '\n';  // if newline, send newline character followed by null
            *cp = 0;
            return Buf;
        }
        *cp++ = ch;
        ix++;
    }
    return NULL;
}

/* write a character to the console */
void PlatformPutc(unsigned char OutCh)
{
    putchar(OutCh);
}

/* mark where to end the program for platforms which require this */
int PlatformSetExitPoint()
{
    return 0;
}

/* exit the program */
extern int errjmp[];

void PlatformExit()
{
    errjmp[40] = 1;
    longjmp(errjmp, 1);
}
#endif

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
