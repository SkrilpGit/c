#include "int_list.h"

#include <stdlib.h>
#include <string.h>

struct IntList {
    int *data;
    size_t size;
    size_t capacity;
};

/* ---------- Internal Helper ---------- */

static bool int_list_resize(IntList *list, size_t new_capacity)
{
    (void)list;
    (void)new_capacity;

    /* TODO: Implement resize logic */
    return false;
}

/* ---------- Creation / Destruction ---------- */

IntList *int_list_create(size_t initial_capacity)
{

    /* TODO: Allocate list struct
       TODO: Allocate backing array
       TODO: Initialize size and capacity
    */
    IntList* reservoir = malloc(sizeof(IntList));
    reservoir->data = malloc(sizeof(int)*initial_capacity);
    (*reservoir).capacity = initial_capacity;
    reservoir->capacity = initial_capacity;
    
    return reservoir;
}

void int_list_destroy(IntList *list)
{
    (void)list;

    /* TODO: Free backing array
       TODO: Free list struct
    */
}

/* ---------- Capacity ---------- */

size_t int_list_size(const IntList *list)
{
    (void)list;

    /* TODO: Return current size */
    return 0;
}

size_t int_list_capacity(const IntList *list)
{
    (void)list;

    /* TODO: Return capacity */
    return 0;
}

bool int_list_is_empty(const IntList *list)
{
    (void)list;

    /* TODO: Return true if size == 0 */
    return false;
}

/* ---------- Element Access ---------- */

bool int_list_get(const IntList *list, size_t index, int *out_value)
{
    (void)list;
    (void)index;
    (void)out_value;

    /* TODO: Bounds check
       TODO: Assign to out_value
    */

    return false;
}

bool int_list_set(IntList *list, size_t index, int value)
{
    (void)list;
    (void)index;
    (void)value;

    /* TODO: Bounds check
       TODO: Assign value
    */

    return false;
}

/* ---------- Modification ---------- */

bool int_list_push_back(IntList *list, int value)
{
    (void)list;
    (void)value;

    /* TODO: Resize if needed
       TODO: Append value
       TODO: Increment size
    */

    return false;
}

bool int_list_pop_back(IntList *list, int *out_value)
{
    (void)list;
    (void)out_value;

    /* TODO: Check if empty
       TODO: Decrement size
       TODO: Optionally write to out_value
    */

    return false;
}

bool int_list_insert(IntList *list, size_t index, int value)
{
    (void)list;
    (void)index;
    (void)value;

    /* TODO: Validate index
       TODO: Resize if needed
       TODO: Shift elements right (memmove)
       TODO: Insert value
       TODO: Increment size
    */

    return false;
}

bool int_list_remove_at(IntList *list, size_t index, int *out_value)
{
    (void)list;
    (void)index;
    (void)out_value;

    /* TODO: Validate index
       TODO: Optionally write removed value
       TODO: Shift elements left (memmove)
       TODO: Decrement size
    */

    return false;
}

void int_list_clear(IntList *list)
{
    (void)list;

    /* TODO: Set size to 0 */
}
