#include "int_list.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct IntList {
    int *data;
    size_t size;
    size_t capacity;
};


/* ---------- Internal Helpers ---------- */

static bool int_list_resize(IntList *list, size_t new_capacity)
{
    list->data = realloc(list->data,new_capacity*sizeof(list->data[0]));
    list->capacity = new_capacity;
    return true;
}

void printList(IntList *list, size_t size){
    if (size == 0)
        return;
    printf("[ %d",list->data[0]);
    for (int i = 1; i < size; i++)
        printf(", %d", list->data[i]);
    printf(" ]\n"); 
}
/* ---------- Creation / Destruction ---------- */

IntList *int_list_create(size_t initial_capacity)
{
    IntList* list = malloc(sizeof(IntList));
    list->data = malloc(sizeof(int)*initial_capacity);
    (*list).capacity = initial_capacity;
    list->capacity = initial_capacity;
    list->size = 0;
    
    return list;
}

void int_list_destroy(IntList *list)
{ 
    free(list->data);
    free(list);
}

/* ---------- Capacity ---------- */

size_t int_list_size(const IntList *list)
{
    return list->size;
}

size_t int_list_capacity(const IntList *list)
{
    return list->capacity;
}

bool int_list_is_empty(const IntList *list)
{
 
    return list->size == 0;
}

/* ---------- Element Access ---------- */

bool int_list_get(const IntList *list, size_t index, int *out_value)
{
    if (index > list->size || list->size == 0)
        return false;

    *out_value = list->data[index];

    return true;
}

bool int_list_set(IntList *list, size_t index, int value)
{
    if (index > list->size || list->size == 0)
        return false;
    list->data[index] = value;

    return true;
}

/* ---------- Modification ---------- */

bool int_list_push_back(IntList *list, int value)
{
    if (list->size == list->capacity)
        int_list_resize(list,list->capacity + 4);

    list->data[list->size] = value;
    list->size += 1;

    return true;
}

bool int_list_pop_back(IntList *list, int *out_value)
{
    if (list->size == 0)
        return false;

    printf("size = %lu\n", list->size);
    
    //printList(list, list->size);

    *out_value = list->data[list->size-1];
    list->size -= 1;

    return true;
}

bool int_list_insert(IntList *list, size_t index, int value)
{ 
    if (index > list->size)
        return false;
    
    if (list->size == list->capacity)
        int_list_resize(list,list->capacity + 4);
    
    // offset by index, then convert to size in bytes
    int size = (list->size - index) * sizeof(list->data[0]);
    memmove(&list->data[index+1], list->data + index, size);
     
    list->data[index] = value; 
    
    list->size += 1;
     
    return true;
}

bool int_list_remove_at(IntList *list, size_t index, int *out_value)
{
    if (index > list->size || list->size == 0)
        return false;
    *out_value = list->data[index];

    //printList(list, list->size);
   
    int size = (list->size - index) * sizeof(list->data[0]);
    memmove(list->data + index, list->data + index + 1, size);
    
    //printList(list, list->size);
 
    list->size -= 1;

    return true;
}

void int_list_clear(IntList *list)
{
    list->size = 0;
}
