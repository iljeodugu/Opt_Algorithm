#include <iostream>
#include <algorithm>
using namespace std;

int data_arr[100000][2];
int d[100000][3];

int main(void)
{
	int test_case_num;

	cin >> test_case_num;

	for (int test_case_i = 0; test_case_i < test_case_num; test_case_i++)
	{
		int sticker_num;

		cin >> sticker_num;

		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < sticker_num; i++)
			{
				cin >> data_arr[i][j];
			}
		}
		d[0][0] = 0;
		d[0][1] = data_arr[0][0];
		d[0][2] = data_arr[0][1];

		for (int i = 1; i < sticker_num; i++)
		{
			d[i][0] = max(d[i - 1][0], max(d[i-1][1], d[i - 1][2]));
			d[i][1] = max(d[i - 1][0] + data_arr[i][0], d[i - 1][2] + data_arr[i][0]);
			d[i][2] = max(d[i - 1][0] + data_arr[i][1], d[i - 1][1] + data_arr[i][1]);
		}

		cout << max(d[sticker_num - 1][0], max(d[sticker_num - 1][1], d[sticker_num - 1][2])) << endl;
	}

	return 0;
}