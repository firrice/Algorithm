//2018_02_24
//ʹ�÷��η�����άƽ����ӽ�������
//=============================================================
#include <iostream>
#include <math.h>
#include <algorithm>
#include "dataset.h"  //���ݽṹʵ�ַ������ͷ�ļ���
#include "func.h"  //����������ͷ�ļ�

using namespace std;

int main(void)
{
	point p[10];  //�趨��ļ���
	int n;
	double minDist;
	cout << "�����ĸ�����\n";
	cin >> n;
	cout << "����㼯��(x , y) \n";
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	sort(p, p + n, comp_x);  //������ĵ��Ƚ�������
	point index[2];
	minDist = closest_distance(p, 0, n - 1, index);
	cout << "��С������Ϊ��(" << index[0].x << "," << index[0].y << "),(" << index[1].x << "," << index[1].y << ")";
	cout << "��С����Ϊ��\n" << minDist;
	system("pause");
	return 0;
}