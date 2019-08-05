#include <iostream>
#include <stdio.h>
using namespace std;

int result_matrix[100][100] = { 0 };
int matrix_size;
int matrix[100][100];
int start;
bool path_data[100];

void find_loot(int now)
{
	for (int i = 0; i < matrix_size; i++)
	{
		if (matrix[now][i] == 1 && !path_data[i] && i != now)
		{
			result_matrix[start][i] = 1;
			path_data[i] = true;
			find_loot(i);
		}
	}
}

int main(void)
{
	cin >> matrix_size;

	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
			path_data[j] = false;
		start = i;
		find_loot(i);
	}

	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			cout << result_matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
