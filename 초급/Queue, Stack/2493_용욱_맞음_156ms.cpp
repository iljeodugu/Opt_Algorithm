#pragma warning(disable:4996)

#include<iostream>
#include<stack>

using namespace std;
stack<pair<int, int>> myStack;

int main() {
	int N, input;
	cin >> N;
	myStack.push(make_pair(0, 100000001)); // 맨 앞에 가장 큰게 있음!

	for (int i = 0; i < N; i++) {
		// cin >> input;
		scanf("%d", &input);
		
		while (myStack.top().second < input)
			myStack.pop();


		// cout << myStack.top().first << " ";
		printf("%d ", myStack.top().first);
		myStack.push(make_pair(i + 1, input));
	}

	return 0;
}