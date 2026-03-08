#include <stdio.h>

int main(){
    int out[32];
    int i = 0;
    int c;
    c = getchar();
    while(c != '\n'){
        //putchar(c);
        out[i] = c;
        c = getchar();
        i++;
    }
    printf("\n buh: ");
    for (int j =0; j <= i; j++)
        printf("%c",out[j]);
    return 1;
}
