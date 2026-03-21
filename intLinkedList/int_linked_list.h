#ifndef INT_LINKED_LIST_H
#define INT_LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct IntLinkedList IntLinkedList;

/* Creation / Destruction */

IntLinkedList *int_linked_list_create(void);
void int_linked_list_destroy(IntLinkedList *list);

/* Capacity */

size_t int_linked_list_size(const IntLinkedList *list);
bool   int_linked_list_is_empty(const IntLinkedList *list);

/* Element Access */

bool int_linked_list_get(const IntLinkedList *list, size_t index, int *out_value);

/* Modification */

bool int_linked_list_push_front(IntLinkedList *list, int value);
bool int_linked_list_push_back(IntLinkedList *list, int value);

bool int_linked_list_pop_front(IntLinkedList *list, int *out_value);
bool int_linked_list_pop_back(IntLinkedList *list, int *out_value);

bool int_linked_list_insert(IntLinkedList *list, size_t index, int value);
bool int_linked_list_remove_at(IntLinkedList *list, size_t index, int *out_value);

/* Utilities */

void int_linked_list_clear(IntLinkedList *list);

#ifdef __cplusplus
}
#endif

#endif
