//随机数
//main.cpp
//==============================================
#include <iostream>
#include <iomanip>
#include "Random.hpp"

using namespace std;

int TossCoins(int numberCoins)
{
	//随机抛硬币
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
	//模拟随机抛硬币事件
	const int NCOINS = 10;
	const long NTOSSES = 50000L;
	//heads[i]是得到i次正面的次数
	long heads[NCOINS + 1];
	int position;
	//初始化数组heads
	for (int i = 0; i < NCOINS + 1; i++)
	{
		heads[i] = 0;
	}
	//重复50000次试验
	for (int j = 0; j < NTOSSES; j++)
	{
		heads[TossCoins(NCOINS)] ++;
	}
	//输出频率图
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