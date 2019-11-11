#include<cstdio>
using namespace std;
int main(void)
{
    int i;
    double Tmp, Sum;
    Sum = 0.0;
    for (i=0; i<12; i++)
    {
        scanf("%lf", &Tmp);
        Sum += Tmp;
    }
    printf("$%.2lf\n", Sum / 12);
    return 0;
}