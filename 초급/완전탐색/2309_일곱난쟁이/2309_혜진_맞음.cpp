#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int height_of_dwarf[9] = { 0 };
	int seven_dwarf[7] = { 0, };
	const int SPY = 0;
	/* input */
	for (int i = 0; i < 9; i++)
	{
		cin >> height_of_dwarf[i];
	}
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		sum += height_of_dwarf[i];
	}
	//cout << sum << endl;
	/* process */
	//2명의 합이 40이 되면 된당
	bool check = false;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int spy_sum = height_of_dwarf[i] + height_of_dwarf[j];
			if (spy_sum == (sum-100) && (i != j))
			{
				height_of_dwarf[i] = SPY;
				height_of_dwarf[j] = SPY;
				check = true;
				break;
			}
		}
		if (check)
			break;
	}
	sort(&height_of_dwarf[0], &height_of_dwarf[9]);

	/* output */
	for (int i = 2; i < 9; i++)
	{
		cout << height_of_dwarf[i] << endl;
	}
}