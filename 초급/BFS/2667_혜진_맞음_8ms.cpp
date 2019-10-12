#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[26][26] = { false, };
bool matrix[26][26];
int MAX_NUM;
int drow[4] = { -1, 1, 0, 0 };
int dcol[4] = { 0, 0, -1, 1 };

struct MyStruct
{
	int row;
	int col;
	int part;
};
int main()
{
	/* input */
	cin >> MAX_NUM;

	for (int row = 0; row < MAX_NUM; row++)
	{
		for (int col = 0; col < MAX_NUM; col++)
		{
			scanf_s("%1d", &matrix[row][col]);
		}
	}

	/* process */
	int r, c, p, len;
	vector<int> length;
	p = 0;

	for (int row = 0; row < MAX_NUM; row++)
	{
		for (int col = 0; col < MAX_NUM; col++)
		{
			if (matrix[row][col] == 1 && visited[row][col] == false)
			{
				p = p + 1;
				len = 0;
				queue<MyStruct> q;
				MyStruct s = { row, col, p};
				q.push(s);

				while (!q.empty())
				{
					r = q.front().row;
					c = q.front().col;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int newr = r + drow[k];
						int newc = c + dcol[k];

						/*가지치나 출력
						for (int i = 0; i < MAX_NUM; i++)
						{
							for (int j = 0; j < MAX_NUM; j++)
							{
								cout << visited[i][j] << " ";
							}cout << endl;
						}cout << endl;
						
						cout << r << ", " << c << ", " << endl;*/

						//범위체크
						if (newr >= 0 && newc >= 0 && newr < MAX_NUM && newr < MAX_NUM)
						{
							//bfs 가지 뻗칠때마다 len 올리기
							if (matrix[newr][newc] == 1 && visited[newr][newc] == false)
							{
								visited[newr][newc] = true;
								len = len + 1;
								MyStruct news = { newr, newc, p };
								q.push(news);
							}
							else
							{
								visited[newr][newc] = true; //확인했다는 거 체크
							}
						}
					}
				}
				if (len == 0)
				{
					length.push_back(1);
				}
				else
					length.push_back(len);
			}
			else
			{
				visited[row][col] = true;
			}
		}
	}
	
	/* output */
	cout << length.size() << endl;

	sort(length.begin(), length.end());

	for (int i = 0; i < length.size(); i++)
	{
		cout << length[i] << endl;
	}
}