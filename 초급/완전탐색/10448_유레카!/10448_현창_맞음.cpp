#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int test_count;

	cin >> test_count;
	vector<int> result;

	for (int test_count_i = 0; test_count_i < test_count; test_count_i++)
	{
		int test_num;
		cin >> test_num;

		vector<int> int_arr;

		int i = 1;
		while (true)
		{
			int temp = (i * (i + 1)) / 2;
			if (temp > test_num)
				break;
			i++;
			int_arr.push_back(temp);
		}
		bool check = false;
		for (int i = 0; i < int_arr.size() ; i++)
		{
			for (int j = 0; j < int_arr.size() ; j++)
			{
				for (int k = 0; k < int_arr.size() ; k++)
				{
					if (int_arr[i] + int_arr[k] + int_arr[j] == test_num)
					{
						check = true;
						break;
					}
				}
			}
		}
		if (check)
			result.push_back(1);
		else
			result.push_back(0);
	}

	for (int temp : result)
		cout << temp << endl;

	return 0;
}