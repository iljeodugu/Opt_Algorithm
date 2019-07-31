#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct My_data
{
	int height;
	int position;
}my_data;

bool compare_my_data(my_data a, my_data b)
{
	if (a.position <= b.position)
		return true;
	else
		return false;
}

int main(void)
{
	int fill_count;
	int count_arr[1001] = { 0 };
	vector<my_data> data_arr;

	cin >> fill_count;
	stack<int> order_data;

	for (int fill_count_i = 0; fill_count_i < fill_count; fill_count_i++)
	{
		my_data temp_data;
		cin >> temp_data.position;
		cin >> temp_data.height;
		data_arr.push_back(temp_data);
		count_arr[temp_data.height] ++;
	}
	for (int i = 0; i < 1001 ; i++)
	{
		if (count_arr[i] != 0)
			order_data.push(i);
	}

	sort(data_arr.begin(), data_arr.end(), compare_my_data);

	long result = data_arr[0].height;
	int now_height = data_arr[0].height;
	int now_position = data_arr[0].position;
	int max_heigth = data_arr[0].height;
	for (my_data temp_data : data_arr)
	{
		if (now_height == temp_data.height)
		{
			result += now_height * (temp_data.position - now_position - 1);
			result += temp_data.height;

			now_position = temp_data.position;
			count_arr[now_height]--;
			if (count_arr[now_height] == 0 && order_data.top() == now_height)
			{
				while ( count_arr[order_data.top()] == 0)
				{
					order_data.pop();
					if (order_data.empty())
						break;
					now_height = order_data.top();
				}
			}
		}
		else if (now_height < temp_data.height)
		{
			result += now_height * (temp_data.position - now_position - 1);
			result += temp_data.height;

			count_arr[temp_data.height]--;
			now_height = temp_data.height;
			if (count_arr[temp_data.height] == 0 && order_data.top() == temp_data.height)
			{
				while ( !order_data.empty() && count_arr[order_data.top()] == 0)
				{
					order_data.pop();
					if (order_data.empty())
						break;
					now_height = order_data.top();
				}
			}
			now_position = temp_data.position;
		}
		else if (now_height > temp_data.height)
		{
			result += now_height * (temp_data.position - now_position - 1);
			result += now_height;
			count_arr[temp_data.height] --;

			now_position = temp_data.position;
		}
	}

	cout << result << endl;

	return 0;
}