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
        if (size >= max_size)
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

int main() {
    IntHashTable *table = int_hash_table_create(16);
    
    table_insert(table,"hi",42);

    char* key;
    char* svalue;
    int value;

    printf("input the key: ");
    key = input(32); //TODO free

    printf("input the value: ");
    svalue = input(sizeof(int)); //TODO free
    value = get_int(svalue);

    table_insert(table,key,value);

    printf("get value from key: ");
    free(key);
    key = input(32); //TODO free
    value = table_get(table,key);
    printf("Your value is %d\n",value);
    display_table(table);

    free(key);
    free(svalue);
}

