#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int m,i,j,n,d[13],Max,e;
    char a[20],b[20],c[20];
    scanf("%d",&m);
    while(m--)
    {
        memset(d,0,sizeof(d));
        for(j=0; j<3; j++)
        {
            scanf("%s %s %s",a,b,c);
            n=strlen(a);
            if(strcmp(c,"even")==0)
            {
                for(i=0; i<n; i++)
                    d[a[i]-'A']=10;
                for(i=0; i<n; i++)
                    d[b[i]-'A']=10;
            }
            else if(strcmp(c,"up")==0)
            {
                for(i=0; i<n; i++)
                    if( d[a[i]-'A']!=10)
                        d[a[i]-'A']++;
                for(i=0;i<n; i++)
                    if( d[b[i]-'A']!=10)
                        d[b[i]-'A']--;

            }
            else if(strcmp(c,"down")==0)
            {
                for(i=0; i<n; i++)
                    if( d[a[i]-'A']!=10)
                        d[a[i]-'A']--;
                for(i=0; i<n; i++)
                    if( d[b[i]-'A']!=10)
                        d[b[i]-'A']++;
            }
        }
        Max = 0;
        e= 0;
        for (i = 0; i < 12; i++)
        {
            if (d[i] != 10 && abs(d[i]) >Max)
            {
                Max = abs(d[i]);
                e = i;
            }
        }
        if (d[e] > 0)
        {
            printf("%c is the counterfeit coin and it is heavy.\n", e+'A');
        }
        else
        {
            printf("%c is the counterfeit coin and it is light.\n", e+'A');
        }
    }
    return 0;
}