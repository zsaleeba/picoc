#include <stdio.h>
#include <string.h>
#include "picoc.h"

void IntrinsicPrintInt(void)
{
    printf("%d\n", TopStackFrame->Parameter[0]->Val->Integer);
}

void IntrinsicPrintf(void)
{
    printf("IntrinsicPrintf\n");
}

void IntrinsicSayHello(void)
{
    printf("Hello\n");
}

struct IntrinsicFunction
{
    void (*Func)(void);
    const char *Prototype;
} Intrinsics[] =
{
    { IntrinsicSayHello,    "void sayhello()" },    /* -1 */
    { IntrinsicPrintf,      "void printf()" },      /* -2 */
    { IntrinsicPrintInt,    "void printint(int)" }, /* -3 */
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
