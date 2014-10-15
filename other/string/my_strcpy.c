#include<stdio.h>

void string_copy(char *src, char *des)
{
    while(*src)
    {
        *des = *src;
        des++;
        src++;
    }
    *des = '\x00';
}

void main(int argc, char** argv)
{
    char src[100];
    char des[100];
    printf("Input: ");
    scanf("%s",src);
    string_copy(src,des);
    printf("%s\n",des);
}
