//merge_sort.templateʵ�ֲ���
#include "merge_sort.h"

template <class Type>
void MergeSort(Type *a , Type *v, int n)  //a������,v�Ǽ�ֵ
{
	Type *b = new Type[n];
	int s = 1;
	while (s < n)
	{
		MergePass(a, b, v , s, n);  //�ϲ�������b
		s += s;
		MergePass(b, a, v , s, n);  //�ϲ�������a
		s += s;
	}
	delete b;
}

template <class Type>
void MergePass(Type *x, Type *y, Type *v, int s, int n)
{
	int i = 0;
	while (i <= n - s * 2)
	{
		Merge(x, y ,v , i, i + s - 1, i + 2 * s - 1);  //�ϲ���СΪs����������������
		i += s * 2;
	}
	if (i + s < n)  //ʣ�µ�Ԫ������2s
		Merge(x, y, v, i, i + s - 1, n - 1);
	else for (int j = i; j <= n - 1; j++)
		y[j] = x[j];
}

template <class Type>
void Merge(Type *c, Type *d, Type *v , int l, int m, int r)  //�ϲ�c[l:m]��c[m+1:r]��d[l:r],����c[l:m]��c[m+1:r]�����Ѿ����������źõ�����
{
	int i = l, j = m + 1, k = l;
	while ((i <= m) && (j <= r))
	{
		if ((v[i] / c[i]) >= (v[j] / c[j]))  //����ʹ�ý�������
			d[k++] = c[i++];
		else
			d[k++] = c[j++];
	}
	if (i > m)
		for (int q = j; q <= r; q++)
			d[k++] = c[q];
	else for (int q = i; q <= m; q++)
		d[k++] = c[q];
}