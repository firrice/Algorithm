//队列类
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

template <class Type>
class LinkedQueue{

public:
	LinkedQueue(){};

	explicit LinkedQueue(int Capacity);  //创建队列
	bool IsEmpty();  //判断是否空
	bool IsFull();  //判断是否满
	bool Add(Type &cell);  //向队列中加入元素
	bool Delete(Type &cell);  //删除队列中的元素

	~LinkedQueue();

private:
	Type cell;
	Type *ptr;  //队列中的元素指针
	int QueueLen;  //队列元素个数
	int QueueCapacity;  //队列容量
	int Head;
	int Tail;

};


template <class Type>
LinkedQueue<Type>::~LinkedQueue()
{
	delete[]ptr;
	ptr = nullptr;
}

template <class Type>
LinkedQueue<Type>::LinkedQueue(int Capacity)
{
	QueueCapacity = Capacity;
	Head = 0;
	Tail = 0;
	QueueLen = 0;
	ptr = new Type[QueueCapacity];
}

template <class Type>
bool LinkedQueue<Type>::IsEmpty()
{
	if (QueueLen == 0)
		return true;
	else
		return false;
}

template <class Type>
bool LinkedQueue<Type>::IsFull()
{
	if (QueueLen == QueueCapacity)
		return true;
	else
		return false;
}

template <class Type>
bool LinkedQueue<Type>::Add(Type &cell)
{
	if (IsFull())
		return false;
	else
	{
		ptr[Tail] = cell;
		Tail++;
		QueueLen++;
		return true;
	}
}

template <class Type>
bool LinkedQueue<Type>::Delete(Type &cell)
{
	if (IsEmpty())
		return false;
	else
	{
		cell = ptr[Head];
		Head++;
		QueueLen--;
		return true;
	}
}

#endif