#include <iostream>

using namespace std;

int map[20][20];
int order_arr[1000];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int dice[4][3] = { 0 };

int main(void)
{
	int height, width;

	cin >> height >> width;

	int x, y;

	cin >> x >> y;

	int order_count;

	cin >> order_count;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < order_count; i++)
	{
		cin >> order_arr[i];
	}

	int now_x = x, now_y = y;

	for (int i = 0; i < order_count; i++)
	{
		now_x += dx[order_arr[i] - 1];
		now_y += dy[order_arr[i] - 1];

		if (now_x < 0 || now_y < 0 || now_x >= height || now_y >= width)
		{
			now_x -= dx[order_arr[i] - 1];
			now_y -= dy[order_arr[i] - 1];
			continue;
		}
		if (order_arr[i] == 1)
		{
			int temp = dice[1][1];
			dice[1][1] = dice[1][0];
			dice[1][0] = dice[3][1];
			dice[3][1] = dice[1][2];
			dice[1][2] = temp;
		}
		else if (order_arr[i] == 2)
		{
			int temp = dice[1][1];
			dice[1][1] = dice[1][2];
			dice[1][2] = dice[3][1];
			dice[3][1] = dice[1][0];
			dice[1][0] = temp;
		}
		else if (order_arr[i] == 3)
		{
			int temp = dice[1][1];
			dice[1][1] = dice[2][1];
			dice[2][1] = dice[3][1];
			dice[3][1] = dice[0][1];
			dice[0][1] = temp;
		}
		else if (order_arr[i] == 4)
		{
			int temp = dice[1][1];
			dice[1][1] = dice[0][1];
			dice[0][1] = dice[3][1];
			dice[3][1] = dice[2][1];
			dice[2][1] = temp;
		}

		if (map[now_x][now_y] == 0)
		{
			map[now_x][now_y] = dice[3][1];
		}
		else
		{
			dice[3][1] = map[now_x][now_y];
			map[now_x][now_y] = 0;
		}

		cout << dice[1][1] << endl;
	}
}