#include "picoc.h"

/* initialise everything */
void Initialise()
{
    HeapInit();
    TableInit();
    VariableInit();
    LexInit();
    VariableInit();
    TypeInit();
    LibraryInit(&GlobalTable, "c library", &CLibrary);
    LibraryInit(&GlobalTable, "platform library", &PlatformLibrary);
}

/* platform-dependent code for running programs is in this file */
#ifdef UNIX_HOST
int main(int argc, char **argv)
{
    if (argc < 2)
        ProgramFail(NULL, "Format: picoc <program.c> <args>...\n");
    
    Initialise();
    PlatformScanFile(argv[1]);
    
    return 0;
}
#else
# ifdef SURVEYOR_HOST
static char *SourceStr = "\
printf(\"This is a test program\n\");\
for (Count = 1; Count <= 10; Count++)\
    printf(\"%d\n\");\
";

int main(int argc, char **argv)
{    
    Initialise();
    Parse("test.c", SourceStr, strlen(SourceStr), TRUE);
    return 0;
}
# endif
#endif
