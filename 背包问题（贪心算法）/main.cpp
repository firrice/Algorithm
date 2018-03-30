//背包问题，使用贪心算法进行求解
//======================================================
#include <iostream>
#include "merge_sort.cpp"

using namespace std;


void init_data(float *v, float *w, float *x, int n)  //初始化数据
{
	cout << "请输入每类物体的价值：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cout << "请输入每类物体的重量： " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < n; i++)
		x[i] = 0;
}

void Knapsack(int n, float M, float *v, float *w, float *x)
//n是物体的种类数，M是背包容量，v是每类物体的价值，w是每类物体的重量,x是每类物体装入的份额，属于[0,1]
{
	int i = 0;
	float c = M;

	MergeSort(w , v , n);  //v[i]/w[i]是每一类物体的单位重量价值，然后对它们进行降序排序

	for (i = 0; i < n; i++)
	{
		if (w[i] > c)
			break;
		x[i] = 1;
		c -= w[i];
	}
	if (i < n)
		x[i] = c / w[i];
}

int main(void)
{
	float M = 0.0;  //背包容量
	cout << "请输入背包容量：  ";
	cin >> M;
	int n = 0;  //物体数量
	cout << "\n请输入物体数量 n :  ";
	cin >> n;
	float *v = new float[n];
	float *w = new float[n];
	float *x = new float[n];

	init_data(v, w, x, n);  //初始化数据
	Knapsack(n, M, v, w, x);

	cout << "排好序的w[i]:  " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << w[i] << "  ";
	}
	cout << "\n\n输出最后的决策x[i] : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << x[i] << "  ";
	}

	/*MergeSort(w, v, n);
	cout << "输出排好序的w[i] : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << w[i] << "  ";

	}*/
	system("pause");
	delete v , w , x;
	return 0;
}