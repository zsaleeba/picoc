#include <string.h>
#include "picoc.h"

/* hash function for strings */
static unsigned int TableHash(const char *Key, int Len)
{
    unsigned int Hash = Len;
    int Offset;
    int Count;
    
    for (Count = 0, Offset = 8; Count < Len; Count++, Offset+=7)
    {
        if (Offset > sizeof(unsigned int) * 8 - 7)
            Offset -= sizeof(unsigned int) * 8 - 6;
            
        Hash ^= *Key++ << Offset;
    }
    
    return Hash;
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
static int TableSearch(struct Table *Tbl, const char *Key, int *AddAt)
{
    struct TableEntry *Entry;
    int HashValue = ((unsigned long)Key) % Tbl->Size;   /* shared strings have unique addresses so we don't need to hash them */
    
    for (Entry = Tbl->HashTable[HashValue]; Entry != NULL; Entry = Entry->Next)
    {
        if (Entry->p.v.Key == Key)
            return HashValue;   /* found */
    }
    
    *AddAt = HashValue;    /* didn't find it in the chain */
    return -1;
}

/* set an identifier to a value. returns FALSE if it already exists. 
 * Key must be a shared string from StrRegister() */
int TableSet(struct Table *Tbl, const char *Key, struct Value *Val)
{
    int AddAt;
    int HashPos = TableSearch(Tbl, Key, &AddAt);
    
    if (HashPos == -1)
    {   /* add it to the table */
        struct TableEntry *NewEntry = VariableAlloc(NULL, sizeof(struct TableEntry), Tbl->OnHeap);
        NewEntry->p.v.Key = Key;
        NewEntry->p.v.Val = Val;
        NewEntry->Next = Tbl->HashTable[AddAt];
        Tbl->HashTable[AddAt] = NewEntry;
        return TRUE;
    }

    return FALSE;
}

/* find a value in a table. returns FALSE if not found. 
 * Key must be a shared string from StrRegister() */
int TableGet(struct Table *Tbl, const char *Key, struct Value **Val)
{
    int AddAt;
    int HashPos = TableSearch(Tbl, Key, &AddAt);
    if (HashPos == -1)
        return FALSE;
    
    *Val = Tbl->HashTable[HashPos]->p.v.Val;
    return TRUE;
}

/* check a hash table entry for an identifier */
static int TableSearchIdentifier(struct Table *Tbl, const char *Key, int Len, int *AddAt)
{
    struct TableEntry *Entry;
    int HashValue = TableHash(Key, Len) % Tbl->Size;
    
    for (Entry = Tbl->HashTable[HashValue]; Entry != NULL; Entry = Entry->Next)
    {
        if (strncmp(&Entry->p.Key[0], Key, Len) == 0 && Entry->p.Key[Len] == '\0')
            return HashValue;   /* found */
    }
    
    *AddAt = HashValue;    /* didn't find it in the chain */
    return -1;
}

/* set an identifier and return the identifier. share if possible */
const char *TableSetIdentifier(struct Table *Tbl, const char *Ident, int IdentLen)
{
    int AddAt;
    int HashPos = TableSearchIdentifier(Tbl, Ident, IdentLen, &AddAt);
    
    if (HashPos != -1)
        return &Tbl->HashTable[HashPos]->p.Key[0];
    else
    {   /* add it to the table - we economise by not allocating the whole structure here */
        struct TableEntry *NewEntry = HeapAlloc(sizeof(struct TableEntry *) + IdentLen + 1);
        strncpy((char *)&NewEntry->p.Key[0], Ident, IdentLen);
        NewEntry->Next = Tbl->HashTable[AddAt];
        Tbl->HashTable[AddAt] = NewEntry;
        return &NewEntry->p.Key[0];
    }
}
