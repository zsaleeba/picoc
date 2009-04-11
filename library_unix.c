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

void Cpeek(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    int size, ptr;
    unsigned char *cp;
    unsigned short *sp;
    unsigned int *ip;
    
    /* x = peek(addr, size);
       mask ptr to align with word size */
    ptr = Param[0]->Val->Integer;
    size = Param[1]->Val->Integer;
    switch (size) {
        case 1: // char *
            cp = (unsigned char *)ptr;
            ReturnValue->Val->Integer = (int)((unsigned int)*cp);
            break;
        case 2: // short *
            sp = (unsigned short *)(ptr & 0xFFFFFFFE);  // align with even boundary
            ReturnValue->Val->Integer = (int)((unsigned short)*sp);
            break;
        case 4: // int *
            ip = (unsigned int *)(ptr & 0xFFFFFFFC);  // aling with quad boundary
            ReturnValue->Val->Integer = (int)*ip;
            break;
        default:
            ReturnValue->Val->Integer = 0;
            break;
    }
}

void Crandom(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->Integer = 1234;
}

void Cpoke(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    int size, ptr, val;
    unsigned char *cp;
    unsigned short *sp;
    unsigned int *ip;
    
    /* x = poke(addr, size, val);
       mask ptr to align with word size */
    ptr = Param[0]->Val->Integer;
    size = Param[1]->Val->Integer;
    val = Param[2]->Val->Integer;
    switch (size) {
        case 1: // char *
            cp = (unsigned char *)ptr;
            *cp = (unsigned char)(val & 0x000000FF);
            break;
        case 2: // short *
            sp = (unsigned short *)(ptr & 0xFFFFFFFE);
            *sp = (unsigned short)(val & 0x0000FFFF);
            break;
        case 4: // int *
            ip = (unsigned int *)(ptr & 0xFFFFFFFC);
            *ip = val;
            break;
        default: // don't bother with bad value
            break;
    }
}

/* list of all library functions and their prototypes */
struct LibraryFunction PlatformLibrary[] =
{
    { ShowComplex,   "void ShowComplex(struct complex *)" },
    { Cpeek,        "int peek(int, int)" },
    { Cpoke,        "void poke(int, int, int)" },
    { Crandom,      "int random(int, int)" },
    { NULL,         NULL }
};

