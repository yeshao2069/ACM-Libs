#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

long long C[30]={1};

void Init(){    //预处理卡特兰数  
    for(int i=1;i<=25;i++)
        C[i]=C[i-1]*(4*i-2)/(i+1);
}

void solve(int k,int cnt){      //输出k个节点的并排在第cnt位的二叉树  
    if(k==1){   //只有一个节点，直接输出
        printf("X");
        return ;
    }
    if(cnt<=C[k-1]){    //排名很靠前，只有右子树  
        printf("X");
        printf("(");
        solve(k-1,cnt);
        printf(")");
    }else if(cnt>C[k]-C[k-1]){  //排名很靠后，只有左子树  
        printf("(");
        solve(k-1,cnt-(C[k]-C[k-1]));
        printf(")");
        printf("X");
    }else{
        int t=k-1,m;
        for(int i=t;i>=0;i--){  //判断左右子树各有多少个节点，更新名次  
            if(C[i]*C[t-i]<cnt)
                cnt-=C[i]*C[t-i];
            else{
                m=i;
                break;
            }
        }
        printf("(");
        solve(t-m,cnt/C[m]+(cnt%C[m]!=0));  //递归左子树  
        printf(")X(");
        solve(m,(cnt-1)%C[m]+1);    //递归右子树
        printf(")");
    }
}

int main(){

    //freopen("input.txt","r",stdin);

    int n,m;
    Init();
    while(~scanf("%d",&n) && n){
        for(int i=1;;i++){
            if(n>C[i])
                n-=C[i];
            else{
                m=i;
                break;
            }
        }
        solve(m,n);
        printf("\n");
    }
    return 0;
}