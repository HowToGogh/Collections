#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int stack_is_null(Stack* stack);

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

// void stack_delete(Stack* stack) {
//     if (stack->array != NULL) {
//         free(stack->array);
//         stack->array = NULL;
//     }
//     stack->top = -1;
// }

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

int stack_is_empty(Stack* stack) {
    if (stack_is_null(stack)) {
        return FAILURE_CODE;
    }
    return stack->top == -1;
}

int stack_is_full(Stack* stack) {
    if (stack_is_null(stack)) {
        return FAILURE_CODE;
    }
    return stack->top == STACK_MAX_SIZE - 1;
}

int stack_is_null(Stack* stack) {
    if (stack == NULL) {
        fprintf(stderr, "Stack pointer is NULL.\n");
        return 1;
    }
    return 0;
}