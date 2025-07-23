#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stdlib.h>
#include "ustr.h"

typedef struct List {
    int32_t size;         // Number of elements in the list
    int32_t capacity;     // Maximum number of elements the list can hold
    struct UStr* data;    // Pointer to the array holding the list elements
} List;

List new_list(int32_t initial_capacity);
List new_list_from_array(struct UStr* array, int32_t size);

// To implement
UStr join(List* list, UStr separator);
int8_t insert(List* list, UStr s, int32_t index);
int8_t listRemoveAt(List* list, int32_t index);
List split(UStr s, UStr separator);

//helper
void listAppend(List* list, UStr element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        UStr* newItems = realloc(list->data, list->capacity * sizeof(UStr));
        if (newItems == NULL) {
            return;
        }
        list->data = newItems;
    }
    list->data[list->size++] = element;
}

UStr substr(UStr s, int32_t start, int32_t end) {
    UStr result;
    result.bytes = end - start;

    result.contents = malloc(result.bytes);
    if (!result.contents) {
        result.bytes = 0;
        return result;
    }

    for (int32_t i = 0; i < result.bytes; i++) {
        result.contents[i] = s.contents[start + i];
    }

    return result;
}

#endif
