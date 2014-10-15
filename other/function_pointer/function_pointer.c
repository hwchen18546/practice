#include <stdio.h>
int printHello()
{
    printf ("Hello\n");
}

int printHi()
{
    printf ("Hi\n");
}

int main(int argc, char *argv[])
{
    // Declare a function pointer
    int (*p)(void);
    // Point the function pointer to the address of a function
    p = printHello;
    p();
    // Point the function pointer to the address of another function
    p = printHi;
    p();
}
