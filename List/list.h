#pragma once
//  This parameter is responsible for the default size of the list array, however,
//  the list size can change during runtime regardless of the macro value.
#define LIST_DEFAULT_SIZE 64

enum error {
    SUCCESS_NO_ERROR     =    0,
    ERROR_MALLOC_FAILURE = -101,
    ERROR_NULL           = -102,
    ERROR_EMPTY_ARRAY    = -103,
    ERROR_FULL_ARRAY     = -104,
    FAILURE_CODE = -199
};

/*
The structure contains:
- array: a pointer to a memory location allocated for list values.
Memory is allocated by the list_create() function (see the list_create() documentation).
- last: the value indicating the index of the last element of the list.
LIST- size: the value indicating the actual size of the array (by default, size LIST_DEFAULT_SIZE)

IMPORTANT:

-It is not recommended to use the structure fields manually, it is better to use the appropriate functions.
Manual modification can lead to errors, data losses, or undefined results.
*/
typedef struct list_t {
    int* array;
    int last;
    int size;
} List;

/*
    To be able to use the list, first of all it must be created.
    If memory for list wasn't allocated correctly (due to reasons beyond the control of the implementation),
    list will remain undefined.

    IMPORTANT:

    - Using the structure before creation is not recommended.
    It's better to declare list immediately.

    USAGE EXAMPLE:

     List* myList = list_create();
*/
List* list_create();
/*
    If the list is no longer required, it should be deleted.
    The function frees up the memory allocated for the list array and makes the fields of the structure undefined.

    IMPORTANT:

    - Using the structure after deletion is not recommended until it is recreated.

    USAGE EXAMPLE:

    list_delete(myStack);
*/
int list_delete(List*);
/*
    The function adds a value to the list.

    IMPORTANT:

    - If there is not enough memory in the list to add a value, the list memory is expanded (doubled).
    - It is possible to add a value to an undefined list (before using the list_create() function),
    but the result will be undefined.

    USAGE EXAMPLE:

    list_add(myList, 42);
*/
int list_add(List*, int);
/*
    The function takes value from the list.
    If the list is empty, an FAILURE_CODE is returned (-1 by default) with the corresponding message.

    IMPORTANT:

    - If the memory for the array has been expanded during the process of adding values to the stack,
    removing values does not free up unused memory.
    - If index is bigger than list array size - an FAILURE_CODE is returned (-1 by default) with the corresponding message.

    USAGE EXAMPLE:

    list_take(myStack, 42);
*/
int list_take(List*, int);
/*
    The function removes value from the list.
    If the list is empty, an FAILURE_CODE is returned (-1 by default) with the corresponding message.

    IMPORTANT:

    - If the memory for the array has been expanded during the process of adding values to the stack,
    removing values does not free up unused memory.
    - If index is bigger than list array size - an error message occured.

    USAGE EXAMPLE:

    list_remove(myStack, 42);
*/
int list_remove(List*, int);
/*
    Function searches for the value in the list, and returns its index.
    The search algorithm is similar to linear search, but in some cases it will be slightly faster.

    IMPORTANT:

    - If the value is not on the list, the FAILURE_CODE returned
    (-1 by default, so it cannot be taken as the result of a function.)

    USAGE EXAMPLE:

    int value_index = list_search(myList, 42);
*/
int list_search(List*, int);
/*
    Function searches for the value in the list, and returns its index.
    The function uses a binary search algorithm, which allows you to search for values
    faster than the linear search algorithm does.

    IMPORTANT:

    - It is very important that the list is sorted, otherwise the returned value will be incorrect.
    - If the value is not on the list, the FAILURE_CODE returned
    (-1 by default, so it cannot be taken as the result of a function.)

    USAGE EXAMPLE:

    list_sort(myList);
    int value_index = list_binary_search(myList, 42);
*/
int list_binary_search(List*, int);
/*
    The function sorts the values in the list in ascending order.
    A quick sort algorithm is used.

    USAGE EXAMPLE:

    list_sort(myList);
*/
int list_sort(List*);