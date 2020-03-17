#include <iostream>
#include <vector>

using namespace std;

int sol = 0; 

void dfs(vector<int> numbers, int target, int cnt, int sum)
{
	if (cnt == numbers.size())
	{
		if (sum == target)
		{
			sol++;
		}
		return;
	}
	//dfs 두개 돌리기
	dfs(numbers, target, cnt + 1, sum + numbers[cnt]);
	dfs(numbers, target, cnt + 1, sum - numbers[cnt]);

	cnt++;
}

int main()
{
	/* input */
	vector<int> numbers{ 1, 1, 1, 1, 1 };
	int target = 3;

	/* process */

	dfs(numbers, target, 0, 0);

	/* output */
	cout << sol << endl;
}