#include "picoc.h"

#ifdef NO_CTYPE
#define isalpha(c) (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'))
#define isdigit(c) ((c) >= '0' && (c) <= '9')
#define isalnum(c) (isalpha(c) || isdigit(c))
#define isspace(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\n')
#endif
#define isCidstart(c) (isalpha(c) || (c)=='_' || (c)=='#')
#define isCident(c) (isalnum(c) || (c)=='_')

#define IS_HEX_ALPHA_DIGIT(c) (((c) >= 'a' && (c) <= 'f') || ((c) >= 'A' && (c) <= 'F'))
#define IS_BASE_DIGIT(c,b) (((c) >= '0' && (c) < '0' + (((b)<10)?(b):10)) || (((b) > 10) ? IS_HEX_ALPHA_DIGIT(c) : FALSE))
#define GET_BASE_DIGIT(c) (((c) <= '9') ? ((c) - '0') : (((c) <= 'F') ? ((c) - 'A' + 10) : ((c) - 'a' + 10)))

#define NEXTIS(c,x,y) { if (NextChar == (c)) { Lexer->Pos++; GotToken = (x); } else GotToken = (y); }
#define NEXTIS3(c,x,d,y,z) { if (NextChar == (c)) { Lexer->Pos++; GotToken = (x); } else NEXTIS(d,y,z) }
#define NEXTIS4(c,x,d,y,e,z,a) { if (NextChar == (c)) { Lexer->Pos++; GotToken = (x); } else NEXTIS3(d,y,e,z,a) }
#define NEXTIS3PLUS(c,x,d,y,e,z,a) { if (NextChar == (c)) { Lexer->Pos++; GotToken = (x); } else if (NextChar == (d)) { if (Lexer->Pos[1] == (e)) { Lexer->Pos += 2; GotToken = (z); } else { Lexer->Pos++; GotToken = (y); } } else GotToken = (a); }
#define NEXTISEXACTLY3(c,d,y,z) { if (NextChar == (c) && Lexer->Pos[1] == (d)) { Lexer->Pos += 2; GotToken = (y); } else GotToken = (z); }

#define MAX_CHAR_VALUE 255      /* maximum value which can be represented by a "char" data type */

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
    { "delete", TokenDelete, NULL },
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
    { "new", TokenNew, NULL },
    { "return", TokenReturn, NULL },
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

/* linked list of tokens used in interactive mode */
struct TokenLine
{
    struct TokenLine *Next;
    unsigned char *Tokens;
    int NumBytes;
};

static struct TokenLine *InteractiveHead = NULL;
static struct TokenLine *InteractiveTail = NULL;
static struct TokenLine *InteractiveCurrentLine = NULL;
static int LexUseStatementPrompt = FALSE;


/* initialise the lexer */
void LexInit()
{
    int Count;
    
    for (Count = 0; Count < sizeof(ReservedWords) / sizeof(struct ReservedWord); Count++)
        ReservedWords[Count].SharedWord = TableStrRegister(ReservedWords[Count].Word);
}

/* deallocate */
void LexCleanup()
{
    LexInteractiveClear(NULL);
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

int IsBaseDigit(unsigned char c, int b)
{
    if (c >= '0' && c < '0' + b)
        return TRUE;
    else
    {
        if (b > 10)
            return IS_HEX_ALPHA_DIGIT(c);
    }
    
    return FALSE;
}

/* get a numeric literal - used while scanning */
enum LexToken LexGetNumber(struct LexState *Lexer, struct Value *Value)
{
    int Result = 0;
    int Base = 10;
    enum LexToken ResultToken;
#ifndef NO_FP
    double FPResult;
    double FPDiv;
#endif
    
    if (*Lexer->Pos == '0')
    { 
        /* a binary, octal or hex literal */
        Lexer->Pos++;
        if (Lexer->Pos != Lexer->End)
        {
            if (*Lexer->Pos == 'x' || *Lexer->Pos == 'X')
                { Base = 16; Lexer->Pos++; }
            else if (*Lexer->Pos == 'b' || *Lexer->Pos == 'B')
                { Base = 2; Lexer->Pos++; }
            else if (*Lexer->Pos != '.')
                Base = 8;
        }
    }

    /* get the value */
    for (; Lexer->Pos != Lexer->End && IS_BASE_DIGIT(*Lexer->Pos, Base); Lexer->Pos++)
        Result = Result * Base + GET_BASE_DIGIT(*Lexer->Pos);
    
    if (Result <= MAX_CHAR_VALUE)
    {
        Value->Typ = &CharType;
        Value->Val->Character = Result;
        ResultToken = TokenCharacterConstant;
    }
    else
    {
        Value->Typ = &IntType;
        Value->Val->Integer = Result;
        ResultToken = TokenIntegerConstant;
    }
#ifndef NO_FP
    if (Lexer->Pos == Lexer->End || *Lexer->Pos != '.')
        return ResultToken;

    Value->Typ = &FPType;
    Lexer->Pos++;
    for (FPDiv = 1.0/Base, FPResult = (double)Result; Lexer->Pos != Lexer->End && IS_BASE_DIGIT(*Lexer->Pos, Base); Lexer->Pos++, FPDiv /= (double)Base)
        FPResult += GET_BASE_DIGIT(*Lexer->Pos) * FPDiv;
    
    if (Lexer->Pos != Lexer->End && (*Lexer->Pos == 'e' || *Lexer->Pos == 'E'))
    {
        Lexer->Pos++;
        for (Result = 0; Lexer->Pos != Lexer->End && IS_BASE_DIGIT(*Lexer->Pos, Base); Lexer->Pos++)
            Result = Result * (double)Base + GET_BASE_DIGIT(*Lexer->Pos);
            
        FPResult *= math_pow((double)Base, (double)Result);
    }
    
    Value->Val->FP = FPResult;
    
    return TokenFPConstant;
#else
    return ResultToken;
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

/* unescape a character from an octal character constant */
unsigned char LexUnEscapeCharacterConstant(const char **From, const char *End, unsigned char FirstChar, int Base)
{
    unsigned char Total = GET_BASE_DIGIT(FirstChar);
    int CCount;
    for (CCount = 0; IS_BASE_DIGIT(**From, Base) && CCount < 2; CCount++, (*From)++)
        Total = Total * Base + GET_BASE_DIGIT(**From);
    
    return Total;
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
    { 
        /* it's escaped */
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
            case '0': case '1': case '2': case '3': return LexUnEscapeCharacterConstant(From, End, ThisChar, 8);
            case 'x': return LexUnEscapeCharacterConstant(From, End, '0', 16);
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
    char *RegString;
    struct Value *ArrayValue;
    
    while (Lexer->Pos != Lexer->End && (*Lexer->Pos != '"' || Escape))
    { 
        /* find the end */
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
    
    /* try to find an existing copy of this string literal */
    RegString = TableStrRegister2(EscBuf, EscBufPos - EscBuf);
    HeapPopStack(EscBuf, EndPos - StartPos);
    ArrayValue = VariableStringLiteralGet(RegString);
    if (ArrayValue == NULL)
    {
        /* create and store this string literal */
        ArrayValue = VariableAllocValueAndData(NULL, sizeof(struct ArrayValue), FALSE, NULL, TRUE);
        ArrayValue->Typ = CharArrayType;
        ArrayValue->Val->Array.Size = EscBufPos - EscBuf + 1;
        ArrayValue->Val->Array.Data = RegString;
        VariableStringLiteralDefine(RegString, ArrayValue);
    }

    /* create the the pointer for this char* */
    Value->Typ = CharPtrType;
#ifndef NATIVE_POINTERS
    Value->Val->Pointer.Segment = ArrayValue;
    Value->Val->Pointer.Offset = 0;
#else
    Value->Val->NativePointer = ArrayValue;
#endif    
    if (*Lexer->Pos == '"')
        Lexer->Pos++;
    
    return TokenStringConstant;
}

/* get a character constant - used while scanning */
enum LexToken LexGetCharacterConstant(struct LexState *Lexer, struct Value *Value)
{
    Value->Typ = &CharType;
    Value->Val->Character = LexUnEscapeCharacter(&Lexer->Pos, Lexer->End);
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
    {   
        /* conventional C comment */
        while (Lexer->Pos != Lexer->End && (*(Lexer->Pos-1) != '*' || *Lexer->Pos != '/'))
            Lexer->Pos++;
        
        if (Lexer->Pos != Lexer->End)
            Lexer->Pos++;
    }
    else
    {   
        /* C++ style comment */
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
        
        if (Lexer->Pos == Lexer->End || *Lexer->Pos == '\0')
            return TokenEOF;
        
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
            case '=': NEXTIS('=', TokenEqual, TokenAssign); break;
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
        case TokenIntegerConstant: return sizeof(int);
        case TokenCharacterConstant: return sizeof(unsigned char);
        case TokenFPConstant: return sizeof(double);
        default: return 0;
    }
}

/* produce tokens from the lexer and return a heap buffer with the result - used for scanning */
void *LexTokenise(struct LexState *Lexer, int *TokenLen)
{
    enum LexToken Token;
    void *HeapMem;
    struct Value *GotValue;
    int MemUsed = 0;
    int ValueSize;
    int ReserveSpace = (Lexer->End - Lexer->Pos) * 3 + 1; 
    void *TokenSpace = HeapAllocStack(ReserveSpace);
    char *TokenPos = (char *)TokenSpace;
    if (TokenSpace == NULL)
        LexFail(Lexer, "out of memory");
    
    do
    { 
        /* store the token at the end of the stack area */
        Token = LexScanGetToken(Lexer, &GotValue);
#ifdef DEBUG_LEXER
        printf("Token: %02x\n", Token);
#endif
        *(unsigned char *)TokenPos = Token;
        TokenPos++;
        MemUsed++;

        ValueSize = LexTokenSize(Token);
        if (ValueSize > 0)
        { 
            /* store a value as well */
            memcpy(TokenPos, (void *)GotValue->Val, ValueSize);
            TokenPos += ValueSize;
            MemUsed += ValueSize;
        }
            
    } while (Token != TokenEOF);
    
    HeapMem = HeapAllocMem(MemUsed);
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
    if (TokenLen)
        *TokenLen = MemUsed;
    
    return HeapMem;
}

/* lexically analyse some source text */
void *LexAnalyse(const char *FileName, const char *Source, int SourceLen, int *TokenLen)
{
    struct LexState Lexer;
    
    Lexer.Pos = Source;
    Lexer.End = Source + SourceLen;
    Lexer.Line = 1;
    Lexer.FileName = FileName;
    return LexTokenise(&Lexer, TokenLen);
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
    enum LexToken Token = TokenNone;
    int ValueSize;
    
    do
    { 
        /* get the next token */
        if (Parser->Pos == NULL && InteractiveHead != NULL)
            Parser->Pos = InteractiveHead->Tokens;
            
        if (Parser->FileName != StrEmpty || InteractiveHead != NULL)
        { 
            /* skip leading newlines */
            while ((Token = (enum LexToken)*(unsigned char *)Parser->Pos) == TokenEndOfLine)
            {
                Parser->Line++;
                Parser->Pos++;
            }
        }
    
        if (Parser->FileName == StrEmpty && (InteractiveHead == NULL || Token == TokenEOF))
        { 
            /* we're at the end of an interactive input token list */
            char LineBuffer[LINEBUFFER_MAX];
            void *LineTokens;
            int LineBytes;
            struct TokenLine *LineNode;

            if (InteractiveHead == NULL || (unsigned char *)Parser->Pos == &InteractiveTail->Tokens[InteractiveTail->NumBytes-1])
            { 
                /* get interactive input */
                if (LexUseStatementPrompt)
                {
                    PlatformPrintf(INTERACTIVE_PROMPT_STATEMENT);
                    LexUseStatementPrompt = FALSE;
                }
                else
                    PlatformPrintf(INTERACTIVE_PROMPT_LINE);
                    
                if (PlatformGetLine(&LineBuffer[0], LINEBUFFER_MAX) == NULL)
                    return TokenEOF;

                /* put the new line at the end of the linked list of interactive lines */        
                LineTokens = LexAnalyse(StrEmpty, &LineBuffer[0], strlen(LineBuffer), &LineBytes);
                LineNode = VariableAlloc(Parser, sizeof(struct TokenLine), TRUE);
                LineNode->Tokens = LineTokens;
                LineNode->NumBytes = LineBytes;
                if (InteractiveHead == NULL)
                { 
                    /* start a new list */
                    InteractiveHead = LineNode;
                    Parser->Line = 1;
                }
                else
                    InteractiveTail->Next = LineNode;

                InteractiveTail = LineNode;
                InteractiveCurrentLine = LineNode;
                Parser->Pos = LineTokens;
            }
            else
            { 
                /* go to the next token line */
                if (Parser->Pos != &InteractiveCurrentLine->Tokens[InteractiveCurrentLine->NumBytes-1])
                { 
                    /* scan for the line */
                    for (InteractiveCurrentLine = InteractiveHead; Parser->Pos != &InteractiveCurrentLine->Tokens[InteractiveCurrentLine->NumBytes-1]; InteractiveCurrentLine = InteractiveCurrentLine->Next)
                    {}
                }

                InteractiveCurrentLine = InteractiveCurrentLine->Next;
                Parser->Pos = InteractiveCurrentLine->Tokens;
            }

            Token = (enum LexToken)*(unsigned char *)Parser->Pos;
        }
    } while ((Parser->FileName == StrEmpty && Token == TokenEOF) || Token == TokenEndOfLine);

    ValueSize = LexTokenSize(Token);
    if (ValueSize > 0)
    { 
        /* this token requires a value - unpack it */
        if (Value != NULL)
        { 
            switch (Token)
            {
                case TokenStringConstant:       LexValue.Typ = CharPtrType; LexValue.Val->Pointer.Offset = 0; break;
                case TokenIdentifier:           LexValue.Typ = NULL; break;
                case TokenIntegerConstant:      LexValue.Typ = &IntType; break;
                case TokenCharacterConstant:    LexValue.Typ = &CharType; break;
#ifndef NO_FP
                case TokenFPConstant:           LexValue.Typ = &FPType; break;
#endif
                default: break;
            }
            
            memcpy((void *)LexValue.Val, (void *)((char *)Parser->Pos+1), ValueSize);
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

/* find the end of the line */
void LexToEndOfLine(struct ParseState *Parser)
{
    while (TRUE)
    {
        enum LexToken Token = (enum LexToken)*(unsigned char *)Parser->Pos;
        if (Token == TokenEndOfLine || Token == TokenEOF)
            return;
        else
            LexGetToken(Parser, NULL, TRUE);
    }
}

/* copy the tokens from StartParser to EndParser into new memory and terminate with a TokenEOF */
void *LexCopyTokens(struct ParseState *StartParser, struct ParseState *EndParser)
{
    int MemSize = 0;
    int CopySize;
    unsigned char *Pos = (unsigned char *)StartParser->Pos;
    unsigned char *NewTokens;
    unsigned char *NewTokenPos;
    struct TokenLine *ILine;
    
    if (InteractiveHead == NULL)
    { 
        /* non-interactive mode - copy the tokens */
        MemSize = EndParser->Pos - StartParser->Pos;
        NewTokens = VariableAlloc(StartParser, MemSize + 1, TRUE);
        memcpy(NewTokens, (void *)StartParser->Pos, MemSize);
    }
    else
    { 
        /* we're in interactive mode - add up line by line */
        for (InteractiveCurrentLine = InteractiveHead; InteractiveCurrentLine != NULL && (Pos < &InteractiveCurrentLine->Tokens[0] || Pos >= &InteractiveCurrentLine->Tokens[InteractiveCurrentLine->NumBytes]); InteractiveCurrentLine = InteractiveCurrentLine->Next)
        {} /* find the line we just counted */
        
        if (EndParser->Pos >= StartParser->Pos && EndParser->Pos < &InteractiveCurrentLine->Tokens[InteractiveCurrentLine->NumBytes])
        { 
            /* all on a single line */
            MemSize = EndParser->Pos - StartParser->Pos;
            NewTokens = VariableAlloc(StartParser, MemSize + 1, TRUE);
            memcpy(NewTokens, (void *)StartParser->Pos, MemSize);
        }
        else
        { 
            /* it's spread across multiple lines */
            MemSize = &InteractiveCurrentLine->Tokens[InteractiveCurrentLine->NumBytes-1] - Pos;
            for (ILine = InteractiveCurrentLine->Next; ILine != NULL && (EndParser->Pos < &ILine->Tokens[0] || EndParser->Pos >= &ILine->Tokens[ILine->NumBytes]); ILine = ILine->Next)
                MemSize += ILine->NumBytes - 1;
            
            assert(ILine != NULL);
            MemSize += EndParser->Pos - &ILine->Tokens[0];
            NewTokens = VariableAlloc(StartParser, MemSize + 1, TRUE);
            
            CopySize = &InteractiveCurrentLine->Tokens[InteractiveCurrentLine->NumBytes-1] - Pos;
            memcpy(NewTokens, Pos, CopySize);
            NewTokenPos = NewTokens + CopySize;
            for (ILine = InteractiveCurrentLine->Next; ILine != NULL && (EndParser->Pos < &ILine->Tokens[0] || EndParser->Pos >= &ILine->Tokens[ILine->NumBytes]); ILine = ILine->Next)
            {
                memcpy(NewTokenPos, &ILine->Tokens[0], ILine->NumBytes-1);
                NewTokenPos += ILine->NumBytes-1;
            }
            assert(ILine != NULL);
            memcpy(NewTokenPos, &ILine->Tokens[0], EndParser->Pos - &ILine->Tokens[0]);
        }
    }
    
    NewTokens[MemSize] = (unsigned char)TokenEndOfFunction;
    return NewTokens;
}

/* indicate that we've completed up to this point in the interactive input and free expired tokens */
void LexInteractiveClear(struct ParseState *Parser)
{
    while (InteractiveHead != NULL)
    {
        struct TokenLine *NextLine = InteractiveHead->Next;
        
        HeapFreeMem(InteractiveHead->Tokens);
        HeapFreeMem(InteractiveHead);
        InteractiveHead = NextLine;
    }

    if (Parser != NULL)
        Parser->Pos = NULL;
    InteractiveTail = NULL;
}

/* indicate that we've completed up to this point in the interactive input and free expired tokens */
void LexInteractiveCompleted(struct ParseState *Parser)
{
    while (InteractiveHead != NULL && !(Parser->Pos >= &InteractiveHead->Tokens[0] && Parser->Pos < &InteractiveHead->Tokens[InteractiveHead->NumBytes]))
    { 
        /* this token line is no longer needed - free it */
        struct TokenLine *NextLine = InteractiveHead->Next;
        
        HeapFreeMem(InteractiveHead->Tokens);
        HeapFreeMem(InteractiveHead);
        InteractiveHead = NextLine;
        
        if (InteractiveHead == NULL)
        { 
            /* we've emptied the list */
            Parser->Pos = NULL;
            InteractiveTail = NULL;
        }
    }
}

/* the next time we prompt, make it the full statement prompt */
void LexInteractiveStatementPrompt()
{
    LexUseStatementPrompt = TRUE;
}
