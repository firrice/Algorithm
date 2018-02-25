//2018_02_24
//使用分治法求解二维平面最接近点问题
//=============================================================
#include <iostream>
#include <math.h>
#include <algorithm>
#include "dataset.h"  //数据结构实现放在这个头文件中
#include "func.h"  //函数声明的头文件

using namespace std;

int main(void)
{
	point p[10];  //设定点的集合
	int n;
	double minDist;
	cout << "输入点的个数：\n";
	cin >> n;
	cout << "输入点集：(x , y) \n";
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	sort(p, p + n, comp_x);  //对输入的点先进行排序
	point index[2];
	minDist = closest_distance(p, 0, n - 1, index);
	cout << "最小距离点对为：(" << index[0].x << "," << index[0].y << "),(" << index[1].x << "," << index[1].y << ")";
	cout << "最小距离为：\n" << minDist;
	system("pause");
	return 0;
}