#include<iostream>
#include<queue>
#include<map>

#define NUM_MAX_NAME 20

using namespace std;

int main() 
{
	int N, K, length, last_length;
	long long cnt = 0;
	string name;
	cin >> N >> K;

	map<int, int> m;
	queue<int> q;

	for (int i = 0; i < N; i++) {
		cin >> name;
		length = name.length();
		cnt += m[length];
		m[length]++;
		q.push(length);

		if (i >= K) {
			m[q.front()]--;
			q.pop();
		}
	}

	cout << cnt;
	return 0;
}