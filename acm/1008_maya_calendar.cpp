#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
char s1[20][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char s2[20][10]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int main()
{
    int t,day,year,ans,sum,num;
    char mon[10];
    scanf("%d",&t);
    printf("%d\n",t);
    for(int xx=0;xx<t;xx++)
    {
        ans=sum=0;
        scanf("%d. %s %d",&day,mon,&year);
        for(int i=0;i<20;i++)
        {
            if(strcmp(s1[i],mon)==0)
            {
                ans=year*365+day+i*20;
                break;
            }
        }		
        ans++;
        year=ans/260;
        num=ans%260;
        if(num==0){//如果是一年的最后一天，我们应该怎样去处理
        	year--;
        	num+=260;
		}
        day=num%13;
        if(day==0)
        	day=13;
        int mon=num%20;
        if(mon==0)
          mon=20;
        printf("%d %s %d\n",day,s2[mon-1],year);
    }
    return 0;
}