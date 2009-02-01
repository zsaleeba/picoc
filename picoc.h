#ifndef PICOC_H
#define PICOC_H

#include <stdarg.h>

/* configurable options */
#define HEAP_SIZE 2048                      /* space for the heap and the stack */
#define LARGE_INT_POWER_OF_TEN 1000000000   /* the largest power of ten which fits in an int on this architecture */
#define ARCH_ALIGN_WORDSIZE sizeof(int)     /* memory alignment boundary on this architecture */

#define GLOBAL_TABLE_SIZE 397               /* global variable table */
#define STRING_TABLE_SIZE 97                /* shared string table size */
#define PARAMETER_MAX 10                    /* maximum number of parameters to a function */
#define LINEBUFFER_MAX 256                  /* maximum number of characters on a line */
#define LOCAL_TABLE_SIZE 11                 /* size of local variable table (can expand) */
#define STRUCT_TABLE_SIZE 11                /* size of struct/union member table (can expand) */

/* handy definitions */
#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef min
#define min(x,y) (((x)<(y))?(x):(y))
#endif

#define MEM_ALIGN(x) (((x) + ARCH_ALIGN_WORDSIZE - 1) & ~(ARCH_ALIGN_WORDSIZE-1))

#define LOG10E 0.43429448190325182765

#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

#define ISVALUETYPE(t) (((t)->Base == TypeInt) || ((t)->Base == TypeFP) || ((t)->Base == TypeString))

struct Table;

/* lexical tokens */
enum LexToken
{
    TokenNone, TokenEOF, TokenEndOfLine,
    TokenIdentifier, TokenIntegerConstant, TokenFPConstant, TokenStringConstant, TokenCharacterConstant,
    TokenOpenBracket, TokenCloseBracket,
    TokenAssign, TokenPlus, TokenMinus, TokenAsterisk, TokenSlash,
    TokenEquality, TokenLessThan, TokenGreaterThan, TokenLessEqual, TokenGreaterEqual,
    TokenSemicolon, TokenComma, TokenDot,
    TokenArrow, TokenAmpersand,
    TokenLeftBrace, TokenRightBrace,
    TokenLeftSquareBracket, TokenRightSquareBracket,
    TokenLogicalAnd, TokenLogicalOr, TokenArithmeticOr, TokenArithmeticExor, TokenUnaryExor, TokenUnaryNot,
    TokenAddAssign, TokenSubtractAssign,
    TokenIncrement, TokenDecrement,
    TokenIntType, TokenCharType, TokenFloatType, TokenDoubleType, TokenVoidType, TokenEnumType,
    TokenLongType, TokenSignedType, TokenShortType, TokenStructType, TokenUnionType, TokenUnsignedType, TokenTypedef,
    TokenDo, TokenElse, TokenFor, TokenIf, TokenWhile, TokenBreak, TokenSwitch, TokenCase, TokenDefault, TokenReturn,
    TokenHashDefine, TokenHashInclude
};

/* parser state - has all this detail so we can parse nested files */
struct ParseState
{
    const void *Pos;
    const void *End;
    int Line;
    const char *FileName;
};

/* values */
enum BaseType
{
    TypeVoid,                   /* no type */
    TypeInt,                    /* integer */
    TypeFP,                     /* floating point */
    TypeChar,                   /* a single character - acts like an integer except in machine memory access */
    TypeString,                 /* a constant source text string with C string emulation */
    TypeFunction,               /* a function */
    TypeMacro,                  /* a macro */
    TypePointer,                /* a pointer */
    TypeArray,                  /* an array of a sub-type */
    TypeStruct,                 /* aggregate type */
    TypeUnion,                  /* merged type */
    TypeEnum,                   /* enumated integer type */
    TypeType                    /* a type (eg. typedef) */
};

/* data type */
struct ValueType
{
    enum BaseType Base;         /* what kind of type this is */
    int ArraySize;              /* the size of an array type */
    int Sizeof;                 /* the storage required */
    const char *Identifier;     /* the name of a struct or union */
    struct ValueType *FromType; /* the type we're derived from (or NULL) */
    struct ValueType *DerivedTypeList;  /* first in a list of types derived from this one */
    struct ValueType *Next;     /* next item in the derived type list */
    struct Table *Members;      /* members of a struct, union or enum */
};

/* function definition */
struct FuncDef
{
    struct ValueType *ReturnType;   /* the return value type */
    int NumParams;                  /* the number of parameters */
    struct Typ *ParamType;          /* array of parameter types */
    const char **ParamName;         /* array of parameter names */
    void (*Intrinsic)();            /* intrinsic call address or NULL */
    struct ParseState Body;         /* lexical tokens of the function body if not intrinsic */
};

struct ArrayValue
{
    unsigned int Size;          /* the number of elements in the array */
    void *Data;                 /* pointer to the array data */
};

struct PointerValue
{
    struct Value *Segment;      /* array or basic value which this points to, NULL for machine memory access */
    union s {
        unsigned int Offset;    /* index into an array */
        void *Memory;           /* machine memory pointer for raw memory access */
    } Data;
};

union AnyValue
{
    unsigned char Character;
    short ShortInteger;
    int Integer;
    double FP;
    char *String;
    struct ArrayValue Array;
    struct PointerValue Pointer;
    struct ParseState Parser;
    struct ValueType *Typ;
    struct FuncDef FuncDef;
};

struct Value
{
    struct ValueType *Typ;
    union AnyValue *Val;
    char ValOnHeap;
    char ValOnStack;
};

/* hash table data structure */
struct TableEntry
{
    const char *Key;
    struct Value *Val;
    struct TableEntry *Next;
};
    
struct Table
{
    short Size;
    short OnHeap;
    struct TableEntry **HashTable;
};

/* stack frame for function calls */
struct StackFrame
{
    struct ParseState ReturnParser;         /* how we got here */
    struct Table LocalTable;                /* the local variables and parameters */
    struct TableEntry *LocalHashTable[LOCAL_TABLE_SIZE];
    struct StackFrame *PreviousStackFrame;  /* the next lower stack frame */
};

/* globals */
extern struct Table GlobalTable;
extern struct Value *Parameter[PARAMETER_MAX];
extern int ParameterUsed;
extern struct StackFrame *TopStackFrame;
extern struct Value *ReturnValue;
extern struct ValueType IntType;
extern struct ValueType CharType;
extern struct ValueType StringType;
extern struct ValueType FPType;
extern struct ValueType VoidType;
extern struct ValueType FunctionType;
extern struct ValueType MacroType;

/* picoc.c */
void ProgramFail(struct ParseState *Parser, const char *Message, ...);
void ScanFile(const char *FileName);

/* table.c */
void TableInit(struct Table *Tbl, struct TableEntry **HashTable, int Size, int OnHeap);
int TableSet(struct Table *Tbl, const char *Key, struct Value *Val);
int TableGet(struct Table *Tbl, const char *Key, struct Value **Val);
const char *TableSetKey(struct Table *Tbl, const char *Ident, int IdentLen);

/* lex.c */
void LexInit(struct ParseState *Parser, const char *Source, int SourceLen, const char *FileName, int Line);
enum LexToken LexGetToken(struct ParseState *Parser, struct Value **Value, int IncPos);
void LexToEndOfLine(struct ParseState *Parser);

/* parse.c */
void ParseInit(void);
int ParseExpression(struct ParseState *Parser, struct Value **Result, int ResultOnHeap, int RunIt);
int ParseIntExpression(struct ParseState *Parser, int RunIt);
int ParseStatement(struct ParseState *Parser, int RunIt);
void Parse(const char *FileName, const char *Source, int SourceLen, int RunIt);

/* type.c */
void TypeInit();
int TypeSizeof(struct ValueType *Typ);
void TypeParse(struct ParseState *Parser, struct ValueType **Typ, const char **Identifier);

/* intrinsic.c */
void IntrinsicInit(struct Table *GlobalTable);
void IntrinsicGetLexer(struct ParseState *Parser, int IntrinsicId);
void IntrinsicCall(struct ParseState *Parser, struct Value *Result, struct ValueType *ReturnType, int IntrinsicId);

/* heap.c */
void HeapInit();
void *HeapAllocStack(int Size);
int HeapPopStack(void *Addr, int Size);
void HeapPushStackFrame();
int HeapPopStackFrame();
void *HeapAlloc(int Size);
void HeapFree(void *Mem);

/* variable.c */
void VariableInit();
void *VariableAlloc(struct ParseState *Parser, int Size, int OnHeap);
void VariableStackPop(struct ParseState *Parser, struct Value *Var);
struct Value *VariableAllocValueAndData(struct ParseState *Parser, int DataSize, int OnHeap);
struct Value *VariableAllocValueAndCopy(struct ParseState *Parser, struct Value *FromValue, int OnHeap);
struct Value *VariableAllocValueFromType(struct ParseState *Parser, struct ValueType *Typ, int OnHeap);
void VariableDefine(struct ParseState *Parser, const char *Ident, struct Value *InitValue);
int VariableDefined(const char *Ident);
void VariableGet(struct ParseState *Parser, const char *Ident, struct Value **LVal);
void VariableStackFrameAdd(struct ParseState *Parser);
void VariableStackFramePop(struct ParseState *Parser);

/* str.c */
void StrInit();
const char *StrRegister(const char *Str);
const char *StrRegister2(const char *Str, int Len);

#endif /* PICOC_H */
