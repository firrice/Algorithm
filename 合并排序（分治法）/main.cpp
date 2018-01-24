#include <iostream>
#include "merge_sort.h"

using namespace std;

#define Type int  //定义Type类型

int main()
{
	int size;  //数组大小
	cout << "请输入数组大小： ";
	cin >> size;
	Type *a = new Type[size];  //定义一个数组
	cout << "请输入数组中元素：" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	MergeSort(a, size);  //对数组进行升序排序
	cout << "输出合并排序后的数组： " << endl;
	for (int j = 0; j < size; j++)
	{
		cout << a[j] << "  ";
	}
	system("pause");
	delete a;
	return 0;
}