#include<iostream>
#include<map>
#include<set>

using namespace std;

int main() {
	map<int, int, greater<int>> livemap;
	set<int> deathset;
	int biggest_area = 0, area = 0;
	int last_x = 0;
	int N, input = 0;

	cin >> N;
	cin >> input;
	livemap.insert(make_pair(0, input));

	for (int i = 1; i < N; i++) {
		cin >> input;

		if (livemap.begin()->second < input) {
			livemap.insert(make_pair(i, input));
		}
		else {
			last_x = -1;
			for (auto a : livemap) {
				if (last_x != -1) {
					deathset.insert(last_x);
				}
				if (a.second > input) {
					livemap[a.first] = input;
					last_x = a.first;
				}
			}
		}

		for (auto a : deathset) {
			livemap.erase(a);
		}

		for (auto a : livemap) {
			area = (i - a.first + 1) * a.second;
			if (biggest_area < area)
				biggest_area = area;
			else if ((i + 1) * a.second < biggest_area) {
				break;
			}
		}
	}

	cout << biggest_area;

	return 0;
}