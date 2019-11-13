#include<cstdio>
#include<cmath>
using namespace std;
const double PI = 3.1415926;
int main(void)
{
    double S;//被腐蚀陆地的总面积
    double r;//腐蚀陆地的半径
    int i,j;
    int T;
    double X,Y;//Fred的坐标
    double Distance;//Fred据坐标原点的距离
    scanf("%d", &T);
    for (i=1; i<=T; i++)
    {
        scanf("%lf%lf", &X, &Y);
        Distance = sqrt(X * X + Y * Y);
        S = 0.0;
        for (j=1; ; j++)
        {
            S += 50.0;
            r = sqrt(2 * S / PI);
            if (r >= Distance)
            {
                break;
            }
        }
        printf("Property %d: This property will begin eroding in year %d.\n", i, j);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}