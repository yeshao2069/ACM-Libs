#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<queue>
#include<cctype>
using namespace std;
#define add_edge(a,b,c) nxt[++tot]=head[a],head[a]=tot,to[tot]=b,val[tot]=c
int N,M,tot=0,ans=0;
int head[3005]={},nxt[6005]={},to[6005]={},val[6005]={},F[3005][3005]={},siz[3005]={};
void solve(int x)
{
	if(!head[x]){siz[x]=1;return;}
	for(int i=head[x];i;i=nxt[i])
	{
		solve(to[i]);
		siz[x]+=siz[to[i]];
		for(int j=siz[x];j>=1;--j)
		{
			for(int k=j;k>=0;--k)//这层循环正反无所谓 
			{
				F[x][j]=max(F[x][j],F[x][k]+F[to[i]][j-k]-val[i]);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<=N;++i)for(int j=1;j<=M;++j)F[i][j]=-1000000000;
	for(int K,i=1;i<=N-M;++i)
	{
		scanf("%d",&K);
		for(int A,C,j=1;j<=K;++j)
		{
			scanf("%d%d",&A,&C);
			add_edge(i,A,C);
		}
	}
	for(int i=N-M+1;i<=N;++i)scanf("%d",&F[i][1]);
	solve(1);
	for(int i=siz[1];i;--i)
	{
		if(F[1][i]>=0)
		{
			printf("%d",i);
			return 0;
		}
	}
    return 0;
}