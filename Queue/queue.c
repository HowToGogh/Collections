// Queue functionality;
// If there no error - there won't be any messages;
// If there is an error - there will be a couple of messages
// and maybe program will stop completely (idk how to fix it I'm stupid);

// Before using any of this create a Queue object:
/* 
Queue myQueue;
queue_create(&myQueue);
*/
// After this you can use others;

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Functions that you can't use in "main" program but used here
int queue_is_empty(Queue* queue);
int queue_is_full(Queue* queue);
int queue_is_null(Queue* queue);
void queue_transition(Queue* queue);

// Before this function Queue object is having undefined values;
// This function will allocate memory for stack and define its attributes;
void queue_create(Queue* queue) {
    if (queue_is_null(queue)) {
        return;
    }
    queue->array = (int*)malloc(QUEUE_MAX_SIZE * sizeof(int));
    if (queue->array == NULL) {
        fprintf(stderr, "Memory allocation for queue is failed");
        return;
    }
    queue->last = -1;
}

// After this function there will not be any memory for stack
// but Stack.top is still defined. Stack isn't destroyed completely;
// (!!!) I'm not sure this function is safe ((((( ;
void queue_delete(Queue* queue) {
    free(queue->array);
    queue->last = -1;
}

// Add item to the and of a queue;
void queue_enqueue(Queue* queue, int value) {
    if (queue_is_null(queue)) {
        return;
    }
    
    if (queue_is_full(queue)) {
        fprintf(stderr, "Queue is full.\n");
        return;
    }

    queue->array[++queue->last] = value;
}

// Get first item of a queue, item is returned and not in queue anymore;
int queue_dequeue(Queue* queue) {
    if (queue_is_null(queue)) {
        fprintf(stderr, "Queue is null.\n");
        return FAILURE_CODE;
    }
    
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Queue is empty.\n");
        return FAILURE_CODE;
    }

    int value = queue->array[0];
    queue_transition(queue);
    --queue->last;
    return value;
}

// Get first item of a queue, item is returned and still in queue;
int queue_next(Queue* queue) {
    if (queue_is_null(queue)) {
        fprintf(stderr, "Queue is null.\n");
        return FAILURE_CODE;
    }
    
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Queue is empty.\n");
        return FAILURE_CODE;
    }

    return queue->array[0];
}

int queue_is_empty(Queue* queue) {
    if (queue_is_null(queue)) {
        fprintf(stderr, "Queue is null.\n");
        return FAILURE_CODE;
    }

    return queue->last == -1;
}

int queue_is_full(Queue* queue) {
    if (queue_is_null(queue)) {
        fprintf(stderr, "Queue is null.\n");
        return FAILURE_CODE;
    }

    return queue->last == QUEUE_MAX_SIZE - 1;
}

int queue_is_null(Queue* queue) {
    if (queue == NULL) {
        fprintf(stderr, "Stack pointer is NULL.\n");
        return 1;
    }
    return 0;
}

void queue_transition(Queue* queue) {
    if (queue_is_null(queue)) {
        return;
    }

    if (queue_is_empty(queue)) {
        return;
    }

    for (int i = 0; i != queue->last; ++i) {
        queue->array[i] = queue->array[i + 1];
    }
}