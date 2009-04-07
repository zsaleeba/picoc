#include "picoc.h"

void PlatformLibraryInit()
{
    struct ParseState Parser;
    char *Identifier;
    struct ValueType *ParsedType;
    void *Tokens;
    const char *IntrinsicName = TableStrRegister("unix library");
    const char *StructDefinition = "struct complex { int i; int j; }";
    
    /* define an example structure */
    Tokens = LexAnalyse(IntrinsicName, StructDefinition, strlen(StructDefinition), NULL);
    LexInitParser(&Parser, Tokens, IntrinsicName, 1, TRUE);
    TypeParse(&Parser, &ParsedType, &Identifier);
    HeapFree(Tokens);
}

void ShowComplex(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    struct Value *ComplexVal = Param[0]->Val->Pointer.Segment;  /* dereferences the pointer */
    struct Value *RealOffset;
    struct Value *ComplexOffset;
    int RealPart;
    int ComplexPart;
    struct ValueType *StructComplexType;
    
    /* find the type */
    StructComplexType = TypeGetMatching(Parser, &UberType, TypeStruct, 0, TableStrRegister("complex"));
    
    /* get the real and complex members */
    TableGet(StructComplexType->Members, TableStrRegister("i"), &RealOffset);
    RealPart = *(int *)((void *)ComplexVal->Val + RealOffset->Val->Integer);
    
    TableGet(StructComplexType->Members, TableStrRegister("j"), &ComplexOffset);
    ComplexPart = *(int *)((void *)ComplexVal->Val + ComplexOffset->Val->Integer);
    
    /* print the result */
    PrintInt(RealPart, PlatformPutc);
    PlatformPutc(',');
    PrintInt(ComplexPart, PlatformPutc);
}

/* list of all library functions and their prototypes */
struct LibraryFunction PlatformLibrary[] =
{
    { ShowComplex,   "void ShowComplex(struct complex *)" },
    { NULL,         NULL }
};

