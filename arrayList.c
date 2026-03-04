// beep boop append depend
#include <stdio.h>

int* append(int* arr, int n){
    int size = (sizeof(*arr)/sizeof(int)) + 1;
    int newArr[size];
    for (int i = 0; i < size; i++)
        newArr[i] = arr[i];
    newArr[size] = n;

    return newArr;
}

int main() {
    printf("Hello World\n");

    return 1;
}
