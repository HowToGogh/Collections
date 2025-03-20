#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int queue_is_empty(Queue* queue);
int queue_is_full(Queue* queue);
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

void queue_delete(Queue* queue) {
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