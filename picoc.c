#include "picoc.h"

/* initialise everything */
void Initialise()
{
    HeapInit();
    TableInit();
    VariableInit();
    LexInit();
    TypeInit();
    LibraryInit(&GlobalTable, "c library", &CLibrary);
    CLibraryInit();
    PlatformLibraryInit();
    LibraryInit(&GlobalTable, "platform library", &PlatformLibrary);
}

/* free memory */
void Cleanup()
{
    PlatformCleanup();
    ParseCleanup();
    LexCleanup();
    VariableCleanup();
    TypeCleanup();
    TableStrFree();
}

/* platform-dependent code for running programs is in this file */
#ifdef UNIX_HOST
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Format: picoc <program.c> - run a program\n        picoc -i          - interactive mode\n");
        exit(1);
    }
    
    Initialise();
    
    if (strcmp(argv[1], "-i") == 0)
        ParseInteractive();
    else
    {
        if (PlatformSetExitPoint())
        {
            Cleanup();
            return 1;
        }
        
        PlatformScanFile(argv[1]);
    }
    
    Cleanup();
    return 0;
}
#else
# ifdef SURVEYOR_HOST
int picoc(char *SourceStr)
{    
    int ix;
    
    Initialise();
    if (SourceStr) {
        for (ix=0; ix<strlen(SourceStr); ix++)  /* clear out ctrl-z from XMODEM transfer */
            if (SourceStr[ix] == 0x1A)
                SourceStr[ix] = 0x20;
        printf("%s\n\r", SourceStr);  /* display program source */
        printf("=====================\n");
    }
    ExitBuf[40] = 0;
    PlatformSetExitPoint();
    if (ExitBuf[40]) {
        printf("leaving picoC\n\r");
        Cleanup();
        return 1;
    }
        
    if (SourceStr)    
        Parse("test.c", SourceStr, strlen(SourceStr), TRUE);
    ParseInteractive();
    Cleanup();
    return 0;
}
# endif
#endif
