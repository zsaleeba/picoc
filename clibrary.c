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
    if (Out->WritePos == Out->MaxPos)
        Out->WritePos--;
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

/* print an integer to a stream without using printf/sprintf */
void PrintInt(int Num, struct OutputStream *Stream)
{
    int Div;
    int Remainder = 0;
    int Printing = FALSE;
    
    if (Num < 0)
    {
        PrintCh('-', Stream);
        Num = -Num;    
    }
    
    if (Num == 0)
        PrintCh('0', Stream);
    else
    {
        Div = LARGE_INT_POWER_OF_TEN;
        while (Div > 0)
        {
            Remainder = Num / Div;
            if (Printing || Remainder > 0)
            {
                PrintCh('0' + Remainder, Stream);
                Printing = TRUE;
            }
            Num -= Remainder * Div;
            Div /= 10;
        }
    }
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
    PrintInt((int)Num, Stream);
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
        PrintInt(Exponent, Stream);
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
#ifndef NO_FP
        case TypeFP:        PrintStr("double", Stream); break;
#endif
        case TypeChar:      PrintStr("char", Stream); break;
        case TypeFunction:  PrintStr("function", Stream); break;
        case TypeMacro:     PrintStr("macro", Stream); break;
        case TypePointer:   if (Typ->FromType) PrintType(Typ->FromType, Stream); PrintCh('*', Stream); break;
        case TypeArray:     PrintType(Typ->FromType, Stream); PrintCh('[', Stream); if (Typ->ArraySize != 0) PrintInt(Typ->ArraySize, Stream); PrintCh(']', Stream); break;
        case TypeStruct:    PrintStr("struct ", Stream); PrintStr(Typ->Identifier, Stream); break;
        case TypeUnion:     PrintStr("union ", Stream); PrintStr(Typ->Identifier, Stream); break;
        case TypeEnum:      PrintStr("enum ", Stream); PrintStr(Typ->Identifier, Stream); break;
    }
}

/* intrinsic functions made available to the language */
void GenericPrintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs, struct OutputStream *Stream)
{
    char *FPos;
    struct Value *NextArg = Param[0];
    struct ValueType *FormatType;
    int ArgCount = 1;
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
            switch (*FPos)
            {
                case 's': FormatType = CharPtrType; break;
                case 'd': case 'c': FormatType = &IntType; break;
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
#ifndef NATIVE_POINTERS
                                struct Value *CharArray;
                                char *Str;
                                
                                if (NextArg->Typ == CharPtrType || (NextArg->Typ->Base == TypePointer && NextArg->Typ->FromType->Base == TypeArray && NextArg->Typ->FromType->FromType->Base == TypeChar) )
                                {
                                    CharArray = NextArg->Val->Pointer.Segment;

                                    if (NextArg->Val->Pointer.Offset < 0 || NextArg->Val->Pointer.Offset >= CharArray->Val->Array.Size)
                                        Str = StrEmpty;
                                    else
                                        Str = (char *)CharArray->Val->Array.Data + NextArg->Val->Pointer.Offset;
                                }
                                else
                                    Str = NextArg->Val->Array.Data;
#else
                                char *Str = NextArg->Val->NativePointer;
                                /* XXX - dereference this properly */
#endif
                                    
                                PrintStr(Str, Stream); 
                                break;
                            }
                            case 'd': PrintInt(COERCE_INTEGER(NextArg), Stream); break;
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
    struct ValueType *DerefType;
    StrStream.i.Str.WritePos = VariableDereferencePointer(StrStream.i.Str.Parser, Param[0], &DerefVal, &DerefOffset, &DerefType);

    if (DerefVal->Typ->Base != TypeArray)
        ProgramFail(Parser, "can only print to arrays of char");
        
    StrStream.Putch = &SPutc;
    StrStream.i.Str.Parser = Parser;
    StrStream.i.Str.MaxPos = StrStream.i.Str.WritePos- DerefOffset + DerefVal->Val->Array.Size;
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
    int MaxLength = CharArray->Val->Array.Size;
    char *Result;

    ReturnValue->Val->NativePointer = NULL;
    
    if (MaxLength < 0)
        return; /* no room for data */
    
    Result = PlatformGetLine(ReadBuffer, MaxLength);
    if (Result == NULL)
        return;
    
    ReturnValue->Val->NativePointer = Param[0]->Val->NativePointer;
#endif
}

void LibGetc(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = PlatformGetCharacter();
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

void LibAsinh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_asinh(Param[0]->Val->FP);
}

void LibAcosh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_acosh(Param[0]->Val->FP);
}

void LibAtanh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = math_atanh(Param[0]->Val->FP);
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
    { LibAsinh,         "float asinh(float)" },
    { LibAcosh,         "float acosh(float)" },
    { LibAtanh,         "float atanh(float)" },
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
