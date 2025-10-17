#include <stdio.h>

int main(void){

    int a,b,c;
    double da;
    char ch;

    a = 3; b = a; c = a+20;
    da = 3.5;
    ch = 'A';

    printf("변수 a: %d\n",a);
    printf("변수 b: %d\n",b);
    printf("변수 c: %d\n",c);
    printf("변수 da: %lf\n",da);
    printf("변수 ch: %c\n",ch);

}