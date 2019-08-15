#include <queue>
#include <iostream>
#include <vector>

using namespace std;

char map[10][10];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool check_map[10][10][10][10] = { false };

typedef struct my_data 
{
	int blue_x, blue_y;
	int red_x, red_y;
	int count;
}my_data;

int main(void)
{
	int n;
	int m;

	cin >> n;
	cin >> m;

	my_data start_data;
	start_data.count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'B')
			{
				start_data.blue_x = i;
				start_data.blue_y = j;
			}
			else if (map[i][j] == 'R')
			{
				start_data.red_x = i;
				start_data.red_y = j;
			}
		}
	}

	queue<my_data> map_queue;
	check_map[start_data.blue_x][start_data.blue_y][start_data.red_x][start_data.red_y] = true;
	map_queue.push(start_data);

	while (!map_queue.empty())
	{
		my_data temp_data = map_queue.front();
		map_queue.pop();
		if (temp_data.count >= 10)
		{
			cout << "-1" << endl;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			my_data pre_data = temp_data;
			bool is_useful = true;
			while (true)
			{
				int temp_x = pre_data.blue_x + dx[i];
				int temp_y = pre_data.blue_y + dy[i];
				int temp2_x = pre_data.red_x + dx[i];
				int temp2_y = pre_data.red_y + dy[i];

				//if (temp_x >= 0 && temp_y < n && temp_y >=0 && temp_y < m && temp2_x >= 0 && temp2_y < n && temp2_y >= 0 && temp2_y < m)
				
				if (map[temp_x][temp_y] == 'O')
				{
					is_useful = false;
					break;
				}
				if (map[temp2_x][temp2_y] == 'O')
				{
					int blue_x = temp_x;
					int blue_y = temp_y;

					while (true)
					{
						if (map[blue_x][blue_y] == 'O')
						{
							is_useful = false;
							break;
						}
						if (map[blue_x][blue_y] == '#')
						{
							break;
						}

						blue_x += dx[i];
						blue_y += dy[i];
					}
					if (is_useful)
					{
						cout << temp_data.count + 1 << endl;;
						return 0;
					}
					else
						break;
				}

				if (map[temp_x][temp_y] == '#')
				{
					temp_x -= dx[i];
					temp_y -= dy[i];
					if (temp2_x == temp_x && temp2_y == temp_y)
					{
						temp2_x -= dx[i];
						temp2_y -= dy[i];
					}
				}
				if (map[temp2_x][temp2_y] == '#')
				{
					temp2_x -= dx[i];
					temp2_y -= dy[i];
					if (temp2_x == temp_x && temp2_y == temp_y)
					{
						temp_x -= dx[i];
						temp_y -= dy[i];
					}
				}

				if (temp_x == pre_data.blue_x && temp_y == pre_data.blue_y && temp2_x == pre_data.red_x && temp2_y == pre_data.red_y)
				{
					break;
				}
				pre_data.blue_x = temp_x;
				pre_data.blue_y = temp_y;
				pre_data.red_x = temp2_x;
				pre_data.red_y = temp2_y;
			}
			if (is_useful && !check_map[pre_data.blue_x][pre_data.blue_y][pre_data.red_x][pre_data.red_y])
			{
				check_map[pre_data.blue_x][pre_data.blue_y][pre_data.red_x][pre_data.red_y] = true;
				pre_data.count++;
				map_queue.push(pre_data);
			}
		}
	}
	cout << "-1" << endl;

	return 0;
}