#include "int_list.h"

int main() {
    struct IntList *list = int_list_create(4);
    int_list_push_back(list,1);
    int_list_push_back(list,2);
    int_list_push_back(list,3);
    int_list_push_back(list,4);

    int len = 4;

    for (int i = 0; i < list->size; i++) {
        if (list->data[i] % 2 == 1){
            int_list_remove_at(list,i);
            len -= 1;
        }
    }
    printList(list);

}

