#include "picoc.h"

void SayHello(struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    PlatformPrintf("Hello\n");
}

void PrintInteger(struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    PlatformPrintf("%d\n", Param[0]->Val->Integer);
}

#ifdef UNIX_HOST
void Random(struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = random();
}
#endif

/* list of all library functions and their prototypes */
struct LibraryFunction PlatformLibrary[] =
{
    { SayHello,     "void sayhello()" },
    { PrintInteger, "void printint(int)" },
#ifdef UNIX_HOST
    { Random,           "int random()" },
#endif
    { NULL,         NULL }
};

