#pragma once
#include <stdio.h>

typedef struct {
    void* array;
    char* free_pos;
    size_t capacity;
} Arena;

Arena* arena_create(size_t);
int arena_delete(Arena*);
int arena_reset(Arena*);
void* arena_alloc(Arena*, size_t);
size_t arena_free_space(Arena*);