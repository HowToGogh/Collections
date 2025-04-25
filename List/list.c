#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//  Static functions are not documented, 
//  due to the clarity of the functionality and unavailability outside the current file.

static int list_is_empty(List*);
static int list_is_full(List*);
static int list_is_null(List*);
static void list_transition(List*, int, int);
static void swap(int*, int*);
static void partition();
static int search(List*, int);

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

int list_delete(List* list) {
    if (list_is_null(list)) {
        return ERROR_NULL;
    }

    free(list->array);
    free(list);

    return SUCCESS_NO_ERROR;
}

int list_add(List* list, int value) {
    if (list_is_null(list)) {
        fprintf(stderr, "List is NULL.\n");
        return ERROR_NULL;
    }

    if (list_is_full(list)) {
        list->size *= 2;
        list->array = realloc(list->array, sizeof(int) * list->size);
    }

    list->array[++list->last] = value;

    return SUCCESS_NO_ERROR;
}

int list_take(List* list, int index) {
    if (list_is_null(list)) {
        fprintf(stderr, "List is NULL.\n");
        return ERROR_NULL;
    }

    if (list_is_empty(list)) {
        fprintf(stderr, "List is empty, nothing to take.\n");
        return ERROR_EMPTY_ARRAY;
    }

    if (index > list->last) {
        fprintf(stderr, "List index is out of range, nothing to take.\n");
        return FAILURE_CODE;
    }

    return list->array[index];
}

int list_remove(List* list, int index) {
    if (list_is_null(list)) {
        fprintf(stderr, "List is NULL.\n");
        return ERROR_NULL;
    }

    if (list_is_empty(list)) {
        fprintf(stderr, "List is empty, nothing to remove.\n");
        return ERROR_EMPTY_ARRAY;
    }

    if (index > list->last) {
        fprintf(stderr, "List index is out of range, nothing to remove.\n");
        return FAILURE_CODE;
    }

    list_transition(list, index, list->last--);

    return SUCCESS_NO_ERROR;
}

int list_sort(List* list) {
    if (list_is_null(list)) {
        fprintf(stderr, "List is NULL.\n");
        return ERROR_NULL;
    }

    if (list_is_empty(list)) {
        fprintf(stderr, "List is empty, nothing to remove.\n");
        return ERROR_EMPTY_ARRAY;
    }
    
    partition(list, 0, list->last);

    return SUCCESS_NO_ERROR;
}

int list_search(List* list, int value) {
    if (list_is_null(list)) {
        fprintf(stderr, "List is NULL.\n");
        return ERROR_NULL;
    }

    if (list_is_empty(list)) {
        fprintf(stderr, "List is empty, nothing to remove.\n");
        return ERROR_EMPTY_ARRAY;
    }
    
    int left = 0, right = list->last;
    while (left <= right) {
        if (list->array[left] == value) return left;
        else if (list->array[right] == value) return right;
        left++, right--;
    }

    fprintf(stderr, "Value is not on the list.\n");
    return FAILURE_CODE;
}

int list_binary_search(List* list, int value) {
    if (list_is_null(list)) {
        fprintf(stderr, "List is NULL.\n");
        return ERROR_NULL;
    }

    if (list_is_empty(list)) {
        fprintf(stderr, "List is empty, nothing to remove.\n");
        return ERROR_EMPTY_ARRAY;
    }
    
    int left = 0, right = list->last, mid;

    if (list->array[left] == value)
        return left;
    if (list->array[right] == value)
        return right;
    
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (list->array[mid] < value) {
            left = mid + 1;
        }
        else if ( list->array[mid] > value) {
            right = mid - 1;
        }
        else return mid;
    }

    fprintf(stderr, "Value is not on the list.\n");
    return FAILURE_CODE;
}

static int list_is_empty(List* list) {
    if (list_is_null(list)) {
        return ERROR_NULL;
    }

    return list->last == -1;
}

static int list_is_full(List* list) {
    if (list_is_null(list)) {
        return ERROR_NULL;
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
        list->array[i] = list->array[i + 1];
    }
}

static void swap(int* a, int* b) {
    if (*a != *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

static void partition(List* list, int left, int right) {
    if (left < right) {
        int pivot = right;

        int i = left - 1, j = left;

        for (; j < pivot; ++j) {
            if (list->array[j] <= list->array[pivot]) {
                swap(&list->array[++i], &list->array[j]);
            }
        }
        swap(&list->array[i + 1], &list->array[j]);

        partition(list, left, i);
        partition(list, i + 1, right);
    }
}