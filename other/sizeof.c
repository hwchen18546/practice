#include <stdio.h>
#include <stdlib.h>
void foo(char str2[100])
{
    printf("%d\n",sizeof(str2)); //4 array decay into a function
}


void main(int argc, char **argv)
{
    char str[] = "http://www.ibegroup.com/";
    printf("%d\n",sizeof(str)); //25
    char str2[100];
    printf("%d\n",sizeof(str2)); //100
    foo(str2);
    char *p = str;
    printf("%d\n",sizeof(p)); //4
    int a;
    printf("%d\n",sizeof(a)); //4
    long int b;
    printf("%d\n",sizeof(b)); //4
    long long int c;
    printf("%d\n",sizeof(c)); //8
    double d;
    printf("%d\n",sizeof(d)); //8
    printf("%d\n",sizeof(&d)); //4
    char *e = (char *)malloc(100);
    printf("%d\n",sizeof(e)); //4
    

}
