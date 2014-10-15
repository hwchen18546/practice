#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *my_strstr(char *s1, char *s2)
{
    int i1 = 0;
    int i2 = 0;
    int count = 0;
    while(s1[i1])
    {
        while(s2[i2])
        {
            if(s1[i1] == s2[i2])
            {
                i1++;
                i2++;
            }
            else
            {
                s1++;
                count++;
                i1 = 0;
                i2 = 0;
                break;
            }
            if(s2[i2] == '\0')
            {
                printf("count = %d\n",count);
                return s1;
            }
        }
    }
    return NULL;
}

int sum(char *s1)
{
    int num = 0;
    while(*s1)
    {
        num += *s1;
        s1++;
    }
    return num;
}

char *my_strstr2(char *s1, char *s2)
{
    int sum_s2 = sum(s2);
    int len_s2 = strlen(s2);
    char *temp = (char*)malloc(len_s2);
    int i = 0,j;
    while(*(s1+i)!='\0')
    {
        strncpy(temp,s1+i,len_s2);
        if(sum(temp)==sum_s2)
        {
            for(j=0;j<len_s2;j++)
            {
                if(s2[j]==temp[j])
                    j++;
                else
                    break;
                if(s2[j]=='\0')
                    return s1+i;
            }
        }
        i++;
    }
    return NULL;
}


void main(int argc,char **argv)
{
    char s1[] = "hello how are you?";
    char s2[] = "ea";
    char *pointer = my_strstr(s1, s2);
    printf("%s\n",s1);
    if(pointer)
        printf("%s\n", pointer);
    char *pointer2 = my_strstr2(s1,s2);
    if(pointer2)
        printf("%s\n", pointer2);
    
}
