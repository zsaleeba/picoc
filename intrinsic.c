#include <stdio.h>
#include <string.h>
#include "picoc.h"

#define NUM_INTRINSICS 3

Str IntrinsicFilename = { 9, "intrinsic" };
struct Value IntrinsicValue[NUM_INTRINSICS];
int IntrinsicReferenceNo[NUM_INTRINSICS];

void IntrinsicPrintInt(void)
{
    printf("%d\n", Parameter[0].Val->Integer);
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
    struct LexState Lexer;
    Str Source;
    int Count;
    union AnyValue Identifier;
    struct ValueType *Typ;
    
    for (Count = 0; Count < sizeof(Intrinsics) / sizeof(struct IntrinsicFunction); Count++)
    {
        Source.Str = Intrinsics[Count].Prototype;
        Source.Len = strlen(Source.Str);
        LexInit(&Lexer, &Source, &IntrinsicFilename, Count+1);
        ParseType(&Lexer, &Typ);
        LexGetToken(&Lexer, &Identifier);
        IntrinsicReferenceNo[Count] = -1 - Count;
        IntrinsicValue[Count].Typ = &FunctionType;
        IntrinsicValue[Count].Val = (union AnyValue *)&IntrinsicReferenceNo[Count];
        IntrinsicValue[Count].MustFree = FALSE;
        TableSet(GlobalTable, &Identifier.String, &IntrinsicValue[Count]);
    }
}

void IntrinsicGetLexer(struct LexState *Lexer, int IntrinsicId)
{
    Lexer->Line = -IntrinsicId;
    Lexer->Pos = Intrinsics[-1-IntrinsicId].Prototype;
    Lexer->End = Lexer->Pos + strlen(Lexer->Pos);
    Lexer->FileName = &IntrinsicFilename;
}

void IntrinsicCall(struct LexState *Lexer, struct Value *Result, struct ValueType *ReturnType, int IntrinsicId)
{
    Intrinsics[-1-IntrinsicId].Func();
    Result->Typ = &VoidType;
}

