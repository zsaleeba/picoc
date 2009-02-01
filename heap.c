/* stack grows up from the bottom and heap grows down from the top of heap space */
#include <memory.h>
#include <assert.h>
#include "picoc.h"

#define FREELIST_BUCKETS 8                          /* freelists for 4, 8, 12 ... 32 byte allocs */
#define SPLIT_MEM_THRESHOLD 16                      /* don't split memory which is close in size */

struct AllocNode
{
    int Size;
    struct AllocNode *NextFree;
};

static unsigned char HeapMemory[HEAP_SIZE];         /* all memory - stack and heap */
static void *StackFrame = &HeapMemory;              /* the current stack frame */
static void *StackTop = &HeapMemory;                /* the top of the stack */

static void *HeapBottom = &HeapMemory[HEAP_SIZE];   /* the bottom of the (downward-growing) heap */
static struct AllocNode *FreeListBucket[FREELIST_BUCKETS];      /* we keep a pool of freelist buckets to reduce fragmentation */
static struct AllocNode *FreeListBig;                           /* free memory which doesn't fit in a bucket */

/* initialise the stack and heap storage */
void HeapInit()
{
    int Count;
    
    StackFrame = &HeapMemory;
    StackTop = &HeapMemory;
    *(void **)StackFrame = NULL;
    HeapBottom = &HeapMemory[HEAP_SIZE];
    FreeListBig = NULL;
    for (Count = 0; Count < FREELIST_BUCKETS; Count++)
        FreeListBucket[Count] = NULL;
}

/* allocate some space on the stack, in the current stack frame
 * clears memory. can return NULL if out of stack space */
void *HeapAllocStack(int Size)
{
    void *NewMem = StackTop;
    void *NewTop = StackTop + MEM_ALIGN(Size);
    if (NewTop > HeapBottom)
        return NULL;
        
    StackTop = NewTop;
    memset(NewMem, '\0', Size);
    return NewMem;
}

/* free some space at the top of the stack */
int HeapPopStack(void *Addr, int Size)
{
    int ToLose = MEM_ALIGN(Size);
    if (ToLose > (StackTop - (void *)&HeapMemory))
        return FALSE;
    
    StackTop -= ToLose;
    assert(StackTop == Addr);
    
    return TRUE;
}

/* push a new stack frame on to the stack */
void HeapPushStackFrame()
{
    *(void **)StackTop = StackFrame;
    StackFrame = StackTop;
    StackTop += sizeof(void *);
}

/* pop the current stack frame, freeing all memory in the frame. can return NULL */
int HeapPopStackFrame()
{
    if (*(void **)StackFrame == NULL)
    {
        StackTop = StackFrame;
        StackFrame = *(void **)StackFrame;
        return TRUE;
    }
    else
        return FALSE;
}

/* allocate some dynamically allocated memory. memory is cleared. can return NULL if out of memory */
void *HeapAlloc(int Size)
{
    struct AllocNode *NewMem = NULL;
    struct AllocNode **FreeNode;
    int AllocSize = MEM_ALIGN(Size) + sizeof(NewMem->Size);
    int Bucket = AllocSize >> 2;
    
    if (Size == 0)
        return NULL;
    
    if (Bucket < FREELIST_BUCKETS && FreeListBucket[Bucket] != NULL)
    { /* try to allocate from a freelist bucket first */
        NewMem = FreeListBucket[Bucket];
        FreeListBucket[Bucket] = *(struct AllocNode **)NewMem;
        NewMem->Size = AllocSize;
    }
    else if (FreeListBig != NULL)
    { /* grab the first item from the "big" freelist we can fit in */
        for (FreeNode = &FreeListBig; *FreeNode != NULL && (*FreeNode)->Size < AllocSize; FreeNode = &(*FreeNode)->NextFree)
        {}
        
        if (*FreeNode != NULL)
        {
            if ((*FreeNode)->Size < Size + SPLIT_MEM_THRESHOLD)
            { /* close in size - reduce fragmentation by not splitting */
                NewMem = *FreeNode;
                *FreeNode = NewMem->NextFree;
            }
            else
            { /* split this big memory chunk */
                NewMem = *FreeNode + (*FreeNode)->Size - AllocSize;
                (*FreeNode)->Size -= AllocSize;
                NewMem->Size = AllocSize;
            }
        }
    }
    
    if (NewMem == NULL)
    { /* couldn't allocate from a freelist - try to increase the size of the heap area */
        if (HeapBottom - AllocSize < StackTop)
            return NULL;
        
        HeapBottom -= AllocSize;
        NewMem = HeapBottom;
        NewMem->Size = AllocSize;
    }
    
    memset(&NewMem->NextFree, '\0', AllocSize-sizeof(NewMem->Size));
    return (void *)&NewMem->NextFree;
}

/* free some dynamically allocated memory */
void HeapFree(void *Mem)
{
    struct AllocNode *MemNode = (struct AllocNode *)(Mem-sizeof(int));
    int Bucket = MemNode->Size >> 2;
    
    if (Mem == NULL)
        return;
    
    if ((void *)MemNode == HeapBottom)
    { /* pop it off the bottom of the heap, reducing the heap size */
        HeapBottom += sizeof(int) + MemNode->Size;
    }
    else if (Bucket < FREELIST_BUCKETS)
    { /* we can fit it in a bucket */
        *(struct AllocNode **)MemNode = FreeListBucket[Bucket];
        FreeListBucket[Bucket] = (struct AllocNode *)MemNode;
    }
    else
    { /* put it in the big memory freelist */
        MemNode->NextFree = FreeListBig;
        FreeListBig = MemNode;
    }
}
