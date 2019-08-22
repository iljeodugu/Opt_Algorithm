#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int d[100001];
int main(void)
{
	int num;

	cin >> num;

	d[1] = 1;
	for (int i = 1; i <= num; i++)
	{
		int min_val = 1000000;
		if (int(sqrt(i)) == sqrt(i))
		{
			min_val = 1;
		}
		for (int j = int(sqrt(i)); j > 0; j--)
		{
			min_val = min(d[i - j*j] + 1, min_val);
		}
		d[i] = min_val;
	}
	cout << d[num] << endl;

	return 0;
}