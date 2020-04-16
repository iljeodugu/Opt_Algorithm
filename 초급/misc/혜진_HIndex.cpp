#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b)
{
	return a > b;
}
int main()
{
	/*input*/
	vector<int> citations{ 3, 0, 6, 1, 5 };

	/*process*/
	int answer = 0;

	sort(citations.begin(), citations.end(), desc);

	for (int i = 0; i < citations.size(); i++)
	{
		if (answer > citations[i]) break;
		answer++;
	}

	/*output*/
	cout << answer << endl;
}