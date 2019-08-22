#include<iostream>
#include<algorithm>
using namespace std;

int d[1001];
int p[10001];

int main(void)
{
	int card_num;

	cin >> card_num;

	for (int i = 1; i <= card_num; i++)
	{
		cin >> p[i];
	}

	d[1] = p[1];
	for (int i = 2; i <= card_num; i++)
	{
		int max_val = p[i];
		for (int j = 1; j < i; j++)
		{
			max_val = max(max_val, d[i - j] + p[j]);
		}
		d[i] = max_val;
	}

	cout << d[card_num] << endl;

	return 0;
}