#include <stdio.h>
#include <stdlib.h>
#include "arena.h"
#include "../errors.h"

Arena* arena_create(size_t capacity) {
    Arena* arena = (Arena*)malloc(sizeof(Arena));

    if (arena == NULL) {
        fprintf(stderr, "Memory for arena pointer is not allocated.\n");
        return NULL;
    }

    arena->capacity = capacity;

    arena->array = malloc(arena->capacity);

    if (arena->array == NULL) {
        fprintf(stderr, "Memory for arena array is not allocated.\n");
        free(arena);
        return NULL;
    }

    arena->free_pos = (char*)arena->array;

    return arena;
}

int arena_delete(Arena* arena) {
    arena->capacity = 0;
    free(arena->array);
    free(arena);
    return SUCCESS_NO_ERROR;
}

void* arena_alloc(Arena* arena, size_t obj_size) {
    if (arena_free_space(arena) < obj_size) {
        fprintf(stderr, "Not enough space to allocate memory for new pointer.\n%lld bytes of space is free.\n", arena_free_space(arena));
        return NULL;
    }
    
    void* ptr_to_return = (void*)arena->free_pos;
    arena->free_pos += obj_size;

    return ptr_to_return;
}

size_t arena_free_space(Arena* arena) {
    return arena->capacity - ((char*)arena->free_pos - (char*)arena->array);
}