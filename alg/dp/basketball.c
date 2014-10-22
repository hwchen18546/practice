#include<stdio.h>

// top-down
int dp(int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else if(n==3)
        return 4;
    else
        return dp(n-1)+dp(n-2)+dp(n-3);
}

int dp2(int n)
{
    int s1 = 1, s2 = 2, s3 = 4;
    int result, i;
    for(i = 3; i < n; i++)
    {
        result = s1 + s2 + s3;
        s1 = s2;
        s2 = s3;
        s3 = result;
    }
    return result;
}

int main()
{
    int i;
    scanf("%d",&i);
    printf("%d\n",dp(i));
    printf("%d\n",dp2(i));
    return 0;
}
