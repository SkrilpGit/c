#include "int_linked_list.h"
#include <stdio.h>
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
    // Allocate Node
    Node* node = malloc(sizeof(Node));
    // Initialize value and next*
    node->next = malloc(sizeof(Node));
    node->value = value;

    return node;
}

IntLinkedList *int_linked_list_create(void)
{
    // Allocate List
    IntLinkedList* list = malloc(sizeof(IntLinkedList)); 
    // initialize head, tail, and size
    list->head = malloc(sizeof(Node));
    list->tail = malloc(sizeof(Node));
    list->size = 0;

    return list;
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
    /* return size */
    return list->size;
}

bool int_linked_list_is_empty(const IntLinkedList *list)
{
    /* return true if size == 0 */
    return (list->size == 0);
}

bool int_linked_list_push_front(IntLinkedList *list, int value)
{
    // Create node
    Node* newNode = node_create(value);
    newNode->next = list->head;
    // Update Head
    list->head = newNode;
    // Update tail if list is empty
    if (list->size == 0)
        list->tail = newNode;
    // increment size
    list->size += 1;
    
    return true;
}

bool int_linked_list_push_back(IntLinkedList *list, int value)
{
    // create Node
    Node* newNode = node_create(value);
    // if list empty update head
    if (list->size == 0)
        list->head = newNode;
    // otherwise link the old tail
    else
        list->tail->next = newNode;
    // set new tail :)
    list->tail = newNode;
    list->size += 1;

    return true;
}

bool int_linked_list_pop_front(IntLinkedList *list, int *out_value)
{
    // check empty
    if (list->size == 0)
        return false;
    // store value of head
    *out_value = list->head->value;
    // if list won't be empty assign new head and free old
    if (list->size > 1){
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
    // if list will be empty free head and tail
    } else {
        free(list->head);
        list->tail = NULL;
    }
    // decrement size
    list->size -= 1;

    return true;
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
    //printf("%lu %lu\n",index,list->size);
    //bounds check
    if (index > list->size-1 || list->size == 0)
        return false;
    else if (index < 0){
        index = list->size - (index * -1);
        if (index < 0)
            return false;
    }
    //iterate through the list
    Node* current = list->head;
    for (int i = 0; i < index; i++)
        current = current->next;
    //assign value
    *out_value = current->value;

    return true;
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
