#include <iostream>

using namespace std;

long long int d[91][2];

int main(void)
{
	int num;

	cin >> num;
	d[1][0] = 1;
	d[1][1] = 1;
	for (int i = 2; i <= num; i++)
	{
		d[i][0] = d[i - 1][1] + d[i - 1][0];
		d[i][1] = d[i - 1][0];
	}
	cout << d[num][1] << endl;

	return 0;
}