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


void StrPrintf(const str *Format, ...)
{
    char FormatBuf[MAX_FORMAT];
    const char *FPos;
    char *BPos;
    va_list Args;
    
    va_start(Args, Format);
    for (FPos = Format, BPos = &FormatBuf[0]; *FPos != '\0'; FPos++, BPos++)
    {
        if (*FPos == '%')
        {
            XXX
        }
        *BPos = *FPos;
    }
}

