/* picoc interactive debugger */

#ifndef NO_DEBUGGER

#include "interpreter.h"

#define BREAKPOINT_TABLE_SIZE 21
#define BREAKPOINT_HASH(p) ( ((unsigned long)(p)->FileName) ^ (((p)->Line << 16) | ((p)->CharacterPos << 16)) )

struct Table BreakpointTable;
struct TableEntry *BreakpointHashTable[BREAKPOINT_TABLE_SIZE];
int BreakpointCount = 0;
int DebugManualBreak = FALSE;

/* initialise the debugger by clearing the breakpoint table */
void DebugInit()
{
    TableInitTable(&BreakpointTable, &BreakpointHashTable[0], BREAKPOINT_TABLE_SIZE, TRUE);
    BreakpointCount = 0;
}

/* free the contents of the breakpoint table */
void DebugCleanup()
{
    struct TableEntry *Entry;
    struct TableEntry *NextEntry;
    int Count;
    
    for (Count = 0; Count < BreakpointTable.Size; Count++)
    {
        for (Entry = BreakpointHashTable[Count]; Entry != NULL; Entry = NextEntry)
        {
            NextEntry = Entry->Next;
            HeapFreeMem(Entry);
        }
    }
}

/* search the table for a breakpoint */
static struct TableEntry *DebugTableSearchBreakpoint(struct ParseState *Parser, int *AddAt)
{
    struct TableEntry *Entry;
    int HashValue = BREAKPOINT_HASH(Parser) % BreakpointTable.Size;
    
    for (Entry = BreakpointHashTable[HashValue]; Entry != NULL; Entry = Entry->Next)
    {
        if (Entry->p.b.FileName == Parser->FileName && Entry->p.b.Line == Parser->Line && Entry->p.b.CharacterPos == Parser->CharacterPos)
            return Entry;   /* found */
    }
    
    *AddAt = HashValue;    /* didn't find it in the chain */
    return NULL;
}

/* set a breakpoint in the table */
void DebugSetBreakpoint(struct ParseState *Parser)
{
    int AddAt;
    struct TableEntry *FoundEntry = DebugTableSearchBreakpoint(Parser, &AddAt);
    
    if (FoundEntry == NULL)
    {   
        /* add it to the table */
        struct TableEntry *NewEntry = HeapAllocMem(sizeof(struct TableEntry));
        if (NewEntry == NULL)
            ProgramFail(NULL, "out of memory");
            
        NewEntry->p.b.FileName = Parser->FileName;
        NewEntry->p.b.Line = Parser->Line;
        NewEntry->p.b.CharacterPos = Parser->CharacterPos;
        NewEntry->Next = BreakpointHashTable[AddAt];
        BreakpointHashTable[AddAt] = NewEntry;
        BreakpointCount++;
    }
}

/* delete a breakpoint from the hash table */
int DebugClearBreakpoint(struct ParseState *Parser)
{
    struct TableEntry **EntryPtr;
    int HashValue = BREAKPOINT_HASH(Parser) % BreakpointTable.Size;
    
    for (EntryPtr = &BreakpointHashTable[HashValue]; *EntryPtr != NULL; EntryPtr = &(*EntryPtr)->Next)
    {
        struct TableEntry *DeleteEntry = *EntryPtr;
        if (DeleteEntry->p.b.FileName == Parser->FileName && DeleteEntry->p.b.Line == Parser->Line && DeleteEntry->p.b.CharacterPos == Parser->CharacterPos)
        {
            *EntryPtr = DeleteEntry->Next;
            HeapFreeMem(DeleteEntry);
            BreakpointCount--;

            return TRUE;
        }
    }

    return FALSE;
}

/* before we run a statement, check if there's anything we have to do with the debugger here */
void DebugCheckStatement(struct ParseState *Parser)
{
    int DoBreak = FALSE;
    int AddAt;
    
    /* has the user manually pressed break? */
    if (DebugManualBreak)
    {
        DoBreak = TRUE;
        DebugManualBreak = FALSE;
    }
    
    /* is this a breakpoint location? */
    if (BreakpointCount != 0 && DebugTableSearchBreakpoint(Parser, &AddAt) != NULL)
        DoBreak = TRUE;
    
    /* handle a break */
    if (DoBreak)
    {
        PlatformPrintf("Handling a break\n");
        PicocParseInteractiveNoStartPrompt(FALSE);
    }
}

void DebugStep()
{
}
#endif /* !NO_DEBUGGER */
