/* stdio.h library */
#include "picoc.h"

#ifndef NO_HASH_INCLUDE

static int EOFValue = EOF;
static int SEEK_SETValue = SEEK_SET;
static int SEEK_CURValue = SEEK_CUR;
static int SEEK_ENDValue = SEEK_END;


void StdioFopen(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->NativePointer = fopen(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StdioFreopen(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->NativePointer = freopen(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer, Param[2]->Val->NativePointer);
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

void StdioRemove(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = remove(Param[0]->Val->NativePointer);
}

void StdioRename(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = rename(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StdioRewind(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    rewind(Param[0]->Val->NativePointer);
}

void StdioTmpfile(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->NativePointer = tmpfile();
}

void StdioClearerr(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    clearerr(Param[0]->Val->NativePointer);
}

void StdioFeof(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = feof(Param[0]->Val->NativePointer);
}

void StdioFerror(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = ferror(Param[0]->Val->NativePointer);
}

void StdioFileno(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = fileno(Param[0]->Val->NativePointer);
}

void StdioFflush(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = fflush(Param[0]->Val->NativePointer);
}

void StdioFgetpos(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = fgetpos(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StdioFsetpos(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = fsetpos(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StdioFputc(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = fputc(Param[0]->Val->Integer, Param[1]->Val->NativePointer);
}

void StdioFputs(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = fputs(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StdioFtell(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = ftell(Param[0]->Val->NativePointer);
}

void StdioFseek(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = fseek(Param[0]->Val->NativePointer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

void StdioPerror(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    perror(Param[0]->Val->NativePointer);
}

void StdioPutc(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = putc(Param[0]->Val->Integer, Param[1]->Val->NativePointer);
}

void StdioPutchar(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = putchar(Param[0]->Val->Integer);
}

void StdioSetbuf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    setbuf(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StdioSetvbuf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    setvbuf(Param[0]->Val->NativePointer, Param[1]->Val->NativePointer, Param[2]->Val->Integer, Param[3]->Val->Integer);
}

void StdioUngetc(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = ungetc(Param[0]->Val->Integer, Param[1]->Val->NativePointer);
}

void StdioPuts(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = puts(Param[0]->Val->NativePointer);
}


const char StdioDefs[] = "\
typedef struct FILEStruct FILE; \
";

struct LibraryFunction StdioFunctions[] =
{
    { StdioFopen,   "FILE *fopen(char *, char *);" },
    { StdioFreopen, "FILE *freopen(char *, char *, FILE *);" },
    { StdioFclose,  "int fclose(FILE *);" },
    { StdioFread,   "int fread(void *, int, int, FILE *);" },
    { StdioFwrite,  "int fwrite(void *, int, int, FILE *);" },
    { StdioFgetc,   "int fgetc(FILE *);" },
    { StdioFgetc,   "int getc(FILE *);" },
    { StdioFgets,   "char *fgets(char *, int, FILE *);" },
    { StdioFputc,   "int fputc(int, FILE *);" },
    { StdioFputc,   "int fputs(char *, FILE *);" },
    { StdioRemove,  "int remove(char *);" },
    { StdioRename,  "int rename(char *, char *);" },
    { StdioRewind,  "void rewind(FILE *);" },
    { StdioTmpfile, "FILE *tmpfile();" },
    { StdioClearerr,"void clearerr(FILE *);" },
    { StdioFeof,    "int feof(FILE *);" },
    { StdioFerror,  "int ferror(FILE *);" },
    { StdioFileno,  "int fileno(FILE *);" },
    { StdioFflush,  "int fflush(FILE *);" },
    { StdioFgetpos, "int fgetpos(FILE *, int *pos);" },
    { StdioFsetpos, "int fsetpos(FILE *, int *pos);" },
    { StdioFtell,   "int ftell(FILE *);" },
    { StdioFseek,   "int fseek(FILE *, int, int);" },
    { StdioFsetpos, "int fsetpos(FILE *, int *);" },
    { StdioPerror,  "void perror(char *);" },
    { StdioPutc,    "int putc(char *, FILE *);" },
    { StdioPutchar, "int putchar(int);" },
    { StdioPutchar, "int fputchar(int);" },
    { StdioSetbuf,  "void setbuf(FILE *, char *);" },
    { StdioSetvbuf, "void setvbuf(FILE *, char *, int, int);" },
    { StdioUngetc,  "int ungetc(int, FILE *);" },
    { StdioPuts,    "int puts(char *);" },
    { NULL,         NULL }
};

void StdioSetupFunc(void)
{
    /* make a "struct FILEStruct" which is the same size as a native FILE structure */
    TypeCreateOpaqueStruct(NULL, TableStrRegister("FILEStruct"), sizeof(FILE));
    
    /* define EOF equal to the system EOF */
    VariableDefinePlatformVar(NULL, "EOF", &IntType, (union AnyValue *)&EOFValue, FALSE);
    VariableDefinePlatformVar(NULL, "SEEK_SET", &IntType, (union AnyValue *)&SEEK_SETValue, FALSE);
    VariableDefinePlatformVar(NULL, "SEEK_CUR", &IntType, (union AnyValue *)&SEEK_CURValue, FALSE);
    VariableDefinePlatformVar(NULL, "SEEK_END", &IntType, (union AnyValue *)&SEEK_ENDValue, FALSE);
}

#endif /* NO_HASH_INCLUDE */

/*
 TODO:
vprintf 	used to print to the standard output stream
fprintf, vfprintf 	used to print to a file
snprintf, vsprintf, vsnprintf 	used to print to a char array (C string)
scanf, vscanf 	used to input from the standard input stream
fscanf, vfscanf 	used to input from a file
sscanf, vsscanf 	used to input from a char array (e.g., a C string)
*/