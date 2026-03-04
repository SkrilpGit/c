#ifndef INT_LIST_H
#define INT_LIST_H

#include <stddef.h>  // for size_t
#include <stdbool.h> // for bool

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Opaque type
 */
typedef struct IntList IntList;

/*
 * Creation / Destruction
 */

/* Create a new list with an initial capacity */
IntList *int_list_create(size_t initial_capacity);

/* Free all memory associated with the list */
void int_list_destroy(IntList *list);

/*
 * Capacity
 */

size_t int_list_size(const IntList *list);
size_t int_list_capacity(const IntList *list);
bool   int_list_is_empty(const IntList *list);

/*
 * Element Access
 */

/* Returns true on success, false if index is out of bounds */
bool int_list_get(const IntList *list, size_t index, int *out_value);

/* Returns true on success, false if index is out of bounds */
bool int_list_set(IntList *list, size_t index, int value);

/*
 * Modification
 */

/* Append to the end (auto-resizes if needed) */
bool int_list_push_back(IntList *list, int value);

/* Remove last element (returns false if empty) */
bool int_list_pop_back(IntList *list, int *out_value);

/* Insert at index (shifts elements right) */
bool int_list_insert(IntList *list, size_t index, int value);

/* Remove at index (shifts elements left) */
bool int_list_remove_at(IntList *list, size_t index, int *out_value);

/*
 * Utilities
 */

/* Remove all elements but keep allocated memory */
void int_list_clear(IntList *list);

#ifdef __cplusplus
}
#endif

#endif /* INT_LIST_H */
