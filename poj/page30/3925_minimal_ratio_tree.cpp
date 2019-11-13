#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define INFINITE 900000000
int G[30][30];
int n,m;
int w[30];
int mNodes[30];
int aResult[30];
double fMiniRatio;
void Prim();
void SelectMNodes(int nDone,int nStart)
{
	if(nDone == m){
		Prim();
		return ;
	}
	for(int i=nStart; i<n; i++){
		mNodes[nDone]=i;
		SelectMNodes(nDone+1,i+1);
	}
}
void Prim()
{
	int i,j,k;
	int anDist[30];
	int anUsed[30];
	int nDoneNum=0;
	int nTotalWE=0,nTotalWN=0;
	for(i=0;i<m;i++){
		anUsed[i]=0;
		anDist[i]=INFINITE;
	}
	anUsed[0]=1;
	nDoneNum=1;
	for( i=1; i<m; i++){
		if(G[mNodes[0]][mNodes[i]] != INFINITE)
			anDist[i]=G[mNodes[0]][mNodes[i]];
	}
	while (nDoneNum < m){
		int nMin=INFINITE;
		int nMini=0;
		for(i=1; i<m; i++){
			if(anUsed[i] == 0 && anDist[i] < nMin){
				nMin=anDist[i];
				nMini=i;
			}
		}
		nTotalWE +=anDist[nMini];
		anUsed[nMini]=1;
		nDoneNum++;
		for(i=1;i<m;i++){
			if(anUsed[i]==0){
				if(anDist[i]>G[mNodes[nMini]][mNodes[i]])
					anDist[i]=G[mNodes[nMini]][mNodes[i]];
			}
		}
	}
	for(i=0;i<m;i++)
		nTotalWN +=w[mNodes[i]];
	double fTmpRatio=(double) nTotalWE / nTotalWN;
	if(abs(fTmpRatio-fMiniRatio) > 0.00000001 && fMiniRatio > fTmpRatio){
		for(i=0;i<m;i++)
			aResult[i]=mNodes[i];
		fMiniRatio=fTmpRatio;
	}
}
int main()
{
	int i,j;
	while(true){
		cin>>n>>m;
		if(n==0 && m==0)
			break;
		for(i=0;i<n;i++)
			cin>>w[i];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>G[i][j];
			fMiniRatio=INFINITE;
			SelectMNodes(0,0);
			cout<<aResult[0]+1;
			for(i=1;i<m;i++)
				cout<<" "<<aResult[i]+1;
			cout<<endl;
	}
	return 0;
}
