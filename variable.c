#include <string.h>

#include "picoc.h"

/* the table of global definitions */
struct Table GlobalTable;
struct TableEntry GlobalHashTable[GLOBAL_TABLE_SIZE];

/* the stack */
struct StackFrame Stack[STACK_MAX];
int StackUsed = 0;


/* initialise the variable system */
void VariableInit()
{
    TableInit(&GlobalTable, &GlobalHashTable[0], GLOBAL_TABLE_SIZE);
}

/* allocate some memory, either on the heap or the stack and check if we've run out */
void *VariableAlloc(struct LexState *Lexer, int Size, int OnHeap)
{
    void *NewValue;
    
    if (OnHeap)
        NewValue = HeapAlloc(Size);
    else
        NewValue = HeapAllocStack(Size);
    
    if (NewValue == NULL)
        ProgramFail(Lexer, "out of memory");
    
    return NewValue;
}

/* allocate a value either on the heap or the stack using space dependent on what type we want */
struct Value *VariableAllocValueAndData(struct LexState *Lexer, int DataSize, int OnHeap)
{
    struct Value *NewValue = VariableAlloc(Lexer, DataSize, OnHeap);
    NewValue->Val = (union AnyValue *)((void *)NewValue + sizeof(struct Value));
    NewValue->ValOnHeap = OnHeap;
    NewValue->ValOnStack = !OnHeap;
    
    return NewValue;
}

/* allocate a value given its type */
struct Value *VariableAllocValueFromType(struct LexState *Lexer, struct ValueType *Typ, int OnHeap)
{
    struct Value *NewValue = VariableAllocValueAndData(Lexer, Typ->Sizeof, OnHeap);
    NewValue->Typ = Typ;
    return NewValue;
}

/* allocate a value either on the heap or the stack and copy its value */
struct Value *VariableAllocValueAndCopy(struct LexState *Lexer, struct Value *FromValue, int OnHeap)
{
    struct Value *NewValue = VariableAllocValueAndData(Lexer, FromValue->Typ->Sizeof, OnHeap);
    NewValue->Typ = FromValue->Typ;
    memcpy(NewValue->Val, FromValue->Val, FromValue->Typ->Sizeof);
    return NewValue;
}

/* define a variable */
void VariableDefine(struct LexState *Lexer, const Str *Ident, struct Value *InitValue)
{
    if (!TableSet((StackUsed == 0) ? &GlobalTable : &Stack[StackUsed-1].LocalTable, Ident, VariableAllocValueAndCopy(Lexer, InitValue, StackUsed == 0)))
        ProgramFail(Lexer, "'%S' is already defined", Ident);
}

/* check if a variable with a given name is defined */
int VariableDefined(Str *Ident)
{
    struct Value *FoundValue;
    
    if (StackUsed == 0 || !TableGet(&Stack[StackUsed-1].LocalTable, Ident, &FoundValue))
    {
        if (!TableGet(&GlobalTable, Ident, &FoundValue))
            return FALSE;
    }

    return TRUE;
}

/* get the value of a variable. must be defined */
void VariableGet(struct LexState *Lexer, Str *Ident, struct Value **LVal)
{
    if (StackUsed == 0 || !TableGet(&Stack[StackUsed-1].LocalTable, Ident, LVal))
    {
        if (!TableGet(&GlobalTable, Ident, LVal))
            ProgramFail(Lexer, "'%S' is undefined", Ident);
    }
}

/* free and/or pop the top value off the stack. Var must be the top value on the stack! */
void VariableStackPop(struct LexState *Lexer, struct Value *Var)
{
    int Success;
    
    if (Var->ValOnHeap)
    {
        HeapFree(Var->Val);
        Success = HeapPopStack(Var, sizeof(struct Value));                       /* free from heap */
    }
    else if (Var->ValOnStack)
        Success = HeapPopStack(Var, sizeof(struct Value) + Var->Typ->Sizeof);    /* free from stack */
    else
        Success = HeapPopStack(Var, sizeof(struct Value));                       /* value isn't our problem */
        
    if (!Success)
        ProgramFail(Lexer, "stack underrun");
}

/* add a stack frame when doing a function call */
void VariableStackFrameAdd(struct LexState *Lexer)
{
    struct StackFrame *NewFrame = &Stack[StackUsed];
    
    if (StackUsed >= STACK_MAX)
        ProgramFail(Lexer, "too many nested function calls");
        
    NewFrame->ReturnLex = *Lexer;
    TableInit(&NewFrame->LocalTable, &NewFrame->LocalHashTable[0], LOCAL_TABLE_SIZE);
    StackUsed++;
    HeapPushStackFrame();
}

/* remove a stack frame */
void VariableStackFramePop(struct LexState *Lexer)
{
    if (StackUsed == 0)
        ProgramFail(Lexer, "stack is empty - can't go back");
        
    StackUsed--;
    *Lexer = Stack[StackUsed].ReturnLex;
    HeapPopStackFrame();
}
