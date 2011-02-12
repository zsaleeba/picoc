#include "../picoc.h"


/* deallocate any storage */
void PlatformCleanup()
{
}

/* get a line of interactive input */
char *PlatformGetLine(char *Buf, int MaxLen, const char *Prompt)
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
void PlatformPutc(unsigned char OutCh, union OutputStreamInfo *Stream)
{
    if (OutCh == '\n')
        putchar('\r');
        
    putchar(OutCh);
}

/* read a character */
int PlatformGetCharacter()
{
    return getch();
}

/* mark where to end the program for platforms which require this */
int ExitBuf[41];

/* exit the program */
void PlatformExit(int RetVal)
{
    ExitValue = RetVal;
    ExitBuf[40] = 1;
    longjmp(ExitBuf, 1);
}

