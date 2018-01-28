#include<iostream>
#include "random_quick_sort.cpp"

using namespace std;

#define Type int  //定义数组元素类型

int main()
{
	int size;  //数组大小
	cout << "请输入数组大小： ";
	cin >> size;
	Type *a = new Type[size];  //定义一个数组
	cout << "请输入数组元素：  " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	RandomQuickSort(a, 0, size - 1);
	cout << "输出快速排序后的数组：" << endl;
	for (int j = 0; j < size; j++)
	{
		cout << a[j] << "   ";
	}
	system("pause");
	delete a;
	return 0;
}