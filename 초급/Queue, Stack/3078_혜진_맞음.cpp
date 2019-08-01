#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	// 친구조건 : 등수 차이가 K 이하
	// 좋은 친구 조건 : 친구중에서 이름 길이가 같음

	/* input */
	long count = 0;
	int N, K; // number of students, limit of gap
	string name;
	queue<int> length[21]; //각 이름 길이에 해당하는 자리에 등수를 저장할 큐

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> name;
		int name_len = name.length();

    /* process */
		if (!length[name_len].empty())
		{
			while ((!length[name_len].empty()) && i - length[name_len].front() > K)
			{
				length[name_len].pop();
			}
			count += length[name_len].size();
		}
		length[name_len].push(i);
	}

	/* output */
	cout << count;
}