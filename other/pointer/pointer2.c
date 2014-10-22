#include<stdio.h>

int main()
{
    int a[5] = {1,2,3,4,5};
    int *p = (int *)(a+1); // *p = 2
    printf("%d\n",*(a+1)); //2
    printf("%d\n",*p+1); //3
    return 0;
}
