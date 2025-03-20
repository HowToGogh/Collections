#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int queue_is_null(Queue* queue);
void queue_transition(Queue* queue);

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

void stack_delete(Queue* queue) {
    free(queue->array);
    queue->last = -1;
}

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

int queue_dequeue(Queue* queue) {
    if (queue_is_null(queue)) {
        return;
    }
    
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Queue is empty.\n");
        return;
    }

    int value = queue->array[queue->last];

    queue_transition(queue);

    --queue->last;

    return value;
}

// You can not use this function in main, it used here only;
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