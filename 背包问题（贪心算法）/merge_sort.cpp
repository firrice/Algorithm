//merge_sort.template实现部分
#include "merge_sort.h"

template <class Type>
void MergeSort(Type *a , Type *v, int n)  //a是重量,v是价值
{
	Type *b = new Type[n];
	int s = 1;
	while (s < n)
	{
		MergePass(a, b, v , s, n);  //合并到数组b
		s += s;
		MergePass(b, a, v , s, n);  //合并到数组a
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
		Merge(x, y ,v , i, i + s - 1, i + 2 * s - 1);  //合并大小为s的相邻两段子数组
		i += s * 2;
	}
	if (i + s < n)  //剩下的元素少于2s
		Merge(x, y, v, i, i + s - 1, n - 1);
	else for (int j = i; j <= n - 1; j++)
		y[j] = x[j];
}

template <class Type>
void Merge(Type *c, Type *d, Type *v , int l, int m, int r)  //合并c[l:m]和c[m+1:r]到d[l:r],其中c[l:m]和c[m+1:r]都是已经经过升序排好的数组
{
	int i = l, j = m + 1, k = l;
	while ((i <= m) && (j <= r))
	{
		if ((v[i] / c[i]) >= (v[j] / c[j]))  //这里使用降序排序
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