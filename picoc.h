#ifndef PICOC_H
#define PICOC_H

#include <stdarg.h>

/* configurable options */
#define USE_MALLOC
#define GLOBAL_TABLE_SIZE 199               /* global variable table */
#define FUNCTION_STORE_MAX 50               /* maximum number of used-defined functions */
#define LARGE_INT_POWER_OF_TEN 1000000000   /* the largest power of ten which fits in an int on this architecture */

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

#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

/* lexical tokens */
enum LexToken
{
    TokenNone,
    TokenEOF,
    TokenIdentifier,
    TokenIntegerConstant,
    TokenStringConstant,
    TokenCharacterConstant,
    TokenType,
    TokenOpenBracket,
    TokenCloseBracket,
    TokenAssign,
    TokenPlus,
    TokenMinus,
    TokenAsterisk,
    TokenSlash,
    TokenEquality,
    TokenLessThan,
    TokenGreaterThan,
    TokenLessEqual,
    TokenGreaterEqual,
    TokenSemicolon,
    TokenArrow,
    TokenAmpersand,
    TokenLeftBrace,
    TokenRightBrace,
    TokenLeftAngleBracket,
    TokenRightAngleBracket,
    TokenLogicalAnd,
    TokenLogicalOr,
    TokenArithmeticOr,
    TokenArithmeticExor,
    TokenUnaryExor,
    TokenUnaryNot,
    TokenComma,
    TokenDot,
    TokenAddAssign,
    TokenSubtractAssign,
    TokenIncrement,
    TokenDecrement,
    TokenIntType,
    TokenCharType,
    TokenVoidType,
    TokenDo,
    TokenElse,
    TokenFor,
    TokenIf,
    TokenWhile,
    TokenBreak,
    TokenSwitch,
    TokenCase,
    TokenDefault,
    TokenReturn
};

/* string type so we can use source file strings */
typedef struct _Str
{
    int Len;
    const char *Str;
} Str;

/* function definition - really just where it is in the source file */
struct FuncDef
{
    Str Source;
    Str FileName;
    int StartLine;
};

/* values */
enum ValueType
{
    TypeVoid,
    TypeInt,
    TypeString,
    TypeFunction
};

union AnyValue
{
    int Integer;
    Str String;
};

struct Value
{
    enum ValueType Typ;
    union AnyValue Val;
};

/* hash table data structure */
struct TableEntry
{
    Str Key;
    struct Value Val;
};
    
struct Table
{
    const char *Name;
    short Size;
    struct TableEntry *HashTable;
};

/* lexer state - so we can lex nested files */
struct LexState
{
    int Line;
    const char *Pos;
    const char *End;
    const Str *FileName;
};


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
void TableInit(struct Table *Tbl, struct TableEntry *HashTable, const char *Name, int Size);
int TableSet(struct Table *Tbl, const Str *Key, struct Value *Val, int Exists);
int TableGet(struct Table *Tbl, const Str *Key, struct Value **Val);

/* lex.c */
void LexInit(struct LexState *Lexer, const Str *Source, const Str *FileName, int Line);
enum LexToken LexGetToken(struct LexState *Lexer, union AnyValue *Value);
enum LexToken LexPeekToken(struct LexState *Lexer, union AnyValue *Value);

/* parse.c */
void ParseInit(void);
void Parse(const Str *FileName, const Str *Source, int RunIt);

#endif /* PICOC_H */

