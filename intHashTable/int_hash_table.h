#ifndef INT_HASH_TABLE_H
#define INT_HASH_TABLE_H

#include <stdlib.h> // int64_t

typedef struct IntHashTable {
    int* data;
    size_t size;
}IntHashTable;

IntHashTable *int_hash_table_create(size_t size);

void add_key_value(IntHashTable *table, int table_size, char* key,
        int key_size, int64_t value);

void add_user_in(IntHashTable *table, int size);

void display_table(IntHashTable *table, int size);


#endif // INT_HASH_TABLE_H
