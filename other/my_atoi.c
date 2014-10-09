#include<stdio.h>
#include<stdlib.h>

char *my_itoa(int i) 
{
    int n = snprintf(NULL, 0, "%d", i) + 1;
    char *s = malloc(n);

    if (s != NULL)
        snprintf(s, n, "%d", i);
    return s;
}

void main()
{
    char *s;
    s = my_itoa(1234);
    printf("%s\n",s);
}
