#include <iostream>
#include "matrix_chain.h"

using namespace std;

int main(void)
{
	int matrix_num = 0;  //矩阵个数
	cout << "请输入矩阵个数：" << endl;
	cin >> matrix_num;

	int **m = new int *[matrix_num];
	for (int i = 0; i < matrix_num; i++)
		m[i] = new int[matrix_num];
	int **s = new int *[matrix_num];
	for (int i = 0; i < matrix_num; i++)
		s[i] = new int[matrix_num];
	int *p = new int[matrix_num];
	cout << "请输入各矩阵的列数：" << endl;
	for (int i = 0; i < matrix_num; i++)
	{
		cin >> p[i];
	}

	matrix_chain(p, matrix_num, m, s);
	traceback(0, matrix_num - 1, s);

	system("pause");
	return 1;
}