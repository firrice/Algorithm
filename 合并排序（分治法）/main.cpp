#include <iostream>
#include "merge_sort.h"

using namespace std;

#define Type int  //����Type����

int main()
{
	int size;  //�����С
	cout << "�����������С�� ";
	cin >> size;
	Type *a = new Type[size];  //����һ������
	cout << "������������Ԫ�أ�" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	MergeSort(a, size);  //�����������������
	cout << "����ϲ����������飺 " << endl;
	for (int j = 0; j < size; j++)
	{
		cout << a[j] << "  ";
	}
	system("pause");
	delete a;
	return 0;
}