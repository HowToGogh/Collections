#pragma once
//  This parameter is responsible for the default size of the stack array, however,
//  the stack size can change during runtime regardless of the macro value.
#define STACK_DEFAULT_SIZE 64
//  Default error code. 
//  It may be mistaken for the result of a function.
//  It is recommended to keep a close eye on error messages.
#define FAILURE_CODE -1

/*
The structure contains:
- array: a pointer to a memory location allocated for stack values.
Memory is allocated by the stack_create() function (see the stack_create() documentation).
- top: the value indicating the index of the top element of the stack.
- size: the value indicating the actual size of the array (by default, size is STACK_DEFAULT_SIZE)

IMPORTANT:

-It is not recommended to use the structure fields manually, it is better to use the appropriate functions.
Manual modification can lead to errors, data losses, or undefined results.
*/
typedef struct stack_t {
    int* array;
    int top;
    size_t size;
} Stack;

/*
    To be able to use the stack, first of all it must be created.
    If memory for stack wasn't allocated correctly (due to reasons beyond the control of the implementation),
    stack will remain undefined.

    IMPORTANT:

    - Using the structure before creation is not recommended.
    It's better to declare stack immediately.

    USAGE EXAMPLE:

    Stack* myStack = stack_create();
*/
Stack* stack_create();
/*
    If the stack is no longer required, it should be deleted.
    The function frees up the memory allocated for the stack array and makes the fields of the structure undefined.

    IMPORTANT:

    - Using the structure after deletion is not recommended until it is recreated.

    USAGE EXAMPLE:

    stack_delete(myStack);
*/
void stack_delete(Stack*);
/*
    The function adds a value to the stack.

    IMPORTANT:

    - If there is not enough memory in the stack to add a value, the stack memory is expanded (doubled).
    - It is possible to add a value to an undefined stack (before using the stack_create() function),
    but the result will be undefined.

    USAGE EXAMPLE:

    stack_push(myStack, 42);
*/
void stack_push(Stack*, int);
/*
    The function returns the top value of the stack and removes it from it.
    If the stack is empty, an FAILURE_CODE is returned (-1 by default) with the corresponding message.
    The function does not delete values from memory, but makes them "garbage".

    IMPORTANT:

    - Value popped from an undefined stack is undefined.
    - If the memory for the array has been expanded during the process of adding values to the stack,
    popping values does not free up unused memory.

    USAGE EXAMPLE:

    int popped_value = stack_pop(myStack);
*/
int stack_pop(Stack*);
/*
    The function returns the top value of the stack and not removes it from it.
    If the stack is empty, an FAILURE_CODE is returned (-1 by default) with the corresponding message.

    IMPORTANT:

    - The value taken from the undefined stack is undefined.

    USAGE EXAMPLE:

    int top_value = stack_top(myStack);
*/
int stack_top(Stack*);