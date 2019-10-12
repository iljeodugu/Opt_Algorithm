//김혜진 화이팅
#include <iostream>
#include <queue>

using namespace std;

int matrix[1001][1001] = { 0, };
bool visited[1001][1001][2] = { false, };
int MAX_COL, MAX_ROW;

int drow[4] = { 0, 0, -1, 1 };
int dcol[4] = { 1, -1, 0, 0 };

struct MyStruct
{
	int row;
	int col;
	bool wreck;
	int length;
};

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
	int r, c, len;
	bool w;
	queue<MyStruct> q;
	
	MyStruct s = { 0,0,0,1 };
	q.push(s);
	
	visited[0][0][0] = true;

	while (!q.empty())
	{
		r = q.front().row;
		c = q.front().col;
		w = q.front().wreck;
		len = q.front().length;

		q.pop();

		//cout << r << ", " << c << ", " << w << " : " << len << endl;

		//MAX 도달 체크
		if (r == MAX_ROW - 1 && c == MAX_COL-1)
		{
			break;
		}

		//돌려돌려 돌림판
		for (int k = 0; k < 4; k++)
		{
			int newr = r + drow[k];
			int newc = c + dcol[k];

			//범위체크
			if (newr >= 0 && newc >= 0 && newr < MAX_ROW && newc < MAX_COL)
			{
				//벽인데 부시적 없는 벽
				if (matrix[newr][newc] == 1 && w == false)
				{
					visited[newr][newc][1] = true;
					MyStruct news = { newr,newc, w + 1, len + 1 };
					q.push(news);
				}
				// 부신적있는 길 & 부신적 없는 길
				else if (matrix[newr][newc] == 0 && visited[newr][newc][w] == false)
				{
					visited[newr][newc][w] = true;
					MyStruct news = { newr,newc, w, len + 1 };
					q.push(news);
				}
			}
		}
	}
	/* output */
	if (r == MAX_ROW - 1 && c == MAX_COL - 1)
	{
		cout << len << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
}