#include <stdio.h>
#include "../intList/int_list.h"

int main() {
    int arr[] = {1,2,3,4};
    struct IntList *list = int_list_from(arr,4);

    int value;

    for (int i = 0; i < list->size; i++) {
        if (list->data[i] % 2 == 1){
            int_list_remove_at(list,i,&value);
        }
    }

    printf("size of list == %ld\nlist contains: [",list->size);
    for (int i = 0; i < list->size; i++) {
        int out; 
        int_list_get(list,i,&out);
        if (i == 0)
            printf("%d",out);
        else
            printf(", %d",out);
    }
    printf("]\n");

    return 0;
}

