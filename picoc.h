#ifndef PICOC_H
#define PICOC_H

/* configurable options */
#define USE_MALLOC
#define GLOBAL_TABLE_SIZE 199

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
    TokenWhile
};

/* string type so we can use source file strings */
typedef struct _Str
{
    int Len;
    const char *Str;
} Str;


/* hash table data structure */
struct TableEntry
{
    Str Key;
    void *Value;
};
    
struct Table
{
    const char *Name;
    short Size;
    struct TableEntry *HashTable;
};


/* function definition - really just where it is in the source file */
struct FuncDef
{
    Str Source;
    Str FileName;
    int StartLine;
};


/* lexer state - so we can lex nested files */
struct LexState
{
    int Line;
    const char *Pos;
    const char *End;
};


/* str.c */
void StrToC(char *Dest, int DestSize, const Str *Source);
void StrFromC(Str *Dest, const char *Source);
int StrEqual(const Str *Str1, const Str *Str2);
int StrEqualC(const Str *Str1, const char *Str2);
void StrPrintf(const str *Format, ...);

/* picoc.c */
void Fail(const char *Message, ...);
void ProgramError(const Str *FileName, int Line, const char *Message, ...);
void ScanFile(const Str *FileName);

/* table.c */
void TableInit(struct Table *Tbl, struct TableEntry *HashTable, const char *Name, int Size);
void TableSet(struct Table *Tbl, const Str *Key, void *Value);
void *TableLookup(struct Table *Tbl, const Str *Key);

/* lex.c */
void LexInit(const Str *Source);
enum LexToken LexGetToken(void);

/* parse.c */
void ParseInit(void);
void ParseScan(const Str *FileName, const Str *Source);
void ParseCallFunction(const Str *FuncIdent, int argc, char **argv);

#endif /* PICOC_H */

