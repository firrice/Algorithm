#include<iostream>
#include "random_quick_sort.cpp"

using namespace std;

#define Type int  //��������Ԫ������

int main()
{
	int size;  //�����С
	cout << "�����������С�� ";
	cin >> size;
	Type *a = new Type[size];  //����һ������
	cout << "����������Ԫ�أ�  " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	RandomQuickSort(a, 0, size - 1);
	cout << "����������������飺" << endl;
	for (int j = 0; j < size; j++)
	{
		cout << a[j] << "   ";
	}
	system("pause");
	delete a;
	return 0;
}