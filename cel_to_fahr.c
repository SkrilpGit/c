#include <stdio.h>

int main(){
    float celsius, fahr;
    int lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;
    
    celsius = lower;
    while(celsius < upper){
        /* C = (5/9)(F-32)*/
        fahr = 9 * celsius / 5 + 32;
        printf("%3.0f\t%6.1f\n",celsius,fahr);
        celsius += step; 
    }
    return 0;
}