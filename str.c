/* maintains a shared string table so we don't have to worry about string allocation */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include "picoc.h"

struct Table StringTable;
struct TableEntry *StringHashTable[STRING_TABLE_SIZE];

/* initialise the shared string system */
void StrInit()
{
    TableInit(&StringTable, &StringHashTable[0], STRING_TABLE_SIZE, TRUE);
}

/* register a string in the shared string store */
const char *StrRegister2(const char *Str, int Len)
{
    return TableSetKey(&StringTable, Str, Len);
}

const char *StrRegister(const char *Str)
{
    return StrRegister2(Str, strlen(Str));
}

/* print an integer to a stream without using printf/sprintf */
void StrPrintInt(int Num, FILE *Stream)
{
    int Div;
    int Remainder = 0;
    int Printing = FALSE;
    
    if (Num < 0)
    {
        fputc('-', Stream);
        Num = -Num;    
    }
    
    if (Num == 0)
        fputc('0', Stream);
    else
    {
        Div = LARGE_INT_POWER_OF_TEN;
        while (Div > 0)
        {
            Remainder = Num / Div;
            if (Printing || Remainder > 0)
            {
                fputc('0' + Remainder, Stream);
                Printing = TRUE;
            }
            Num -= Remainder * Div;
            Div /= 10;
        }
    }
}

/* print a double to a stream without using printf/sprintf */
void StrPrintFP(double Num, FILE *Stream)
{
    int Exponent = 0;
    
    if (abs(Num) >= 1e7)
        Exponent = log(Num) / LOG10E;
    else if (abs(Num) <= 1e-7)
        Exponent = log(Num) / LOG10E - 0.999999999;
    
    Num /= pow(10.0, Exponent);
    StrPrintInt((int)Num, Stream);
    fputc('.', Stream);
    for (Num -= (int)Num; Num != 0.0; Num *= 10.0)
        fputc('0' + (int)Num, Stream);
    
    if (Exponent)
    {
        fputc('e', Stream);
        StrPrintInt(Exponent, Stream);
    }
}

#if 0
/* Str version of printf */
void StrPrintf(const char *Format, ...)
{
    va_list Args;
    
    va_start(Args, Format);
    vStrPrintf(Format, Args);
    va_end(Args);
}

void vStrPrintf(const char *Format, va_list Args)
{
    Str *str;
    const char *FPos;
    
    for (FPos = Format; *FPos != '\0'; FPos++)
    {
        if (*FPos == '%')
        {
            FPos++;
            switch (*FPos)
            {
            case 'S': str = va_arg(Args, Str *); fwrite(str->Str, 1, str->Len, stdout); break;
            case 's': fputs(va_arg(Args, char *), stdout); break;
            case 'd': StrPrintInt(va_arg(Args, int), stdout); break;
            case 'c': fputc(va_arg(Args, int), stdout); break;
            case 'f': StrPrintFP(va_arg(Args, double), stdout); break;
            case '%': fputc('%', stdout); break;
            case '\0': FPos--; break;
            }
        }
        else
            putchar(*FPos);
    }
}
#endif

