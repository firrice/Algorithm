//2018_02_25
//循环赛日程问题
//==========================================
#include <iostream>
#include <vector>

using namespace std;
//实现函数
void Table(vector<vector<int>> &vec)
{
	if (vec.size() == 0)
		return;
	size_t s = vec.size();  //size_t的range一般大于int
	int k = 0;
	while (s = s >> 1)
	{
		k++;
	}
	vec[0][0] = 1;
	vec[0][1] = 2;
	vec[1][0] = 2;
	vec[1][1] = 1;

	for (int i = 2; i <= k; i++)
	{
		int length = 1 << i;
		int half = length >> 1;
		//左下角的子表中项为左上角子表对应项加half = 2^(i-1)
		for (int row = 0; row < half; row++)
		{
			for (int col = 0; col < half; col++)
			{
				vec[row + half][col] = vec[row][col] + half;
			}
		}
		//右上角的子表等于左下角子表
		for (int row = 0; row < half; row++)
		{
			for (int col = 0; col < half; col++)
			{
				vec[row][col + half] = vec[row + half][col];
			}
		}
		//右小角子表等于左上角子表
		for (int row = 0; row < half; row++)
		{
			for (int col = 0; col < half; col++)
			{
				vec[row + half][col + half] = vec[row][col];
			}
		}
	}
}
//主函数
int main(void)
{
	cout << "共有2 ^ k 个选手参加比赛 ， 输入k(k > 0)：" << endl;
	int k;
	do
	{
		cin >> k;
	} while ((k < 0) || (k > 31));
	int s = 1 << k;  //总共s个选手
	vector <vector <int> > vec(s, vector<int>(s, 0));  //初始化表格，初始值为0

	Table(vec);

	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}