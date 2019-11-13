#include <iostream>
#include <stdio.h>
#define MAXNumPart 66
#define MAXUnit 53
using namespace std;
int numPart,mNumPart,sLength,alLength,mLength;
int part[MAXNumPart];
int maxPart,minPart;
bool Road=false;

void dfs(int now)
{
    if(mLength<sLength)
    {
        for(int i=now;i>=minPart;i--)
        {
            if(part[i]>0)
            {
                part[i]--;
                mLength+=i;
                mNumPart--;
                dfs(i);
                if(Road)
                    return;
                part[i]++;
                mLength-=i;
                mNumPart++;
//                if(mLength+i>sLength)
//                {
//                    break;
//                }
            }
        }
    }
    else
    {
        if(mLength==sLength)
        {
            if(mNumPart!=0)
            {
                for(int i=maxPart;i>=minPart;i--)
                {
                    if(part[i]>0)
                    {
                        part[i]--;
                        mNumPart--;
                        mLength=i;
                        dfs(i);
                        if(Road)
                            return;
                        part[i]++;
                        mNumPart++;
                        mLength=sLength;
                        break;
                    }
                }
            }
            else
                Road=true;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int temp;
    while(~scanf("%d",&numPart)&&numPart!=0)
    {
        mNumPart=numPart;
        alLength=0;
        maxPart=0;
        minPart=MAXUnit-1;
        Road=false;
        for(int i=0;i<MAXNumPart;i++)
            part[i]=0;
        for(int i=0;i<numPart;i++)
        {
            scanf("%d",&temp);
            alLength+=temp;
            part[temp]++;
            if(maxPart<temp)
                maxPart=temp;
            if(temp<minPart)
                minPart=temp;
        }
        for(sLength=maxPart;sLength<=alLength;sLength++)
        {
            if(alLength%sLength==0)
            {
                part[maxPart]--;
                mNumPart--;
                mLength=maxPart;
                dfs(maxPart);
                if(mNumPart==0)
                {
                    printf("%d\n",sLength);
                    break;
                }
                else
                {
                    part[maxPart]++;
                    mNumPart++;
                    mLength=0;
                }
            }
        }
    }
    return 0;
}