#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int test_num;
	int data_arr[100000];

	cin >> test_num;

	for (int test_count_i = 0; test_count_i < test_num; test_count_i++)
	{
		string func_str;
		cin >> func_str;
		int data_len;
		cin >> data_len;

		char temp;
		cin >> temp;
		if (data_len != 0)
		{
			for (int input_i = 0; input_i < data_len; input_i++)
			{
				cin >> data_arr[input_i];
				cin >> temp;
			}
		}
		else
		{
			cin >> temp;
		}

		int d_count = 0;

		for (int i = 0; i < func_str.size(); i++)
		{
			if (func_str[i] == 'D')
				d_count++;
		}
		if (d_count > data_len)
		{
			cout << "error" << endl;
			continue;
		}

		int head_num = 0;
		int tail_num = data_len - 1;
		bool is_right = true;
		
		for (int i = 0; i < func_str.size(); i++)
		{
			if (func_str[i] == 'R')
			{
				is_right = !is_right;
			}
			else
			{
				if (is_right)
					head_num++;
				else
					tail_num--;
			}
		}

		if (is_right)
		{
			cout << "[";
			for (int i = head_num; i <= tail_num; i++)
			{
				cout << data_arr[i];
				if (i != tail_num)
					cout << ",";
			}
			cout << "]";
		}
		else
		{
			cout << "[";
			for (int i = tail_num; i >= head_num; i--)
			{
				cout << data_arr[i];
				if (i != head_num)
					cout << ",";
			}
			cout << "]";
		}
		cout << endl;

	}

	return 0;
}