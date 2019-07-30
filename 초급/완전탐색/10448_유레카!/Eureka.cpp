#include <iostream>

using namespace std;

int main()
{
	const int POSSIBLE = 1;
	const int IMPOSSIBLE = 0;

	int num_of_tc;
	int tc[1001] = { 0, };
	int is_possible[1001] = { IMPOSSIBLE, };
	int tri_number[46] = { 0, };

	/* input */
	cin >> num_of_tc;

	for (int i = 0; i < num_of_tc; i++)
	{
		cin >> tc[i];
	}

	/* process */
	for (int i = 1; i < 46; i++)
	{
		tri_number[i] = i * (i + 1) / 2;
	}

	int sum;

	for(int j = 1; j < 46; j++)
	{
		for (int k = 1; k < 46; k++) 
		{
			for (int l = 1; l < 46; l++)
			{
				sum = tri_number[j] + tri_number[k] + tri_number[l];
				if (sum >= 3 && sum <= 1000)
				{
					is_possible[sum] = POSSIBLE;
				}
			}
		}
	}

	/* output */
	for (int i = 0; i < num_of_tc; i++)
	{
		int n = tc[i];
		cout << is_possible[n] << endl;
	}
}