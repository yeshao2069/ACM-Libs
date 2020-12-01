#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdio>
typedef long long ll;
#define N 105
using namespace std;
int a[N][N];
int main()
{
    int i,j,k,n,t,sum,imax;
    while (scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        for (i=1;i<=n;++i)
        {
            for (j=1;j<=n;++j)
            {
                scanf("%d",&t);
                a[i][j]=a[i-1][j]+t;
            }
        }
        imax=0;
        for (i=1;i<=n;++i)  //第一行
        {
            for (j=i;j<=n;++j) //第二行
            {
                sum=0;
                for (k=1;k<=n;++k)
                {
                    t=a[j][k]-a[i-1][k];//前j行前k列的和-前i-1行前k列的和
                    sum+=t;
                    if (sum<0) sum=0;
                    if (sum>imax) imax=sum;
                }
            }
        }
        printf("%d\n",imax);
    }
    return 0;
}