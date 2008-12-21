#include <string.h>

#include "picoc.h"

    
static unsigned int TableHash(const Str *Key)
{
    unsigned int Hash;
    int Count;
    int Offset;
    const char *KeyPos;
    
    Hash = Key->Len;
    KeyPos = Key->Str;
    Offset = 8;
    for (Count = 0; Count < Key->Len; Count++, Offset+=7)
    {
        if (Offset > sizeof(unsigned int) * 8 - 7)
            Offset -= (sizeof(unsigned int)-1) * 8;
            
        Hash ^= *KeyPos++ << Offset;
    }
    
    return Hash;
}


void TableInit(struct Table *Tbl, struct TableEntry *HashTable, const char *Name, int Size)
{
    Tbl->Name = Name;
    Tbl->Size = Size;
    Tbl->HashTable = HashTable;
    memset(HashTable, '\0', sizeof(struct TableEntry) * Size);
}


static int TableCheckEntry(struct Table *Tbl, const Str *Key, int HashPos)
{
    struct TableEntry *Entry = &Tbl->HashTable[HashPos];
    
    if (Entry->Key.Len == 0)
        return -1;   /* empty */
        
    else if (StrEqual(&Entry->Key, Key))
        return HashPos;   /* found */
    
    else
        return -2;  /* wrong key */
}


static int TableSearch(struct Table *Tbl, const Str *Key, int *AddAt)
{
    int HashValue;
    int HashPos;
    int Result;
    
    HashValue = TableHash(Key) % Tbl->Size;
    
    for (HashPos = HashValue; HashPos < Tbl->Size; HashPos++)
    {
        *AddAt = HashPos;
        if ( (Result = TableCheckEntry(Tbl, Key, HashPos)) != -2)
            return Result;
    }
    
    for (HashPos = 0; HashPos < HashValue; HashPos++)
    {
        *AddAt = HashPos;
        if ( (Result = TableCheckEntry(Tbl, Key, HashPos)) != -2)
            return Result;
    }
    
    /* not found and table is full */
    *AddAt = -1;
    return -1;
}


int TableSet(struct Table *Tbl, const Str *Key, struct Value *Val)
{
    int HashPos;
    int AddAt;
    
    HashPos = TableSearch(Tbl, Key, &AddAt);

    if (HashPos == -1)
    {
        if (AddAt == -1)
            Fail("table '%s' is full\n", Tbl->Name);
        
        else
        {   /* add it to the table */
            struct TableEntry *Entry = &Tbl->HashTable[AddAt];
            Entry->Key = *Key;
            Entry->Val = *Val;
        }
    }
    
    return TRUE;
}


int TableGet(struct Table *Tbl, const Str *Key, struct Value **Val)
{
    int HashPos;
    int AddAt;
    
    HashPos = TableSearch(Tbl, Key, &AddAt);

    if (HashPos == -1)
        return FALSE;
    
    *Val = &Tbl->HashTable[HashPos].Val;
    return TRUE;
}

