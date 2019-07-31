#include<iostream>
#include<map>

using namespace std;

int main() {
	multimap<int, int, greater<int>> storage;
	int N, a, b, l_x = 0, r_x = 0;
	long total_area = 0;
	bool isTop = false;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		storage.insert(make_pair(b, a));
	}

	for (auto a : storage) {
		// cout << a.first << " " << a.second << endl;
		if (l_x == 0) // initialize
		{
			l_x = a.second;
			r_x = a.second;
			total_area += a.first;
		}
		else 
		{
			if (a.second < l_x) {
				total_area += ((l_x - a.second) * a.first);
				l_x = a.second;
			}
			else if (a.second > r_x) {
				total_area += ((a.second - r_x) * a.first);
				r_x = a.second;
			}
		}
	}

	cout << total_area;

	return 0;
}