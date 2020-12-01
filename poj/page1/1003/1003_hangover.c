#include<stdio.h>
int main()
{
    int n,i,k;
    double t,T;
    while(scanf("%lf",&t),t)
    {
       k=2;T=t;
       for(i=2;t>=0;i++)
       {
            t-=(float)1/i;
            k=i-1;
       }
       printf("%d card(s)\n",k);
    }
    return 0;
}