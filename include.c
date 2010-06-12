#include "picoc.h"

#ifndef NO_HASH_INCLUDE

/* a list of libraries we can include */
struct IncludeLibrary
{
    const char *IncludeName;
    void (*SetupFunction)(void);
    struct LibraryFunction (*FuncList)[];
    const char *SetupCSource;
};

struct IncludeLibrary IncludeLibInfo[] =
{
    { "stdio.h", 
        &StdioSetupFunc, 
        &StdioFunctions, 
        StdioDefs },
    { NULL, NULL, NULL, NULL }
};


/* include one of a number of predefined libraries, or perhaps an actual file */
void IncludeFile(char *FileName)
{
    struct IncludeLibrary *LInclude;
    
    /* scan for the include file name to see if it's in our list of predefined includes */
    for (LInclude = &IncludeLibInfo[0]; LInclude->IncludeName != NULL; LInclude++)
    {
        if (strcmp(LInclude->IncludeName, FileName) == 0)
        {
            /* found it - protect against multiple inclusion */
            if (!VariableDefined(FileName))
            {
                VariableDefine(NULL, FileName, NULL, &VoidType, FALSE);
                
                /* run an extra startup function if there is one */
                if (LInclude->SetupFunction != NULL)
                    (*LInclude->SetupFunction)();
                
                /* parse the setup C source code - may define types etc. */
                if (LInclude->SetupCSource != NULL)
                    Parse(FileName, LInclude->SetupCSource, strlen(LInclude->SetupCSource), TRUE);
                
                /* set up the library functions */
                if (LInclude->FuncList != NULL)
                    LibraryInit(&GlobalTable, FileName, LInclude->FuncList);
            }
            
            return;
        }
    }
    
    /* not a predefined file, read a real file */
    PlatformScanFile(FileName);
}

#endif /* NO_HASH_INCLUDE */
