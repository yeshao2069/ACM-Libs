#include "stdio.h"
#include "stdlib.h"
#include "string.h"
 
#define MAX_STUDENT 30
 
int gwFriendList[MAX_STUDENT+1][MAX_STUDENT+1];
int gwdivide[MAX_STUDENT+1];
int gwStudentNum;
 
int MAX(int a, int b)
{
    return (a>b) ? a : b;
}
 
int MIN(int a, int b)
{
    return (a>b) ? b : a;
}
 
int strangeNum(int wboy, int class[])
{
    int i = 0;
    int j = 0;
    int lone = 0;
    for(i=1; i<=class[0]; i++)
    {
        if(wboy == class[i])
            continue;
        for(j=1; j<=gwFriendList[class[i]][0]; j++)
        {
            if(wboy == gwFriendList[class[i]][j])
                break;
        }
        if(j > gwFriendList[class[i]][0])
            lone++;
    }
    return lone;
}
 
void exchangeValue(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
 
void buildClass(int class[], int flag)
{
    int i = 0;
    int j = 0;
    for(i=1; i<=gwStudentNum; i++)
    {
        if(gwdivide[i] == flag)
            class[++j] = i;
    }
    class[0] = j;
}
 
int calcLone(int class[])
{
    int i = 0;
    int lone = 0;
    for(i=1; i<=class[0]; i++)
    {
        lone = MAX(lone, strangeNum(class[i], class));
    }
    return lone;
}
 
int Lone()
{
    int class1[MAX_STUDENT+1];
    int class2[MAX_STUDENT+1];
    buildClass(class1, 1);
    buildClass(class2, 0);
    return MAX(calcLone(class1), calcLone(class2));
}
 
int divideClass(int now, int max)
{
    int wlone = 30;
    int i = 0;
    if(now == max)
        return Lone();
    else
    {
        wlone = MIN(wlone, divideClass(now+1, max));
        for(i=now+1; i<=max; i++)
        {
            if(gwdivide[i] != gwdivide[max])
            {
                exchangeValue(&gwdivide[i], &gwdivide[max]);
                wlone = MIN(wlone, divideClass(i, max));
                exchangeValue(&gwdivide[i], &gwdivide[max]);
            }
        }
        return wlone;
    }
}
 
int main()
{
    int i = 0;
    int j = 0;
    int wCount = 0;
    int lone = 0;
 
    while(1)
    {
        if(EOF == scanf("%d", &j))
            break;
        scanf("%d", &wCount);
        gwFriendList[j][0] = wCount;
        gwStudentNum++;
        for(i=1; i<=wCount; i++)
        {
            scanf("%d", &gwFriendList[j][i]);
        }
        wCount = 0;
    }
    for(i=1; i<=(gwStudentNum/2); i++)
    {
        gwdivide[i] = 1;
    }
 
    lone = divideClass(1,gwStudentNum);
 
    printf("%d\n", lone);
    return 0;
}