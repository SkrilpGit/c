#include "int_hash_table.h"

#include <stdio.h>
#include <stdlib.h>

IntHashTable *int_hash_table_create(size_t size){
    IntHashTable* table = malloc(sizeof(IntHashTable));
    table->data = malloc(sizeof(int)*size);
    table->size = size;

    return table;
}

int hash(char* key, int size) {
    int out = 0;
    char* c = key;

    while (*c != '\0'){
        out += *c;
        c += 1;
    }

    // printf("%d index\n",out);

    return out % size;
}


void insert(IntHashTable *table, char* key, int value){
    int i = hash(key,table->size);
    table->data[i] = value;
}

int get(IntHashTable *table, char* key){
    return table->data[hash(key,table->size)];
}

void display_table(IntHashTable *table){
    size_t size = table->size;
    for(int i = 0; i < size; i++){
        printf("%d: %d,\n",i,table->data[i]);
    }
}

