//����
//=======================================================================

#include <iostream>

using namespace std;

struct MaxHeap
{
	int *heap;  //����Ԫ�صĴ�ſռ䣬�±��1��ʼ���Ԫ�أ��±�0�����ʱ����
	int HeapSize;  //����Ԫ�صĸ���
	int MaxSize;  //�������Ԫ�ؿռ�Ĵ�С
};

//��ʼ������
void MaxHeapint(MaxHeap &H)  
{
	for (int i = H.HeapSize / 2; i > 0; i--)
	{
		H.heap[0] = H.heap[i];
		int son = i * 2;
		while (son <= H.HeapSize)
		{
			if (son < H.HeapSize && H.heap[son] < H.heap[son + 1])
				son++;
			if (H.heap[son] < H.heap[0])
				break;
			else
			{
				H.heap[son / 2] = H.heap[son];
				son *= 2;
			}
		}
		H.heap[son / 2] = H.heap[0];
	}
}

//�����в���ڵ�
//˼�룺���ڶѵ�������һ���ڵ㣬Ȼ�����Ŷ���������
void MaxHeapInsert(MaxHeap &H, int x)
{
	if (H.HeapSize == H.MaxSize)
		return;
	int i = ++H.HeapSize;
	while (i != 1 && x > H.heap[i / 2])
	{
		H.heap[i] = H.heap[i / 2];
		i = i / 2;
	}
	H.heap[i] = x;
}

//���ѶѶ��ڵ�ɾ��
//˼�룺�����������Ľڵ��ᵽ����㣬Ȼ��ɾ�����ֵ��Ȼ���ٰ��µĸ��ڵ�ŵ����ʵ�λ�á�
void MaxHeapDelete(MaxHeap &H , int &top)
{
	int x;
	if (H.HeapSize == 0)
		return;
	top = H.heap[1];
	H.heap[0] = H.heap[H.HeapSize--];
	int i = 1, son = i * 2;
	while (son <= H.HeapSize)
	{
		if (son < H.HeapSize && H.heap[son] < H.heap[son + 1])
			son++;
		if (H.heap[0] >= H.heap[son])
			break;
		H.heap[i] = H.heap[son];
		i = son;
		son = son * 2;
	}
	H.heap[i] = H.heap[0];
	return;
}

int main(void)
{
	int top;
	int &top_1 = top;
	MaxHeap H;
	cout << "���������ݵ�size: " << endl;
	cin >> H.HeapSize;
	H.heap = new int(H.HeapSize + 1);
	cout << "�밴����ȫ�������������ݣ�" << endl;
	for (int i = 0; i <= H.HeapSize; i++)
	{
		cin >> H.heap[i];  //��������Ĭ��H.heap[0]Ϊ��ʱ���ݣ���Ϊ0
	}
	
	MaxHeapint(H);  //��������ת��Ϊ����
	MaxHeapInsert(H, 3);
	MaxHeapDelete(H, top);

	for (int i = 1; i <= H.HeapSize; i++)
	{
		cout << H.heap[i] << "  ";
	}
	cout << endl << top;
	system("pause");
}