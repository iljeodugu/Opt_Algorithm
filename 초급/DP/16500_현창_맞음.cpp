#include <iostream>
#include <string>
#include <queue>
using namespace std;

string sub_str[100];
bool len_check[100][100];
int len_arr[100];

int main(void)
{
	string main_str;
	cin >> main_str;

	int str_count;
	cin >> str_count;

	bool check[100];

	for (int i = 0; i < str_count; i++)
	{
		cin >> sub_str[i];
		len_arr[i] = sub_str[i].size();
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			len_check[i][j] = false;
		}
	}

	for (int i = 0; i < main_str.size(); i++)
	{
		for (int j = 0; j < str_count; j++)
		{
			bool check = true;

			if (i + sub_str[j].size() <= main_str.size())
			{
				for (int k = 0; k < sub_str[j].size() ; k++)
				{
					if (main_str[i + k] != sub_str[j][k])
					{
						check = false;
						break;
					}
				}
				if (check)
					len_check[j][i] = true;
			}
		}
	}

	queue<int> str_q;
	str_q.push(0);

	bool is_sol = false;
	while (!str_q.empty())
	{
		int temp = str_q.front();
		str_q.pop();

		if (temp == main_str.size())
		{
			is_sol = true;
			break;
		}
		for (int i = 0; i < str_count; i++)
		{
			if (len_check[i][temp])
			{
				str_q.push(temp + len_arr[i]);
			}
		}
	}
	cout << is_sol << endl;

	return 0;
}