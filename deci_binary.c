#include <stdio.h>

int minPartitions(char* n){
    int i = 0;
    int ans = 0;

    while(n[i] != 0){
        if (ans == 57)
            break;
        if (n[i] > ans)
            ans = n[i];
        i++;
    }
    ans -= 48;
    return ans;
}

int main(){
    minPartitions("A");
    if (minPartitions("32") == 3)
        printf("Test 1 passed\n");
    if (minPartitions("82734") == 8)
        printf("Test 2 passed\n");
    if (minPartitions("27346209830709182346") == 9)
        printf("Test 3 passed\n");
}
