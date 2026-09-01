#include "int_hash_table.h"

#include <stdio.h>

// IntList *int_list_create(size_t initial_capacity)
// {
//     IntList* list = malloc(sizeof(IntList));
//     list->data = malloc(sizeof(int)*initial_capacity);
//     (*list).capacity = initial_capacity;
//     list->capacity = initial_capacity;
//     list->size = 0;
//
//     return list;
// }
IntHashTable *int_hash_table_create(size_t size){
    IntHashTable* table = malloc(sizeof(IntHashTable));
    table->data = malloc(sizeof(int64_t)*size);
    table->size = size;

    return table;
}

int hash(char* key, int key_size, int size) {
    int out = 0;

    for (int c = 0; c < key_size; c++){
        out += key[c];
    }

    // printf("%d index\n",out);

    return out % size;
}


void add_key_value(IntHashTable *table, int table_size, char* key,
        int key_size, int64_t value){
    int i = hash(key,key_size,table_size);
    table->data[i] = value;
}

void display_table(IntHashTable *table, int size){
    for(int i = 0; i < size; i++){
        printf("%d: %d,\n",i,table->data[i]);
    }
}

