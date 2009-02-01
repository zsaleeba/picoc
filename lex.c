#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#include "picoc.h"


#define isCidstart(c) (isalpha(c) || (c)=='_' || (c)=='#')
#define isCident(c) (isalnum(c) || (c)=='_')

#define NEXTIS(c,x,y) { if (NextChar == (c)) { Lexer->Pos++; return (x); } else return (y); }
#define NEXTIS3(c,x,d,y,z) { if (NextChar == (c)) { Lexer->Pos++; return (x); } else NEXTIS(d,y,z) }
#define NEXTIS4(c,x,d,y,e,z,a) { if (NextChar == (c)) { Lexer->Pos++; return (x); } else NEXTIS3(d,y,e,z,a) }

static union AnyValue LexAnyValue;
static struct Value LexValue = { TypeVoid, &LexAnyValue, FALSE, FALSE };

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

struct LexState
{
    const char *Pos;
    const char *End;
    int Line;
    const char *FileName;
};

void LexInit(struct ParseState *Parser, const char *Source, int SourceLen, const char *FileName, int Line)
{
    Parser->Pos = Source;
    Parser->End = Source + SourceLen;
    Parser->Line = Line;
    Parser->FileName = FileName;
}

void LexFail(struct LexState *Lexer, const char *Message, ...)
{
    va_list Args;

    printf("%s:%d: ", Lexer->FileName, Lexer->Line);      
    va_start(Args, Message);
    vprintf(Message, Args);
    printf("\n");
    exit(1);
}

enum LexToken LexCheckReservedWord(const char *Word)
{
    int Count;
    
    for (Count = 0; Count < sizeof(ReservedWords) / sizeof(struct ReservedWord); Count++)
    {
        if (strcmp(Word, ReservedWords[Count].Word) == 0)
            return ReservedWords[Count].Token;
    }
    
    return TokenNone;
}

enum LexToken LexGetNumber(struct LexState *Lexer, struct Value *Value)
{
    int Result = 0;
    double FPResult;
    double FPDiv;
    
    for (; Lexer->Pos != Lexer->End && isdigit(*Lexer->Pos); Lexer->Pos++)
        Result = Result * 10 + (*Lexer->Pos - '0');

    Value->Typ = &IntType;
    Value->Val->Integer = Result;
    if (Lexer->Pos == Lexer->End || *Lexer->Pos != '.')
        return TokenIntegerConstant;

    Value->Typ = &FPType;
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

enum LexToken LexGetWord(struct LexState *Lexer, struct Value *Value)
{
    const char *Pos = Lexer->Pos + 1;
    enum LexToken Token;
    
    while (Lexer->Pos != Lexer->End && isCident(*Pos))
        Pos++;
    
    Value->Typ = &StringType;
    Value->Val->String = (char *)StrRegister2(Lexer->Pos, Pos - Lexer->Pos);
    Lexer->Pos = Pos;
    
    Token = LexCheckReservedWord(Value->Val->String);
    if (Token != TokenNone)
        return Token;
    
    return TokenIdentifier;
}

enum LexToken LexGetStringConstant(struct LexState *Lexer, struct Value *Value)
{
    int Escape = FALSE;
    const char *StartPos = Lexer->Pos;
    
    // XXX - do escaping here
    Value->Typ = &StringType;
    while (Lexer->Pos != Lexer->End && (*Lexer->Pos != '"' || Escape))
    {
        if (Escape)
            Escape = FALSE;
        else if (*Lexer->Pos == '\\')
            Escape = TRUE;
            
        Lexer->Pos++;
    }
    Value->Val->String = (char *)StrRegister2(StartPos, Lexer->Pos - StartPos);
    if (*Lexer->Pos == '"')
        Lexer->Pos++;
    
    return TokenStringConstant;
}

enum LexToken LexGetCharacterConstant(struct LexState *Lexer, struct Value *Value)
{
    Value->Typ = &IntType;
    Value->Val->Integer = Lexer->Pos[1];
    if (Lexer->Pos[2] != '\'')
        LexFail(Lexer, "illegal character '%c'", Lexer->Pos[2]);
        
    Lexer->Pos += 3;
    return TokenCharacterConstant;
}

enum LexToken LexGetComment(struct LexState *Lexer, char NextChar, struct Value *Value)
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

enum LexToken LexGetTokenToStack(struct LexState *Lexer, struct Value **Value)
{
    char ThisChar;
    char NextChar;
    
    if (Lexer->Pos == Lexer->End)
    {
        char LineBuffer[LINEBUFFER_MAX];
        if (fgets(&LineBuffer[0], LINEBUFFER_MAX, stdin) == NULL)
            return TokenEOF;
    }
    
    *Value = &LexValue;
    while (Lexer->Pos != Lexer->End && isspace(*Lexer->Pos))
    {
        if (*Lexer->Pos == '\n')
            Lexer->Line++;

        Lexer->Pos++;
    }
    
    ThisChar = *Lexer->Pos;
    if (isCidstart(ThisChar))
        return LexGetWord(Lexer, *Value);
    
    if (isdigit(ThisChar))
        return LexGetNumber(Lexer, *Value);
    
    NextChar = (Lexer->Pos+1 != Lexer->End) ? *(Lexer->Pos+1) : 0;
    Lexer->Pos++;
    switch (ThisChar)
    {
        case '"': return LexGetStringConstant(Lexer, *Value);
        case '\'': return LexGetCharacterConstant(Lexer, *Value);
        case '(': return TokenOpenBracket;
        case ')': return TokenCloseBracket;
        case '=': NEXTIS('=', TokenEquality, TokenAssign);
        case '+': NEXTIS3('=', TokenAddAssign, '+', TokenIncrement, TokenPlus);
        case '-': NEXTIS4('=', TokenSubtractAssign, '>', TokenArrow, '-', TokenDecrement, TokenMinus);
        case '*': return TokenAsterisk;
        case '/': if (NextChar == '/' || NextChar == '*') return LexGetComment(Lexer, NextChar, *Value); else return TokenSlash;
        case '<': NEXTIS('=', TokenLessEqual, TokenLessThan);
        case '>': NEXTIS('=', TokenGreaterEqual, TokenGreaterThan);
        case ';': return TokenSemicolon;
        case '&': NEXTIS('&', TokenLogicalAnd, TokenAmpersand);
        case '|': NEXTIS('|', TokenLogicalOr, TokenArithmeticOr);
        case '{': return TokenLeftBrace;
        case '}': return TokenRightBrace;
        case '[': return TokenLeftSquareBracket;
        case ']': return TokenRightSquareBracket;
        case '!': return TokenUnaryNot;
        case '^': return TokenArithmeticExor;
        case '~': return TokenUnaryExor;
        case ',': return TokenComma;
        case '.': return TokenDot;
    }

    LexFail(Lexer, "illegal character '%c'", ThisChar);
    return TokenEOF;
}

void LexTokeniseToStack(struct LexState *Lexer, struct Value **Value)
{
    XXX - finish this
}

enum LexToken LexGetToken(struct ParseState *Parser, struct Value **Value, int IncPos)
{
    enum LexToken;
        
    while (Parser->Pos != Parser->End && (enum LexToken)*(unsigned char *)Parser->Pos == TokenEndOfLine)
    { /* skip leading newlines */
        Pos->Line++;
        Pos++;
    }
    
    if (Parser->Pos == Parser->End)
        return TokenEOF;

    LexToken = (enum LexToken)*(unsigned char *)Parser->Pos;
    if (LexToken >= TokenIdentifier && LexToken <= TokenCharacterConstant)
    { /* this token requires a value */
        int ValueLen = sizeof(struct Value) + ((struct Value *)Parser->Pos)->Typ->Sizeof;
        if (Value != NULL)
        { /* copy the value out (aligns it in the process) */
            memcpy(LexValue, (struct Value *)Parser->Pos, ValueLen);
            *Value = &LexValue;
        }
        
        if (IncPos)
            Parser->Pos += ValueLen + 1;
    }
    else
    {
        if (IncPos)
            Parser->Pos++;
    }
    
    return LexToken;
}

