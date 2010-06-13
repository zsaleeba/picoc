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

void StringStrncat(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = strncat(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer, Param[2]->Val->Integer);
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
    ReturnValue->Val->NativePointer = memset(Param[0]->Val->NativePointer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

void StringMemcpy(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = memcpy(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer, Param[2]->Val->Integer);
}

void StringMemcmp(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = memcmp(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer, Param[2]->Val->Integer);
}

void StringMemmove(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = memmove(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer, Param[2]->Val->Integer);
}

void StringMemchr(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = memchr(Param[0]->Val->NativePointer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

void StringStrchr(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = strchr(Param[0]->Val->NativePointer, Param[1]->Val->Integer);
}

void StringStrrchr(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = strrchr(Param[0]->Val->NativePointer, Param[1]->Val->Integer);
}

void StringStrcoll(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = strcoll(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StringStrerror(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = strerror(Param[0]->Val->Integer);
}

void StringStrspn(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = strspn(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StringStrcspn(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = strcspn(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StringStrpbrk(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = strpbrk(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StringStrstr(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = strstr(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StringStrtok(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = strtok(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StringStrxfrm(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = strxfrm(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer, Param[2]->Val->Integer);
}

void StringStrdup(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = strdup(Param[0]->Val->NativePointer);
}

void StringStrtok_r(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->NativePointer = strtok_r(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer, Param[2]->Val->NativePointer);
}

/* all string.h functions */
struct LibraryFunction StringFunctions[] =
{
    { StringIndex,         "char *index(char *,int);" },
    { StringRindex,        "char *rindex(char *,int);" },
    { StringMemcpy,        "void *memcpy(void *,void *,int);" },
    { StringMemmove,       "void *memmove(void *,void *,int);" },
    { StringMemchr,        "void *memchr(char *,int,int);" },
    { StringMemcmp,        "int memcmp(void *,void *,int);" },
    { StringMemset,        "void *memset(void *,int,int);" },
    { StringStrcat,        "char *strcat(char *,char *);" },
    { StringStrncat,       "char *strncat(char *,char *,int);" },
    { StringStrchr,        "char *strchr(char *,int);" },
    { StringStrrchr,       "char *strrchr(char *,int);" },
    { StringStrcmp,        "int strcmp(char *,char *);" },
    { StringStrncmp,       "int strncmp(char *,char *,int);" },
    { StringStrcoll,       "int strcoll(char *,char *);" },
    { StringStrcpy,        "char *strcpy(char *,char *);" },
    { StringStrncpy,       "char *strncpy(char *,char *,int);" },
    { StringStrerror,      "char *strerror(int);" },
    { StringStrlen,        "int strlen(char *);" },
    { StringStrspn,        "int strspn(char *,char *);" },
    { StringStrcspn,       "int strcspn(char *,char *);" },
    { StringStrpbrk,       "char *strpbrk(char *,char *);" },
    { StringStrstr,        "char *strstr(char *,char *);" },
    { StringStrtok,        "char *strtok(char *,char *);" },
    { StringStrxfrm,       "int strxfrm(char *,char *,int);" },
    { StringStrdup,        "char *strdup(char *);" },
    { StringStrtok_r,      "char *strtok_r(char *,char *,char **);" },
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
