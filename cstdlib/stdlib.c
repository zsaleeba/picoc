/* stdlib.h library for large systems - small embedded systems use clibrary.c instead */
#include "../picoc.h"

#ifndef BUILTIN_MINI_STDLIB

static int ZeroValue = 0;

void StdlibMalloc(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = malloc(Param[0]->Val->Integer);
}

void StdlibCalloc(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = calloc(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

void StdlibRealloc(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = realloc(Param[0]->Val->NativePointer, Param[1]->Val->Integer);
}

void StdlibFree(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    free(Param[0]->Val->NativePointer);
}

/* all stdlib.h functions */
struct LibraryFunction StdlibFunctions[] =
{
    { StdlibMalloc,        "void *malloc(int);" },
    { StdlibCalloc,        "void *calloc(int,int);" },
    { StdlibRealloc,       "void *realloc(void *,int);" },
    { StdlibFree,          "void free(void *);" },
    { NULL,             NULL }
};

/* creates various system-dependent definitions */
void StdlibSetupFunc(void)
{
    /* define NULL */
    if (!VariableDefined(TableStrRegister("NULL")))
        VariableDefinePlatformVar(NULL, "NULL", &IntType, (union AnyValue *)&ZeroValue, FALSE);
}

#endif /* !BUILTIN_MINI_STDLIB */
