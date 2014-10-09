/*
 * Divide and conquer cut list to two sub-lists
 * theta(n^2)/theta(nlgn)/theta(nlgn)
 * 1.Pick a pivot
 * 2.partition base on pivot
 * 3.repeat
*/

#include <stdio.h>
int a[] = { 1, 2, 8, 7, 9, 5, 6, 4, 3, 66, 77, 33, 22, 11 };
 
void prt(int n, int q)
{
    int i;
    for (i = 0; i < n; i++) 
    {
        if(i == q)
            printf("*%d*\t", a[i]);
        else
            printf("%d\t", a[i]);
    }
    printf("\n");
}
 
void quick_sort(int data[], int left, int right)
{
    int q;
    if(left < right)
    {
        q = partition(data, left, right);
        prt(14 , q);
        quick_sort(data, left, q-1);
        quick_sort(data, q+1, right);
    }
}
 
int partition(int data[], int left, int right)
{
    /* pick last one as pivot */
    int pivot = data[right];
    int i = left-1;
    int j, temp;
    /* j < right, keep the last one be pivot */
    for(j = left; j < right; j++)
    {
        if(data[j] <= pivot)
        {
            /* i: how many number is smaller than pivot */
            i++;
            /* swap small number to left side <i side>  */
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    /* put pivot to i+1 position */
    temp = data[i+1];
    data[i+1] = data[right];
    data[right] = temp;
    return i+1;
}

int main(void) {
    prt(14,-1);
    quick_sort(a, 0, 13);
    prt(14,-1);
    return 0;
}
