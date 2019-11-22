#include<iostream>
using namespace std;
 
int phi(int n){  //对于n=p1^a1*p2^a2*...*pk^ak,其中p1,p2,...,pk为素数且整除n,phi(n)=n*(1-1/p1)*(1-1/p2)*...*(1-1/pk)
 	int i,ans=n;
	for(i=2;i*i<=n;i++){
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans=ans/n*(n-1);
	return ans;
}
 
int main(){
	int n,m;
	while(cin>>n){
		long long ans=1;
		while(n--){
			cin>>m;
			ans*=phi(m);
			if(ans>=1000000007) ans%=1000000007;
		}
		cout<<ans<<endl;
	}
	return 0;
}