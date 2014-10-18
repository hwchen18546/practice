#include<stdio.h>

int main()
{
    int N = 1;
    int a;
    for(a = 0;a<40;a++)
    {
        int count = 0;
        int i,j,k;
        for(i=0;i<=N;i++)
        {
            for(j=0;j<=N;j++)
            {
                for(k=0;k<=N;k++)
                {
                    if(i+2*j+3*k==N)
                        count++;
                }
            }
        }
        printf("%d: %d\n",N,count);
        N++;
    }
    
}
