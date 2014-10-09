#include <stdio.h>

int A[]={1,3,5,6,7,9,10,11,12,15,20,22};
int key = 22;

int binary(int A[], int key , int start, int end)
{
    int mid = (start+end) / 2;
    if (start > end)
    {
        return -1;
    }
    else
    {
        if(A[mid] > key)
        {
            return binary(A, key, start, mid-1);
        }
        else if(A[mid] < key)
        {
            return binary(A, key, mid+1, end);
        }
        else
        {
            return mid;
        }
    }
}

void main()
{
    int result;
    result = binary(A, key, 0, sizeof(A)/4 - 1);
    printf("%d\n", result);
}
