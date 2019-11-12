#include <stdio.h>
#include <string.h>
 
int main()
{
    int p, e, i, d;
    int n(0);//计录循环数的
 
    while(scanf("%d%d%d%d", &p, &e, &i, &d) != EOF && p >= 0)
    {
        int n1, n2, n3;
 
        p = p % 23 + 1;//得到在一个周期内高峰第几天
        e = e % 28 + 1;
        i = i % 33 + 1;
 
        for(int k = 1; ; k++){
            int m = (k * 924) % 23;
            if(p % m == 0){
                n1 = k * 924 * (p / m);
                break;
            }
        }
        for(int k = 1; ; k++){
            int m = (k * 759) % 28;
            if(e % m == 0){
                n2 = k * 759 * (e / m);
                break;
            }
        }
        for(int k = 1; ; k++){
            int m = (k * 644) % 33;
            if(i % m == 0){
                n3 = k * 644 * (i / m);
                break;
            }
        }
 
        //int sum = n1 + n2 + n3;
        //printf("%d %d %d XX %d %d %d %d\n", n1%23, n2%28, n3%33, sum%23, sum%28, sum%33, sum);
 
        int ans = (n1 + n2 + n3 - 1) % 21252;
 
        while(ans - d <= 0)
            ans += 21252;
 
        printf("Case %d: the next triple peak occurs in %d days.\n", ++n, ans - d);
 
    }
 
    return 0;
}