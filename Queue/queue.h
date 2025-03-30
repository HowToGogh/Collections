#pragma once

#define QUEUE_MAX_SIZE 256
#define FAILURE_CODE -1

typedef struct {
    int* array;
    size_t count;
    size_t front;
    size_t rear;
} Queue;

Queue* queue_create();
void queue_delete(Queue*);
void queue_enqueue(Queue*, int);
int queue_dequeue(Queue*);
int queue_next(Queue*);