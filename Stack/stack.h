#pragma once

#define STACK_MAX_SIZE 128
#define FAILURE_CODE -1

typedef struct {
    int* array;
    int top;
} Stack;

void stack_create(Stack* stack);
// void stack_delete(Stack* stack);
void stack_push(int value, Stack* stack);
int stack_pop(Stack* stack);
int stack_top(Stack* stack);
int stack_is_empty(Stack* stack);
int stack_is_full(Stack* stack);