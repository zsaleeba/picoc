#include <stdio.h>
#include <string.h>
#include "picoc.h"

void IntrinsicPrintInt(struct Value *ReturnValue, struct Value **Param)
{
    printf("%d\n", Param[0]->Val->Integer);
}

void IntrinsicPrintf(struct Value *ReturnValue, struct Value **Param)
{
    printf("IntrinsicPrintf\n");
}

void IntrinsicSayHello(struct Value *ReturnValue, struct Value **Param)
{
    printf("Hello\n");
}

struct IntrinsicFunction
{
    void (*Func)(struct Value *, struct Value **);
    const char *Prototype;
} Intrinsics[] =
{
    { IntrinsicSayHello,    "void sayhello()" },
    { IntrinsicPrintf,      "void printf(char *, ...)" },
    { IntrinsicPrintInt,    "void printint(int)" },
};

void IntrinsicInit(struct Table *GlobalTable)
{
    struct ParseState Parser;
    int Count;
    const char *Identifier;
    struct ValueType *ReturnType;
    struct Value *NewValue;
    void *Tokens;
    const char *IntrinsicName = StrRegister("intrinsic");
    
    for (Count = 0; Count < sizeof(Intrinsics) / sizeof(struct IntrinsicFunction); Count++)
    {
        Tokens = LexAnalyse(IntrinsicName, Intrinsics[Count].Prototype, strlen(Intrinsics[Count].Prototype));
        LexInitParser(&Parser, Tokens, IntrinsicName, Count+1, TRUE);
        TypeParse(&Parser, &ReturnType, &Identifier);
        NewValue = ParseFunctionDefinition(&Parser, ReturnType, Identifier, TRUE);
        NewValue->Val->FuncDef.Intrinsic = Intrinsics[Count].Func;
        HeapFree(Tokens);
    }
}
