#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
char s[43];
int a[30];
int main()
{
    int T,n;
    int k,m;
 
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            k=0;
            scanf("%d",&n);
            for(int i=1; i<=n; i++)
            {
                scanf("%d",&a[i]);
            }
 
            for(int i=1; i<=n; i++)
            {
                m=a[i]-a[i-1];
                while(m--)
                {
                    s[k++]='(';
 
                }
                s[k++]=')';
            }
//            for(int i=0; i<k; i++)
//                printf("%d %c\n",i,s[i]);
            int ans;
            int flag;
            int j;
            bool mark=1;
            for(int i=1; i<k; i++)
            {
                ans=0;
                flag=1;
                if(s[i]==')')
                {
                    j=i-1;
 
                    while(flag&&j>=0)
                    {
                        if(s[j]=='(')
                        {
                            flag--;
                            ans++;
                        }
                        else if(s[j]==')')
                        {
                            flag++;
 
                        }
                        j--;
                    }
                     if(mark)
                    mark=0;
                else
                    printf(" ");
                printf("%d",ans);
                }
 
            }
            printf("\n");
        }
    }
    return 0;
}