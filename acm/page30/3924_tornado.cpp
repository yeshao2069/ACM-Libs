#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int MAX=1000000000;   //平行线数目上界
const double ZERO=1e-7;    //实数精度
struct Tnode{
	double x,y;
}w1,w2,t1,t2;
double vw,vt,dl,du;
//取最小值
double min(double a,double b)
{
	return (a>b)?b:a;
}
//求点积
double dot(Tnode &a,Tnode &b,Tnode &c)
{
	return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
}
//求叉积
double det(Tnode &a,Tnode &b,Tnode &c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
//求距离
double dis(Tnode &a,Tnode &b)
{
	return sqrt(fabs((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)));
}
//求点O到线段的最近距离
double getdistance(Tnode &o,Tnode a,Tnode b,double dx,double dy)
{
	a.x +=dx;
	a.y +=dy;
	b.x +=dx;
	b.y +=dy;
	double d=min(dis(o,a),dis(o,b));
	double di=dis(a,b);
	if(di<=ZERO)
		return dis(o,a);
	if(dot(a,o,b)>= -ZERO && dot(b,o,a) >= -ZERO)
		return fabs(det(a,b,o)) /di;
	else
		return min(dis(o,a),dis(o,b));
}
//求点O到以线段ab为起始，（dx,dy）为间距的平行线段族的最近距离
double calc(Tnode &o, Tnode &a, Tnode &b, double dx, double dy)
{
	Tnode a1,b1;
	int  l=0,r=MAX;
	while(l<r)
	{
		int mid=(l+r)/2;
		double d1=getdistance(o,a,b,dx*mid,dy*mid);
		double d2=getdistance(o,a,b,dx*(mid+1),dy*(mid+1));
		if(d1<=d2+ZERO)
			r=mid;
		else
			l=mid+1;
	}
	return getdistance(o,a,b,dx*l,dy*l);
}
void work()
{
	Tnode wdr,tdr,move,a1,a2,b1,b2;
	double distance,time,d,d1,d2;

	distance =dis(w1,w2);
	wdr.x=(w2.x-w1.x)*vw/distance;
	wdr.y=(w2.y-w1.y)*vw/distance;
	distance=dis(t1,t2);
	time=distance/vt;
	tdr.x=(t2.x-t1.x)*vt/distance;
	tdr.y=(t2.y-t1.y)*vt/distance;
	move.x=(-wdr.x+tdr.x)*time;
	move.y=(-wdr.y+tdr.y)*time;
	a1=t1;
	b1.x=a1.x+move.x;
	b1.y=a1.y+move.y;
	move.x=(-wdr.x-tdr.x)*time;
	move.y=(-wdr.y-tdr.y)*time;

	a2=b1;
	b2.x=a2.x+move.x;
	b2.y=a2.y+move.y;

	d1=calc(w1,a1,b1,b2.x-a1.x,b2.y-a1.y);
	d2=calc(w1,a2,b2,b2.x-a1.x,b2.y-a1.y);

	d=min(d1,d2);
	if(d+ZERO<dl)
		printf("Dangerous\n");
	else
		if(d-ZERO>du)
			printf("Miss\n");
		else
			printf("Perfect\n");
}

int main()
{
	while(scanf("%lf", &w1.x)!=EOF){
		scanf("%lf %lf %lf %lf",&w1.y,&w2.x,&w2.y,&vw);
		scanf("%lf %lf %lf %lf %lf",&t1.x,&t1.y,&t2.x,&t2.y,&vt);
		scanf("%lf %lf",&dl,&du);
		work();
	}
	return 0;
}
