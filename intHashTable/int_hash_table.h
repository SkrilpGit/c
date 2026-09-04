#ifndef INT_HASH_TABLE_H
#define INT_HASH_TABLE_H

#include <stddef.h> // size_t

typedef struct IntHashTable {
    int* data;
    size_t size;
}IntHashTable;

IntHashTable *int_hash_table_create(size_t size);

void table_insert(IntHashTable *table, char* key, int value);

int table_get(IntHashTable *table, char* key);

void display_table(IntHashTable *table);


#endif // INT_HASH_TABLE_H
