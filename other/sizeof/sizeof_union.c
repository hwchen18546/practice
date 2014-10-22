#include<stdio.h>

typedef union stt
{
    int i; //4
    char c; //1
    char c2;//1 +2nop
    int i2;//4
}stt;

int array[10]={1,2,3,4,5,6,7,8,9,10};

int main()
{
    stt s;
    stt *p;
    p = (stt*)&array[0];
    printf("P1=%d\n",sizeof(s));
    printf("P2=%d\n",sizeof(p));
    printf("P3=%d\n",p->i);
    printf("P4=%d\n",p->c);
    printf("P5=%d\n",p->c2);
    printf("P6=%d\n",p->i2);
    p++; //p+sizeof(p)
    printf("P7=%d\n",p->i);
    printf("P8=%d\n",p->c);
    printf("P9=%d\n",p->c2);
    printf("P10=%d\n",p->i2);
    return 0;
}
/*
P1=4 // same memory
P2=4
P3=1
P4=1
P5=1
P6=1
P7=2
P8=2
P9=2
P10=2
*/
