#include<cstdio>
 
using namespace std;
 
struct _stru_DNA
 
{
 
    char String[52];
 
    int Measure;
 
};
 
_stru_DNA DNA[110];
 
int n,m;
 
//计算第Index条DNA的Measure
 
void CountMeasure(int Index);
 
//DNA排序
 
void SortDNA();
 
 
 
int main(void)
 
{
 
    int i;
 
    scanf("%d%d", &n, &m);
 
    for (i=0; i<m; i++)
 
    {
 
        scanf("%s", DNA[i].String);
 
        CountMeasure(i);
 
        //printf("%d\n", DNA[i].Measure);
 
    }
 
    SortDNA();
 
    for (i=0; i<m; i++)
 
    {
 
        printf("%s\n", DNA[i].String);
 
        //printf("%d\n", DNA[i].Measure);
 
    }
 
    return 0;
 
}
 
//计算第Index条DNA的Measure
 
void CountMeasure(int Index)
 
{
 
    int i,j;
 
    int Measure = 0;
 
    for (i=0; i<n-1; i++)
 
    {
 
        if ('A' == DNA[Index].String[i])
 
        {
 
            continue;
 
        }
 
        for (j=i+1; j<n; j++)
 
        {
 
            if (DNA[Index].String[i] > DNA[Index].String[j])
 
            {
 
                Measure++;
 
            }
 
        }
 
    }
 
    DNA[Index].Measure = Measure;
 
}
 
//DNA排序
 
void SortDNA()
 
{
 
    int i,j;
 
    int MinIndex;
 
    _stru_DNA Tmp;
 
    for (i=0; i<m-1; i++)
 
    {
 
        MinIndex = i;
 
        for (j=i+1; j<m; j++)
 
        {
 
            if (DNA[j].Measure < DNA[MinIndex].Measure)
 
            {
 
                MinIndex = j;
 
            }
 
        }
 
        Tmp = DNA[i];
 
        DNA[i] = DNA[MinIndex];
 
        DNA[MinIndex] = Tmp;
 
    }
 
}