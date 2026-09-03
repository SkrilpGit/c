#include "int_hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void add_user_in(IntHashTable *table){

    size_t size = table->size;
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

    add_key_value(table, key, value);
    free(key);
}

int main() {
    IntHashTable *table = int_hash_table_create(16);
    
    add_key_value(table,"hi",42);

    add_user_in(table);

    display_table(table);
}

