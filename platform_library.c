#include "picoc.h"

void SayHello(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    PlatformPrintf("Hello\n");
}

void PrintInteger(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    PlatformPrintf("%d\n", Param[0]->Val->Integer);
}

#ifdef UNIX_HOST
void Random(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = random();
}
#endif

static int SomeVar = 42;
static int SomeArray[4];
void PlatformLibraryInit()
{
    struct ValueType *IntArrayType;
    
    VariableDefinePlatformVar(NULL, "somevar", &IntType, (union AnyValue *)&SomeVar, TRUE);
    
    IntArrayType = TypeGetMatching(NULL, &IntType, TypeArray, 4, NULL);
    SomeArray[0] = 12;
    SomeArray[1] = 34;
    SomeArray[2] = 56;
    SomeArray[3] = 78;
    VariableDefinePlatformVar(NULL, "somearray", IntArrayType, (union AnyValue *)&SomeArray, FALSE);
}

/* list of all library functions and their prototypes */
struct LibraryFunction PlatformLibrary[] =
{
    { SayHello,     "void sayhello()" },
    { PrintInteger, "void printint(int)" },
#ifdef UNIX_HOST
    { Random,       "int random()" },
#endif
    { NULL,         NULL }
};

