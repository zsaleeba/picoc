#include <string.h>
#include "picoc.h"

/* quick hash function */
static unsigned int TableHash(const Str *Key)
{
    if (Key->Len == 0)
        return 0;
    else
        return ((*Key->Str << 24) | (Key->Str[Key->Len-1] << 16) | (Key->Str[Key->Len >> 1] << 8)) ^ Key->Len;
}

/* initialise a table */
void TableInit(struct Table *Tbl, struct TableEntry **HashTable, int Size, int OnHeap)
{
    Tbl->Size = Size;
    Tbl->OnHeap = OnHeap;
    Tbl->HashTable = HashTable;
    memset(HashTable, '\0', sizeof(struct TableEntry *) * Size);
}

/* check a hash table entry for a key */
static int TableSearch(struct Table *Tbl, const Str *Key, int *AddAt)
{
    struct TableEntry *Entry;
    int HashValue = TableHash(Key) % Tbl->Size;;
    
    for (Entry = Tbl->HashTable[HashValue]; Entry != NULL; Entry = Entry->Next)
    {
        if (StrEqual(&Entry->Key, Key))
            return HashValue;   /* found */
    }
    
    *AddAt = HashValue;    /* didn't find it in the chain */
    return -1;
}

/* set an identifier to a value. returns FALSE if it already exists */
int TableSet(struct Table *Tbl, const Str *Key, struct Value *Val)
{
    int HashPos;
    int AddAt;
    
    HashPos = TableSearch(Tbl, Key, &AddAt);

    if (HashPos == -1)
    {   /* add it to the table */
        struct TableEntry *NewEntry = VariableAlloc(NULL, sizeof(struct TableEntry), Tbl->OnHeap);
        NewEntry->Key = *Key;
        NewEntry->Val = Val;
        NewEntry->Next = Tbl->HashTable[AddAt];
        Tbl->HashTable[AddAt] = NewEntry;
        return TRUE;
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
    
    *Val = Tbl->HashTable[HashPos]->Val;
    return TRUE;
}
