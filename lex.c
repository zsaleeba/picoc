#include <ctype.h>
#include <math.h>

#include "picoc.h"


#define isCidstart(c) (isalpha(c) || (c)=='_' || (c)=='#')
#define isCident(c) (isalnum(c) || (c)=='_')

#define NEXTIS(c,x,y) { if (NextChar == (c)) { Lexer->Pos++; return (x); } else return (y); }
#define NEXTIS3(c,x,d,y,z) { if (NextChar == (c)) { Lexer->Pos++; return (x); } else NEXTIS(d,y,z) }
#define NEXTIS4(c,x,d,y,e,z,a) { if (NextChar == (c)) { Lexer->Pos++; return (x); } else NEXTIS3(d,y,e,z,a) }


struct ReservedWord
{
    const char *Word;
    enum LexToken Token;
};

static struct ReservedWord ReservedWords[] =
{
    { "#define", TokenHashDefine },
    { "#include", TokenHashInclude },
    { "break", TokenBreak },
    { "case", TokenCase },
    { "char", TokenCharType },
    { "default", TokenDefault },
    { "do", TokenDo },
    { "double", TokenDoubleType },
    { "else", TokenElse },
    { "enum", TokenEnumType },
    { "float", TokenFloatType },
    { "for", TokenFor },
    { "if", TokenIf },
    { "int", TokenIntType },
    { "long", TokenLongType },
    { "return", TokenReturn },
    { "signed", TokenSignedType },
    { "short", TokenShortType },
    { "struct", TokenStructType },
    { "switch", TokenSwitch },
    { "typedef", TokenTypedef },
    { "union", TokenUnionType },
    { "unsigned", TokenUnsignedType },
    { "void", TokenVoidType },
    { "while", TokenWhile }
};

void LexInit(struct LexState *Lexer, const Str *Source, const Str *FileName, int Line)
{
    Lexer->Pos = Source->Str;
    Lexer->End = Source->Str + Source->Len;
    Lexer->Line = Line;
    Lexer->FileName = FileName;
}

enum LexToken LexCheckReservedWord(const Str *Word)
{
    int Count;
    
    for (Count = 0; Count < sizeof(ReservedWords) / sizeof(struct ReservedWord); Count++)
    {
        if (StrEqualC(Word, ReservedWords[Count].Word))
            return ReservedWords[Count].Token;
    }
    
    return TokenNone;
}

enum LexToken LexGetNumber(struct LexState *Lexer, union AnyValue *Value)
{
    int Result = 0;
    double FPResult;
    double FPDiv;
    
    for (; Lexer->Pos != Lexer->End && isdigit(*Lexer->Pos); Lexer->Pos++)
        Result = Result * 10 + (*Lexer->Pos - '0');

    Value->Integer = Result;
    if (Lexer->Pos == Lexer->End || *Lexer->Pos != '.')
        return TokenIntegerConstant;

    Lexer->Pos++;
    for (FPDiv = 0.1, FPResult = (double)Result; Lexer->Pos != Lexer->End && isdigit(*Lexer->Pos); Lexer->Pos++, FPDiv /= 10.0)
        FPResult += (*Lexer->Pos - '0') * FPDiv;
    
    if (Lexer->Pos != Lexer->End && (*Lexer->Pos == 'e' || *Lexer->Pos == 'E'))
    {
        Lexer->Pos++;
        for (Result = 0; Lexer->Pos != Lexer->End && isdigit(*Lexer->Pos); Lexer->Pos++)
            Result = Result * 10 + (*Lexer->Pos - '0');
            
        FPResult *= pow(10.0, (double)Result);
    }
    
    return TokenFPConstant;
}

enum LexToken LexGetWord(struct LexState *Lexer, union AnyValue *Value)
{
    const char *Pos = Lexer->Pos + 1;
    enum LexToken Token;
    
    while (Lexer->Pos != Lexer->End && isCident(*Pos))
        Pos++;
    
    Value->String.Str = Lexer->Pos;
    Value->String.Len = Pos - Lexer->Pos;
    Lexer->Pos = Pos;
    
    Token = LexCheckReservedWord(&Value->String);
    if (Token != TokenNone)
        return Token;
    
    return TokenIdentifier;
}

enum LexToken LexGetStringConstant(struct LexState *Lexer, union AnyValue *Value)
{
    int Escape = FALSE;
    
    Value->String.Str = Lexer->Pos;
    while (Lexer->Pos != Lexer->End && (*Lexer->Pos != '"' || Escape))
    {
        if (Escape)
            Escape = FALSE;
        else if (*Lexer->Pos == '\\')
            Escape = TRUE;
            
        Lexer->Pos++;
    }
    Value->String.Len = Lexer->Pos - Value->String.Str;
    if (*Lexer->Pos == '"')
        Lexer->Pos++;
    
    return TokenStringConstant;
}

enum LexToken LexGetCharacterConstant(struct LexState *Lexer, union AnyValue *Value)
{
    Value->Integer = Lexer->Pos[1];
    if (Lexer->Pos[2] != '\'')
        ProgramFail(Lexer, "illegal character '%c'", Lexer->Pos[2]);
        
    Lexer->Pos += 3;
    return TokenCharacterConstant;
}

enum LexToken LexGetComment(struct LexState *Lexer, char NextChar, union AnyValue *Value)
{
    Lexer->Pos++;
    if (NextChar == '*')
    {   /* conventional C comment */
        while (Lexer->Pos != Lexer->End && (*(Lexer->Pos-1) != '*' || *Lexer->Pos != '/'))
            Lexer->Pos++;
        
        if (Lexer->Pos != Lexer->End)
            Lexer->Pos++;
    }
    else
    {   /* C++ style comment */
        while (Lexer->Pos != Lexer->End && *Lexer->Pos != '\n')
            Lexer->Pos++;
    }

    return LexGetToken(Lexer, Value);
}

enum LexToken LexGetTokenUncached(struct LexState *Lexer, union AnyValue *Value)
{
    char ThisChar;
    char NextChar;
    
    while (Lexer->Pos != Lexer->End && isspace(*Lexer->Pos))
    {
        if (*Lexer->Pos == '\n')
            Lexer->Line++;

        Lexer->Pos++;
    }
    
    if (Lexer->Pos == Lexer->End)
        return TokenEOF;

    ThisChar = *Lexer->Pos;
    if (isCidstart(ThisChar))
        return LexGetWord(Lexer, Value);
    
    if (isdigit(ThisChar))
        return LexGetNumber(Lexer, Value);
    
    NextChar = (Lexer->Pos+1 != Lexer->End) ? *(Lexer->Pos+1) : 0;
    Lexer->Pos++;
    switch (ThisChar)
    {
        case '"': return LexGetStringConstant(Lexer, Value);
        case '\'': return LexGetCharacterConstant(Lexer, Value);
        case '(': return TokenOpenBracket;
        case ')': return TokenCloseBracket;
        case '=': NEXTIS('=', TokenEquality, TokenAssign);
        case '+': NEXTIS3('=', TokenAddAssign, '+', TokenIncrement, TokenPlus);
        case '-': NEXTIS4('=', TokenSubtractAssign, '>', TokenArrow, '-', TokenDecrement, TokenMinus);
        case '*': return TokenAsterisk;
        case '/': if (NextChar == '/' || NextChar == '*') return LexGetComment(Lexer, NextChar, Value); else return TokenSlash;
        case '<': NEXTIS('=', TokenLessEqual, TokenLessThan);
        case '>': NEXTIS('=', TokenGreaterEqual, TokenGreaterThan);
        case ';': return TokenSemicolon;
        case '&': NEXTIS('&', TokenLogicalAnd, TokenAmpersand);
        case '|': NEXTIS('|', TokenLogicalOr, TokenArithmeticOr);
        case '{': return TokenLeftBrace;
        case '}': return TokenRightBrace;
        case '[': return TokenLeftAngleBracket;
        case ']': return TokenRightAngleBracket;
        case '!': return TokenUnaryNot;
        case '^': return TokenArithmeticExor;
        case '~': return TokenUnaryExor;
        case ',': return TokenComma;
        case '.': return TokenDot;
    }

    ProgramFail(Lexer, "illegal character '%c'", ThisChar);
    return TokenEOF;
}

enum LexToken LexGetToken(struct LexState *Lexer, union AnyValue *Value)
{
    static const char *CachedPos = NULL;
    static union AnyValue CachedValue;
    static struct LexState CachedLexer;
    static enum LexToken CachedToken;
    
    if (Lexer->Pos == CachedPos)
    {
        *Value = CachedValue;
        *Lexer = CachedLexer;
    }
    else
    {
        CachedPos = Lexer->Pos;
        CachedToken = LexGetTokenUncached(Lexer, Value);
        CachedLexer = *Lexer;
        CachedValue = *Value;
    }
    
    return CachedToken;
}

enum LexToken LexGetPlainToken(struct LexState *Lexer)
{
    union AnyValue Value;
    return LexGetToken(Lexer, &Value);
}

/* look at the next token without changing the lexer state */
enum LexToken LexPeekToken(struct LexState *Lexer, union AnyValue *Value)
{
    struct LexState LocalState = *Lexer;
    return LexGetToken(&LocalState, Value);
}

enum LexToken LexPeekPlainToken(struct LexState *Lexer)
{
    struct LexState LocalState = *Lexer;
    union AnyValue Value;
    return LexGetToken(&LocalState, &Value);
}

/* skip everything up to the end of the line */
void LexToEndOfLine(struct LexState *Lexer)
{
    while (Lexer->Pos != Lexer->End && *Lexer->Pos != '\n')
        Lexer->Pos++;
}
