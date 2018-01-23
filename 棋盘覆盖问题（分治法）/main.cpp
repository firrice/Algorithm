//���̸������⣬���η��㷨
#include <iostream>

using namespace std;

int tile = 1;  //L�͹��Ƶı��
const int Maxnum = 1 << 10;  //���̵ĳߴ��С���Ϊ2��10�η�
int Board[Maxnum][Maxnum];  //����һ����ά�����ʾ�������

void ChessBoard(int tr, int tc, int dr, int dc, int size)  //tr , tc�ֱ�������Ͻ��кź��к�,dr��dc�ֱ�������ⷽ����кź��к�,size�����̵ĳߴ�
{
	if (size == 1)
		return;
	int t = tile++;  //tile��ȫ�ֱ���������L�͹��Ƶı��
	int s = size / 2;
	//====================================================
	if (dr < tr + s && dc < tc + s)  //����
		ChessBoard(tr, tc, dr, dc, s);
	else
	{
		Board[tr + s - 1][tc + s - 1] = t;  //��t��L�͹���������½�
		ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);  //�ݹ�
	}
	//====================================================
	if (dr < tr + s && dc >= tc + s)  //����
		ChessBoard(tr, tc + s, dr, dc, s);
	else
	{
		Board[tr + s - 1][tc + s] = t;  //��t��L�͹���������½�
		ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);  //�ݹ�
	}
	//====================================================
	if (dr >= tr + s && dc < tc + s)  //����
		ChessBoard(tr + s , tc, dr, dc, s);
	else
	{
		Board[tr + s][tc + s - 1] = t;  //��t��L�͹���������Ͻ�
		ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);  //�ݹ�
	}
	//=====================================================
	if (dr >= tr + s && dc >= tc + s)  //���½�
		ChessBoard(tr + s, tc + s, dr, dc, s);
	else
	{
		Board[tr + s][tc + s] = t;  //��t��L�͹���������Ͻ�
		ChessBoard(tr + s, tc + s, tr + s, tc + s, s);  //�ݹ�
	}
}
int main(void)
{
	int x, y, size;  //x , y�ֱ�������ⷽ���λ��,size�������̵Ĵ�С
	cout << "���������ⷽ���λ��(x,y)�����̵ĳߴ��Сsize:  ";
	cin >> x >> y >> size;
	if (size == 0)
	{
		cout << "���̳ߴ����벻�Ϸ���" << endl;
		system("pause");
		return 1;
	}
	else if (x >= size || y >= size)
	{
		cout << "���ⷽ���λ�����벻�Ϸ�!" << endl;
		system("pause");
		return 1;
	}
	//���ⷽ�鸳ֵΪ0
	Board[x][y] = 0;
	//���η���������
	ChessBoard(0, 0, x, y, size);
	//�������
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << Board[i][j] << "\t";
		}
		cout << endl << endl << endl;
	}
	system("pause");
	return 0;
}
