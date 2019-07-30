#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int small_man[9];

	for (int i = 0; i < 9; i++)
	{
		cin >> small_man[i];
	}

	vector<int> result;
	bool end_bool = false;
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == j)
				continue;

			int sum = 0;
			for (int k = 0; k < 9; k++)
			{
				if (k == i || k == j)
					continue;
				sum += small_man[k];
			}
			if (sum == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j)
						continue;
					result.push_back(small_man[k]);
				}
				end_bool = true;
				break;
			}
		}
		if (end_bool)
			break;
	}
	sort(result.begin(), result.end());

	for (int temp : result)
		cout << temp << endl;

	return 0;
}