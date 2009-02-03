/* stack grows up from the bottom and heap grows down from the top of heap space */
#include <stdio.h>
#include <memory.h>
#include <assert.h>
#include "picoc.h"

#define FREELIST_BUCKETS 8                          /* freelists for 4, 8, 12 ... 32 byte allocs */
#define SPLIT_MEM_THRESHOLD 16                      /* don't split memory which is close in size */

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

/* get all the free space from the top of the stack - only suitable for temporary work */
void *HeapStackGetFreeSpace(int *MemAvailable)
{
    *MemAvailable = HeapBottom - StackTop;
    return StackTop;
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
#ifdef DEBUG_HEAP
        printf("allocating %d(%d) from bucket", Size, AllocSize);
#endif
        NewMem = FreeListBucket[Bucket];
        assert((unsigned long)NewMem >= (unsigned long)&HeapMemory && (unsigned char *)NewMem - &HeapMemory[0] < HEAP_SIZE);
        FreeListBucket[Bucket] = *(struct AllocNode **)NewMem;
        assert(FreeListBucket[Bucket] == NULL || ((unsigned long)FreeListBucket[Bucket] >= (unsigned long)&HeapMemory && (unsigned char *)FreeListBucket[Bucket] - &HeapMemory[0] < HEAP_SIZE));
        NewMem->Size = AllocSize;
    }
    else if (FreeListBig != NULL)
    { /* grab the first item from the "big" freelist we can fit in */
        for (FreeNode = &FreeListBig; *FreeNode != NULL && (*FreeNode)->Size < AllocSize; FreeNode = &(*FreeNode)->NextFree)
        {}
        
        if (*FreeNode != NULL)
        {
            assert((unsigned long)*FreeNode >= (unsigned long)&HeapMemory && (unsigned char *)*FreeNode - &HeapMemory[0] < HEAP_SIZE);
            assert((*FreeNode)->Size < HEAP_SIZE && (*FreeNode)->Size > 0);
            if ((*FreeNode)->Size < Size + SPLIT_MEM_THRESHOLD)
            { /* close in size - reduce fragmentation by not splitting */
#ifdef DEBUG_HEAP
               printf("allocating %d(%d) from freelist, no split (%d)", Size, AllocSize, (*FreeNode)->Size);
#endif
                NewMem = *FreeNode;
                assert((unsigned long)NewMem >= (unsigned long)&HeapMemory && (unsigned char *)NewMem - &HeapMemory[0] < HEAP_SIZE);
                *FreeNode = NewMem->NextFree;
            }
            else
            { /* split this big memory chunk */
#ifdef DEBUG_HEAP
                printf("allocating %d(%d) from freelist, split chunk (%d)", Size, AllocSize, (*FreeNode)->Size);
#endif
                NewMem = *FreeNode + (*FreeNode)->Size - AllocSize;
                assert((unsigned long)NewMem >= (unsigned long)&HeapMemory && (unsigned char *)NewMem - &HeapMemory[0] < HEAP_SIZE);
                (*FreeNode)->Size -= AllocSize;
                NewMem->Size = AllocSize;
            }
        }
    }
    
    if (NewMem == NULL)
    { /* couldn't allocate from a freelist - try to increase the size of the heap area */
#ifdef DEBUG_HEAP
        printf("allocating %d(%d) at bottom of heap", Size, AllocSize);
#endif
        if (HeapBottom - AllocSize < StackTop)
            return NULL;
        
        HeapBottom -= AllocSize;
        NewMem = HeapBottom;
        NewMem->Size = AllocSize;
    }
    
    memset(&NewMem->NextFree, '\0', AllocSize-sizeof(NewMem->Size));
#ifdef DEBUG_HEAP
    printf(" = %lx\n", (unsigned long)&NewMem->NextFree);
#endif
    return (void *)&NewMem->NextFree;
}

/* free some dynamically allocated memory */
void HeapFree(void *Mem)
{
    struct AllocNode *MemNode = (struct AllocNode *)(Mem-sizeof(int));
    int Bucket = MemNode->Size >> 2;
    
    assert((unsigned long)Mem >= (unsigned long)&HeapMemory && (unsigned char *)Mem - &HeapMemory[0] < HEAP_SIZE);
    assert(MemNode->Size < HEAP_SIZE && MemNode->Size > 0);
    if (Mem == NULL)
        return;
    
    if ((void *)MemNode == HeapBottom)
    { /* pop it off the bottom of the heap, reducing the heap size */
#ifdef DEBUG_HEAP
        printf("freeing %d from bottom of heap\n", MemNode->Size);
#endif
        HeapBottom += sizeof(int) + MemNode->Size;
    }
    else if (Bucket < FREELIST_BUCKETS)
    { /* we can fit it in a bucket */
#ifdef DEBUG_HEAP
        printf("freeing %d to bucket\n", MemNode->Size);
#endif
        assert(FreeListBucket[Bucket] == NULL || ((unsigned long)FreeListBucket[Bucket] >= (unsigned long)&HeapMemory && (unsigned char *)FreeListBucket[Bucket] - &HeapMemory[0] < HEAP_SIZE));
        *(struct AllocNode **)MemNode = FreeListBucket[Bucket];
        FreeListBucket[Bucket] = (struct AllocNode *)MemNode;
    }
    else
    { /* put it in the big memory freelist */
#ifdef DEBUG_HEAP
        printf("freeing %lx:%d to freelist\n", (unsigned long)Mem, MemNode->Size);
#endif
        assert(FreeListBig == NULL || ((unsigned long)FreeListBig >= (unsigned long)&HeapMemory && (unsigned char *)FreeListBig - &HeapMemory[0] < HEAP_SIZE));
        MemNode->NextFree = FreeListBig;
        FreeListBig = MemNode;
    }
}
