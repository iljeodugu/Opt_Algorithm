#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	//input
	vector<int> process{ 93,30,55 };
	vector<int> speeds{ 1,30,5 };
	queue<int> q_pro;
	queue<int> q_spd;
	vector<int> answer;

	//process
	for (int i = 0; i < process.size(); i++)
	{
		q_pro.push(process[i]);
		q_spd.push(speeds[i]);
	}

	int day = 1;
	while (!q_pro.empty())
	{
		int left = q_pro.size();
		int cnt = 0;
		for (int i = 0; i < left; i++)
		{
			if (q_pro.front() + (day*q_spd.front()) >= 100)
			{
				cnt++;
				q_pro.pop();
				q_spd.pop();
			}
			
		}
		if (cnt != 0) answer.push_back(cnt);
		day++;
		
	}
	//output
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}

	return 0;
}