#include <stdio.h>

int sum(int N)
{
    if (N == 0)
        return 0;
    return sum(N-1)+N;
}

void main(int argc, char **argv)
{
    int N;
    scanf("%d", &N);
    printf("%d\n", sum(N));
}
