#include "../picoc.h"

/* list of all library functions and their prototypes */
struct LibraryFunction PlatformLibrary[] =
{
    { NULL,         NULL }
};

void PlatformLibraryInit()
{
    LibraryInit(&GlobalTable, "platform library", &PlatformLibrary);
}

