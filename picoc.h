#ifndef PICOC_H
#define PICOC_H

#include <stdarg.h>

/* configurable options */
#define HEAP_SIZE 2048                      /* space for the heap and the stack */
#define GLOBAL_TABLE_SIZE 397               /* global variable table */
#define FUNCTION_STORE_MAX 200              /* maximum number of used-defined functions and macros */
#define STACK_MAX 10                        /* maximum function call stack depth */
#define PARAMETER_MAX 10                    /* maximum number of parameters to a function */
#define LOCAL_TABLE_SIZE 11                 /* maximum number of local variables */
#define STRUCT_TABLE_SIZE 11                /* maximum number of struct/union members */
#define LARGE_INT_POWER_OF_TEN 1000000000   /* the largest power of ten which fits in an int on this architecture */
#define ARCH_ALIGN_WORDSIZE sizeof(int)     /* memory alignment boundary on this architecture */

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

/* string type so we can use source file strings */
typedef struct _Str
{
    int Len;
    const char *Str;
} Str;

/* lexer state - so we can lex nested files */
struct LexState
{
    int Line;
    const char *Pos;
    const char *End;
    const Str *FileName;
};

/* function definition - really just where it is in the source file */
struct FuncDef
{
    Str Source;
    Str FileName;
    int StartLine;
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

struct ValueType
{
    enum BaseType Base;         /* what kind of type this is */
    int ArraySize;              /* the size of an array type */
    int Sizeof;                 /* the storage required */
    Str Identifier;             /* the name of a struct or union */
    struct ValueType *FromType; /* the type we're derived from (or NULL) */
    struct ValueType *DerivedTypeList;  /* first in a list of types derived from this one */
    struct ValueType *Next;     /* next item in the derived type list */
    struct Table *Members;      /* members of a struct, union or enum */
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
    Str String;
    struct ArrayValue Array;
    struct PointerValue Pointer;
    struct LexState Lexer;
    struct ValueType *Typ;
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
    Str Key;
    struct Value *Val;
};
    
struct Table
{
    short Size;
    struct TableEntry *HashTable;
};

/* stack frame for function calls */
struct StackFrame
{
    struct LexState ReturnLex;              /* how we got here */
    struct Table LocalTable;                /* the local variables and parameters */
    struct TableEntry LocalHashTable[LOCAL_TABLE_SIZE];
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
extern Str StrEmpty;

/* str.c */
void StrToC(char *Dest, int DestSize, const Str *Source);
void StrFromC(Str *Dest, const char *Source);
int StrEqual(const Str *Str1, const Str *Str2);
int StrEqualC(const Str *Str1, const char *Str2);
void StrPrintf(const char *Format, ...);
void vStrPrintf(const char *Format, va_list Args);

/* picoc.c */
void Fail(const char *Message, ...);
void ProgramFail(struct LexState *Lexer, const char *Message, ...);
void ScanFile(const Str *FileName);

/* table.c */
void TableInit(struct Table *Tbl, struct TableEntry *HashTable, int Size);
int TableSet(struct Table *Tbl, const Str *Key, struct Value *Val);
int TableGet(struct Table *Tbl, const Str *Key, struct Value **Val);

/* lex.c */
void LexInit(struct LexState *Lexer, const Str *Source, const Str *FileName, int Line);
enum LexToken LexGetToken(struct LexState *Lexer, struct Value **Value);
enum LexToken LexGetPlainToken(struct LexState *Lexer);
enum LexToken LexPeekToken(struct LexState *Lexer, struct Value **Value);
enum LexToken LexPeekPlainToken(struct LexState *Lexer);
void LexToEndOfLine(struct LexState *Lexer);

/* parse.c */
void ParseInit(void);
int ParseExpression(struct LexState *Lexer, struct Value **Result, int ResultOnHeap, int RunIt);
int ParseIntExpression(struct LexState *Lexer, int RunIt);
void Parse(const Str *FileName, const Str *Source, int RunIt);

/* type.c */
void TypeInit();
int TypeSizeof(struct ValueType *Typ);
void TypeParse(struct LexState *Lexer, struct ValueType **Typ, Str *Identifier);

/* intrinsic.c */
void IntrinsicInit(struct Table *GlobalTable);
void IntrinsicGetLexer(struct LexState *Lexer, int IntrinsicId);
void IntrinsicCall(struct LexState *Lexer, struct Value *Result, struct ValueType *ReturnType, int IntrinsicId);

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
void *VariableAlloc(struct LexState *Lexer, int Size, int OnHeap);
void VariableStackPop(struct LexState *Lexer, struct Value *Var);
struct Value *VariableAllocValueAndData(struct LexState *Lexer, int DataSize, int OnHeap);
struct Value *VariableAllocValueAndCopy(struct LexState *Lexer, struct Value *FromValue, int OnHeap);
struct Value *VariableAllocValueFromType(struct LexState *Lexer, struct ValueType *Typ, int OnHeap);
void VariableDefine(struct LexState *Lexer, const Str *Ident, struct Value *InitValue);
int VariableDefined(Str *Ident);
void VariableGet(struct LexState *Lexer, Str *Ident, struct Value **LVal);
void VariableStackFrameAdd(struct LexState *Lexer);
void VariableStackFramePop(struct LexState *Lexer);

#endif /* PICOC_H */
