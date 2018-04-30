//2018_04_28
//使用回朔法解决装载问题
//=============================================================================
#include <iostream>
#include "load.h"

using namespace std;


int main(void)
{
	int n = 0;  //集装箱数量；
	int c = 0;  //第一艘船的载重重量
	int bestx[4];  //最优解
	int *w = new int[n + 1];  //集装箱重量数组
	int m = 0;  //最优载重量
	cout << "请输入集装箱数量: ";
	cin >> n;
	cout << endl;
	cout << "请输入第一艘船的载重重量: ";
	cin >> c;
	cout << endl;
	cout << "请输入集装箱的重量数组 ：";
	for (int i = 0; i <= n; i++)
	{
		cin >> w[i];
	}

	m = Maxloading(w, c, n, bestx);  //求解问题

	cout << "输出最优解如下：" << endl;
	for (int i = 1; i < n; i++)
	{
		cout << bestx[i] << " ";
	}
	cout << "请输出最优载重量： " << endl;
	cout << m;

	system("pause");
	return 0;
}
