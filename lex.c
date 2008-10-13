#include "picoc.h"

#define LEXINC Lexer->Pos++
#define NEXTIS(c,x,y) { if (NextChar == (c)) { LEXINC; return (x); } else return (y); }
#define NEXTIS3(c,x,d,y,z) { if (NextChar == (c)) { LEXINC; return (x); } else NEXTIS(d,y,z) }
#define NEXTIS4(c,x,d,y,e,z,a) { if (NextChar == (c)) { LEXINC; return (x); } else NEXTIS3(d,y,e,z,a) }

struct ReservedWord
{
    const char *Word;
    enum LexToken Token;
};

static char *ReservedWords[] =
{
    { "char", TokenCharType },
    { "do", TokenDo },
    { "else", TokenElse },
    { "for", TokenFor },
    { "if", TokenIf },
    { "int", TokenIntType },
    { "while", TokenWhile },
    { "void", TokenVoidType }
};

void LexInit(struct LexState *Lexer, const Str *Source, int Line)
{
    Lexer->Pos = Source->Str;
    Lexer->End = Source->Str + Source->Len;
    Lexer->Line = Line;
}


enum LexToken LexCheckReservedWord(const Str *Word)
{
    int Count;
    
    for (Count = 0; Count < sizeof(ReservedWords) / sizeof(struct ReservedWord); Count++)
    {
        if (StrEqualC(Word, ReservedWord[Count].Word))
            return ReservedWord[Count].Token;
    }
    
    return TokenNone;
}


enum LexToken LexGetNumber(struct LexState *Lexer)
{
    XXX
}


enum LexToken LexGetWord(struct LexState *Lexer)
{
    XXX
}


enum LexToken LexGetToken(struct LexState *Lexer)
{
    char ThisChar;
    char NextChar;
    
    while (Lexer->Pos != Lexer->End && isspace(*Lexer->Pos))
        Lexer->Pos++;
    
    if (Lexer->Pos == Lexer->End)
        return TokenEOF;

    ThisChar = *Lexer->Pos;
    if (isCidstart(ThisChar))
        return LexGetWord(Lexer);
    
    if (isdigit(ThisChar))
        return LexGetNumber(Lexer);
    
    NextChar = (Lexer->Pos+1 != Lexer->End) ? *(Lexer->Pos+1) : 0;
    LEXINC;
    switch (ThisChar)
    {
        case '"': return LexGetStringConstant(Lexer);
        case '\'': return LexGetCharacterConstant(Lexer);
        case '(': return TokenOpenBracket;
        case ')': return TokenCloseBracket;
        case '=': NEXTIS('=', TokenEquality, TokenAssignment);
        case '+': NEXTIS3('=', TokenAddAssign, '+', TokenIncrement, TokenPlus);
        case '-': NEXTIS4('=', TokenSubtractAssign, '>', TokenArrow, '-', TokenDecrement, TokenMinus);
        case '*': return TokenAsterisk;
        case '/': return TokenSlash;
        case '<': NEXTIS('=', TokenLessEqual, TokenLess);
        case '>': NEXTIS('=', TokenGreaterEqual, TokenGreater);
        case ';': return TokenSemiColon;
        case '&': NEXTIS('&', TokenLogicalAnd, TokenAmpersand);
        case '|': NEXTIS('|', TokenLogicalOr, TokenArithmeticOr);
        case '{': return TokenLeftBrace;
        case '}': return TokenRightBrace;
        case '[': return TokenLeftAngleBracket;
        case ']': return TokenRightAngleBracket;
        case '^': return TokenArithmeticExor;
        case '~': return TokenUnaryExor;
        case ',': return TokenComma;
        case '.': return TokenDot;
    }

    ProgramError(Lexer->FileName, Lexer->Line, "illegal character '%c'", ThisChar);
    return TokenEOF;
}

