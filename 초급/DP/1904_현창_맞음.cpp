#include <iostream>

using namespace std;

int d[1000001];

int main(void)
{
	int num;

	cin >> num;

	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= num; i++)
	{
		d[i] = d[i - 2] + d[i - 1];
		d[i] %= 15746;
	}

	cout << d[num]<< endl;

	return 0;
}