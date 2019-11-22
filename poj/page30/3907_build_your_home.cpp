#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 10005
#define eps 1e-8
using namespace std;
struct point
{
    double x,y;
    inline double operator *(const point &rhs) const
    {
        return x*rhs.y-y*rhs.x;
    }
}po[N];
int n;
double S;
double abs(double x)
{
    return x>0?x:-x;
}
double calc()
{
    double ret=0;
    for (int i=1;i<=n;i++)
    ret+=po[i]*po[i+1];
    return abs(ret/2)+0.5;
}
int main()
{
    while (scanf("%d",&n)!=EOF && n)
    {
    for (int i=1;i<=n;i++)
        scanf("%lf%lf",&po[i].x,&po[i].y);
    po[n+1]=po[1];
    printf("%d\n",(int)calc());
    }
    return 0;
}