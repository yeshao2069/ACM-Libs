#include <stdio.h>
#define MAXM 1000000
int n,k;
int a[MAXM+1];
int r[MAXM+1];
void Solve()
{
	int i,j;
	a[0]=0;
	r[0]=0;
	for(i=1,j=0;i<=MAXM;i++)
	{
		a[i]=r[i-1]+1;
		while(j+1<i && a[j+1]*k<a[i])
		{
			j++;
		}
		r[i]=a[i]+r[j];
		if(r[i]>=n)
			break;
	}
	if(i>MAXM)
	{
		printf("un solvable\n");
		return;
	}
	if(a[i]==n)
	{
		printf("lose\n");
		return;
	}
	for(;i>=1;i--)
	{
		if(n==a[i])
		{
			printf("%d\n",n);
			return;
		}
		else if(n>a[i])
		{
			n-=a[i];
		}
	}
	printf("logic error\n");
}

int main()
{
	int ca,cc=0;
	scanf("%d",&ca);
	while(ca-->0)
	{
		scanf("%d %d",&n,&k);
		printf("Case %d: ",++cc);
		Solve();
	}
	return 0;
}