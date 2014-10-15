#include<stdio.h>
#include<string.h>
int main(int argc, char argv)
{
    char buff[]="hello how are you";
    int i,j;
    for(i=strlen(buff)-1;i>=0;i--)
        printf("%c",buff[i]);
    printf("\n");

    int temp = strlen(buff);
    for(i=strlen(buff)-1;i>=0;i--)
    {
        if(buff[i-1]==' ' | i==0)
        {
            for(j=i;j<temp;j++)
                printf("%c",buff[j]);
            printf(" ");
            temp = i-1;
        }
    }
    printf("\n");
}
