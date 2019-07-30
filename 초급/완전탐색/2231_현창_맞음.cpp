#include <iostream>
using namespace std;

int main(void)
{
	int input_num;
	cin >> input_num;

	bool is_result = false;
	for (int i = 1; i < input_num; i++)
	{
		int bun_sum = 0;
		int temp_num = i;
		while (temp_num != 0)
		{
			bun_sum += temp_num % 10;
			temp_num /= 10;
		}

		bun_sum += i;
		if (bun_sum == input_num)
		{
			is_result = true;
			cout << i << endl;
			break;
		}
	}
	if (!is_result)
		cout << "0" << endl;
}