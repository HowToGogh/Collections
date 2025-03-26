#pragma once

#define LIST_DEFAULT_SIZE 64
#define FAILURE_CODE -1

typedef struct {
    int* array;
    int last;
    size_t size;
} List;

List* list_create();
void list_delete(List* list);
void list_add(List* list, int value);
int list_take(List* list, int index);
void list_remove(List* list, int index);
int list_find(List* list, int value);
void list_sort(List* list);