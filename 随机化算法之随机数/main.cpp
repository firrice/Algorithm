//�����
//main.cpp
//==============================================
#include <iostream>
#include <iomanip>
#include "Random.hpp"

using namespace std;

int TossCoins(int numberCoins)
{
	//�����Ӳ��
	static RandomNumber coinToss(0);
	int tosses = 0;
	for (int i = 0; i < numberCoins; i++)
	{
		tosses += coinToss.Random(2);
	}
	return tosses;
}

int main(void)
{
	//ģ�������Ӳ���¼�
	const int NCOINS = 10;
	const long NTOSSES = 50000L;
	//heads[i]�ǵõ�i������Ĵ���
	long heads[NCOINS + 1];
	int position;
	//��ʼ������heads
	for (int i = 0; i < NCOINS + 1; i++)
	{
		heads[i] = 0;
	}
	//�ظ�50000������
	for (int j = 0; j < NTOSSES; j++)
	{
		heads[TossCoins(NCOINS)] ++;
	}
	//���Ƶ��ͼ
	for (int i = 0; i < NCOINS; i++)
	{
		position = int(float(heads[i]) / NTOSSES * 72);
		cout << setw(6) << i << " ";
		for (int j = 0; j < position - 1; j++)
		{
			cout << " ";
		}
		cout << "*" << endl;
	}

	system("pause");
}