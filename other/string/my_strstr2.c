#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Rabin-Karp
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
    int len_p = strlen(pattern); //m
    int len_s = strlen(string); // n
    int sum_p = sum(pattern,len_p);
    int sum_s = sum(string,len_p); //pre-order O(m)
    int i;
    for(i = 0; i < len_s-len_p+1; i++) //compare O(n-m+1)
    {
        /* hash match */
        if(sum_s == sum_p)
        {
            /* final check */
            int j, match = 1;
            for(j=0; j<len_p; j++) //chech O(m)
            {
                if(string[i+j] != pattern[j])
                    match = 0;
            }
            if(match)
                return string+i;
        }
        sum_s = sum_s - string[i] + string[len_p+i]; // KEY!!!
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
