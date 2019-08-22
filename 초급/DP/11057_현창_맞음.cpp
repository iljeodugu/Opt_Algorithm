#include <iostream>

using namespace std;

int main(void)
{
	int num;

	cin >> num;

	long long int d[1001][10];

	for (int i = 0; i < 10; i++)
		d[1][i] = 1;

	for (int i = 2; i <= num; i++)
	{
		long long int sum = 0;

		for (int j = 9; j >= 0 ; j--)
		{
			sum += d[i - 1][j];
			sum %= 10007;
			d[i][j] = sum;
		}
	}

	long long int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		sum += d[num][i];
	}

	cout << sum % 10007<< endl;

	return 0;
}