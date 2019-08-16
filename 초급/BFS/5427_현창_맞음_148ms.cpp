#include <vector>
#include <queue>
#include <iostream>
using namespace std;

char map[1000][1000];
char check_map[1000][1000];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1 ,1 };

struct point {
	int x, y;
};

int main(void)
{
	int x, y;
	int test_count;

	cin >> test_count;

	for (int test_i = 0; test_i < test_count; test_i++)
	{
		cin >> y;
		cin >> x;

		queue<point> fire_queue;
		queue<point> human_queue;

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '*')
				{
					point temp = { i,j };
					fire_queue.push(temp);
				}
				if (map[i][j] == '@')
				{
					map[i][j] = '.';
					point temp = { i,j };
					human_queue.push(temp);
				}
			}
		}

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				check_map[i][j] = false;
			}
		}

		int count = 0;
		bool is_sol = false;
		while (true)
		{
			int fire_size = fire_queue.size();
			count += 1;

			for (int fire_i = 0; fire_i < fire_size; fire_i++)
			{
				point temp = fire_queue.front();
				fire_queue.pop();

				for (int i = 0; i < 4; i++)
				{
					int next_x = temp.x + dx[i];
					int next_y = temp.y + dy[i];

					if (next_x >= 0 && next_x < x && next_y >= 0 && next_y < y && map[next_x][next_y] == '.')
					{
						map[next_x][next_y] = '*';
						point fire = { next_x,next_y };

						fire_queue.push(fire);
					}
				}
			}

			int human_size = human_queue.size();

			for (int human_i = 0; human_i < human_size; human_i++)
			{
				point temp = human_queue.front();
				human_queue.pop();

				for (int i = 0; i < 4; i++)
				{
					int next_x = temp.x + dx[i];
					int next_y = temp.y + dy[i];

					if (next_x < 0 || next_x >= x || next_y < 0 || next_y >= y)
					{
						is_sol = true;
						human_i = human_size;
					}
					else if(map[next_x][next_y] == '.' && !check_map[next_x][next_y])
					{
						check_map[next_x][next_y] = true;
						point human= { next_x,next_y };

						human_queue.push(human);
					}
				}
			}

			if (human_queue.size() == 0)
				break;
			if (is_sol)
			{
				break;
			}
		}
		if (is_sol)
		{
			cout << count << endl;
		}
		else
		{
			cout << "IMPOSSIBLE" << endl;
		}

	}

	return 0;
}
