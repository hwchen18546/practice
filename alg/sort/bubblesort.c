#include <stdio.h>
#define LENGTH 8

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int i, j;
    int number[LENGTH] = {5,1,3,4,8,6,7,2};
    for(i = 0; i < LENGTH; i++)
    {
        for(j = 0; j < LENGTH-1-i; j++)
        {
            /* keep last one is max */
            if(number[j] > number[j+1])
            {
                /* call by pointer */
                swap(&number[j], &number[j+1]);
            }
        }
    }
    for(i = 0; i < LENGTH; i++) 
    {
        printf("%d ",number[i]);
    }
}
