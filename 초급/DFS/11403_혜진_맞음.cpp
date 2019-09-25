#include <iostream>

using namespace std;

int arr[101][101] = { 0, };
int sol_arr[101][101] = { 0, };
bool visited[101] = { false, };
int num_of_point;
int start;

void dfs(int x)
{
	for (int i = 0; i < num_of_point; i++)
	{
		if ((visited[i] == false) && (arr[x][i] == 1))
		{
			sol_arr[start][i] = 1;
			visited[i] = true;
			dfs(i);
		}
	}
}

int main()
{
	/* input */
	cin >> num_of_point;

	for (int i = 0; i < num_of_point; i++)
	{
		for (int j = 0; j < num_of_point; j++)
		{
			cin >> arr[i][j];
		}
	}

	/* process */

	for (int i = 0; i < num_of_point; i++)
	{
		for (int j = 0; j < num_of_point; j++)
		{
			visited[j] = false;
		}
		start = i;
		dfs(i);
	}

	/* output */
	for (int i = 0; i < num_of_point; i++)
	{
		for (int j = 0; j < num_of_point; j++)
		{
			cout << sol_arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
