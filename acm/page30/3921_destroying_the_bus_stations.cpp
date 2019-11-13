#include <iostream>
using namespace std;
const int maxm=10005; //最大边数
const int maxn=105;   //最大点数
struct aaa
{
	int s,f,next;  //邻接表的域，s是边的起点，f为边的终点，next为指向s的下一条边
};
aaa c[maxm];
int sta[maxn],fa[maxn],zh[maxn];
int d[maxn][maxn],e[maxn];
bool b[maxn];
int n,m,now,tot;
bool goal;
void ins(int s,int f)
{
	now++;
	c[now].s=s;
	c[now].f=f;
	c[now].next=sta[s];
	sta[s]=now;
}
void bfs()
{
	int i,c1,op,k,t;
	c1=0;
	op=1;
	for(i=1;i<=n;i++)
		fa[i]=0;
	zh[1]=1;
	fa[1]=-1;

	while(c1<op)
	{
		c1++;
		k=zh[c1];
		for(t=sta[k];t;t=c[t].next)
			if(b[t[c].f]&&fa[c[t].f]==0)
			{
				op++;
				zh[op]=c[t].f;
				fa[c[t].f]=c[t].s;
				if(c[t].f==n)
					break;
			}
			if(fa[n]) break;
	}
}
	void dfs(int deep)
	{
		int i,l,k;
		if(goal)return;
		bfs();
		if(fa[n]==0)
		{
			goal=true;
			return;
		}
		l=0;
		for(k=n;k>1;k=fa[k])
		{
			l++;
			d[deep][l]=k;
		}
		if(l>m)
		{
			goal=true;
			return;
		}
		if(deep>tot)
			return;
		for(i=2;i<=l;i++)
		{
			b[d[deep][i]]=false;
			if(e[d[deep][i]]==0)
				dfs(deep+1);
			b[d[deep][i]]=true;
			e[d[deep][i]]++;
		}
		for(i=2;i<=l;i++)
			e[d[deep][i]]--;
	}

	int make()
	{
		int i,j;
		goal=false;
		for(i=0;i<=n;i++)
		{
			tot=i;
			for(j=1;j<=n;j++)
				b[j]=true;
			memset(e,0,sizeof(e));
			dfs(1);
			if(goal)return i;
		}
		return n;
	}

	int main()
	{
		int i,s,f,g;
		while(true)
		{
			cin>>n>>g>>m;
			if(n==0)break;
			memset(sta,0,sizeof(sta));
			now=0;
			for(i=1;i<=g;i++)
			{
				cin>>s>>f;
				ins(s,f);
			}
			g=make();
			cout<<g<<endl;
	}	
        return 0;
}
