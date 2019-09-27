#include<iostream>
#include<queue>

using namespace std;

int MAX_ROW, MAX_COL; 
int matrix[101][101] = {0, };
int length[101][101] = { 0, };
//int dx[] = { 0, 0, -1, 1}; 
//int dy[] = { -1, 1, 0, 0 }; 
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs()
{
	int x = 0; //row
	int y = 0; //col
	
	queue<pair<int, int>> q;
	q.push(pair<int, int>(y, x));
	length[0][0] = 1;

	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();

		if ((x == MAX_ROW - 1) && (y == MAX_COL - 1))
		{
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int newx = x + dx[i];
			int newy = y + dy[i];

			//cout << i << ": " << newx << ", " << newy << endl;

			if ((length[newx][newy] == false) && (newx >= 0) && (newy >= 0) && (newx < MAX_ROW) && (newy < MAX_COL) && (matrix[newx][newy] == 1))
			{
				length[newx][newy] = length[x][y] + 1;
				q.push(pair<int,int>(newy, newx));

				/*
				for (int row = 0; row < MAX_ROW; row++)
				{
					for (int col = 0; col < MAX_COL; col++)
					{
						cout << length[row][col] << " ";
					}
					cout << endl;
				}*/
			}
		}
	}
	/* output */
	cout << length[MAX_ROW-1][MAX_COL-1] << endl;
}
int main()
{
	/* input */
	cin >> MAX_ROW >> MAX_COL;
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			scanf_s("%1d", &matrix[row][col]);
		}
	}

	/* process */
	bfs();
}