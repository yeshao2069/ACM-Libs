#include <iostream>
using namespace std;
 
int main()
{
	int matrix[101][101];//定义一个二维矩阵
 
	int Nline;//输入行总数
	cin >> Nline;
 
	for (int i = 1; i <= Nline; i++)//当前输入第i行
	{
		for (int j = 1; j <= i; j++)//第i行总共又i个数
		{
			cin >> matrix[i][j];
		}
	}
 
	//从下向上计算，最后matrix[1][1]中存放的就是计算结果
	for (int i = Nline-1; i > 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			matrix[i][j] = 
				(matrix[i][j] + matrix[i + 1][j] > matrix[i][j] + matrix[i + 1][j + 1]) ?
				(matrix[i][j] + matrix[i + 1][j]) : 
				(matrix[i][j] + matrix[i + 1][j + 1]);
		}
	}
	cout << matrix[1][1];
	return 0;
}