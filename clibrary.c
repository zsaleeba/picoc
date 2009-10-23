#include "picoc.h"

struct OutputStream CStdOut;

static int TRUEValue = 1;
static int ZeroValue = 0;

/* initialise a library */
void LibraryInit(struct Table *GlobalTable, const char *LibraryName, struct LibraryFunction (*FuncList)[])
{
    struct ParseState Parser;
    int Count;
    char *Identifier;
    struct ValueType *ReturnType;
    struct Value *NewValue;
    void *Tokens;
    const char *IntrinsicName = TableStrRegister("c library");
    
    CStdOut.Putch = &PlatformPutc;
    
    for (Count = 0; (*FuncList)[Count].Prototype != NULL; Count++)
    {
        Tokens = LexAnalyse(IntrinsicName, (*FuncList)[Count].Prototype, strlen((char *)(*FuncList)[Count].Prototype), NULL);
        LexInitParser(&Parser, (*FuncList)[Count].Prototype, Tokens, IntrinsicName, TRUE);
        TypeParse(&Parser, &ReturnType, &Identifier);
        NewValue = ParseFunctionDefinition(&Parser, ReturnType, Identifier, TRUE);
        NewValue->Val->FuncDef.Intrinsic = (*FuncList)[Count].Func;
        HeapFreeMem(Tokens);
    }
}

/* initialise the C library */
void CLibraryInit()
{
    /* define some constants */
    VariableDefinePlatformVar(NULL, "NULL", &IntType, (union AnyValue *)&ZeroValue, FALSE);
    VariableDefinePlatformVar(NULL, "TRUE", &IntType, (union AnyValue *)&TRUEValue, FALSE);
    VariableDefinePlatformVar(NULL, "FALSE", &IntType, (union AnyValue *)&ZeroValue, FALSE);
}

/* stream for writing into strings */
void SPutc(unsigned char Ch, union OutputStreamInfo *Stream)
{
    struct StringOutputStream *Out = &Stream->Str;
    *Out->WritePos++ = Ch;
#ifndef NATIVE_POINTERS
    if (Out->WritePos == Out->MaxPos)
        Out->WritePos--;
#endif
}

/* print a character to a stream without using printf/sprintf */
void PrintCh(char OutCh, struct OutputStream *Stream)
{
    (*Stream->Putch)(OutCh, &Stream->i);
}

/* print a string to a stream without using printf/sprintf */
void PrintStr(const char *Str, struct OutputStream *Stream)
{
    while (*Str != 0)
        PrintCh(*Str++, Stream);
}

/* print a single character a given number of times */
void PrintRepeatedChar(char ShowChar, int Length, struct OutputStream *Stream)
{
    while (Length-- > 0)
        PrintCh(ShowChar, Stream);
}

/* print an unsigned integer to a stream without using printf/sprintf */
void PrintUnsigned(unsigned int Num, unsigned int Base, int FieldWidth, int ZeroPad, int LeftJustify, struct OutputStream *Stream)
{
    char Result[33];
    int ResPos = sizeof(Result);

    if (Num == 0)
        PrintCh('0', Stream);
            
    Result[--ResPos] = '\0';
    while (Num > 0)
    {
        unsigned int NextNum = Num / Base;
        unsigned int Digit = Num - NextNum * Base;
        if (Digit < 10)
            Result[--ResPos] = '0' + Digit;
        else
            Result[--ResPos] = 'a' + Digit - 10;
        
        Num = NextNum;
    }
    
    if (FieldWidth > 0 && !LeftJustify)
        PrintRepeatedChar(ZeroPad ? '0' : ' ', FieldWidth - (sizeof(Result) - 1 - ResPos), Stream);
        
    PrintStr(&Result[ResPos], Stream);

    if (FieldWidth > 0 && LeftJustify)
        PrintRepeatedChar(' ', FieldWidth - (sizeof(Result) - 1 - ResPos), Stream);
}

/* print an integer to a stream without using printf/sprintf */
void PrintInt(int Num, int FieldWidth, int ZeroPad, int LeftJustify, struct OutputStream *Stream)
{
    if (Num < 0)
    {
        PrintCh('-', Stream);
        Num = -Num;
        if (FieldWidth != 0)
            FieldWidth--;
    }
    
    PrintUnsigned((unsigned int)Num, 10, FieldWidth, ZeroPad, LeftJustify, Stream);
}

#ifndef NO_FP
/* print a double to a stream without using printf/sprintf */
void PrintFP(double Num, struct OutputStream *Stream)
{
    int Exponent = 0;
    int MaxDecimal;
    
    if (Num < 0)
    {
        PrintCh('-', Stream);
        Num = -Num;    
    }
    
    if (Num >= 1e7)
        Exponent = math_log(Num) / LOG10E;
    else if (Num <= 1e-7 && Num != 0.0)
        Exponent = math_log(Num) / LOG10E - 0.999999999;
    
    Num /= math_pow(10.0, Exponent);    
    PrintInt((int)Num, 0, FALSE, FALSE, Stream);
    PrintCh('.', Stream);
    Num = (Num - (int)Num) * 10;
    if (abs(Num) >= 1e-7)
    {
       for (MaxDecimal = 6; MaxDecimal > 0 && abs(Num) >= 1e-7; Num = (Num - (int)(Num + 1e-7)) * 10, MaxDecimal--)
           PrintCh('0' + (int)(Num + 1e-7), Stream);
    }
    else
        PrintCh('0', Stream);
        
    if (Exponent != 0)
    {
        PrintCh('e', Stream);
        PrintInt(Exponent, 0, FALSE, FALSE, Stream);
    }
}
#endif

/* print a type to a stream without using printf/sprintf */
void PrintType(struct ValueType *Typ, struct OutputStream *Stream)
{
    switch (Typ->Base)
    {
        case TypeVoid:      PrintStr("void", Stream); break;
        case TypeInt:       PrintStr("int", Stream); break;
        case TypeShort:     PrintStr("short", Stream); break;
        case TypeChar:      PrintStr("char", Stream); break;
#ifndef NO_FP
        case TypeFP:        PrintStr("double", Stream); break;
#endif
        case TypeFunction:  PrintStr("function", Stream); break;
        case TypeMacro:     PrintStr("macro", Stream); break;
        case TypePointer:   if (Typ->FromType) PrintType(Typ->FromType, Stream); PrintCh('*', Stream); break;
        case TypeArray:     PrintType(Typ->FromType, Stream); PrintCh('[', Stream); if (Typ->ArraySize != 0) PrintInt(Typ->ArraySize, 0, FALSE, FALSE, Stream); PrintCh(']', Stream); break;
        case TypeStruct:    PrintStr("struct ", Stream); PrintStr(Typ->Identifier, Stream); break;
        case TypeUnion:     PrintStr("union ", Stream); PrintStr(Typ->Identifier, Stream); break;
        case TypeEnum:      PrintStr("enum ", Stream); PrintStr(Typ->Identifier, Stream); break;
        case Type_Type:     PrintStr("type ", Stream); break;
    }
}

/* intrinsic functions made available to the language */
void GenericPrintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs, struct OutputStream *Stream)
{
    char *FPos;
    struct Value *NextArg = Param[0];
    struct ValueType *FormatType;
    int ArgCount = 1;
    int LeftJustify = FALSE;
    int ZeroPad = FALSE;
    int FieldWidth = 0;
#ifndef NATIVE_POINTERS
    char *Format;
    struct Value *CharArray = Param[0]->Val->Pointer.Segment;

    if (Param[0]->Val->Pointer.Offset < 0 || Param[0]->Val->Pointer.Offset >= CharArray->Val->Array.Size)
        Format = StrEmpty;
    else
        Format = (char *)CharArray->Val->Array.Data + Param[0]->Val->Pointer.Offset;
#else
    char *Format = Param[0]->Val->NativePointer;
    /* XXX - dereference this properly */
#endif
    
    for (FPos = Format; *FPos != '\0'; FPos++)
    {
        if (*FPos == '%')
        {
            FPos++;
            if (*FPos == '-')
            {
                /* a leading '-' means left justify */
                LeftJustify = TRUE;
                FPos++;
            }
            
            if (*FPos == '0')
            {
                /* a leading zero means zero pad a decimal number */
                ZeroPad = TRUE;
                FPos++;
            }
            
            /* get any field width in the format */
            while (isdigit(*FPos))
                FieldWidth = FieldWidth * 10 + (*FPos++ - '0');
            
            /* now check the format type */
            switch (*FPos)
            {
                case 's': FormatType = CharPtrType; break;
                case 'd': case 'u': case 'x': case 'b': case 'c': FormatType = &IntType; break;
#ifndef NO_FP
                case 'f': FormatType = &FPType; break;
#endif
                case '%': PrintCh('%', Stream); FormatType = NULL; break;
                case '\0': FPos--; FormatType = NULL; break;
                default:  PrintCh(*FPos, Stream); FormatType = NULL; break;
            }
            
            if (FormatType != NULL)
            { /* we have to format something */
                if (ArgCount >= NumArgs)
                    PrintStr("XXX", Stream);   /* not enough parameters for format */
                else
                {
                    NextArg = (struct Value *)((char *)NextArg + sizeof(struct Value) + TypeStackSizeValue(NextArg));
                    if (NextArg->Typ != FormatType && 
                            !((FormatType == &IntType || *FPos == 'f') && IS_NUMERIC_COERCIBLE(NextArg)) &&
                            !(FormatType == CharPtrType && ( (NextArg->Typ->Base == TypePointer && NextArg->Typ->FromType->Base == TypeArray && NextArg->Typ->FromType->FromType->Base == TypeChar) || 
                                                             (NextArg->Typ->Base == TypeArray && NextArg->Typ->FromType->Base == TypeChar) ) ) )
                        PrintStr("XXX", Stream);   /* bad type for format */
                    else
                    {
                        switch (*FPos)
                        {
                            case 's':
                            {
                                char *Str;
                                
                                if (NextArg->Typ == CharPtrType || (NextArg->Typ->Base == TypePointer && NextArg->Typ->FromType->Base == TypeArray && NextArg->Typ->FromType->FromType->Base == TypeChar) )
                                {
#ifndef NATIVE_POINTERS
                                    struct Value *CharArray = NextArg->Val->Pointer.Segment;

                                    if (NextArg->Val->Pointer.Offset < 0 || NextArg->Val->Pointer.Offset >= CharArray->Val->Array.Size)
                                        Str = StrEmpty;
                                    else
                                        Str = (char *)CharArray->Val->Array.Data + NextArg->Val->Pointer.Offset;
#else
                                    Str = NextArg->Val->NativePointer;
#endif
                                }
                                else
                                    Str = NextArg->Val->Array.Data;
                                    
                                PrintStr(Str, Stream); 
                                break;
                            }
                            case 'd': PrintInt(COERCE_INTEGER(NextArg), FieldWidth, ZeroPad, LeftJustify, Stream); break;
                            case 'u': PrintUnsigned((unsigned int)COERCE_INTEGER(NextArg), 10, FieldWidth, ZeroPad, LeftJustify, Stream); break;
                            case 'x': PrintUnsigned((unsigned int)COERCE_INTEGER(NextArg), 16, FieldWidth, ZeroPad, LeftJustify, Stream); break;
                            case 'b': PrintUnsigned((unsigned int)COERCE_INTEGER(NextArg), 2, FieldWidth, ZeroPad, LeftJustify, Stream); break;
                            case 'c': PrintCh(COERCE_INTEGER(NextArg), Stream); break;
#ifndef NO_FP
                            case 'f': PrintFP(COERCE_FP(NextArg), Stream); break;
#endif
                        }
                    }
                }
                
                ArgCount++;
            }
        }
        else
            PrintCh(*FPos, Stream);
    }
}

/* printf(): print to console output */
void LibPrintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    struct OutputStream ConsoleStream;
    
    ConsoleStream.Putch = &PlatformPutc;
    GenericPrintf(Parser, ReturnValue, Param, NumArgs, &ConsoleStream);
}

/* sprintf(): print to a string */
void LibSPrintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    struct OutputStream StrStream;
    struct Value *DerefVal;
    int DerefOffset;
    StrStream.i.Str.WritePos = VariableDereferencePointer(StrStream.i.Str.Parser, Param[0], &DerefVal, &DerefOffset, NULL, NULL);

    if (DerefVal->Typ->Base != TypeArray)
        ProgramFail(Parser, "can only print to arrays of char");
        
    StrStream.Putch = &SPutc;
    StrStream.i.Str.Parser = Parser;
#ifndef NATIVE_POINTERS
    StrStream.i.Str.MaxPos = StrStream.i.Str.WritePos - DerefOffset + DerefVal->Val->Array.Size;
#endif
    GenericPrintf(Parser, ReturnValue, Param+1, NumArgs-1, &StrStream);
    PrintCh(0, &StrStream);
#ifndef NATIVE_POINTERS
    ReturnValue->Val->Pointer.Segment = *Param;
    ReturnValue->Val->Pointer.Offset = 0;
#else
    ReturnValue->Val->NativePointer = *Param;
#endif
}

/* get a line of input. protected from buffer overrun */
void LibGets(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
#ifndef NATIVE_POINTERS
    struct Value *CharArray = Param[0]->Val->Pointer.Segment;
    char *ReadBuffer = (char *)CharArray->Val->Array.Data + Param[0]->Val->Pointer.Offset;
    int MaxLength = CharArray->Val->Array.Size - Param[0]->Val->Pointer.Offset;
    char *Result;

    ReturnValue->Val->Pointer.Segment = NULL;
    ReturnValue->Val->Pointer.Offset = 0;
    
    if (Param[0]->Val->Pointer.Offset < 0 || MaxLength < 0)
        return; /* no room for data */
    
    Result = PlatformGetLine(ReadBuffer, MaxLength);
    if (Result == NULL)
        return;
    
    ReturnValue->Val->Pointer = Param[0]->Val->Pointer;
#else
    struct Value *CharArray = (struct Value *)(Param[0]->Val->NativePointer);
    char *ReadBuffer = CharArray->Val->Array.Data;
    char *Result;

    ReturnValue->Val->NativePointer = NULL;
    Result = PlatformGetLine(ReadBuffer, GETS_BUF_MAX);
    if (Result == NULL)
        return;
    
    ReturnValue->Val->NativePointer = Param[0]->Val->NativePointer;
#endif
}

void LibGetc(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = PlatformGetCharacter();
}

void LibExit(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    PlatformExit();
}

#ifdef PICOC_MATH_LIBRARY
void LibSin(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_sin(Param[0]->Val->FP);
}

void LibCos(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_cos(Param[0]->Val->FP);
}

void LibTan(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_tan(Param[0]->Val->FP);
}

void LibAsin(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_asin(Param[0]->Val->FP);
}

void LibAcos(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_acos(Param[0]->Val->FP);
}

void LibAtan(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_atan(Param[0]->Val->FP);
}

void LibSinh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_sinh(Param[0]->Val->FP);
}

void LibCosh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_cosh(Param[0]->Val->FP);
}

void LibTanh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_tanh(Param[0]->Val->FP);
}

void LibExp(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_exp(Param[0]->Val->FP);
}

void LibFabs(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_fabs(Param[0]->Val->FP);
}

void LibLog(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_log(Param[0]->Val->FP);
}

void LibLog10(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_log10(Param[0]->Val->FP);
}

void LibPow(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_pow(Param[0]->Val->FP, Param[1]->Val->FP);
}

void LibSqrt(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_sqrt(Param[0]->Val->FP);
}

void LibRound(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_floor(Param[0]->Val->FP + 0.5);   /* XXX - fix for soft float */
}

void LibCeil(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_ceil(Param[0]->Val->FP);
}

void LibFloor(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_floor(Param[0]->Val->FP);
}
#endif

/* list of all library functions and their prototypes */
struct LibraryFunction CLibrary[] =
{
    { LibPrintf,        "void printf(char *, ...)" },
    { LibSPrintf,       "char *sprintf(char *, char *, ...)" },
    { LibGets,          "void gets(char *, int)" },
    { LibGetc,          "int getchar()" },
    { LibExit,          "void exit()" },
#ifdef PICOC_MATH_LIBRARY
    { LibSin,           "float sin(float)" },
    { LibCos,           "float cos(float)" },
    { LibTan,           "float tan(float)" },
    { LibAsin,          "float asin(float)" },
    { LibAcos,          "float acos(float)" },
    { LibAtan,          "float atan(float)" },
    { LibSinh,          "float sinh(float)" },
    { LibCosh,          "float cosh(float)" },
    { LibTanh,          "float tanh(float)" },
    { LibExp,           "float exp(float)" },
    { LibFabs,          "float fabs(float)" },
    { LibLog,           "float log(float)" },
    { LibLog10,         "float log10(float)" },
    { LibPow,           "float pow(float,float)" },
    { LibSqrt,          "float sqrt(float)" },
    { LibRound,         "float round(float)" },
    { LibCeil,          "float ceil(float)" },
    { LibFloor,         "float floor(float)" },
#endif
    { NULL,             NULL }
};
