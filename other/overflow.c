#include<stdio.h>
#include<limits.h>
int main()
{
    int a = 1000000000000;
    int b = 1000000000000;
    int sum = a + b;
    if(a > INT_MAX - b)
        printf("overflow!!!\n");
    return 0;
}
