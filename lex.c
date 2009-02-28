#include "picoc.h"

#ifdef NO_CTYPE
#define isalpha(c) (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'))
#define isdigit(c) ((c) >= '0' && (c) <= '9')
#define isalnum(c) (isalpha(c) || isdigit(c))
#define isspace(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\n')
#endif
#define isCidstart(c) (isalpha(c) || (c)=='_' || (c)=='#')
#define isCident(c) (isalnum(c) || (c)=='_')

#define NEXTIS(c,x,y) { if (NextChar == (c)) { Lexer->Pos++; GotToken = (x); } else GotToken = (y); }
#define NEXTIS3(c,x,d,y,z) { if (NextChar == (c)) { Lexer->Pos++; GotToken = (x); } else NEXTIS(d,y,z) }
#define NEXTIS4(c,x,d,y,e,z,a) { if (NextChar == (c)) { Lexer->Pos++; GotToken = (x); } else NEXTIS3(d,y,e,z,a) }
#define NEXTIS3PLUS(c,x,d,y,e,z,a) { if (NextChar == (c)) { Lexer->Pos++; GotToken = (x); } else if (NextChar == (d)) { if (Lexer->Pos[1] == (e)) { Lexer->Pos += 2; GotToken = (z); } else { Lexer->Pos++; GotToken = (y); } } else GotToken = (a); }
#define NEXTISEXACTLY3(c,d,y,z) { if (NextChar == (c) && Lexer->Pos[1] == (d)) { Lexer->Pos += 2; GotToken = (y); } else GotToken = (z); }

static union AnyValue LexAnyValue;
static struct Value LexValue = { TypeVoid, &LexAnyValue, FALSE, FALSE };

struct ReservedWord
{
    const char *Word;
    enum LexToken Token;
    const char *SharedWord; /* word stored in shared string space */
};

static struct ReservedWord ReservedWords[] =
{
    { "#define", TokenHashDefine, NULL },
    { "#include", TokenHashInclude, NULL },
    { "break", TokenBreak, NULL },
    { "case", TokenCase, NULL },
    { "char", TokenCharType, NULL },
    { "continue", TokenContinue, NULL },
    { "default", TokenDefault, NULL },
    { "do", TokenDo, NULL },
#ifndef NO_FP
    { "double", TokenDoubleType, NULL },
#endif
    { "else", TokenElse, NULL },
    { "enum", TokenEnumType, NULL },
#ifndef NO_FP
    { "float", TokenFloatType, NULL },
#endif
    { "for", TokenFor, NULL },
    { "if", TokenIf, NULL },
    { "int", TokenIntType, NULL },
    { "long", TokenLongType, NULL },
    { "return", TokenReturn, NULL },
    { "short", TokenShortType, NULL },
    { "signed", TokenSignedType, NULL },
    { "sizeof", TokenSizeof, NULL },
    { "struct", TokenStructType, NULL },
    { "switch", TokenSwitch, NULL },
    { "typedef", TokenTypedef, NULL },
    { "union", TokenUnionType, NULL },
    { "unsigned", TokenUnsignedType, NULL },
    { "void", TokenVoidType, NULL },
    { "while", TokenWhile, NULL }
};


/* initialise the lexer */
void LexInit()
{
    int Count;
    
    for (Count = 0; Count < sizeof(ReservedWords) / sizeof(struct ReservedWord); Count++)
        ReservedWords[Count].SharedWord = TableStrRegister(ReservedWords[Count].Word);
}

/* check if a word is a reserved word - used while scanning */
enum LexToken LexCheckReservedWord(const char *Word)
{
    int Count;
    
    for (Count = 0; Count < sizeof(ReservedWords) / sizeof(struct ReservedWord); Count++)
    {
        if (Word == ReservedWords[Count].SharedWord)
            return ReservedWords[Count].Token;
    }
    
    return TokenNone;
}

/* get a numeric constant - used while scanning */
enum LexToken LexGetNumber(struct LexState *Lexer, struct Value *Value)
{
    int Result = 0;
#ifndef NO_FP
    double FPResult;
    double FPDiv;
#endif
    
    for (; Lexer->Pos != Lexer->End && isdigit(*Lexer->Pos); Lexer->Pos++)
        Result = Result * 10 + (*Lexer->Pos - '0');

    Value->Typ = &IntType;
    Value->Val->Integer = Result;
#ifndef NO_FP
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
#else
    return TokenIntegerConstant;
#endif
}

/* get a reserved word or identifier - used while scanning */
enum LexToken LexGetWord(struct LexState *Lexer, struct Value *Value)
{
    const char *Pos = Lexer->Pos + 1;
    enum LexToken Token;
    
    while (Lexer->Pos != Lexer->End && isCident(*Pos))
        Pos++;
    
    Value->Typ = NULL;
    Value->Val->Identifier = TableStrRegister2(Lexer->Pos, Pos - Lexer->Pos);
    Lexer->Pos = Pos;
    
    Token = LexCheckReservedWord(Value->Val->Identifier);
    if (Token != TokenNone)
        return Token;
    
    return TokenIdentifier;
}

/* unescape a character from a string or character constant */
unsigned char LexUnEscapeCharacter(const char **From, const char *End)
{
    unsigned char ThisChar;
    
    while ( *From != End && **From == '\\' && 
            &(*From)[1] != End && (*From)[1] == '\n')
        (*From) += 2;       /* skip escaped end of lines */
    
    if (*From == End)
        return '\\';
    
    if (**From == '\\')
    { /* it's escaped */
        (*From)++;
        if (*From == End)
            return '\\';
        
        ThisChar = *(*From)++;
        switch (ThisChar)
        {
            case '\\': return '\\'; 
            case '\'': return '\'';
            case '"':  return '"';
            case 'a':  return '\a';
            case 'b':  return '\b';
            case 'f':  return '\f';
            case 'n':  return '\n';
            case 'r':  return '\r';
            case 't':  return '\t';
            case 'v':  return '\v';
            /* case '0': XXX - implement octal character constants */
            /* case 'x': XXX - implement hex character constants */
            default:   return ThisChar;
        }
    }
    else
        return *(*From)++;
}

/* get a string constant - used while scanning */
enum LexToken LexGetStringConstant(struct LexState *Lexer, struct Value *Value)
{
    int Escape = FALSE;
    const char *StartPos = Lexer->Pos;
    const char *EndPos;
    char *EscBuf;
    char *EscBufPos;
    struct Value *ArrayValue;
    
    while (Lexer->Pos != Lexer->End && (*Lexer->Pos != '"' || Escape))
    { /* find the end */
        if (Escape)
            Escape = FALSE;
        else if (*Lexer->Pos == '\\')
            Escape = TRUE;
            
        Lexer->Pos++;
    }
    EndPos = Lexer->Pos;
    
    EscBuf = HeapAllocStack(EndPos - StartPos);
    if (EscBuf == NULL)
        LexFail(Lexer, "out of memory");
    
    for (EscBufPos = EscBuf, Lexer->Pos = StartPos; Lexer->Pos != EndPos;)
        *EscBufPos++ = LexUnEscapeCharacter(&Lexer->Pos, EndPos);
    
    ArrayValue = VariableAllocValueAndData(NULL, sizeof(struct ArrayValue), FALSE, NULL, TRUE);
    ArrayValue->Typ = CharArrayType;
    ArrayValue->Val->Array.Size = EscBufPos - EscBuf + 1;
    ArrayValue->Val->Array.Data = TableStrRegister2(EscBuf, EscBufPos - EscBuf);
    HeapPopStack(EscBuf, EndPos - StartPos);
    Value->Typ = CharPtrType;
    Value->Val->Pointer.Segment = ArrayValue;
    Value->Val->Pointer.Data.Offset = 0;
    
    if (*Lexer->Pos == '"')
        Lexer->Pos++;
    
    return TokenStringConstant;
}

/* get a character constant - used while scanning */
enum LexToken LexGetCharacterConstant(struct LexState *Lexer, struct Value *Value)
{
    Value->Typ = &IntType;
    Value->Val->Integer = LexUnEscapeCharacter(&Lexer->Pos, Lexer->End);
    if (Lexer->Pos != Lexer->End && *Lexer->Pos != '\'')
        LexFail(Lexer, "expected \"'\"");
        
    Lexer->Pos++;
    return TokenCharacterConstant;
}

/* skip a comment - used while scanning */
void LexSkipComment(struct LexState *Lexer, char NextChar)
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
}

/* get a single token from the source - used while scanning */
enum LexToken LexScanGetToken(struct LexState *Lexer, struct Value **Value)
{
    char ThisChar;
    char NextChar;
    enum LexToken GotToken = TokenNone;
    
    do
    {
        *Value = &LexValue;
        while (Lexer->Pos != Lexer->End && isspace(*Lexer->Pos))
        {
            if (*Lexer->Pos == '\n')
            {
                Lexer->Line++;
                Lexer->Pos++;
                return TokenEndOfLine;
            }
    
            Lexer->Pos++;
        }
        
        if (Lexer->Pos == Lexer->End)
        { /* end of input */
            if (Lexer->FileName == StrEmpty)
            { /* get interactive input */
                char LineBuffer[LINEBUFFER_MAX];
                if (PlatformGetLine(&LineBuffer[0], LINEBUFFER_MAX) == NULL)
                    return TokenEOF;
                
                // XXX - finish this
            }
            else
                return TokenEOF;
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
            case '"': GotToken = LexGetStringConstant(Lexer, *Value); break;
            case '\'': GotToken = LexGetCharacterConstant(Lexer, *Value); break;
            case '(': GotToken = TokenOpenBracket; break;
            case ')': GotToken = TokenCloseBracket; break;
            case '=': NEXTIS('=', TokenEquality, TokenAssign); break;
            case '+': NEXTIS3('=', TokenAddAssign, '+', TokenIncrement, TokenPlus); break;
            case '-': NEXTIS4('=', TokenSubtractAssign, '>', TokenArrow, '-', TokenDecrement, TokenMinus); break;
            case '*': NEXTIS('=', TokenMultiplyAssign, TokenAsterisk); break;
            case '/': if (NextChar == '/' || NextChar == '*') LexSkipComment(Lexer, NextChar); else NEXTIS('=', TokenDivideAssign, TokenSlash); break;
            case '%': NEXTIS('=', TokenModulusAssign, TokenModulus); break;
            case '<': NEXTIS3PLUS('=', TokenLessEqual, '<', TokenShiftLeft, '=', TokenShiftLeftAssign, TokenLessThan); break;
            case '>': NEXTIS3PLUS('=', TokenGreaterEqual, '>', TokenShiftRight, '=', TokenShiftRightAssign, TokenGreaterThan); break;
            case ';': GotToken = TokenSemicolon; break;
            case '&': NEXTIS3('=', TokenArithmeticAndAssign, '&', TokenLogicalAnd, TokenAmpersand); break;
            case '|': NEXTIS3('=', TokenArithmeticOrAssign, '|', TokenLogicalOr, TokenArithmeticOr); break;
            case '{': GotToken = TokenLeftBrace; break;
            case '}': GotToken = TokenRightBrace; break;
            case '[': GotToken = TokenLeftSquareBracket; break;
            case ']': GotToken = TokenRightSquareBracket; break;
            case '!': NEXTIS('=', TokenNotEqual, TokenUnaryNot); break;
            case '^': NEXTIS('=', TokenArithmeticExorAssign, TokenArithmeticExor); break;
            case '~': GotToken = TokenUnaryExor; break;
            case ',': GotToken = TokenComma; break;
            case '.': NEXTISEXACTLY3('.', '.', TokenEllipsis, TokenDot); break;
            case '?': GotToken = TokenQuestionMark; break;
            case ':': GotToken = TokenColon; break;
            default:  LexFail(Lexer, "illegal character '%c'", ThisChar); break;
        }
    } while (GotToken == TokenNone);
    
    return GotToken;
}

/* what size value goes with each token */
int LexTokenSize(enum LexToken Token)
{
    switch (Token)
    {
        case TokenIdentifier: case TokenStringConstant: return sizeof(char *);
        case TokenIntegerConstant: case TokenCharacterConstant: return sizeof(int);
        case TokenFPConstant: return sizeof(double);
        default: return 0;
    }
}

/* produce tokens from the lexer and return a heap buffer with the result - used for scanning */
void *LexTokenise(struct LexState *Lexer)
{
    enum LexToken Token;
    void *HeapMem;
    struct Value *GotValue;
    int MemUsed = 0;
    int ValueSize;
    int ReserveSpace = (Lexer->End - Lexer->Pos) * 3 + 1; 
    void *TokenSpace = HeapAllocStack(ReserveSpace);
    void *TokenPos = TokenSpace;
    if (TokenSpace == NULL)
        LexFail(Lexer, "out of memory");
    
    do
    { /* store the token at the end of the stack area */
        Token = LexScanGetToken(Lexer, &GotValue);
#ifdef DEBUG_LEXER
        printf("Token: %02x\n", Token);
#endif
        *(unsigned char *)TokenPos = Token;
        TokenPos++;
        MemUsed++;

        ValueSize = LexTokenSize(Token);
        if (ValueSize > 0)
        { /* store a value as well */
            memcpy(TokenPos, GotValue->Val, ValueSize);
            TokenPos += ValueSize;
            MemUsed += ValueSize;
        }
            
    } while (Token != TokenEOF);
    
    HeapMem = HeapAlloc(MemUsed);
    if (HeapMem == NULL)
        LexFail(Lexer, "out of memory");
        
    memcpy(HeapMem, TokenSpace, MemUsed);
    HeapPopStack(TokenSpace, ReserveSpace);
#ifdef DEBUG_LEXER
    {
        int Count;
        for (Count = 0; Count < MemUsed; Count++)
            printf("%02x ", *(unsigned char *)(HeapMem+Count));
        printf("\n");
    }
#endif
    
    return HeapMem;
}

/* lexically analyse some source text */
void *LexAnalyse(const char *FileName, const char *Source, int SourceLen)
{
    struct LexState Lexer;
    
    Lexer.Pos = Source;
    Lexer.End = Source + SourceLen;
    Lexer.Line = 1;
    Lexer.FileName = FileName;
    return LexTokenise(&Lexer);
}

/* prepare to parse a pre-tokenised buffer */
void LexInitParser(struct ParseState *Parser, void *TokenSource, const char *FileName, int Line, int RunIt)
{
    Parser->Pos = TokenSource;
    Parser->Line = Line;
    Parser->FileName = FileName;
    Parser->Mode = RunIt ? RunModeRun : RunModeSkip;
    Parser->SearchLabel = 0;
}

/* get the next token given a parser state */
enum LexToken LexGetToken(struct ParseState *Parser, struct Value **Value, int IncPos)
{
    enum LexToken Token;
    int ValueSize;
        
    while ((enum LexToken)*(unsigned char *)Parser->Pos == TokenEndOfLine)
    { /* skip leading newlines */
        Parser->Line++;
        Parser->Pos++;
    }
    
    Token = (enum LexToken)*(unsigned char *)Parser->Pos;
    ValueSize = LexTokenSize(Token);
    if (ValueSize > 0)
    { /* this token requires a value - unpack it */
        if (Value != NULL)
        { 
            switch (Token)
            {
                case TokenStringConstant:       LexValue.Typ = CharPtrType; break;
                case TokenIdentifier:           LexValue.Typ = NULL; break;
                case TokenIntegerConstant: case TokenCharacterConstant: LexValue.Typ = &IntType; break;
#ifndef NO_FP
                case TokenFPConstant:           LexValue.Typ = &FPType; break;
#endif
                default: break;
            }
            
            memcpy(LexValue.Val, Parser->Pos+1, ValueSize);
            LexValue.ValOnHeap = FALSE;
            LexValue.ValOnStack = FALSE;
            LexValue.IsLValue = FALSE;
            LexValue.LValueFrom = NULL;
            *Value = &LexValue;
        }
        
        if (IncPos)
            Parser->Pos += ValueSize + 1;
    }
    else
    {
        if (IncPos && Token != TokenEOF)
            Parser->Pos++;
    }
    
#ifdef DEBUG_LEXER
    printf("Got token=%02x inc=%d\n", Token, IncPos);
#endif
    return Token;
}

