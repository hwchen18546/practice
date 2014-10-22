#include<stdio.h>

int main()
{
    char strAry[] = "Thisz is a string";
    char *aryPtr = strAry;
    int *intPtr = (int*)strAry;

    printf("P0 = %d\n",sizeof(strAry));
    printf("P1 = %d\n",sizeof(aryPtr));
    printf("P2 = %d\n",sizeof(*aryPtr)); //1
    printf("P3 = %c\n",*aryPtr);
    printf("P4 = %c\n",*aryPtr+1);
    printf("P5 = %c\n",*(aryPtr+1));
    printf("P6 = %d\n",sizeof(*intPtr)); //4
    printf("P7 = %s\n",intPtr);
    printf("P8 = %c\n",*intPtr);
    printf("P9 = %c\n",*intPtr+1);
    printf("P10 = %c\n",*(intPtr+1));
}
/*
P0 = 18
P1 = 4
P2 = 1
P3 = T
P4 = U
P5 = h
P6 = 4
P7 = Thisz is a string
P8 = T
P9 = U
P10 = z
*/
