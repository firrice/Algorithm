//2018_04_28
//ʹ�û�˷�����װ������
//=============================================================================
#include <iostream>
#include "load.h"

using namespace std;


int main(void)
{
	int n = 0;  //��װ��������
	int c = 0;  //��һ�Ҵ�����������
	int bestx[4];  //���Ž�
	int *w = new int[n + 1];  //��װ����������
	int m = 0;  //����������
	cout << "�����뼯װ������: ";
	cin >> n;
	cout << endl;
	cout << "�������һ�Ҵ�����������: ";
	cin >> c;
	cout << endl;
	cout << "�����뼯װ����������� ��";
	for (int i = 0; i <= n; i++)
	{
		cin >> w[i];
	}

	m = Maxloading(w, c, n, bestx);  //�������

	cout << "������Ž����£�" << endl;
	for (int i = 1; i < n; i++)
	{
		cout << bestx[i] << " ";
	}
	cout << "����������������� " << endl;
	cout << m;

	system("pause");
	return 0;
}
