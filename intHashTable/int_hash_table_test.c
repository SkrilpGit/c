#include "int_hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flush_in(){
    int c;

    while((c = getchar()) != '\n' && c != EOF);
}

char* input(int max_size){
    char temp[max_size];
    int size = 0;
    int c = getchar();
    while(c != '\n'){
        if (size > max_size-1)
            break;
        temp[size] = c;
        c = getchar();
        size++;
    }

    if (size > max_size-1 && c != '\n')
        flush_in();

    char* in = malloc((size)*sizeof(char));
    memcpy(in,temp,(size)*sizeof(char));

    return in;
}

int get_int(char* word){
    int num = 0;
    char* c = word;
    while (*c != '\0'){
        num *= 10;
        num += *c - 48;
        c += 1;
    };
    return num;
}

void add_user_in(IntHashTable *table){

    size_t size = table->size;
    char* key;
    int value;

    printf("input the key: ");
    key = input(32); // need free

    printf("input the value: ");
    char* svalue = input(sizeof(int));
    // value = -1;
    value = get_int(svalue);
    free(svalue);

    insert(table, key, value);
    free(key);
}

int main() {
    IntHashTable *table = int_hash_table_create(16);
    
    insert(table,"hi",42);

    add_user_in(table);

    display_table(table);
}

