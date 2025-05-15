#pragma once
//  This parameter is responsible for the default size of the queue array.
//  The queue size cannot be changed during runtime.
//  You can use this parameter to change the amount of memory allocated for each structure object.
#define QUEUE_MAX_SIZE 512

/*
The structure contains:
- array: a pointer to a memory location allocated for queue values.
Memory is allocated by the queue_create() function (see the queue_create() documentation).
- count: the value indicating the number of items in the queue.
- front and rear: values indicating the first item in the queue and the last item in the queue (respectively).

IMPORTANT:

-It is not recommended to use the structure fields manually, it is better to use the appropriate functions.
Manual modification can lead to errors, data losses, or undefined results.
*/
typedef struct queue_t {
    int* array;
    int count;
    int front;
    int rear;
} Queue;

/*
    To be able to use the queue, first of all it must be created.
    If memory for queue wasn't allocated correctly (due to reasons beyond the control of the implementation),
    queue will remain undefined.

    IMPORTANT:

    - Using the structure before creation is not recommended.
    It's better to declare queue immediately.

    USAGE EXAMPLE:

    Queue* myQueue = queue_create();
*/
Queue* queue_create();
/*
    If the queue is no longer required, it should be deleted.
    The function frees up the memory allocated for the queue array and makes the fields of the structure undefined.

    IMPORTANT:

    - Using the structure after deletion is not recommended until it is recreated.

    USAGE EXAMPLE:

    queue_delete(myQueue);
*/
int queue_delete(Queue*);
/*
    The function adds the value to the end of the queue.

    IMPORTANT:

    - If there is not enough memory in the queue to add a value, the highest queue element
    (i.e. the first one) is replaced with a new queue element.
    In this queue implementation, new data has a higher priority than old data.
    - It is possible to add a value to an undefined queue (before using the queue_create() function),
    but the result will be undefined.

    USAGE EXAMPLE:

    queue_enqueue(myQueue, 42);
*/
int queue_enqueue(Queue*, int);
/*
    The function returns the first value of the queue and removes it from it.
    If the queue is empty, an FAILURE_CODE is returned (-1 by default) with the corresponding message.
    The function does not delete values from memory, but makes them "garbage".

    IMPORTANT:

    - Value dequeued from an undefined queue is undefined.

    USAGE EXAMPLE:

    int dequeued_value = queue_dequeue(myQueue);
*/
int queue_dequeue(Queue*);
/*
    The function returns the first value of the queue and not removes it from it.
    If the queue is empty, an FAILURE_CODE is returned (-1 by default) with the corresponding message.

    IMPORTANT:

    - Value taken from an undefined queue is undefined.

    USAGE EXAMPLE:

    int next_value = queue_next(myQueue);
*/
int queue_next(Queue*);