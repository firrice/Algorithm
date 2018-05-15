//使用分支限界法解决布线问题
//====================================================
#include <iostream>
#include "LinkedQueue.h"
//#include <queue>  

using namespace std;

int n, m;  //布线盘是n * m大小

class Position{
	public:
		int row;
		int col;
};

bool FindPath(int ** grid , Position start, Position finish, int &PathLen, Position * &path)
{
	//计算从起始位置start到目标位置finish的最短布线路径
	//找到最短布线路径则返回true，否则返回flase
	if ((start.row == finish.row) && (start.col == finish.col))
	{
		PathLen = 0;
		return true;
	}
	//设置方格阵列“围墙”
	for (int i = 0; i < m + 1; i++)
	{
		grid[0][i] = grid[n + 1][i] = 1;  //顶部和底部
	}
	for (int i = 0; i < n + 1; i++)
	{
		grid[i][0] = grid[i][m + 1] = 1;  //左翼和右翼
	}
	//初始化相对位移
	Position offset[4];
	offset[0].row = 0; offset[0].col = 1;  //右
 	offset[1].row = 1; offset[1].col = 0;  //下
	offset[2].row = 0; offset[2].col = -1;  //左
	offset[3].row = -1; offset[3].col = 0;  //上
	int neigh_num = 4;  //相邻方格数
	Position here, nbr;
	here.row = start.row;
	here.col = start.col;
	grid[start.row][start.col] = 2;
	//标记所有可以到达的方格位置

	LinkedQueue<Position> Q(n * m + 1);  //队列
	//queue<Position> Q();  //队列

	//标记可到达的相邻方格
	do {
		for (int i = 0; i < neigh_num; i++)
		{
			nbr.row = here.row + offset[i].row;
			nbr.col = here.col + offset[i].col;
			if (grid[nbr.row][nbr.col] == 0)  //该方格未被锁定
			{
				grid[nbr.row][nbr.col] = grid[here.row][here.col] + 1;
				if ((nbr.row == finish.row) && (nbr.col == finish.col))  //完成布线
					break;
				Q.Add(nbr);  //压入队列称为活节点
			}
		}
		//是否到达目标位置finish?
		if ((nbr.row == finish.row) && (nbr.col == finish.col))  //完成布线,是否要加这一步？
			break;
		//活节点队列是否非空
		if (Q.IsEmpty())  //无解
			return false;
		Q.Delete(here);  //取下一个扩展节点
	} while (true);
	//构造最短布线路径
	PathLen = grid[finish.row][finish.col] - 2;
	path = new Position[PathLen];
	//从目标位置finish开始向起始位置回溯
	here = finish;
	for (int j = PathLen - 1; j >= 0; j--)
	{
		path[j] = here;
		//找前驱位置
		for (int i = 0; i < neigh_num; i++)
		{
			nbr.row = here.row + offset[i].row;
			nbr.col = here.col + offset[i].col;
			if (grid[nbr.row][nbr.col] == j + 2)
				break;
		}
		here = nbr;  //向前移动
	}
	return true;
}

int main(void)
{
	Position start, finish;  //开始位置和目标位置
	int PathLen;  //最短路径的长度
	Position *path;  //记录的最短路径
	cout << "请输入布线盘的大小，n * m 规格： " << endl;
	cin >> n >> m;
	cout << "请输入开始位置(x , y) :" << endl;
	cin >> start.col >> start.row;
	cout << "请输入结束位置(x , y) :" << endl;
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

	cout << "最短路径是： " << endl;
	cout << PathLen << endl;

	system("pause");
	return 0;
}