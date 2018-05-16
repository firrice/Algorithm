//最大堆
//=======================================================================

#include <iostream>

using namespace std;

struct MaxHeap
{
	int *heap;  //数据元素的存放空间，下标从1开始存放元素，下标0存放临时数据
	int HeapSize;  //数据元素的个数
	int MaxSize;  //存放数据元素空间的大小
};

//初始化最大堆
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

//最大堆中插入节点
//思想：先在堆的最后添加一个节点，然后沿着堆树上升。
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

//最大堆堆顶节点删除
//思想：将堆树的最后的节点提到根结点，然后删除最大值，然后再把新的根节点放到合适的位置。
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
	cout << "请输入数据的size: " << endl;
	cin >> H.HeapSize;
	H.heap = new int(H.HeapSize + 1);
	cout << "请按照完全二叉树输入数据：" << endl;
	for (int i = 0; i <= H.HeapSize; i++)
	{
		cin >> H.heap[i];  //我们这里默认H.heap[0]为临时数据，设为0
	}
	
	MaxHeapint(H);  //将二叉树转换为最大堆
	MaxHeapInsert(H, 3);
	MaxHeapDelete(H, top);

	for (int i = 1; i <= H.HeapSize; i++)
	{
		cout << H.heap[i] << "  ";
	}
	cout << endl << top;
	system("pause");
}