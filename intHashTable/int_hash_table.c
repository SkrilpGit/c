#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(char* key, int key_size, int size) {
    int out = 0;

    for (int c = 0; c < key_size; c++){
        out += key[c];
    }

    printf("%d index\n",out);

    return out % size;
}

void flush_in(){
    int c;

    while((c = getchar()) != '\n');
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

    if (i > max_size-1)
        flush_in();

    printf("temp = %s, size = %d\n",temp, i);
    char* in = malloc((i)*sizeof(char));
    memcpy(in,temp,i*sizeof(char));
    return in;
}

int get_int(char* word, int size){
    float num = 0;
    float exp = 0.1;
    for(int i = 0; i < size; i++){
        num += (word[i] - 48)/(10*exp);
        exp *= 10;
    }
    printf("get_int (%s) = %f\n",word,num);
    return (int)(num*exp);
}

int main() {
    int table[16];

    char* key = "hi";
    int value = 42;

    int i = hash(key,2,16);

    table[i] = value;

    printf("input the key: ");
    int key_size = 0;
    key = input(2, &key_size);
    printf("you have input: %s\n",key);

    printf("input the value: ");
    int value_size = 0;
    char* svalue = input(32, &value_size);
    printf("svalue = %s\n",svalue);
    value = get_int(svalue,value_size);
    printf("value = %d\n", value);
    free(svalue);

}
