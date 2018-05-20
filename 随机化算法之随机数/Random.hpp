//随机数类
//Random.hpp
//=====================================================
#ifndef RANDOM_HPP
#define RANDOM_HPP

#include<ctime>

const unsigned long maxshort = 65536L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;

class RandomNumber{
private:
	//当前种子
	unsigned long randSeed;
public:
	RandomNumber(){};
	RandomNumber(unsigned long s = 0);  //构造函数,默认值0表示由系统自动产生种子
	unsigned short Random(unsigned long n);  //产生0:n-1之间的随机整数
	double fRandom(void);  //产生[0 , 1)之间的随机整数
};

RandomNumber::RandomNumber(unsigned long s)  //产生种子
{
	if (s == 0)
	{
		randSeed = time(0);  //使用系统时间产生随机种子
	}
	else
	{
		randSeed = s;
	}
}

unsigned short RandomNumber::Random(unsigned long n)  //产生 0:n-1之间的随机整数
{
	randSeed = multiplier * randSeed + adder;
	return(unsigned short)((randSeed >> 16) % n);
}

double RandomNumber::fRandom(void)  //产生[0 , 1)之间的随机数
{
	return Random(maxshort) / double(maxshort);
}

#endif