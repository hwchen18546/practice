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
                if(s2[i2] == '\0')
                {
                    printf("count = %d\n",count);
                    return s1;
                }
            }
            else
            {
                s1++;
                count++;
                i1 = 0;
                i2 = 0;
                break;
            }
        }
    }
    return NULL;
}

void main(int argc,char **argv)
{
    char s1[] = "hello how are you?";
    char s2[] = "ar";
    char *pointer = my_strstr(s1, s2);
    printf("%s\n",s1);
    if(pointer)
        printf("%s\n", pointer);
}
