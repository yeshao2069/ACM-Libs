
#include<iostream>
#include<cmath>
#include<memory.h>
#define MAXV 110
//最长公共子序列的变形
//dp[i][j]表示s1[0..i]和s2[0..j]的最大值
/*
1.取字符i-1和j-1的时候dp[i][j]=dp[i-1][j-1]+matrix[s1[i-1]][s2[j-1]];
2.取字符i-1不取j-1的时候dp[i][j]=dp[i-1][j]+matrix[s1[i-1]]['-'];
3.取字符j-1不取i-1的时候dp[i][j]=dp[i][j-1]+matrix['-'][s2[j-1]];
*/
using namespace std;
int max3(int a,int b,int c){
    return max(a,max(b,c));
}
int matrix[5][5]={
    5,-1,-2,-1,-3,
    -1,5,-3,-2,-4,
    -2,-3,5,-2,-2,
    -1,-2,-2,5,-1,
    -3,-4,-2,-1,0
};
int GetId(char a){
    switch(a){
        case 'A':return 0;
        case 'C':return 1;
        case 'G':return 2;
        case 'T':return 3;
        case '-':return 4;
    }
}
int main(){
    int len1,len2,total_cases,i,j,t1,t2,t3;
    char s1[MAXV],s2[MAXV];
    int dp[MAXV][MAXV];
    cin>>total_cases;
    while(total_cases--){
        cin>>len1;
        cin>>s1;
        cin>>len2;
        cin>>s2;
        memset(dp,0,sizeof(dp));
        dp[0][0] = 0;
        for(i = 1; i <= len1;i++){
            dp[i][0] = dp[i-1][0] + matrix[GetId(s1[i-1])][GetId('-')];
        }
        for(i = 1; i < len2; i++){
            dp[0][i] = dp[0][i-1]+matrix[GetId('-')][GetId(s2[i-1])];
        }
        for(i = 1; i <= len1; i++){
            for(j = 1; j <= len2; j++){
                t1 = dp[i-1][j] + matrix[GetId(s1[i-1])][GetId('-')];
                t2 = dp[i][j-1] + matrix[GetId('-')][GetId(s2[j-1])];
                t3 = dp[i-1][j-1] + matrix[GetId(s1[i-1])][GetId(s2[j-1])];
                dp[i][j] = max3(t1,t2,t3);
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
}