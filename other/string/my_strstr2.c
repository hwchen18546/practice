#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int sum(char *s1, int length)
{
    int i;
    int sum = 0;
    for(i = 0; i < length; i++)
    {
        sum += s1[i];
    }
    return sum;
}

char *my_strstr(char *string, char *pattern)
{
    int len_p = strlen(pattern);
    int len_s = strlen(string);
    int sum_p = sum(pattern,len_p);
    int i;
    for(i = 0; i < len_s-len_p+1; i++)
    {
        /* hash match */
        if(sum(string+i, len_p) == sum_p)
        {
            /* final check */
            int j, match = 1;
            for(j=0; j<len_p; j++)
            {
                if(string[i+j] != pattern[j])
                    match = 0;
            }
            if(match)
                return string+i;
        }
    }
    return NULL;
}

void main(int argc,char **argv)
{
    char s1[] = "hello how are you?";
    char s2[] = "how ";
    printf("%s\n",s1);
    char *pointer = my_strstr(s1, s2);
    if(pointer)
        printf("%s\n", pointer);
}
