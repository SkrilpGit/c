#include "int_hash_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void flush_in(){
    int c;

    while((c = getchar()) != '\n' && c != EOF);
}

char* input(int max_size, int* size){
    char temp[max_size];
    int i = 0;
    int c = getchar();
    while(c != '\n'){
        if (i > max_size-1)
            break;
        temp[i] = c;
        c = getchar();
        i++;
        // printf("it %d\n",i);
    }
    *size = i;
    // printf("temp = %s, size = %d\n",temp, i);

    if (i > max_size-1 && c != '\n')
        flush_in();

    char* in = malloc((i)*sizeof(char));
    memcpy(in,temp,i*sizeof(char));
    return in;
}

int get_int(char* word, int size){
    int nums[size];
    int exp = 1;
    for(int i = 0; i < size; i++){
        nums[i] = (word[i] - 48);
        exp *= 10;
    }

    int num = 0;

    for(int i = 0;i < size; i++){
        num += nums[i]*exp/10; //exp is too large :P
        exp /= 10;
    }
    // printf("get_int (%s) = %d\n",word,num);
    return (int)(num*exp);
}

void add_user_in(IntHashTable *table, int size){

    char* key;
    int64_t value;

    printf("input the key: ");
    int key_size = 0;
    key = input(32, &key_size); // need free

    printf("input the value: ");
    int value_size = 0;
    char* svalue = input(sizeof(int64_t), &value_size);
    value = get_int(svalue,value_size);
    free(svalue);

    // printf("value = %ld\n", value);

    int i = hash(key,key_size,size);

    table->data[i] = value;
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

