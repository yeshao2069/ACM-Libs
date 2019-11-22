#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
 
int main()
{
	double vs, r, c;
	int n;
	cin>>vs>>r>>c;
	cin>>n;
 
	while(n-->0)
	{
		double w;
		cin>>w;
		double vr = r*c*w*vs*sqrt(1/(r*c*w*r*c*w+1));
		printf("%.3lf\n", vr);
	}
	return 0;
}