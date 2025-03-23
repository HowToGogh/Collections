#pragma once

#define STACK_DEFAULT_SIZE 64
#define FAILURE_CODE -1

typedef struct {
    int* array;
    size_t size;
    size_t top;
} Stack;

Stack* stack_create();
void stack_delete(Stack* stack);
void stack_push(Stack* stack, int value);
int stack_pop(Stack* stack);
int stack_top(Stack* stack);