#include "int_hash_table.h"


int main() {
    IntHashTable *table = int_hash_table_create(16);
    
    add_key_value(table,16,"hi",2,42);

    add_user_in(table,16);

    display_table(table,16);
}

