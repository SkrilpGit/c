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
    // check if empty
    if (list->size == 0)
        return false;
    // if list is 1 element, pop value and free Node
    else if (list->size == 1){
        *out_value = list->tail->value;
        free(list->tail);
        list->head = NULL;
        list->size -= 1;
        return true;
    }
    // find the second last node
    Node* secondLast = list->head;
    //start at 1 to line up with size, -1 for second last index 
    for (int i = 1; i < list->size-1; i++)
        secondLast = secondLast->next;
    //printf("%d, %d \n", secondLast->value, list->tail->value);
    //pop value
    *out_value = list->tail->value;
    //assign new tail
    list->tail = secondLast;
    //free old tail
    free(list->tail->next);
    //decrement size
    list->size -= 1;

    return true;
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
    /*
     * find index and 1 before index
     * assign the newNode's next to index
     * assign 1 before's next to newNode
     * increment size
     */
    if (index >= list->size+1)
        return false;
    else{
        Node* newNode = node_create(value);
        if (index == 0){ 
            newNode->next = list->head;
            list->head = newNode;
            list->size++;
        }
        else if (index == list->size-1){
            list->tail->next = newNode;
            list->tail = newNode;
            list->size++;
        }
        else {
            // find one before index
            Node* current = list->head;
            for (int i = 0; i < index-1; i++)
                current = current->next;
            // insert the new node
            newNode->next = current->next;
            current->next = newNode;
            list->size++;
        }
    }

    return true;
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
