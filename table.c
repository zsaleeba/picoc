#include <string.h>
#include "picoc.h"

/* quick hash function */
static unsigned int TableHash(const char *Key, int KeyLen)
{
    if (KeyLen == 0)
        return 0;
    else
        return ((*Key << 24) | (Key[KeyLen-1] << 16) | (Key[KeyLen >> 1] << 8)) ^ KeyLen;
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
static int TableSearch(struct Table *Tbl, const char *Key, int Len, int *AddAt)
{
    struct TableEntry *Entry;
    int HashValue = TableHash(Key, Len) % Tbl->Size;
    
    for (Entry = Tbl->HashTable[HashValue]; Entry != NULL; Entry = Entry->Next)
    {
        if (strncmp(Entry->Key, Key, Len) == 0 && Entry->Key[Len] == '\0')
            return HashValue;   /* found */
    }
    
    *AddAt = HashValue;    /* didn't find it in the chain */
    return -1;
}

/* set an identifier to a value. returns FALSE if it already exists */
int TableSet(struct Table *Tbl, const char *Key, struct Value *Val)
{
    int AddAt;
    int KeyLen = strlen(Key);
    int HashPos = TableSearch(Tbl, Key, KeyLen, &AddAt);
    
    if (HashPos == -1)
    {   /* add it to the table */
        struct TableEntry *NewEntry = VariableAlloc(NULL, sizeof(struct TableEntry), Tbl->OnHeap);
        NewEntry->Key = Key;
        NewEntry->Val = Val;
        NewEntry->Next = Tbl->HashTable[AddAt];
        Tbl->HashTable[AddAt] = NewEntry;
        return TRUE;
    }

    return FALSE;
}

/* find a value in a table. returns FALSE if not found */
int TableGet(struct Table *Tbl, const char *Key, struct Value **Val)
{
    int AddAt;
    int HashPos = TableSearch(Tbl, Key, strlen(Key), &AddAt);
    if (HashPos == -1)
        return FALSE;
    
    *Val = Tbl->HashTable[HashPos]->Val;
    return TRUE;
}

/* set an identifier and return the identifier. share if possible */
const char *TableSetKey(struct Table *Tbl, const char *Ident, int IdentLen)
{
    int AddAt;
    int HashPos = TableSearch(Tbl, Ident, IdentLen, &AddAt);
    
    if (HashPos != -1)
        return Tbl->HashTable[HashPos]->Key;
    else
    {   /* add it to the table */
        struct TableEntry *NewEntry = HeapAlloc(sizeof(struct TableEntry) + IdentLen + 1);
        NewEntry->Key = (void *)NewEntry + sizeof(struct TableEntry);
        strncpy((char *)NewEntry->Key, Ident, IdentLen);
        NewEntry->Val = NULL;
        NewEntry->Next = Tbl->HashTable[AddAt];
        Tbl->HashTable[AddAt] = NewEntry;
        return NewEntry->Key;
    }
}
