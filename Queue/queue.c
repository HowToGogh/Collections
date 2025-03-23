#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static int queue_is_empty(Queue* queue);
static int queue_is_full(Queue* queue);
static int queue_is_null(Queue* queue);
static void queue_transition(Queue* queue);

Queue* queue_create() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    if (queue == NULL) {
        fprintf(stderr, "Memory for queue is not allocated.\n");
        return NULL;
    }

    queue->array = (int*)malloc(sizeof(int) * QUEUE_MAX_SIZE);

    if (queue->array == NULL) {
        fprintf(stderr, "Memory for queue array is not allocated.\n");
        free(queue);
        return NULL;
    }

    queue->count = 0;
    queue->front = 0;
    queue->rear = -1;

    return queue;
}

void queue_delete(Queue* queue) {
    free(queue->array);
    free(queue);
}

void queue_enqueue(Queue* queue, int value) {
    if (queue_is_null(queue)) {
        printf("Queue is NULL.\n");
        return;
    }

    if (queue_is_full(queue)) {
        printf("Queue is full! Front value replaced.\n");
        --queue->count;
        queue->front = (queue->front + 1) % QUEUE_MAX_SIZE;
    }

    ++queue->count;
    //queue->array[(queue->rear + 1) % QUEUE_MAX_SIZE] = value;
    queue->array[(queue->rear + 1) % QUEUE_MAX_SIZE] = value;
    ++queue->rear;
}

int queue_dequeue(Queue* queue) {
    if (queue_is_null(queue)) {
        printf("Queue is NULL.\n");
        return FAILURE_CODE;
    }
    
    if (queue_is_empty(queue)) {
        printf("Queue is empty. No value to dequeue.\n");
        return FAILURE_CODE;
    }

    int val = queue->array[queue->front];

    --queue->count;
    queue->front = (queue->front + 1) % QUEUE_MAX_SIZE;
    
    return val;

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

    return queue->array[queue->front];
}

static int queue_is_empty(Queue* queue) {
    if (queue_is_null(queue)) {
        return FAILURE_CODE;
    }

    return queue->count == 0;
}

static int queue_is_full(Queue* queue) {
    if (queue_is_null(queue)) {
        return FAILURE_CODE;
    }

    return queue->count >= 256;
}

static int queue_is_null(Queue* queue) {
    return (queue == NULL);
}