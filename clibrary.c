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
        LexInitParser(&Parser, Tokens, IntrinsicName, Count+1, TRUE);
        TypeParse(&Parser, &ReturnType, &Identifier);
        NewValue = ParseFunctionDefinition(&Parser, ReturnType, Identifier, TRUE);
        NewValue->Val->FuncDef.Intrinsic = (*FuncList)[Count].Func;
        HeapFree(Tokens);
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
    
    if (Num < 0)
    {
        PrintCh('-', Stream);
        Num = -Num;    
    }
    
    if (Num >= 1e7)
        Exponent = log(Num) / LOG10E;
    else if (Num <= 1e-7)
        Exponent = log(Num) / LOG10E - 0.999999999;
    
    Num /= pow(10.0, Exponent);
    PrintInt((int)Num, Stream);
    PrintCh('.', Stream);
    Num = (Num - (int)Num) * 10;
    if (abs(Num) >= 1e-7)
    {
       for (; abs(Num) >= 1e-7; Num = (Num - (int)(Num + 1e-7)) * 10)
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
        Format = CharArray->Val->Array.Data + Param[0]->Val->Pointer.Offset;
#else
    char *Format = Param[0]->Val->NativePointer;
    // XXX - dereference this properly
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
                    NextArg = (struct Value *)((void *)NextArg + sizeof(struct Value) + TypeStackSizeValue(NextArg));
                    if (NextArg->Typ != FormatType && !(FormatType == &IntType && IS_INTEGER_COERCIBLE(NextArg)))
                        PrintStr("XXX", Stream);   /* bad type for format */
                    else
                    {
                        switch (*FPos)
                        {
                            case 's':
                            {
#ifndef NATIVE_POINTERS
                                struct Value *CharArray = NextArg->Val->Pointer.Segment;
                                char *Str;
                                
                                if (NextArg->Val->Pointer.Offset < 0 || NextArg->Val->Pointer.Offset >= CharArray->Val->Array.Size)
                                    Str = StrEmpty;
                                else
                                    Str = CharArray->Val->Array.Data + NextArg->Val->Pointer.Offset;
#else
                                char *Str = NextArg->Val->NativePointer;
                                // XXX - dereference this properly
#endif
                                    
                                PrintStr(Str, Stream); 
                                break;
                            }
                            case 'd': PrintInt(COERCE_INTEGER(NextArg), Stream); break;
                            case 'c': PrintCh(COERCE_INTEGER(NextArg), Stream); break;
#ifndef NO_FP
                            case 'f': PrintFP(NextArg->Val->FP, Stream); break;
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
    char *ReadBuffer = CharArray->Val->Array.Data + Param[0]->Val->Pointer.Offset;
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

/* list of all library functions and their prototypes */
struct LibraryFunction CLibrary[] =
{
    { LibPrintf,        "void printf(char *, ...)" },
    { LibSPrintf,       "char *sprintf(char *, char *, ...)" },
    { LibGets,          "void gets(char *, int)" },
    { LibGetc,          "int getchar()" },
    { NULL,             NULL }
};
