#include<stdio.h>
int main()
{
    int a,b,n;
    while(~scanf("%d",&n))
    {
        if(n>198)
            printf("0\n");
        else
        {
            b=(99-n/2)*2;
            if(n%2==0)
                b+=1;
            printf("%d\n",b);
        }
    }
    return 0;
}