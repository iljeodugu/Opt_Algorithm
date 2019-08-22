#include <iostream>

using namespace std;

long long int d[101][10];

int main(void)
{
	int num;
	
	cin >> num;

	for (int i = 0; i < 10; i++)
	{
		d[1][i] = 1;
	}

	for (int i = 2; i <= num; i++)
	{
		d[i][0] = d[i-1][1] % 1000000000;
		for (int j = 1; j < 9; j++)
		{
			d[i][j] = (d[i - 1][j - 1] % 1000000000) + (d[i - 1][j + 1] % 1000000000);
		}
		d[i][9] = d[i - 1][8] % 1000000000;
	}

	long long int sum_val = 0;
	for (int i = 1; i < 10; i++)
	{
		sum_val += d[num][i];
		sum_val %= 1000000000;
	}

	cout << sum_val << endl;

	return 0;
}