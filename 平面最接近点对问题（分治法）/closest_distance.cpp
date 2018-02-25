//����������ĺ���ʵ��
#include "dataset.h"
#include <math.h>
#include <algorithm>

using namespace std;

double Distance(point a, point b)  //�����������
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) - (a.y - b.y));
}

bool comp_x(point a, point b)  //��x�����б���
{
	return a.x < b.x;
}

bool comp_y(point a, point b)  //��y�����б���
{
	return a.y < b.y;
}
//����ʵ�֣�rec[]�洢��ӽ���ԣ�
double closest_distance(point s[], int low, int high, point rec[])
{
	double d1, d2, d3, d;
	int mid, i, j, index;
	double x1, y1, x2, y2; //��¼����ĵ��
	point *P = new point[high - low + 1];
	point temp_1[2], temp_2[2], temp_3[2];

	if (high - low == 1)  //������ʱ�����
	{
		rec[0].x = s[low].x; rec[0].y = s[low].y;
		rec[1].x = s[high].x; rec[1].y = s[high].y;
		return Distance(s[low], s[high]);
	}

	if (high - low == 2)  //������ʱ�����
	{
		d1 = Distance(s[low], s[low + 1]);
		d2 = Distance(s[low + 1], s[high]);
		d3 = Distance(s[low], s[high]);
		if ((d1 <= d2) && (d1 <= d3))  //�������ж��������ʱ���ڶ������û��Ҫʹ��(d2<d3)&&(d2<d1),��ϸ������ˣ�
		{
			rec[0].x = s[low].x; rec[0].y = s[low].y;
			rec[1].x = s[low + 1].x; rec[1].y = s[low + 1].y;
			return d1;
		}
		else if (d2 < d3)
		{
			rec[0].x = s[low + 1].x; rec[0].y = s[low + 1].y;
			rec[1].x = s[high].x; rec[1].y = s[high].y;
			return d2;
		}
		else
		{
			rec[0].x = s[low].x; rec[0].y = s[low].y;
			rec[1].x = s[high].x; rec[1].y = s[high].y;
			return d3;
		}
	}

	mid = (low + high) / 2;
	d1 = closest_distance(s, low, mid, rec);
	temp_1[0] = rec[0];
	temp_1[1] = rec[1];
	d2 = closest_distance(s, mid + 1 ,high, rec);
	temp_2[0] = rec[0];
	temp_2[1] = rec[1];
	if (d1 <= d2)
	{
		d = d1;
		rec[0] = temp_1[0];
		rec[1] = temp_1[1];
	}
	else
	{
		d = d2;
		rec[0] = temp_2[0];
		rec[1] = temp_2[1];
	}
	index = 0;
	for (i = mid; (i >= low) && ((s[mid].x - s[i].x) < d); i--)
	{
		P[index++] = s[i];  //�㼯��P1
	}
	for (i = mid + 1; (i <= high) && ((s[i].x - s[mid].x) < d); i++)
	{
		P[index++] = s[i];  //�㼯��P2
	}
	sort(P, P + index, comp_y);  //��������
	for (i = 0; i < index; i++)
	{
		for (j = i + 1; j < index; j++)
		{
			if ((P[j].y - P[i].y) >= d)
				break;
			else
			{
				d3 = Distance(P[i], P[j]);
				if (d3 < d)
				{
					rec[0].x = P[i].x; rec[0].y = P[i].y;
					rec[1].x = P[j].x; rec[1].y = P[j].y;
					d = d3;
				}
			}
		}
	}
	delete []P;  //ע�⶯̬�ڴ��ɾ����ʽ����ֹ�ڴ�й©
	return d;
}