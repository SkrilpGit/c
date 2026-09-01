#include <stdio.h>

int main(){
    int a = 5;
    int* p = &a;
    int* q = p;

    printf("a=%d p=%p q=%p\n&a=%p *p=%d *q=%d\n",
            a,p,q,&a,*p,*q);
    *q += 5;
    printf("*q + 5\n");
    
    printf("a=%d p=%p q=%p\n&a=%p *p=%d *q=%d\n",
            a,p,q,&a,*p,*q);
}
