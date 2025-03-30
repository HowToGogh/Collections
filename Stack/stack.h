#pragma once

#define STACK_DEFAULT_SIZE 64
#define FAILURE_CODE -1

typedef struct {
    int* array;
    int top;
    size_t size;
} Stack;

Stack* stack_create();
void stack_delete(Stack*);
void stack_push(Stack*, int);
int stack_pop(Stack*);
int stack_top(Stack*);