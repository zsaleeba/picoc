#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "picoc.h"


void StrToC(char *Dest, int DestSize, const Str *Source)
{
    int CopyLen = min(DestSize-1, Source->Len);
    memcpy(Dest, Source->Str, CopyLen);
    Dest[CopyLen] = '\0';
}


void StrFromC(Str *Dest, const char *Source)
{
    Dest->Str = Source;
    Dest->Len = strlen(Source);
}


int StrEqual(const Str *Str1, const Str *Str2)
{
    if (Str1->Len != Str2->Len)
        return FALSE;
    
    return memcmp(Str1->Str, Str2->Str, Str1->Len) == 0;
}


int StrEqualC(const Str *Str1, const char *Str2)
{
    return strncmp(Str1->Str, Str2, Str1->Len) == 0 && Str2[Str1->Len] == '\0';
}


void StrPrintf(const char *Format, ...)
{
    const char *FPos;
    va_list Args;
    Str *str;
    
    va_start(Args, Format);
    for (FPos = Format; *FPos != '\0'; FPos++)
    {
        if (*FPos == '%')
        {
            FPos++;
            switch (*FPos)
            {
            case 'S':
                str = va_arg(Args, Str *);
                fwrite(str->Str, 1, str->Len, stdout);
                break;
                
            case 's': fputs(va_arg(Args, char *), stdout); break;
            case 'd': printf("%d", va_arg(Args, int)); break;
            case 'c': fputc(va_arg(Args, int), stdout); break;
            case '%': fputc('%', stdout); break;
            case '\0': FPos--; break;
            }
        }
        else
            putchar(*FPos);
    }
    va_end(Args);
}

