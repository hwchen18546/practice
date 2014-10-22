#include<stdio.h>
#define SET_BIT(x,y) ((x) = (x) | (1 << (y)))
#define CLEAR_BIT(x,y) ((x) = (x) & ~(1 << (y)))
#define REVERSE_BIT(x,y) ((x) = (x) ^ (1 << (y)))
#define GET_BIT(x,y) (((x) >> (y)) & 1)

int BIT_COUNT(int x);
{
    int counter = 0;
    while(x)
    {
        counter++;
        x = x & (x-1);
    }
}

int main()
{
    unsigned i = 0;
    printf("%d\n",GET_BIT(i,3));
    SET_BIT(i,3);
    printf("%d\n",GET_BIT(i,3));
    CLEAR_BIT(i,3);
    printf("%d\n",GET_BIT(i,3));
    REVERSE_BIT(i,3);
    printf("%d\n",GET_BIT(i,3));
    return 0;
}
