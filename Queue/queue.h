#pragma once

#define QUEUE_MAX_SIZE 128
#define FAILURE_CODE -1

typedef struct {
    int* array;
    int last;
} Queue;

void queue_create(Queue* queue);
void queue_delete(Queue* queue);
void queue_enqueue(Queue* queue, int value);
int queue_dequeue(Queue* queue);
int queue_next(Queue* queue);