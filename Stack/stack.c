// Stack functionality;
// If there no error - there won't be any messages;
// If there is an error - there will be a couple of messages
// and maybe program will stop completely (idk how to fix it I'm stupid);

// Before using any of this create a stack object:
/* 
Stack myStack;
stack_create(&stack);
*/
// After this you can use others;


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int stack_is_empty(Stack* stack);
int stack_is_full(Stack* stack);
int stack_is_null(Stack* stack);

// Before this function Stack object is having undefined values
// This function will allocate memory for stack and define Stack.top;
void stack_create(Stack* stack) {
    if (stack_is_null(stack)) {
        return;
    }

    stack->array = (int*)malloc(STACK_MAX_SIZE * sizeof(int));
    if (stack->array == NULL) {
        fprintf(stderr, "Memory allocation for stack failed.\n");
        return;
    }
    stack->top = -1;
}

// After this function there will not be any memory for stack
// but Stack.top is still defined. Stack isn't destroyed completely;
// (!!!) I'm not sure this function is safe ((((( ;
void stack_delete(Stack* stack) {
    free(stack->array);
    stack->top = -1;
}

// Add item to an existing Stack;
void stack_push(int value, Stack* stack) {
    if (stack_is_null(stack)) {
        return;
    }

    if (stack_is_full(stack)) {
        fprintf(stderr, "Stack is full. Value is not pushed.\n");
        return;
    }

    stack->array[++stack->top] = value;
}

// Take item from Stack, item is returned and not in Stack anymore;
int stack_pop(Stack* stack) {
    if (stack_is_null(stack)) {
        return FAILURE_CODE;
    }

    if (stack_is_empty(stack)) {
        fprintf(stderr, "Stack is empty. No value to pop.\n");
        return FAILURE_CODE;
    }

    return stack->array[stack->top--];
}

// Take item from Stack, item is returned and still in Stack;
int stack_top(Stack* stack) {
    if (stack_is_null(stack)) {
        return FAILURE_CODE;
    }

    if (stack_is_empty(stack)) {
        fprintf(stderr, "Stack is empty.\n");
        return FAILURE_CODE;
    }

    return stack->array[stack->top];
}

// Check for Stack is empty (helpful definition)
int stack_is_empty(Stack* stack) {
    if (stack_is_null(stack)) {
        return FAILURE_CODE;
    }

    return stack->top == -1;
}

// Check for Stack is full (one more helpful definition)
int stack_is_full(Stack* stack) {
    if (stack_is_null(stack)) {
        return FAILURE_CODE;
    }

    return stack->top == STACK_MAX_SIZE - 1;
}

// You can not use this function in main, it used here only;
int stack_is_null(Stack* stack) {
    if (stack == NULL) {
        fprintf(stderr, "Stack pointer is NULL.\n");
        return 1;
    }
    return 0;
}