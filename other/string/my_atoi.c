#include<stdio.h>

int my_atoi(char* num_str)
{
    int i = 0;
    int num = 0;
    while(num_str[i] != '\0')
    {
        num = num*10 + (num_str[i] - '0');
        i++;
    }
    return num;
}


int main()
{
    char num_str[100];
    int num;
    scanf("%s",num_str);
    num = my_atoi(num_str);
    printf("%d\n",num);
    return 0;
}
