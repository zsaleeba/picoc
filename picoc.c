#include "picoc.h"

#define CALL_MAIN_NO_ARGS "main();"
#define CALL_MAIN_WITH_ARGS "main(__argc,__argv);"


/* initialise everything */
void Initialise()
{
    BasicIOInit();
    HeapInit();
    TableInit();
    VariableInit();
    LexInit();
    TypeInit();
    IncludeInit();
#ifdef BUILTIN_MINI_STDLIB
    LibraryInit(&GlobalTable, "c library", &CLibrary);
    CLibraryInit();
#endif
    PlatformLibraryInit();
}

/* free memory */
void Cleanup()
{
    PlatformCleanup();
    IncludeCleanup();
    ParseCleanup();
    LexCleanup();
    VariableCleanup();
    TypeCleanup();
    TableStrFree();
}

/* platform-dependent code for running programs is in this file */
#ifdef UNIX_HOST
void CallMain(int argc, char **argv)
{
    /* check if the program wants arguments */
    struct Value *FuncValue;

    VariableGet(NULL, TableStrRegister("main"), &FuncValue);
    if (FuncValue->Typ->Base != TypeFunction)
        ProgramFail(NULL, "main is not a function - can't call it");

    if (FuncValue->Val->FuncDef.NumParams == 0)
        Parse("", CALL_MAIN_NO_ARGS, strlen(CALL_MAIN_NO_ARGS), TRUE);
    else
    {
        /* define the arguments */
        VariableDefinePlatformVar(NULL, "__argc", &IntType, (union AnyValue *)&argc, FALSE);
        VariableDefinePlatformVar(NULL, "__argv", CharPtrPtrType, (union AnyValue *)&argv, FALSE);

        Parse("", CALL_MAIN_WITH_ARGS, strlen(CALL_MAIN_WITH_ARGS), TRUE);
    }
}

int main(int argc, char **argv)
{
    int ParamCount = 1;
    int DontRunMain = FALSE;
    
    if (argc < 2)
    {
        printf("Format: picoc <csource1.c>... [- <arg1>...]    : run a program (calls main() to start it)\n"
               "        picoc -m <csource1.c>... [- <arg1>...] : run a program without calling main()\n"
               "        picoc -i                               : interactive mode\n");
        exit(1);
    }
    
    Initialise();
    
    if (strcmp(argv[ParamCount], "-m") == 0)
    {
        DontRunMain = TRUE;
        ParamCount++;
    }
        
    if (strcmp(argv[ParamCount], "-i") == 0)
        ParseInteractive();
    else
    {
        if (PlatformSetExitPoint())
        {
            Cleanup();
            return 1;
        }
        
        for (; ParamCount < argc && strcmp(argv[ParamCount], "-") != 0; ParamCount++)
            PlatformScanFile(argv[ParamCount]);
        
        if (!DontRunMain)
            CallMain(argc - ParamCount, &argv[ParamCount]);
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
        /*printf("%s\n\r", SourceStr);*/  /* display program source */
        /*printf("=====================\n");*/
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
# else
#  ifdef SRV1_UNIX_HOST
/*
 * Howard - this was my guess at what might suit you.
 * Please feel free to change this to whatever type of main function suits you best 
 */
int picoc(char *SourceFile, int Interactive)
{    
    Initialise();
    
    if (Interactive)
        ParseInteractive();
    else
    {
        if (PlatformSetExitPoint())
        {
            Cleanup();
            return 1;
        }
        
        PlatformScanFile(SourceFile);
    }
    
    Cleanup();
    return 0;
}
#  endif
# endif
#endif

