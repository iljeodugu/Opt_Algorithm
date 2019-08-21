#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	int d[10001];
	for (int i = 0; i < 10001; i++)
		d[i] = -1;

	int coin[101];

	vector<int> temp_coin;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp > k)
		{
			i--;
			n--;
			continue;
		}
		temp_coin.push_back(temp);
	}

	sort(temp_coin.begin(), temp_coin.end());
	temp_coin.erase(unique(temp_coin.begin(), temp_coin.end()), temp_coin.end());

	int i = 0;
	for (int temp : temp_coin)
	{
		coin[i++] = temp;
	}
	n = i;

	for (int i = 0; i < n; i++)
	{
		d[coin[i]] = 1;
	}

	for (int i = 1; i <= k; i++)
	{
		if (d[i] != -1)
		{
			continue;
		}
		int min_val = 2000000;
		for (int j = 0; j < n; j++)
		{
			int index = i - coin[j];
			if (index >= 0 && index <= 10001 && d[index] != -1)
			{
				if (d[index] + 1 < min_val)
					min_val = d[index] + 1;
			}
		}
		if (min_val != 2000000)
			d[i] = min_val;
		else
			d[i] = -1;
	}

	cout << d[k] << endl;

	return 0;
}