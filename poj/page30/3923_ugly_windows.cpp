#include <iostream>
#include <vector>
using namespace std;
const int big=10005; //定义无穷大
const int maxn=105;  //屏幕最大边长
struct aaa
{
	int x,y;
};
vector<aaa> c; //保存着同一个字母位置的坐标的集合
int n,m;
char a[maxn][maxn]; //保存了屏幕中每个元素的值，即输入的数组
void make()
{
	char ch;
	int i,j,minx,maxx,miny,maxy;
	aaa node;
	bool f;
	for (ch='A';ch<='Z';ch++)//枚举每个大写字母，寻找其“顶端窗口”是否存在
	{
		c.clear();
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(a[i][j]==ch)
				{
					node.x=i;
					node.y=j;
					c.push_back(node);
				}
				if(c.size()==0)
					continue;
				minx=big;
				miny=big;
				maxx=0;
				maxy=0;
				for(i=0;i<c.size();i++)
				{
					if(c[i].x<minx) minx=c[i].x;
					if(c[i].y<miny) miny=c[i].y;
					if(c[i].x>maxx) maxx=c[i].x;
					if(c[i].y>maxy) maxy=c[i].y;
				}
				if(maxx<minx+2) continue;
				if(maxy<miny+2) continue;
				if(c.size()!=(maxx-minx+maxy-miny)*2) continue;
				f=true;
				for(i=minx+1;i<maxx;i++)
					for(j=miny+1;j<maxy;j++)
						if(isupper(a[i][j])) f=false;
						if(f) cout<<ch;
	}
	cout<<endl;
}
int main()
{
	int i,j;
	while (true)
	{
		cin>>n>>m;
		if(n+m==0)
			break;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				cin>>a[i][j];
			make();
	}
	return 0;
}