#pragma once

#define LIST_DEFAULT_SIZE 64
#define FAILURE_CODE -1

typedef struct {
    int* array;
    int last;
    size_t size;
} List;

List* list_create();
void list_delete(List*);
void list_add(List*, int);
int list_take(List*, int);
void list_remove(List*, int);
int list_search(List*, int);
int list_binary_search(List*, int);
void list_sort(List*);