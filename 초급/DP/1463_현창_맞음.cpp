#include <iostream>
#include <vector>
using namespace std;

int d[1000000];

int main(void)
{
	int num;

	cin >> num;

	d[1] = 0;
	d[2] = 1;
	d[3] = 1;

	for (int i = 4; i < num + 1; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 3 == 0)
		{
			if (d[i / 3] + 1 < d[i])
				d[i] = d[i / 3] + 1;
		}
		if (i % 2 == 0)
		{
			if (d[i / 2] + 1 < d[i])
				d[i] = d[i / 2] + 1;
		}
	}

	cout << d[num] << endl;
}