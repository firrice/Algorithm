//������
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

template <class Type>
class LinkedQueue{

public:
	LinkedQueue(){};

	explicit LinkedQueue(int Capacity);  //��������
	bool IsEmpty();  //�ж��Ƿ��
	bool IsFull();  //�ж��Ƿ���
	bool Add(Type &cell);  //������м���Ԫ��
	bool Delete(Type &cell);  //ɾ�������е�Ԫ��

	~LinkedQueue();

private:
	Type cell;
	Type *ptr;  //�����е�Ԫ��ָ��
	int QueueLen;  //����Ԫ�ظ���
	int QueueCapacity;  //��������
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