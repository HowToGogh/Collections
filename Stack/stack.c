#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//  Static functions are not documented, 
//  due to the clarity of the functionality and unavailability outside the current file.

static int stack_is_empty(Stack*);
static int stack_is_full(Stack*);
static int stack_is_null(Stack*);

Stack* stack_create() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    if (stack == NULL) {
        fprintf(stderr, "Memory for stack pointer is not allocated.\n");
        return NULL;
    }

    stack->size = STACK_DEFAULT_SIZE;

    stack->array = (int*)malloc(sizeof(int) * stack->size);
    if (stack->array == NULL) {
        fprintf(stderr, "Memory for stack array is not allocated.\n");
        free(stack);
        return NULL;
    }

    stack->top = -1;

    return stack;
}

void stack_delete(Stack* stack) {
    if (stack_is_null(stack)) {
        return;
    }
    free(stack->array);
    free(stack);
}

void stack_push(Stack* stack, int value) {
    if (stack_is_null(stack)) {
        printf("Stack is NULL.\n");
        return;
    }

    if (stack_is_full(stack)) {
        stack->size *= 2;
        stack->array = realloc(stack->array, sizeof(int) * stack->size);
    }

    stack->array[++stack->top] = value;
}

int stack_pop(Stack* stack) {
    if (stack_is_null(stack)) {
        printf("Stack is NULL.\n");
        return FAILURE_CODE;
    }

    if (stack_is_empty(stack)) {
        fprintf(stderr, "Stack is empty. No value to pop.\n");
        return FAILURE_CODE;
    }

    return stack->array[stack->top--];
}

int stack_top(Stack* stack) {
    if (stack_is_null(stack)) {
        printf("Stack is NULL.\n");
        return FAILURE_CODE;
    }

    if (stack_is_empty(stack)) {
        fprintf(stderr, "Stack is empty.\n");
        return FAILURE_CODE;
    }

    return stack->array[stack->top];
}

static int stack_is_empty(Stack* stack) {
    if (stack_is_null(stack)) {
        return FAILURE_CODE;
    }

    return stack->top == -1;
}

static int stack_is_full(Stack* stack) {
    if (stack_is_null(stack)) {
        return FAILURE_CODE;
    }

    return stack->top == stack->size - 1;
}

static int stack_is_null(Stack* stack) {
    return stack == NULL;
}