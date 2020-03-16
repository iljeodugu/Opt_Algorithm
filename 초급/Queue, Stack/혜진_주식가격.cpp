#include <iostream>
#include <vector>

using namespace std;

int cnt;

int main()
{
	//input
	vector<int> prices{ 1, 2, 3, 2, 3 };
	
	//process
	vector<int> sol;
	
	for (int i = 0; i < prices.size()-1; i++)
	{
		cnt = 0;
		for (int j = i + 1; j < prices.size(); j++)
		{
			if (prices[i] <= prices[j])
			{
				cnt++;
			}
			else
			{
				cnt++;
				break;
			}
		}
		sol.push_back(cnt);
	}

	sol.push_back(0);
	//output
	for (int i = 0; i < prices.size(); i++)
	{
		cout << sol[i] << " ";
	}cout << endl;
}