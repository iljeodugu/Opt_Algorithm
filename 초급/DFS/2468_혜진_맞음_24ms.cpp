#include <iostream>

using namespace std;

int N;
int max_height = 0;
int min_height = 101;
int result = 1;
int cnt;
int visited[101][101] = { 0, };
int area[101][101] = { 0, };
int safe[101][101] = { 0, };

//╩С, ©Л, го, аб
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void dfs(int x, int y, int height)
{
	visited[x][y] = height;

	for (int i = 0; i < 4; i++)
	{
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (newx >= 0 && newy >= 0 && newx < N && newy < N && visited[newx][newy] < height && area[newx][newy] > height )
		{
			dfs(newx, newy, height);
		}
	}
}
int main()
{
	/* input */
	cin >> N;

	for (int i=0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> area[i][j];

			if (area[i][j] > max_height)
				max_height = area[i][j];
			if (area[i][j] < min_height)
				min_height = area[i][j];
		}
	}

	/* process */
	for (int k = min_height; k < max_height + 1; k++)
	{
		cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j] < k && area[i][j] > k)
				{
					dfs(i, j, k);
					cnt++;
				}
				if (result < cnt) result = cnt;
			}
		}
	}
	/* output */
	cout << result << endl;
}