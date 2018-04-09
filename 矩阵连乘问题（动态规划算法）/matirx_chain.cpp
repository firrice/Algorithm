#include <iostream>
#include "matrix_chain.h"

using namespace std;

//利用动态规划算法获取最优值
void matrix_chain(int *p, int n, int **m, int **s)  //p:各个矩阵的列数，n：矩阵个数，m：m[i:j]矩阵i到j的相乘次数，s:对应的分开位置
{
	for (int i = 0; i < n; i++)
	{
		m[i][i] = 0;
	}
	for (int r = 2; r <= n; r++)
	{
		for (int i = 0; i < n - r + 1; i++)
		{
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}

//利用s[i][j]获取最优解
void traceback(int i, int j, int **s)
{
	if (i == j)
		return;
	traceback(i, s[i][j], s);
	traceback(s[i][j] + 1, j, s);
	cout << "Multiply A" << i << " , " << s[i][j];
	cout << "and A" << (s[i][j] + 1) << " , " << j << endl;
}