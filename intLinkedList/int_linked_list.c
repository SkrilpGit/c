#include "int_linked_list.h"

#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

struct IntLinkedList {
    Node *head;
    Node *tail;
    size_t size;
};

static Node *node_create(int value)
{
    (void)value;

    /* TODO: allocate node
       TODO: initialize value and next pointer
    */

    return NULL;
}

IntLinkedList *int_linked_list_create(void)
{
    /* TODO: allocate list
       TODO: initialize head, tail, size
    */

    return NULL;
}

void int_linked_list_clear(IntLinkedList *list)
{
    (void)list;

    /* TODO: iterate through nodes
       TODO: free each node
       TODO: reset head/tail/size
    */
}

void int_linked_list_destroy(IntLinkedList *list)
{
    (void)list;

    /* TODO: clear list
       TODO: free list
    */
}

size_t int_linked_list_size(const IntLinkedList *list)
{
    (void)list;

    /* TODO: return size */
    return 0;
}

bool int_linked_list_is_empty(const IntLinkedList *list)
{
    (void)list;

    /* TODO: return true if size == 0 */
    return false;
}

bool int_linked_list_push_front(IntLinkedList *list, int value)
{
    (void)list;
    (void)value;

    /* TODO: create node
       TODO: update head
       TODO: update tail if list was empty
       TODO: increment size
    */

    return false;
}

bool int_linked_list_push_back(IntLinkedList *list, int value)
{
    (void)list;
    (void)value;

    /* TODO: create node
       TODO: attach after tail
       TODO: update head if empty
       TODO: update tail
       TODO: increment size
    */

    return false;
}

bool int_linked_list_pop_front(IntLinkedList *list, int *out_value)
{
    (void)list;
    (void)out_value;

    /* TODO: check empty
       TODO: store value
       TODO: move head
       TODO: update tail if list becomes empty
       TODO: free node
       TODO: decrement size
    */

    return false;
}

bool int_linked_list_pop_back(IntLinkedList *list, int *out_value)
{
    (void)list;
    (void)out_value;

    /* TODO: handle empty
       TODO: find last node
       TODO: track previous node
       TODO: update tail
       TODO: free node
       TODO: decrement size
    */

    return false;
}

bool int_linked_list_get(const IntLinkedList *list, size_t index, int *out_value)
{
    (void)list;
    (void)index;
    (void)out_value;

    /* TODO: bounds check
       TODO: walk list to index
       TODO: assign value
    */

    return false;
}

bool int_linked_list_insert(IntLinkedList *list, size_t index, int value)
{
    (void)list;
    (void)index;
    (void)value;

    /* TODO: validate index
       TODO: handle front/back cases
       TODO: find previous node
       TODO: insert new node
       TODO: increment size
    */

    return false;
}

bool int_linked_list_remove_at(IntLinkedList *list, size_t index, int *out_value)
{
    (void)list;
    (void)index;
    (void)out_value;

    /* TODO: validate index
       TODO: handle front case
       TODO: find previous node
       TODO: unlink node
       TODO: update tail if needed
       TODO: free node
       TODO: decrement size
    */

    return false;
}
