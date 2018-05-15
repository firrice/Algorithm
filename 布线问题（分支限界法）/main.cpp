//ʹ�÷�֧�޽編�����������
//====================================================
#include <iostream>
#include "LinkedQueue.h"
//#include <queue>  

using namespace std;

int n, m;  //��������n * m��С

class Position{
	public:
		int row;
		int col;
};

bool FindPath(int ** grid , Position start, Position finish, int &PathLen, Position * &path)
{
	//�������ʼλ��start��Ŀ��λ��finish����̲���·��
	//�ҵ���̲���·���򷵻�true�����򷵻�flase
	if ((start.row == finish.row) && (start.col == finish.col))
	{
		PathLen = 0;
		return true;
	}
	//���÷������С�Χǽ��
	for (int i = 0; i < m + 1; i++)
	{
		grid[0][i] = grid[n + 1][i] = 1;  //�����͵ײ�
	}
	for (int i = 0; i < n + 1; i++)
	{
		grid[i][0] = grid[i][m + 1] = 1;  //���������
	}
	//��ʼ�����λ��
	Position offset[4];
	offset[0].row = 0; offset[0].col = 1;  //��
 	offset[1].row = 1; offset[1].col = 0;  //��
	offset[2].row = 0; offset[2].col = -1;  //��
	offset[3].row = -1; offset[3].col = 0;  //��
	int neigh_num = 4;  //���ڷ�����
	Position here, nbr;
	here.row = start.row;
	here.col = start.col;
	grid[start.row][start.col] = 2;
	//������п��Ե���ķ���λ��

	LinkedQueue<Position> Q(n * m + 1);  //����
	//queue<Position> Q();  //����

	//��ǿɵ�������ڷ���
	do {
		for (int i = 0; i < neigh_num; i++)
		{
			nbr.row = here.row + offset[i].row;
			nbr.col = here.col + offset[i].col;
			if (grid[nbr.row][nbr.col] == 0)  //�÷���δ������
			{
				grid[nbr.row][nbr.col] = grid[here.row][here.col] + 1;
				if ((nbr.row == finish.row) && (nbr.col == finish.col))  //��ɲ���
					break;
				Q.Add(nbr);  //ѹ����г�Ϊ��ڵ�
			}
		}
		//�Ƿ񵽴�Ŀ��λ��finish?
		if ((nbr.row == finish.row) && (nbr.col == finish.col))  //��ɲ���,�Ƿ�Ҫ����һ����
			break;
		//��ڵ�����Ƿ�ǿ�
		if (Q.IsEmpty())  //�޽�
			return false;
		Q.Delete(here);  //ȡ��һ����չ�ڵ�
	} while (true);
	//������̲���·��
	PathLen = grid[finish.row][finish.col] - 2;
	path = new Position[PathLen];
	//��Ŀ��λ��finish��ʼ����ʼλ�û���
	here = finish;
	for (int j = PathLen - 1; j >= 0; j--)
	{
		path[j] = here;
		//��ǰ��λ��
		for (int i = 0; i < neigh_num; i++)
		{
			nbr.row = here.row + offset[i].row;
			nbr.col = here.col + offset[i].col;
			if (grid[nbr.row][nbr.col] == j + 2)
				break;
		}
		here = nbr;  //��ǰ�ƶ�
	}
	return true;
}

int main(void)
{
	Position start, finish;  //��ʼλ�ú�Ŀ��λ��
	int PathLen;  //���·���ĳ���
	Position *path;  //��¼�����·��
	cout << "�����벼���̵Ĵ�С��n * m ��� " << endl;
	cin >> n >> m;
	cout << "�����뿪ʼλ��(x , y) :" << endl;
	cin >> start.col >> start.row;
	cout << "���������λ��(x , y) :" << endl;
	cin >> finish.col >> finish.row;

	int ** grid = new int*[n + 2];
	for (int i = 0; i < n + 2; i++)
	{
		grid[i] = new int[m + 2];
	}
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < m + 2; j++)
		{
			grid[i][j] = 0;
		}
	}

	FindPath(grid, start, finish, PathLen, path);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << grid[i][j] << "  ";
		}
		cout << endl;
	}

	cout << "���·���ǣ� " << endl;
	cout << PathLen << endl;

	system("pause");
	return 0;
}