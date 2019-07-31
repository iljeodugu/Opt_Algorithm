#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
	int people_num;
	int order_num;
	cin >> people_num;
	cin >> order_num;

	queue<int> people_queue[19];

	for (int people_i = 0; people_i < people_num; people_i++)
	{
		string name;
		cin >> name;

		people_queue[(int)name.size() - 2].push(people_i);
	}

	long good_friend = 0;

	for (int queue_i = 0; queue_i < 19; queue_i++)
	{
		if (people_queue[queue_i].size() < 2)
			continue;
		queue<int> temp_queue;
		int temp = people_queue[queue_i].front();
		people_queue[queue_i].pop();
		temp_queue.push(temp);

		while (!people_queue[queue_i].empty())
		{
			temp = people_queue[queue_i].front();
			people_queue[queue_i].pop();

			while (!temp_queue.empty())
			{
				if ((temp - temp_queue.front()) <= order_num)
					break;
				temp_queue.pop();
			}
			good_friend += temp_queue.size();
			temp_queue.push(temp);
		}
	}

	cout << good_friend << endl;

	return 0;
}