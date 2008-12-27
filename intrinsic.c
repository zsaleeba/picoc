#include <stdio.h>
#include <string.h>
#include "picoc.h"

Str IntrinsicFilename = { 9, "intrinsic" };

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
};

void IntrinsicInit(struct Table *GlobalTable)
{
    struct Value FuncVal;
    struct LexState Lexer;
    Str Source;
    int Count;
    union AnyValue Identifier;
    enum ValueType Typ;
    
    FuncVal.Typ = TypeFunction;
    for (Count = 0; Count < sizeof(Intrinsics) / sizeof(struct IntrinsicFunction); Count++)
    {
        Source.Str = Intrinsics[Count].Prototype;
        Source.Len = strlen(Source.Str);
        LexInit(&Lexer, &Source, &IntrinsicFilename, Count+1);
        ParseType(&Lexer, &Typ);
        LexGetToken(&Lexer, &Identifier);
        FuncVal.Val.Integer = -1 - Count;
        TableSet(GlobalTable, &Identifier.String, &FuncVal);
    }
}

void IntrinsicGetLexer(struct LexState *Lexer, int IntrinsicId)
{
    Lexer->Line = -IntrinsicId;
    Lexer->Pos = Intrinsics[-1-IntrinsicId].Prototype;
    Lexer->End = Lexer->Pos + strlen(Lexer->Pos);
    Lexer->FileName = &IntrinsicFilename;
}

void IntrinsicCall(struct LexState *Lexer, struct Value *Result, enum ValueType ReturnType, int IntrinsicId)
{
    Intrinsics[-1-IntrinsicId].Func();
    Result->Typ = TypeVoid;
}

