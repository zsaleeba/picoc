#include <string.h>

#include "picoc.h"

/* the table of global definitions */
struct Table GlobalTable;
struct TableEntry GlobalHashTable[GLOBAL_TABLE_SIZE];

/* the table of function definitions */
struct LexState FunctionStore[FUNCTION_STORE_MAX];
int FunctionStoreUsed = 0;

/* the stack */
struct StackFrame Stack[STACK_MAX];
int StackUsed = 0;


/* initialise the variable system */
void VariableInit()
{
    TableInit(&GlobalTable, &GlobalHashTable[0], GLOBAL_TABLE_SIZE);
}

/* allocate some memory, either on the heap or the stack and check if we've run out */
void *VariableAlloc(struct LexState *Lexer, int Size)
{
    void *NewValue;
    
    if (StackUsed == 0)
        NewValue = HeapAlloc(Size);
    else
        NewValue = HeapAllocStack(Size);
    
    if (NewValue == NULL)
        ProgramFail(Lexer, "out of memory");
    
    return NewValue;
}

/* allocate a value either on the heap or the stack using space dependent on what type we want */
struct Value *VariableAllocValueAndData(struct LexState *Lexer, int DataSize)
{
    struct Value *NewValue = VariableAlloc(Lexer, DataSize);
    NewValue->Val = (union AnyValue *)((void *)NewValue + sizeof(struct Value));
    NewValue->MustFree = (StackUsed == 0);
    
    return NewValue;
}

/* allocate a value given its type */
struct Value *VariableAllocValueFromType(struct LexState *Lexer, struct ValueType *Typ)
{
    struct Value *NewValue = VariableAllocValueAndData(Typ->Sizeof);
    NewValue->Typ = Typ;
    return NewValue;
}

/* allocate a value either on the heap or the stack and copy its value */
struct Value *VariableAllocValueAndCopy(struct LexState *Lexer, struct Value *FromValue)
{
    struct Value *NewValue = VariableAllocValueAndData(TypeSizeof(FromValue->Typ));
    NewValue->Typ = FromValue->Typ;
    memcpy(NewValue->Val, FromValue->Val, TypeSizeof(FromValue->Typ));
    return NewValue;
}

/* define a variable */
void VariableDefine(struct LexState *Lexer, const Str *Ident, struct Value *InitValue)
{
    if (!TableSet((StackUsed == 0) ? &GlobalTable : &Stack[StackUsed-1].LocalTable, Ident, VariableAllocValueAndCopy(InitValue)))
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
XXX
void VariableGet(struct LexState *Lexer, Str *Ident, struct Value *Val, struct Value **LVal)
{
    if (StackUsed == 0 || !TableGet(&Stack[StackUsed-1].LocalTable, Ident, LVal))
    {
        if (!TableGet(&GlobalTable, Ident, LVal))
            ProgramFail(Lexer, "'%S' is undefined", Ident);
    }

    *Val = **LVal;
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
}
