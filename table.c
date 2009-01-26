#include <string.h>
#include "picoc.h"

/* hash function */
static unsigned int TableHash(const Str *Key)
{
    if (Key->Len == 0)
        return 0;
    else
        return ((*Key->Str << 24) | (Key->Str[Key->Len-1] << 16) | (Key->Str[Key->Len >> 1] << 8)) ^ Key->Len;
}

/* initialise a table */
void TableInit(struct Table *Tbl, struct TableEntry *HashTable, int Size)
{
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

/* search a table for an identifier. sets AddAt to where to add it at if not found */
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

/* set an identifier to a value. returns FALSE if it already exists */
int TableSet(struct Table *Tbl, const Str *Key, struct Value *Val)
{
    int HashPos;
    int AddAt;
    
    HashPos = TableSearch(Tbl, Key, &AddAt);

    if (HashPos == -1)
    {
        if (AddAt == -1)
            Fail("variable table is full\n");
        else
        {   /* add it to the table */
            struct TableEntry *Entry = &Tbl->HashTable[AddAt];
            Entry->Key = *Key;
            Entry->Val = Val;
            return TRUE;
        }
    }

    return FALSE;
}

/* find a value in a table. returns FALSE if not found */
int TableGet(struct Table *Tbl, const Str *Key, struct Value **Val)
{
    int HashPos;
    int AddAt;
    
    HashPos = TableSearch(Tbl, Key, &AddAt);

    if (HashPos == -1)
        return FALSE;
    
    *Val = Tbl->HashTable[HashPos].Val;
    return TRUE;
}
