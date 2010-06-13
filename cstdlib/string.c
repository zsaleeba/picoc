/* string.h library for large systems - small embedded systems use clibrary.c instead */
#include "../picoc.h"

#ifndef BUILTIN_MINI_STDLIB

static int ZeroValue = 0;

void StringStrcpy(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = strcpy(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StringStrncpy(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = strncpy(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer, Param[2]->Val->Integer);
}

void StringStrcmp(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = strcmp(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StringStrncmp(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = strncmp(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer, Param[2]->Val->Integer);
}

void StringStrcat(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = strcat(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StringIndex(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = index(Param[0]->Val->NativePointer, Param[1]->Val->Integer);
}

void StringRindex(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = rindex(Param[0]->Val->NativePointer, Param[1]->Val->Integer);
}

void StringStrlen(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = strlen(Param[0]->Val->NativePointer);
}

void StringMemset(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    memset(Param[0]->Val->NativePointer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

void StringMemcpy(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    memcpy(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer, Param[2]->Val->Integer);
}

void StringMemcmp(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = memcmp(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer, Param[2]->Val->Integer);
}

/* all string.h functions */
struct LibraryFunction StringFunctions[] =
{
    { StringStrcpy,        "char *strcpy(char *,char *);" },
    { StringStrncpy,       "char *strncpy(char *,char *,int);" },
    { StringStrcmp,        "int strcmp(char *,char *);" },
    { StringStrncmp,       "int strncmp(char *,char *,int);" },
    { StringStrcat,        "char *strcat(char *,char *);" },
    { StringIndex,         "char *index(char *,int);" },
    { StringRindex,        "char *rindex(char *,int);" },
    { StringStrlen,        "int strlen(char *);" },
    { StringMemset,        "void *memset(void *,int,int);" },
    { StringMemcpy,        "void *memcpy(void *,void *,int);" },
    { StringMemcmp,        "int memcmp(void *,void *,int);" },
    { NULL,             NULL }
};

/* creates various system-dependent definitions */
void StringSetupFunc(void)
{
    /* define NULL */
    if (!VariableDefined(TableStrRegister("NULL")))
        VariableDefinePlatformVar(NULL, "NULL", &IntType, (union AnyValue *)&ZeroValue, FALSE);
}

#endif /* !BUILTIN_MINI_STDLIB */
