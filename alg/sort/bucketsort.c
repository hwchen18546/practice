#include <stdio.h>
#define LENGTH 8

void bucket_sort(int number[], int len)
{
    int i,j;
    int bucket[100] = {0};

    for(i = 0; i < len; i++)
    {
        bucket[number[i]]++;
    }
    j = 0;

    for(i = 0 ; i < 100; i++)
    {
        if(bucket[i])
        {   
            number[j++] = i;
        }
    }
}

int main()
{
    int i;
    int number[LENGTH] = {5,1,3,4,8,6,7,2};

    bucket_sort(number,LENGTH);

    for(i = 0; i < LENGTH; i++) 
    {
        printf("%d ",number[i]);
    }
}
