#include<stdio.h>

// step 1,2,6
int dp(int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else if(n<6)
        return dp(n-1)+dp(n-2);
    else if(n==6)
        return dp(n-1)+dp(n-2)+1;
    else
        return dp(n-1)+dp(n-2)+dp(n-6);
}

int dp2(int n)
{
    int s1 = 1, s2 = 2, s3 = 3;
    int s4 = 5, s5 = 8, s6 = 14;
    int result, i;
    for(i = 6; i < n; i++)
    {
        result = s6 + s5 + s1;
        s1 = s2;
        s2 = s3;
        s3 = s4;
        s4 = s5;
        s5 = s6;
        s6 = result;
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
