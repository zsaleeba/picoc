/* stdio.h library */
#include "picoc.h"

#ifndef NO_HASH_INCLUDE

void StdioFopen(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->NativePointer = fopen(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StdioFclose(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = fclose(Param[0]->Val->NativePointer);
}

void StdioFread(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = fread(Param[0]->Val->NativePointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->NativePointer);
}

void StdioFwrite(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = fwrite(Param[0]->Val->NativePointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->NativePointer);
}

void StdioFgetc(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = fgetc(Param[0]->Val->NativePointer);
}

void StdioFgets(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->NativePointer = fgets(Param[0]->Val->NativePointer, Param[1]->Val->Integer, Param[2]->Val->NativePointer);
}

const char StdioDefs[] = "\
typedef struct FILEStruct FILE; \
";

struct LibraryFunction StdioFunctions[] =
{
    { StdioFopen,   "FILE *fopen(char *, char *);" },
    { StdioFclose,  "int fclose(FILE *);" },
    { StdioFread,   "int fread(void *, int, int, FILE *);" },
    { StdioFwrite,  "int fwrite(void *, int, int, FILE *);" },
    { StdioFgetc,   "int fgetc(FILE *);" },
    { StdioFgetc,   "int getc(FILE *);" },
    { StdioFgets,   "char *fgets(char *, int, FILE *);" },
    { NULL,         NULL }
};

void StdioSetupFunc(void)
{
    /* make a "struct FILEStruct" which is the same size as a native FILE structure */
    TypeCreateOpaqueStruct(NULL, TableStrRegister("FILEStruct"), sizeof(FILE));
}

#endif /* NO_HASH_INCLUDE */
