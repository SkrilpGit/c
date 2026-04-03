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
    /* iterate through nodes
       free each node
       reset head/tail/size
    */
    Node* temp;
    int size = list->size;
    for (int i = 0; i < size; i++){
        temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size -= 1;
    }
    list->tail = NULL;
}

void int_linked_list_destroy(IntLinkedList *list)
{
    /* clear list
       free list
    */
    int_linked_list_clear(list);
    free(list);
}

size_t int_linked_list_size(const IntLinkedList *list)
{
    if (list == NULL)
        return false;
    /* return size */
    return list->size;
}

bool int_linked_list_is_empty(const IntLinkedList *list)
{
    if (list == NULL)
        return false;
    /* return true if size == 0 */
    return (list->size == 0);
}

bool int_linked_list_push_front(IntLinkedList *list, int value)
{
    if (list == NULL)
        return false;
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
    if (list == NULL)
        return false;
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
    if (list == NULL)
        return false;
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
    if (list == NULL)
        return false;
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
    if (list == NULL)
        return false;
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
    if (list == NULL)
        return false;
    /*
     * 1 before index
     * assign the newNode's next to index
     * assign 1 before's next to newNode
     * increment size
     */
    // handle negative index
    if (index < 0)
        index = (list->size + index);
    // check index out of range
    if (index >= list->size+1)
        return false;
    else{
        Node* newNode = node_create(value);
        // inserting at the head
        if (index == 0){ 
            newNode->next = list->head;
            list->head = newNode;
            list->size++;
        }
        // inserting at the tail
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
    if (list == NULL)
        return false;
    /*
     * assign 1 before index's next to index next
     * free the index duder
     * decrement size
     */
    // handle negative index
    if (index < 0)
        index = (list->size + index);
    // check index out of range
    if (index >= list->size)
        return false;
    else {
        // removing at the head
        if (index == 0){
            Node* temp = list->head;
            list->head = list->head->next;
            *out_value = temp->value;
            free(temp);
            list->size--;
        // removing at the tail
        } else if (index == list->size-1) {
            Node* current = list->head;
            for (int i = 0; i < index-1; i++)
                current = current->next;
            current->next = NULL;
            *out_value = list->tail->value;
            free(list->tail);
            list->tail = current;
            list->size--;
        } else {
            // pointer for index and the one before
            Node* indexPtr = list->head;
            Node* previous;
            for (int i = 0; i < index; i++){
                previous = indexPtr;
                indexPtr = indexPtr->next;
            }
            // assigning the previous next to the one after the index
            previous->next = indexPtr->next;
            // assinging the out value and freeing the index
            *out_value = indexPtr->value;
            free(indexPtr);
            list->size--;
        }
    }

    return true;
}
