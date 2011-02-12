#include "picoc.h"

#define CALL_MAIN_NO_ARGS_RETURN_VOID "main();"
#define CALL_MAIN_WITH_ARGS_RETURN_VOID "main(__argc,__argv);"
#define CALL_MAIN_NO_ARGS_RETURN_INT "__exit_value = main();"
#define CALL_MAIN_WITH_ARGS_RETURN_INT "__exit_value = main(__argc,__argv);"

/* initialise everything */
void Initialise(int StackSize)
{
    BasicIOInit();
    HeapInit(StackSize);
    TableInit();
    VariableInit();
    LexInit();
    TypeInit();
#ifndef NO_HASH_INCLUDE
    IncludeInit();
#endif
#ifdef BUILTIN_MINI_STDLIB
    LibraryInit(&GlobalTable, "c library", &CLibrary[0]);
    CLibraryInit();
#endif
    PlatformLibraryInit();
}

/* free memory */
void Cleanup()
{
    PlatformCleanup();
#ifndef NO_HASH_INCLUDE
    IncludeCleanup();
#endif
    ParseCleanup();
    LexCleanup();
    VariableCleanup();
    TypeCleanup();
    TableStrFree();
    HeapCleanup();
}

/* platform-dependent code for running programs is in this file */
#ifdef UNIX_HOST
void CallMain(int argc, char **argv)
{
    /* check if the program wants arguments */
    struct Value *FuncValue = NULL;

    if (!VariableDefined(TableStrRegister("main")))
        ProgramFail(NULL, "main() is not defined");
        
    VariableGet(NULL, TableStrRegister("main"), &FuncValue);
    if (FuncValue->Typ->Base != TypeFunction)
        ProgramFail(NULL, "main is not a function - can't call it");

    if (FuncValue->Val->FuncDef.NumParams != 0)
    {
        /* define the arguments */
        VariableDefinePlatformVar(NULL, "__argc", &IntType, (union AnyValue *)&argc, FALSE);
        VariableDefinePlatformVar(NULL, "__argv", CharPtrPtrType, (union AnyValue *)&argv, FALSE);
    }

    if (FuncValue->Val->FuncDef.ReturnType == &VoidType)
    {
        if (FuncValue->Val->FuncDef.NumParams == 0)
            Parse("startup", CALL_MAIN_NO_ARGS_RETURN_VOID, strlen(CALL_MAIN_NO_ARGS_RETURN_VOID), TRUE, TRUE, FALSE);
        else
            Parse("startup", CALL_MAIN_WITH_ARGS_RETURN_VOID, strlen(CALL_MAIN_WITH_ARGS_RETURN_VOID), TRUE, TRUE, FALSE);
    }
    else
    {
        VariableDefinePlatformVar(NULL, "__exit_value", &IntType, (union AnyValue *)&ExitValue, TRUE);
    
        if (FuncValue->Val->FuncDef.NumParams == 0)
            Parse("startup", CALL_MAIN_NO_ARGS_RETURN_INT, strlen(CALL_MAIN_NO_ARGS_RETURN_INT), TRUE, TRUE, FALSE);
        else
            Parse("startup", CALL_MAIN_WITH_ARGS_RETURN_INT, strlen(CALL_MAIN_WITH_ARGS_RETURN_INT), TRUE, TRUE, FALSE);
    }
}

int main(int argc, char **argv)
{
    int ParamCount = 1;
    int DontRunMain = FALSE;
    int StackSize = getenv("STACKSIZE") ? atoi(getenv("STACKSIZE")) : STACK_SIZE;
    
    if (argc < 2)
    {
        printf("Format: picoc <csource1.c>... [- <arg1>...]    : run a program (calls main() to start it)\n"
               "        picoc -s <csource1.c>... [- <arg1>...] : script mode - runs the program without calling main()\n"
               "        picoc -i                               : interactive mode\n");
        exit(1);
    }
    
    Initialise(StackSize);
    
    if (strcmp(argv[ParamCount], "-s") == 0 || strcmp(argv[ParamCount], "-m") == 0)
    {
        DontRunMain = TRUE;
        IncludeAllSystemHeaders();
        ParamCount++;
    }
        
    if (argc > ParamCount && strcmp(argv[ParamCount], "-i") == 0)
    {
        IncludeAllSystemHeaders();
        ParseInteractive();
    }
    else
    {
        if (PlatformSetExitPoint())
        {
            Cleanup();
            return ExitValue;
        }
        
        for (; ParamCount < argc && strcmp(argv[ParamCount], "-") != 0; ParamCount++)
            PlatformScanFile(argv[ParamCount]);
        
        if (!DontRunMain)
            CallMain(argc - ParamCount, &argv[ParamCount]);
    }
    
    Cleanup();
    return ExitValue;
}
#else
# ifdef SURVEYOR_HOST
int picoc(char *SourceStr)
{    
    unsigned int i;
    unsigned int sl;
	
    Initialise(HEAP_SIZE);

	sl = strlen(SourceStr);
	if (SourceStr) 
	{
        for (i = 0; i < sl; i++)
		{
            if (SourceStr[i] == 0x1A)
			{
                SourceStr[i] = 0x20;
			}
		}
    }
    ExitBuf[40] = 0;
    PlatformSetExitPoint();
    if (ExitBuf[40]) {
        printf("leaving picoC\n\r");
        Cleanup();
        return ExitValue;
    }
        
    if (SourceStr)    
        Parse("nofile", SourceStr, strlen(SourceStr), TRUE, TRUE, FALSE);
    ParseInteractive();
    Cleanup();
    return ExitValue;
}
# endif
#endif
