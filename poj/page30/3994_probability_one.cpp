#include<stdio.h>
 
int main()
{
    int n0;
    int Case = 1;
    while(scanf("%d",&n0) != EOF){
        if(n0 == 0){
            return 0;
        }
 
        int n1 = 3*n0;
        bool flag;
        if(n1%2 == 1){
            flag = true;//奇数
        }
        else{
            flag = false;//偶数
        }
 
        int n2;
        if(!flag){
            n2 = n1/2;
        }
        else{
            n2 = (n1+1)/2;
        }
 
        int n3 = 3*n2;
 
        int n4 = n3/9;
 
        if(!flag)
            printf("%d. even %d\n",Case++,n4);
        else
            printf("%d. odd %d\n",Case++,n4);
    }
    return 0;
}