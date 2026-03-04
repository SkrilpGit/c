#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int countBits(int Item){
    int bitCount = 0;
    while (Item != 0){
        bitCount += Item % 2;
        Item = Item >> 1;
    }
    return bitCount;

}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    int* newArr = malloc(arrSize*sizeof(int));
    *returnSize = arrSize;
    for (int i = 0; i < arrSize; i++){
        newArr[i] = arr[i];
    }
    bool done = false;
    while(!done){
        done = true;
        for(int i = 0; i < (arrSize - 1); i++){
            int n = newArr[i];
            int iCount = countBits(newArr[i]);
            int iPlusCount = countBits(newArr[i+1]);
            if (iCount > iPlusCount){
               n = newArr[i+1];
               newArr[i+1] = newArr[i];
               done = false; 
            }
            else if (iCount == iPlusCount){
                if (newArr[i] > newArr[i+1]){
                    n = newArr[i+1];
                    newArr[i+1] = newArr[i];
                    done = false;
                }
            }
            newArr[i] = n;
        }  
    }

    return newArr;
}

int main(){
    // assign array [0,1,2,3,4,5,6,7,8]
    int arr[9];
    for(int i = 0; i < 9; i++)
        arr[i] = i;
    
    int returnSize;
    int* sorted = sortByBits(arr, 9, &returnSize);
    
    printf("[ %d",sorted[0]);
    for(int i = 1; i < returnSize; i++)
        printf(", %d ",sorted[i]);
    printf("]\n");
    
    free(sorted);

    return 1;
}
