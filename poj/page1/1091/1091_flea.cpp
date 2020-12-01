#include<iostream>
#include<cstdio>
#include<list>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<cmath>
#include<memory.h>
#include<set>
 
#define ll long long
#define LL __int64
#define eps 1e-8
 
//const ll INF=9999999999999;
 
#define inf 0xfffffff
 
using namespace std;
 
//vector<pair<int,int> > G;
//typedef pair<int,int> P;
//vector<pair<int,int>> ::iterator iter;
//
//map<ll,int>mp;
//map<ll,int>::iterator p;
//
//vector<int>G[30012];
 
int dive[112];
int cnt;
 
void divide(int m)
{
    cnt=0;
    for(int i=2;i<=sqrt(double(m));i++)
    {
        if(m%i==0)
        {
            cnt++;
            dive[cnt]=i;
            while(m%i==0)
                m/=i;
        }
    }
    if(m!=1)
        dive[++cnt]=m;
}
 
ll multiquick(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans*=a;
            b--;
        }
        b>>=1;
        a=a*a;
    }
    return ans;
}
 
int a[112];
ll tmp;
int n,m;
 
void dfs(int id,int num,int comon)
{
    int temp;
    if(num==comon)
    {
        temp=m;
        for(int i=1;i<=comon;i++)
            temp/=a[i];
        tmp+=multiquick(temp,n);
        return ;
    }
    for(int i=id+1;i<=cnt;i++)
    {
        a[id+1]=dive[i];
        dfs(i,id+1,comon);
    }
}
 
int main(void)
{
    while(scanf("%d %d",&n,&m)==2)
    {
        ll ans=0;
        divide(m);
        for(int i=1;i<=cnt;i++)
        {
            tmp=0;
            dfs(0,0,i);
            if(i&1)
                ans+=tmp;
            else
                ans-=tmp;
        }
        ans=multiquick(m,n)-ans;
        printf("%lld\n",ans);
    }
}