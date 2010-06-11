/* stdio.h library */
#include <errno.h>
#include "picoc.h"

#ifndef BUILTIN_MINI_STDLIB

#define MAX_FORMAT 80

FILE *CStdOut;

static int EOFValue = EOF;
static int SEEK_SETValue = SEEK_SET;
static int SEEK_CURValue = SEEK_CUR;
static int SEEK_ENDValue = SEEK_END;
static int BUFSIZValue = BUFSIZ;
static int FILENAME_MAXValue = FILENAME_MAX;
static int _IOFBFValue = _IOFBF;
static int _IOLBFValue = _IOLBF;
static int _IONBFValue = _IONBF;
static int L_tmpnamValue = L_tmpnam;
static int GETS_MAXValue = 255;     /* arbitrary maximum size of a gets() file */

typedef struct StdOutStreamStruct
{
    FILE *FilePtr;
    char *StrOutPtr;
    int StrOutLen;
    int CharCount;
    
} StdOutStream;

struct StdVararg
{
    struct Value **Param;
    int NumArgs;
};


void BasicIOInit()
{
    CStdOut = stdout;
}

void StdioOutPutc(int OutCh, StdOutStream *Stream)
{
    if (Stream->FilePtr != NULL)
    {
        /* output to stdio stream */
        putc(OutCh, Stream->FilePtr);
        Stream->CharCount++;
    }
    else if (Stream->StrOutLen < 0 || Stream->StrOutLen > 1)
    {
        /* output to a string */
        *Stream->StrOutPtr = OutCh;
        Stream->StrOutPtr++;
        
        if (Stream->StrOutLen > 1)
            Stream->StrOutLen--;

        Stream->CharCount++;
    }
}

void StdioOutPuts(const char *Str, StdOutStream *Stream)
{
    while (*Str != '\0')
        StdioOutPutc(*Str++, Stream);
}

void StdioFprintfWord(StdOutStream *Stream, const char *Format, unsigned int Value)
{
    if (Stream->FilePtr != NULL)
        Stream->CharCount += fprintf(Stream->FilePtr, Format, Value);
    
    else if (Stream->StrOutLen >= 0)
    {
        int CCount = snprintf(Stream->StrOutPtr, Stream->StrOutLen, Format, Value);
        Stream->StrOutPtr += CCount;
        Stream->StrOutLen -= CCount;
        Stream->CharCount += CCount;
    }
    else
        Stream->CharCount += sprintf(Stream->StrOutPtr, Format, Value);
}

void StdioFprintfFP(StdOutStream *Stream, const char *Format, double Value)
{
    if (Stream->FilePtr != NULL)
        Stream->CharCount += fprintf(Stream->FilePtr, Format, Value);
    
    else if (Stream->StrOutLen >= 0)
    {
        int CCount = snprintf(Stream->StrOutPtr, Stream->StrOutLen, Format, Value);
        Stream->StrOutPtr += CCount;
        Stream->StrOutLen -= CCount;
        Stream->CharCount += CCount;
    }
    else
        Stream->CharCount += sprintf(Stream->StrOutPtr, Format, Value);
}

void StdioFprintfPointer(StdOutStream *Stream, const char *Format, void *Value)
{
    if (Stream->FilePtr != NULL)
        Stream->CharCount += fprintf(Stream->FilePtr, Format, Value);
    
    else if (Stream->StrOutLen >= 0)
    {
        int CCount = snprintf(Stream->StrOutPtr, Stream->StrOutLen, Format, Value);
        Stream->StrOutPtr += CCount;
        Stream->StrOutLen -= CCount;
        Stream->CharCount += CCount;
    }
    else
        Stream->CharCount += sprintf(Stream->StrOutPtr, Format, Value);
}

int StdioBasePrintf(struct ParseState *Parser, FILE *Stream, char *StrOut, int StrOutLen, char *Format, struct StdVararg *Args)
{
    struct Value **ArgPos = Args->Param;
    int ArgCount = 0;
    char *FPos = Format;
    char OneFormatBuf[MAX_FORMAT+1];
    int OneFormatCount;
    struct ValueType *ShowType;
    StdOutStream SOStream;
    
    SOStream.FilePtr = Stream;
    SOStream.StrOutPtr = StrOut;
    SOStream.StrOutLen = StrOutLen;
    SOStream.CharCount = 0;
    
    while (*FPos != '\0')
    {
        if (*FPos == '%')
        {
            /* work out what type we're printing */
            FPos++;
            ShowType = NULL;
            OneFormatBuf[OneFormatCount] = '%';
            OneFormatCount = 1;
            
            do
            {
                switch (*FPos)
                {
                    case 'd': case 'i':     ShowType = &IntType; break;     /* integer decimal */
                    case 'o': case 'u': case 'x': case 'X': ShowType = &IntType; break; /* integer base conversions */
                    case 'e': case 'E':     ShowType = &FPType; break;      /* double, exponent form */
                    case 'f': case 'F':     ShowType = &FPType; break;      /* double, fixed-point */
                    case 'g': case 'G':     ShowType = &FPType; break;      /* double, flexible format */
                    case 'a': case 'A':     ShowType = &IntType; break;     /* hexadecimal, 0x- format */
                    case 'c':               ShowType = &IntType; break;     /* character */
                    case 's':               ShowType = CharPtrType; break;  /* string */
                    case 'p':               ShowType = VoidPtrType; break;  /* pointer */
                    case 'n':               ShowType = &VoidType; break;    /* number of characters written */
                    case 'm':               ShowType = &VoidType; break;    /* strerror(errno) */
                    case '%':               ShowType = &VoidType; break;    /* just a '%' character */
                    case '\0':              ShowType = &VoidType; break;    /* end of format string */
                }
                
                /* copy one character of format across to the OneFormatBuf */
                OneFormatBuf[OneFormatCount] = *FPos;
                OneFormatCount++;

                /* do special actions depending on the conversion type */
                if (ShowType == &VoidType)
                {
                    switch (*FPos)
                    {
                        case 'm':   StdioOutPuts(strerror(errno), &SOStream); break;
                        case '%':   StdioOutPutc(*FPos, &SOStream); break;
                        case '\0':  OneFormatBuf[OneFormatCount] = '\0'; StdioOutPutc(*FPos, &SOStream); break;
                        case 'n':   
                            if ((*ArgPos)->Typ->Base == TypeArray && (*ArgPos)->Typ->FromType->Base == TypeInt)
                                *(int *)(*ArgPos)->Val->Integer = SOStream.CharCount;
                            break;
                    }
                }
                
                FPos++;
                
            } while (ShowType == NULL && OneFormatCount < MAX_FORMAT);
            
            if (ShowType != &VoidType)
            {
                if (ArgCount >= Args->NumArgs)
                    StdioOutPuts("XXX", &SOStream);
                else
                {
                    /* null-terminate the buffer */
                    OneFormatBuf[OneFormatCount] = '\0';
    
                    if (ShowType == &IntType)
                    {
                        /* show a signed integer */
                        if (IS_INTEGER_NUMERIC(*ArgPos))
                            StdioFprintfWord(&SOStream, OneFormatBuf, ExpressionCoerceUnsignedInteger(*ArgPos));
                        else
                            StdioOutPuts("XXX", &SOStream);
                    }
                    else if (ShowType == &FPType)
                    {
                        /* show a floating point number */
                        if (IS_FP(*ArgPos))
                            StdioFprintfFP(&SOStream, OneFormatBuf, ExpressionCoerceFP(*ArgPos));
                        else
                            StdioOutPuts("XXX", &SOStream);
                    }                    
                    else if (ShowType == CharPtrType)
                    {
                        if ((*ArgPos)->Typ->Base == TypePointer)
                            StdioFprintfPointer(&SOStream, OneFormatBuf, (*ArgPos)->Val->NativePointer);
                            
                        else if ((*ArgPos)->Typ->Base == TypeArray && (*ArgPos)->Typ->FromType->Base == TypeChar)
                            StdioFprintfPointer(&SOStream, OneFormatBuf, &(*ArgPos)->Val->ArrayMem[0]);
                            
                        else
                            StdioOutPuts("XXX", &SOStream);
                    }
                    else if (ShowType == VoidPtrType)
                    {
                        if ((*ArgPos)->Typ->Base == TypePointer)
                            StdioFprintfPointer(&SOStream, OneFormatBuf, (*ArgPos)->Val->NativePointer);
                            
                        else if ((*ArgPos)->Typ->Base == TypeArray)
                            StdioFprintfPointer(&SOStream, OneFormatBuf, &(*ArgPos)->Val->ArrayMem[0]);
                            
                        else
                            StdioOutPuts("XXX", &SOStream);
                    }
                    
                    ArgPos++;
                    ArgCount++;
                }
            }
        }
        else
        {
            /* just output a normal character */
            StdioOutPutc(*FPos, &SOStream);
            FPos++;
        }
    }
    
    /* null-terminate */
    if (SOStream.StrOutPtr != NULL && SOStream.StrOutLen > 0)
        *SOStream.StrOutPtr = '\0';      
    
    return SOStream.CharCount;
}

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

void StdioGets(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->NativePointer = fgets(Param[0]->Val->NativePointer, GETS_MAXValue, stdin);
}

void StdioGetchar(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    ReturnValue->Val->Integer = getchar();
}

void StdioPrintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    struct StdVararg PrintfArgs;
    
    PrintfArgs.Param = Param+1;
    PrintfArgs.NumArgs = NumArgs;
    ReturnValue->Val->Integer = StdioBasePrintf(Parser, stdout, NULL, 0, Param[0]->Val->NativePointer, &PrintfArgs);
}

void StdioVprintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = StdioBasePrintf(Parser, stdout, NULL, 0, Param[0]->Val->NativePointer, Param[1]->Val->NativePointer);
}

void StdioFprintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    struct StdVararg PrintfArgs;
    
    PrintfArgs.Param = Param+1;
    PrintfArgs.NumArgs = NumArgs;
    ReturnValue->Val->Integer = StdioBasePrintf(Parser, Param[0]->Val->NativePointer, NULL, 0, Param[1]->Val->NativePointer, &PrintfArgs);
}

void StdioVfprintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = StdioBasePrintf(Parser, Param[0]->Val->NativePointer, NULL, 0, Param[1]->Val->NativePointer, Param[2]->Val->NativePointer);
}

void StdioSprintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    struct StdVararg PrintfArgs;
    
    PrintfArgs.Param = Param+2;
    PrintfArgs.NumArgs = NumArgs;
    ReturnValue->Val->Integer = StdioBasePrintf(Parser, NULL, Param[0]->Val->NativePointer, -1, Param[1]->Val->NativePointer, &PrintfArgs);
}

void StdioSnprintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) 
{
    struct StdVararg PrintfArgs;
    
    PrintfArgs.Param = Param+3;
    PrintfArgs.NumArgs = NumArgs;
    ReturnValue->Val->Integer = StdioBasePrintf(Parser, NULL, Param[0]->Val->NativePointer, Param[1]->Val->Integer, Param[2]->Val->NativePointer, &PrintfArgs);
}

void StdioVsprintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = StdioBasePrintf(Parser, NULL, Param[0]->Val->NativePointer, -1, Param[1]->Val->NativePointer, Param[2]->Val->NativePointer);
}

void StdioVsnprintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = StdioBasePrintf(Parser, NULL, Param[0]->Val->NativePointer, Param[1]->Val->Integer, Param[2]->Val->NativePointer, Param[3]->Val->NativePointer);
}


const char StdioDefs[] = "\
typedef struct __FILEStruct FILE; \
typedef struct __va_listStruct va_list; \
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
    { StdioFputs,   "int fputs(char *, FILE *);" },
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
    { StdioPrintf,  "void printf(char *, ...);" },
    { StdioSprintf, "char *sprintf(char *, char *, ...);" },
    { StdioGets,    "char *gets(char *);" },
    { StdioGetchar, "int getchar();" },
    { StdioPrintf,  "int printf(char *format, ...);" },
    { StdioFprintf, "int fprintf(FILE *stream, char *format, ...);" },
    { StdioSprintf, "int sprintf(char *str, char *format, ...);" },
    { StdioSnprintf,"int snprintf(char *str, size_t size, char *format, ...);" },
    { StdioVprintf, "int vprintf(const char *format, va_list ap);" },
    { StdioVfprintf,"int vfprintf(FILE *stream, char *format, va_list ap);" },
    { StdioVsprintf,"int vsprintf(char *str, char *format, va_list ap);" },
    { StdioVsnprintf,"int vsnprintf(char *str, size_t size, char *format, va_list ap);" },
    { NULL,         NULL }
};

void StdioSetupFunc(void)
{
    /* make a "struct __FILEStruct" which is the same size as a native FILE structure */
    TypeCreateOpaqueStruct(NULL, TableStrRegister("__FILEStruct"), sizeof(FILE));

    /* make a "struct __va_listStruct" which is the same size as our struct StdVararg */
    TypeCreateOpaqueStruct(NULL, TableStrRegister("__va_listStruct"), sizeof(FILE));
    
    /* define EOF equal to the system EOF */
    VariableDefinePlatformVar(NULL, "EOF", &IntType, (union AnyValue *)&EOFValue, FALSE);
    VariableDefinePlatformVar(NULL, "SEEK_SET", &IntType, (union AnyValue *)&SEEK_SETValue, FALSE);
    VariableDefinePlatformVar(NULL, "SEEK_CUR", &IntType, (union AnyValue *)&SEEK_CURValue, FALSE);
    VariableDefinePlatformVar(NULL, "SEEK_END", &IntType, (union AnyValue *)&SEEK_ENDValue, FALSE);
    VariableDefinePlatformVar(NULL, "BUFSIZ", &IntType, (union AnyValue *)&BUFSIZValue, FALSE);
    VariableDefinePlatformVar(NULL, "FILENAME_MAX", &IntType, (union AnyValue *)&FILENAME_MAXValue, FALSE);
    VariableDefinePlatformVar(NULL, "_IOFBF", &IntType, (union AnyValue *)&_IOFBFValue, FALSE);
    VariableDefinePlatformVar(NULL, "_IOLBF", &IntType, (union AnyValue *)&_IOLBFValue, FALSE);
    VariableDefinePlatformVar(NULL, "_IONBF", &IntType, (union AnyValue *)&_IONBFValue, FALSE);
    VariableDefinePlatformVar(NULL, "L_tmpnam", &IntType, (union AnyValue *)&L_tmpnamValue, FALSE);
    VariableDefinePlatformVar(NULL, "GETS_MAX", &IntType, (union AnyValue *)&GETS_MAXValue, FALSE);
}

void PrintCh(char OutCh, FILE *Stream)
{
    putc(OutCh, Stream);
}

void PrintSimpleInt(long Num, FILE *Stream)
{
    fprintf(Stream, "%ld", Num);
}

void PrintStr(const char *Str, FILE *Stream)
{
    fputs(Str, Stream);
}

void PrintFP(double Num, FILE *Stream)
{
    fprintf(Stream, "%f", Num);
}

#endif /* !BUILTIN_MINI_STDLIB */

/*
 TODO:
scanf, vscanf 	used to input from the standard input stream
fscanf, vfscanf 	used to input from a file
sscanf, vsscanf 	used to input from a char array (e.g., a C string)
*/