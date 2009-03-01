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
    LibraryInit(&GlobalTable, "platform library", &PlatformLibrary);
    PlatformLibraryInit();
}

/* platform-dependent code for running programs is in this file */
#ifdef UNIX_HOST
int main(int argc, char **argv)
{
    if (argc < 2)
        ProgramFail(NULL, "Format: picoc <program.c> <args>...\n");
    
    Initialise();
    if (PlatformSetExitPoint())
        return 1;
    
    PlatformScanFile(argv[1]);
    
    return 0;
}
#else
# ifdef SURVEYOR_HOST
static char *SourceStr = "\n\
int Count;\n\
\n\
printf(\"This is a test program\n\");\n\
for (Count = 1; Count <= 10; Count++)\n\
    printf(\"%d\n\", Count);\n\
";

int errjmp[41];

int picoc()
{
   Initialise();

   errjmp[40] = 0;
   setjmp(errjmp);
   if (errjmp[40]) {
       printf("\n\rgoodbye ...\n\r");
       return 1;
   }

   Parse("test.c", SourceStr, strlen(SourceStr), TRUE);
   return 0;
}
# endif
#endif
