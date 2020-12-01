#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stdio.h>
#include <iomanip>
#include <math.h>   
#include <list>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;
 
int main(void)
{
	int n;
	int a, b, c;
	cin >> n;
	cout << "Gnomes:"<<endl;
	for(;n--;)
	{
		cin >> a >> b >> c;
		if(a > b)
		{
			if(b > c)
			{
				cout << "Ordered"<<endl;
			}
			else
			{
				cout << "Unordered"<<endl;
			}
		}
		else if(a < b)
		{
			if(b < c)
			{
				cout << "Ordered"<<endl;
			}
			else
			{
				cout << "Unordered"<<endl;
			}
		}
	}
	return 0;
}