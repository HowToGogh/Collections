#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static int list_is_empty(List*);
static int list_is_full(List*);
static int list_is_null(List*);
static void list_transition(List*, int, int);

List* list_create() {
    List* list = (List*)malloc(sizeof(List));

    if (list == NULL) {
        fprintf(stderr, "Memory for list pointer is not allocated.\n");
        return NULL;
    }

    list->size = LIST_DEFAULT_SIZE;

    list->array = (int*)malloc(sizeof(int) * list->size);
    if (list->array == NULL) {
        fprintf(stderr, "Memory for list array is not allocated.\n");
        free(list);
        return NULL;
    }

    list->last = -1;

    return list;
}

void list_delete(List* list) {
    if (list_is_null(list)) {
        return;
    }
    free(list->array);
    free(list);
}

void list_add(List* list, int value) {
    if (list_is_null(list)) {
        fprintf(stderr, "List is NULL.\n");
        return;
    }

    if (list_is_full(list)) {
        list->size *= 2;
        list->array = realloc(list->array, sizeof(int) * list->size);
    }

    list->array[++list->last] = value;
}

int list_take(List* list, int index) {
    if (list_is_null(list)) {
        fprintf(stderr, "List is NULL.\n");
        return FAILURE_CODE;
    }

    if (list_is_empty(list)) {
        fprintf(stderr, "List is empty, nothing to take.\n");
        return FAILURE_CODE;
    }

    if (index > list->last) {
        fprintf(stderr, "List index is out of range, nothing to take.\n");
        return FAILURE_CODE;
    }

    return list->array[index];
}

void list_remove(List* list, int index) {
    if (list_is_null(list)) {
        fprintf(stderr, "List is NULL.\n");
        return;
    }

    if (list_is_empty(list)) {
        fprintf(stderr, "List is empty, nothing to remove.\n");
        return;
    }

    if (index > list->last) {
        fprintf(stderr, "List index is out of range, nothing to remove.\n");
        return;
    }

    list_transition(list, index, list->last--);
}

static int list_is_empty(List* list) {
    if (list_is_null(list)) {
        return FAILURE_CODE;
    }

    return list->last == -1;
}

static int list_is_full(List* list) {
    if (list_is_null(list)) {
        return FAILURE_CODE;
    }

    return list->last == list->size - 1;
}

static int list_is_null(List* list) {
    return list == NULL;
}

static void list_transition(List* list, int from, int to) {
    if (list_is_null(list)) {
        return;
    }

    if (list_is_empty(list)) {
        return;
    }

    for (int i = from; i != to; ++i) {
        list->array[from] = list->array[from + 1];
    }
}