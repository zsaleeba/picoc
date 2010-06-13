/* stdio.h library for large systems - small embedded systems use clibrary.c instead */
#include "../picoc.h"

#ifndef BUILTIN_MINI_STDLIB

void MathSin(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = sin(Param[0]->Val->FP);
}

void MathCos(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = cos(Param[0]->Val->FP);
}

void MathTan(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = tan(Param[0]->Val->FP);
}

void MathAsin(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = asin(Param[0]->Val->FP);
}

void MathAcos(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = acos(Param[0]->Val->FP);
}

void MathAtan(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = atan(Param[0]->Val->FP);
}

void MathSinh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = sinh(Param[0]->Val->FP);
}

void MathCosh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = cosh(Param[0]->Val->FP);
}

void MathTanh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = tanh(Param[0]->Val->FP);
}

void MathExp(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = exp(Param[0]->Val->FP);
}

void MathFabs(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = fabs(Param[0]->Val->FP);
}

void MathLog(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = log(Param[0]->Val->FP);
}

void MathLog10(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = log10(Param[0]->Val->FP);
}

void MathPow(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = pow(Param[0]->Val->FP, Param[1]->Val->FP);
}

void MathSqrt(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = sqrt(Param[0]->Val->FP);
}

void MathRound(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = floor(Param[0]->Val->FP + 0.5);   /* XXX - fix for soft float */
}

void MathCeil(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = ceil(Param[0]->Val->FP);
}

void MathFloor(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP = floor(Param[0]->Val->FP);
}

/* all math.h functions */
struct LibraryFunction MathFunctions[] =
{
    { MathSin,          "float sin(float);" },
    { MathCos,          "float cos(float);" },
    { MathTan,          "float tan(float);" },
    { MathAsin,         "float asin(float);" },
    { MathAcos,         "float acos(float);" },
    { MathAtan,         "float atan(float);" },
    { MathSinh,         "float sinh(float);" },
    { MathCosh,         "float cosh(float);" },
    { MathTanh,         "float tanh(float);" },
    { MathExp,          "float exp(float);" },
    { MathFabs,         "float fabs(float);" },
    { MathLog,          "float log(float);" },
    { MathLog10,        "float log10(float);" },
    { MathPow,          "float pow(float,float);" },
    { MathSqrt,         "float sqrt(float);" },
    { MathRound,        "float round(float);" },
    { MathCeil,         "float ceil(float);" },
    { MathFloor,        "float floor(float);" },
    { NULL,             NULL }
};

/* creates various system-dependent definitions */
void MathSetupFunc(void)
{
#if 0
    VariableDefinePlatformVar(NULL, "EOF", &IntType, (union AnyValue *)&EOFValue, FALSE);
    VariableDefinePlatformVar(NULL, "SEEK_SET", &IntType, (union AnyValue *)&SEEK_SETValue, FALSE);
    VariableDefinePlatformVar(NULL, "SEEK_CUR", &IntType, (union AnyValue *)&SEEK_CURValue, FALSE);
    VariableDefinePlatformVar(NULL, "SEEK_END", &IntType, (union AnyValue *)&SEEK_ENDValue, FALSE);
    VariableDefinePlatformVar(NULL, "BUFSIZ", &IntType, (union AnyValue *)&BUFSIZValue, FALSE);
    VariableDefinePlatformVar(NULL, "FILENAME_MAX", &IntType, (union AnyValue *)&FILENAME_MAXValue, FALSE);
    VariableDefinePlatformVar(NULL, "_IOFBF", &IntType, (union AnyValue *)&_IOFBFValue, FALSE);
    VariableDefinePlatformVar(NULL, "_IOLBF", &IntType, (union AnyValue *)&_IOLBFValue, FALSE);
    VariableDefinePlatformVar(NULL, "_IONBF", &IntType, (union AnyValue *)&_IONBFValue, FALSE);
    VariableDefinePlatformVar(NULL, "L_tmpnam", &IntType, (union AnyValue *)&L_tmpnamValue, FALSE);
    VariableDefinePlatformVar(NULL, "GETS_MAX", &IntType, (union AnyValue *)&GETS_MAXValue, FALSE);
#endif
}

#endif /* !BUILTIN_MINI_STDLIB */
