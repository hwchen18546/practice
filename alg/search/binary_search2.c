#include <stdio.h>

// normal binary_search
int binary(int A[], int key , int start, int end);
// offset sorting_array, know offset
int binary2(int A[], int key , int start, int end, int cut);
// offset sorting_array, unknow offset
int binary3(int A[], int key , int start, int end);

void main()
{
    int key = 5;
    int A[]={1,3,5,6,7,9,10,11,12,15,20,22};
    int cut = 7;
    int B[]={9,10,11,12,15,20,22,1,3,5,6,7};
    int result;

    result = binary(A, key, 0, sizeof(A)/4 - 1);
    printf("%d\n", result);
    result = binary2(B, key, 0, sizeof(B)/4 - 1, cut);
    printf("%d\n", result);
    result = binary3(B, key, 0, sizeof(B)/4 - 1);
    printf("%d\n", result);
}

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

int binary2(int A[], int key , int start, int end, int cut)
{
    if(A[cut]==key)
        return cut;
    else
    {
        int result;
        result =binary(A, key, 0, cut-1);
        if(result != -1)
            return result;
        else
            return binary(A, key, cut+1, end);
    }
}

int binary3(int A[], int key , int start, int end)
{
    int mid = (start+end) / 2;
    if (start > end)
    {
        return -1;
    }
    else
    {
        if(A[mid] == key)
        {
            return mid;
        }
        else if(A[start] <= A[mid-1]) //order
        {
            if(key >= A[start] && key <= A[mid-1]) //between
                return binary3(A, key, start, mid-1);
            else //another
                return binary3(A, key, mid+1, end);
        }
        else if(A[mid+1] <= A[end]) //order
        {
            if(key >= A[mid+1] && key <= A[end]) //between
                return binary3(A, key, mid+1, end);
            else //another
                return binary3(A, key, start, mid-1);
        }
        
    }
}
