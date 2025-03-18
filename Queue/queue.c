#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// int queue_is_null(Queue* queue);

void queue_create(Queue* queue) {
    if (queue_is_null(queue)) {
        return;
    }
    queue->array = (int*)malloc(QUEUE_MAX_SIZE * sizeof(int));
    if (queue->array == NULL) {
        fprintf(stderr, "Memory allocation for queue is failed");
        return;
    }
    queue->next = 0;
}

void stack_delete(Queue* queue) {
    free(queue->array);
    queue->next = -1;
}

// You can not use this function in main, it used here only;
int stack_is_null(Queue* queue) {
    if (queue == NULL) {
        fprintf(stderr, "Stack pointer is NULL.\n");
        return 1;
    }
    return 0;
}