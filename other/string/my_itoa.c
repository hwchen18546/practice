#include<stdio.h>
#include<stdlib.h>

char *my_itoa(int num) 
{
    int digit = 0;
    int temp = num;
    while(temp != 0)
    {
        temp /= 10;
        digit++;
    }
    char *str = (char*)malloc(digit);
    int i;
    temp = num;
    for(i = digit-1; i >=0; i--)
    {
        str[i] = (temp % 10) + '0';
        temp /= 10;
    }
    str[digit] = '\0';
    return str;
}

void main()
{
    char *s;
    int num;
    scanf("%d",&num);
    s = my_itoa(num);
    printf("%s\n",s);
}
