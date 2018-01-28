#include "random_quick_sort.h"
#include <stdlib.h>

template<class Type>
void RandomQuickSort(Type a[], int p, int r)
{
	if (p < r)
	{
		int q = random_partition(a, p, r);
		RandomQuickSort(a, p, q - 1);
		RandomQuickSort(a, q + 1, r);
	}
}
//���������׼��
template <class Type>
int random_partition(Type a[], int p, int r)
{
	int i = rand() % (r - p) + p;
	Type b;
	b = a[p];
	a[p] = a[i];
	a[i] = b;
	return partition(a, p, r);
}

//���ݻ�׼Ԫ�ؽ�������
template <class Type>
int partition(Type a[], int p, int r)
{
	int i = p, j = r + 1;
	Type b;
	Type x = a[p];  //��a[p]��Ϊ��׼Ԫ��
	while (true)
	{
		while (a[++i] < x && i < r);
		while (a[--j] > x);
		if (i >= j)
		    break;
		b = a[j];
		a[j] = a[i];
		a[i] = b;
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}