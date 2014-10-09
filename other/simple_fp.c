#include<stdio.h>

int print_number(int n)
{
    printf("%d\n",n);
    return 0;
}

void add_number(float a, float b)
{
    printf("%f\n",a+b);
}

void main(int argc, char** argv)
{
    int (*fp)(int);
    fp = &print_number;
    void (*fp2)(float,float);
    fp2 = &add_number;
    fp(2);
    fp2(3,4);
}
