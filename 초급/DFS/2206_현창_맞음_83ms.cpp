#include<iostream>
#include<queue>
using namespace std;

char map[1000][1000];
bool broken_path[1000][1000] = { false };
bool no_broken_path[1000][1000] = { false };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

typedef struct my_data
{
	int x, y;
	bool broken_used;
	int move_count;
}my_data;

int main(void)
{
	int height;
	int width;

	cin >> height;
	cin >> width;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> map[i][j];
		}
	}

	my_data start_data;
	start_data.move_count = 0;
	start_data.x = 0;
	start_data.y = 0;
	start_data.broken_used = false;
	
	queue<my_data> map_queue;
	map_queue.push(start_data);
	no_broken_path[0][0] = true;
	bool is_can = false;
	int result = 0;
	while (!map_queue.empty())
	{
		my_data queue_data = map_queue.front();
		map_queue.pop();
		if (queue_data.x == height - 1 && queue_data.y == width - 1)
		{
			is_can = true;
			result = queue_data.move_count;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			my_data new_data;
			new_data.x = queue_data.x + dx[i];
			new_data.y = queue_data.y + dy[i];

			if (new_data.x >= 0 && new_data.x < height && new_data.y >= 0 && new_data.y < width)
			{
				if (map[new_data.x][new_data.y] == '1' && queue_data.broken_used)
					continue;
				else if (map[new_data.x][new_data.y] == '1' && !queue_data.broken_used && !broken_path[new_data.x][new_data.y])
				{
					new_data.broken_used = true;
					new_data.move_count = queue_data.move_count + 1;
					broken_path[new_data.x][new_data.y] = true;
					map_queue.push(new_data);
				}
				else if (map[new_data.x][new_data.y] == '0' && queue_data.broken_used && !broken_path[new_data.x][new_data.y])
				{
					new_data.broken_used = queue_data.broken_used;
					new_data.move_count = queue_data.move_count + 1;
					broken_path[new_data.x][new_data.y] = true;
					map_queue.push(new_data);
				}
				else if (map[new_data.x][new_data.y] == '0' && !queue_data.broken_used && !no_broken_path[new_data.x][new_data.y])
				{
					new_data.broken_used = queue_data.broken_used;
					new_data.move_count = queue_data.move_count + 1;
					no_broken_path[new_data.x][new_data.y] = true;
					map_queue.push(new_data);
				}
			}
		}
	}

	if (is_can)
		cout << result + 1 << endl;
	else
		cout << "-1" << endl;

}