//�������⣬ʹ��̰���㷨�������
//======================================================
#include <iostream>
#include "merge_sort.cpp"

using namespace std;


void init_data(float *v, float *w, float *x, int n)  //��ʼ������
{
	cout << "������ÿ������ļ�ֵ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cout << "������ÿ������������� " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < n; i++)
		x[i] = 0;
}

void Knapsack(int n, float M, float *v, float *w, float *x)
//n���������������M�Ǳ���������v��ÿ������ļ�ֵ��w��ÿ�����������,x��ÿ������װ��ķݶ����[0,1]
{
	int i = 0;
	float c = M;

	MergeSort(w , v , n);  //v[i]/w[i]��ÿһ������ĵ�λ������ֵ��Ȼ������ǽ��н�������

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
	float M = 0.0;  //��������
	cout << "�����뱳��������  ";
	cin >> M;
	int n = 0;  //��������
	cout << "\n�������������� n :  ";
	cin >> n;
	float *v = new float[n];
	float *w = new float[n];
	float *x = new float[n];

	init_data(v, w, x, n);  //��ʼ������
	Knapsack(n, M, v, w, x);

	cout << "�ź����w[i]:  " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << w[i] << "  ";
	}
	cout << "\n\n������ľ���x[i] : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << x[i] << "  ";
	}

	/*MergeSort(w, v, n);
	cout << "����ź����w[i] : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << w[i] << "  ";

	}*/
	system("pause");
	delete v , w , x;
	return 0;
}