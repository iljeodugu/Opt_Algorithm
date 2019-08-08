#include <iostream>
#include <queue>
using namespace std;

int map[100][100];
bool check_map[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

typedef struct point
{
	int x, y;
}point;

int main(void)
{
	int size;
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> map[i][j];
		}
	}
	
	int max_count = 0;
	for (int water_count = 1; water_count <= 100; water_count++)
	{
		queue<point> point_queue;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (map[i][j] < water_count)
				{
					check_map[i][j] = false;
				}
				else 
				{
					point temp_point = { i,j };
					point_queue.push(temp_point);
					check_map[i][j] = true;
				}
			}
		}

		int count = 0;
		while (!point_queue.empty())
		{
			point now_data = point_queue.front();
			point_queue.pop();
			if (check_map[now_data.x][now_data.y])
			{
				count++;
				check_map[now_data.x][now_data.y] = true;
				
				queue<point> temp_queue;
				temp_queue.push(now_data);

				while (!temp_queue.empty())
				{
					point temp_point = temp_queue.front();
					temp_queue.pop();

					for (int i = 0; i < 4; i++)
					{
						point new_data;
						new_data.x = temp_point.x + dx[i];
						new_data.y = temp_point.y + dy[i];

						if (new_data.x >= 0 && new_data.x < size && new_data.y >= 0 && new_data.y < size)
						{
							if (check_map[new_data.x][new_data.y])
							{
								temp_queue.push(new_data);
								check_map[new_data.x][new_data.y] = false;
							}
						}
					}
				}
			}
		}
		if (count > max_count)
			max_count = count;
	}

	cout << max_count << endl;

	return 0;
}