#include<iostream>
#include<set>

using namespace std;
#define MIN 3
#define MAX 1000

int main()
{
	int test_num = 1;
	cin >> test_num;
	int* exam_num = new int[test_num];

	for (int i = 0; i < test_num; i++) {
		cin >> exam_num[i];
	}

	int nature_num[100] = { 0 };
	int cur = 1, idx = 0;

	while (cur < MAX) {
		nature_num[idx] = cur;
		cur += idx + 2;
		idx++;
		// cout << nature_num[idx-1] << " ";
	}

	// cout << "max index = " << idx;

	set<int> able_num;

	for (int i = 0; i < idx; i++) {
		for (int j = 0; j < idx; j++) {
			for (int k = 0; k < idx; k++) {
				able_num.insert(nature_num[i] + nature_num[j] + nature_num[k]);
			}
		}
	}

	for (int i = 0; i < test_num; i++) {
		if (able_num.find(exam_num[i]) == able_num.end())
			cout << "0" << endl;
		else
			cout << "1" << endl;
	}

	delete(exam_num);
	return 0;
}