#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// int queue_is_null(Queue* queue);

void queue_create(Queue* queue) {
    // if (queue_is_null(queue)) {
    //     return;
    // }
    queue->array = (int*)malloc(QUEUE_MAX_SIZE * sizeof(int));
    if (queue->array == NULL) {
        fprintf(stderr, "Memory allocation for queue is failed");
        return;
    }
    queue->next = -1;
}

// void queue_delete(Queue* queue) {
//     // if ()
// }