#include "int_hash_table.h"

#include <stdio.h>

IntHashTable *int_hash_table_create(size_t size){
    IntHashTable* table = malloc(sizeof(IntHashTable));
    table->data = malloc(sizeof(int64_t)*size);
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


void add_key_value(IntHashTable *table, char* key, int64_t value){
    int i = hash(key,table->size);
    table->data[i] = value;
}

void display_table(IntHashTable *table){
    size_t size = table->size;
    for(int i = 0; i < size; i++){
        printf("%d: %d,\n",i,table->data[i]);
    }
}

