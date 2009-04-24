#include "picoc.h"

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

/* print a string to a stream without using printf/sprintf */
void PrintStr(const char *Str, CharWriter *PutCh)
{
    while (*Str != 0)
        PutCh(*Str++);
}

/* print an integer to a stream without using printf/sprintf */
void PrintInt(int Num, CharWriter *PutCh)
{
    int Div;
    int Remainder = 0;
    int Printing = FALSE;
    
    if (Num < 0)
    {
        PutCh('-');
        Num = -Num;    
    }
    
    if (Num == 0)
        PutCh('0');
    else
    {
        Div = LARGE_INT_POWER_OF_TEN;
        while (Div > 0)
        {
            Remainder = Num / Div;
            if (Printing || Remainder > 0)
            {
                PutCh('0' + Remainder);
                Printing = TRUE;
            }
            Num -= Remainder * Div;
            Div /= 10;
        }
    }
}

#ifndef NO_FP
/* print a double to a stream without using printf/sprintf */
void PrintFP(double Num, CharWriter *PutCh)
{
    int Exponent = 0;
    
    if (abs(Num) >= 1e7)
        Exponent = log(Num) / LOG10E;
    else if (abs(Num) <= 1e-7)
        Exponent = log(Num) / LOG10E - 0.999999999;
    
    Num /= pow(10.0, Exponent);
    PrintInt((int)Num, PutCh);
    PutCh('.');
    for (Num -= (int)Num; Num != 0.0; Num *= 10.0)
        PutCh('0' + (int)Num);
    
    if (Exponent)
    {
        PutCh('e');
        PrintInt(Exponent, PutCh);
    }
}
#endif

/* print a type to a stream without using printf/sprintf */
void PrintType(struct ValueType *Typ, CharWriter *PutCh)
{
    switch (Typ->Base)
    {
        case TypeVoid:      PrintStr("void", PutCh); break;
        case TypeInt:       PrintStr("int", PutCh); break;
#ifndef NO_FP
        case TypeFP:        PrintStr("double", PutCh); break;
#endif
        case TypeChar:      PrintStr("char", PutCh); break;
        case TypeFunction:  PrintStr("function", PutCh); break;
        case TypeMacro:     PrintStr("macro", PutCh); break;
        case TypePointer:   if (Typ->FromType) PrintType(Typ->FromType, PutCh); PutCh('*'); break;
        case TypeArray:     PrintType(Typ->FromType, PutCh); PutCh('['); if (Typ->ArraySize != 0) PrintInt(Typ->ArraySize, PutCh); PutCh(']'); break;
        case TypeStruct:    PrintStr("struct ", PutCh); PrintStr(Typ->Identifier, PutCh); break;
        case TypeUnion:     PrintStr("union ", PutCh); PrintStr(Typ->Identifier, PutCh); break;
        case TypeEnum:      PrintStr("enum ", PutCh); PrintStr(Typ->Identifier, PutCh); break;
    }
}

/* intrinsic functions made available to the language */
void LibPrintf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    struct Value *CharArray = Param[0]->Val->Pointer.Segment;
    char *Format;
    char *FPos;
    struct Value *NextArg = Param[0];
    struct ValueType *FormatType;
    int ArgCount = 1;
    
    if (Param[0]->Val->Pointer.Offset < 0 || Param[0]->Val->Pointer.Offset >= CharArray->Val->Array.Size)
        Format = StrEmpty;
    else
        Format = CharArray->Val->Array.Data + Param[0]->Val->Pointer.Offset;
    
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
                case '%': PlatformPutc('%'); FormatType = NULL; break;
                case '\0': FPos--; FormatType = NULL; break;
                default:  PlatformPutc(*FPos); FormatType = NULL; break;
            }
            
            if (FormatType != NULL)
            { /* we have to format something */
                if (ArgCount >= NumArgs)
                    PrintStr("XXX", PlatformPutc);   /* not enough parameters for format */
                else
                {
                    NextArg = (struct Value *)((void *)NextArg + sizeof(struct Value) + TypeStackSizeValue(NextArg));
                    if (NextArg->Typ != FormatType && !(FormatType == &IntType && IS_INTEGER_COERCIBLE(NextArg)))
                        PrintStr("XXX", PlatformPutc);   /* bad type for format */
                    else
                    {
                        switch (*FPos)
                        {
                            case 's':
                            {
                                struct Value *CharArray = NextArg->Val->Pointer.Segment;
                                char *Str;
                                
                                if (NextArg->Val->Pointer.Offset < 0 || NextArg->Val->Pointer.Offset >= CharArray->Val->Array.Size)
                                    Str = StrEmpty;
                                else
                                    Str = CharArray->Val->Array.Data + NextArg->Val->Pointer.Offset;
                                    
                                PrintStr(Str, PlatformPutc); 
                                break;
                            }
                            case 'd': PrintInt(COERCE_INTEGER(NextArg), PlatformPutc); break;
                            case 'c': PlatformPutc(COERCE_INTEGER(NextArg)); break;
#ifndef NO_FP
                            case 'f': PrintFP(NextArg->Val->FP, PlatformPutc); break;
#endif
                        }
                    }
                }
                
                ArgCount++;
            }
        }
        else
            PlatformPutc(*FPos);
    }
}

/* get a line of input. protected from buffer overrun */
void LibGets(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    struct Value *CharArray = Param[0]->Val->Pointer.Segment;
    char *ReadBuffer = CharArray->Val->Array.Data + Param[0]->Val->Pointer.Offset;
    int MaxLength = CharArray->Val->Array.Size - Param[0]->Val->Pointer.Offset;
    char *Result;

    ReturnValue->Val->Pointer.Segment = 0;
    ReturnValue->Val->Pointer.Offset = 0;
    
    if (Param[0]->Val->Pointer.Offset < 0 || MaxLength < 0)
        return; /* no room for data */
    
    Result = PlatformGetLine(ReadBuffer, MaxLength);
    if (Result == NULL)
        return;
    
    ReturnValue->Val->Pointer = Param[0]->Val->Pointer;
}

void LibGetc(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = PlatformGetCharacter();
}

/* list of all library functions and their prototypes */
struct LibraryFunction CLibrary[] =
{
    { LibPrintf,        "void printf(char *, ...)" },
    { LibGets,          "void gets(char *, int)" },
    { LibGetc,          "int getchar()" },
    { NULL,             NULL }
};
