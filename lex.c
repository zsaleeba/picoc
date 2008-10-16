#include <ctype.h>

#include "picoc.h"


#define isCidstart(c) (isalpha(c) || (c)=='_')
#define isCident(c) (isalnum(c) || (c)=='_')

#define LEXINC Lexer->Pos++
#define NEXTIS(c,x,y) { if (NextChar == (c)) { LEXINC; return (x); } else return (y); }
#define NEXTIS3(c,x,d,y,z) { if (NextChar == (c)) { LEXINC; return (x); } else NEXTIS(d,y,z) }
#define NEXTIS4(c,x,d,y,e,z,a) { if (NextChar == (c)) { LEXINC; return (x); } else NEXTIS3(d,y,e,z,a) }


struct ReservedWord
{
    const char *Word;
    enum LexToken Token;
};

static struct ReservedWord ReservedWords[] =
{
    { "break", TokenBreak },
    { "case", TokenCase },
    { "char", TokenCharType },
    { "default", TokenDefault },
    { "do", TokenDo },
    { "else", TokenElse },
    { "for", TokenFor },
    { "if", TokenIf },
    { "int", TokenIntType },
    { "return", TokenReturn },
    { "switch", TokenSwitch },
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

enum LexToken LexGetNumber(struct LexState *Lexer)
{
    int Result = 0;
    
    while (Lexer->Pos != Lexer->End && isdigit(*Lexer->Pos))
        Result = Result * 10 + (*Lexer->Pos - '0');

    Lexer->Value.Integer = Result;
    return TokenIntegerConstant;
}

enum LexToken LexGetWord(struct LexState *Lexer)
{
    const char *Pos = Lexer->Pos + 1;
    enum LexToken Token;
    
    while (Lexer->Pos != Lexer->End && isCident(*Pos))
        Pos++;
    
    Lexer->Value.String.Str = Lexer->Pos;
    Lexer->Value.String.Len = Pos - Lexer->Pos;
    Lexer->Pos = Pos;
    
    Token = LexCheckReservedWord(&Lexer->Value.String);
    if (Token != TokenNone)
        return Token;
    
    return TokenIdentifier;
}

enum LexToken LexGetStringConstant(struct LexState *Lexer)
{
    int Escape = FALSE;
    
    Lexer->Pos++;
    Lexer->Value.String.Str = Lexer->Pos;
    while (Lexer->Pos != Lexer->End && !Escape && *Lexer->Pos != '"')
    {
        if (Escape)
            Escape = FALSE;
        else if (*Lexer->Pos == '\\')
            Escape = TRUE;
    }
    Lexer->Value.String.Len = Lexer->Pos - Lexer->Value.String.Str;
    if (*Lexer->Pos != '"')
        Lexer->Pos++;
    
    return TokenStringConstant;
}

enum LexToken LexGetCharacterConstant(struct LexState *Lexer)
{
    Lexer->Value.Integer = Lexer->Pos[1];
    if (Lexer->Pos[2] != '\'')
        ProgramError(Lexer->FileName, Lexer->Line, "illegal character '%c'", Lexer->Pos[2]);
        
    Lexer->Pos += 3;
    return TokenCharacterConstant;
}

enum LexToken LexGetToken(struct LexState *Lexer)
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
        case '=': NEXTIS('=', TokenEquality, TokenAssign);
        case '+': NEXTIS3('=', TokenAddAssign, '+', TokenIncrement, TokenPlus);
        case '-': NEXTIS4('=', TokenSubtractAssign, '>', TokenArrow, '-', TokenDecrement, TokenMinus);
        case '*': return TokenAsterisk;
        case '/': return TokenSlash;
        case '<': NEXTIS('=', TokenLessEqual, TokenLessThan);
        case '>': NEXTIS('=', TokenGreaterEqual, TokenGreaterThan);
        case ';': return TokenSemicolon;
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

