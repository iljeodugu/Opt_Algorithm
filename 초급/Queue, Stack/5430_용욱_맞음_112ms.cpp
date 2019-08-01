#include<iostream>

using namespace std;

int main() {
	int l_pos, r_pos, T, n, arr_n, j;
	string opers, nums;
	int strpos, temppos;
	bool isRight, isError;
	int arr[100000];
	char tempint[4];
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> opers >> n >> nums;
		
		isRight = true;
		isError = false;
		l_pos = 0;
		r_pos = n - 1;
		strpos = 1;
		for (int k = 0; k < n; k++) {
			for (int l = 0; l < 4; l++)
				tempint[l] = NULL;
			temppos = 0;
			while (nums[strpos] != ',' && nums[strpos] != ']')
				tempint[temppos++] = nums[strpos++];

			arr[k] = atoi(tempint);
			strpos++;
		}

		for (auto c : opers) {
			if (c == 'R') {
				isRight = !isRight;
			}
			else { // D
				if (isRight)
					l_pos++;
				else
					r_pos--;
			}
			if (l_pos > r_pos+1) {
				isError = true;
				break;
			}
		}

		// cout << l_pos << " " << r_pos << endl;

		if (isError == true)
			cout << "error" << endl;
		else if (l_pos == r_pos + 1)
		{
			cout << "[]" << endl;
		}
		else {
			cout << "[";
			if (isRight == true) {
				for (j = l_pos; j < r_pos; j++) {
					cout << arr[j] << ",";
				}
			}
			else {
				for (j = r_pos; j > l_pos; j--) {
					cout << arr[j] << ",";
				}
			}
			cout << arr[j] << "]" << endl;
		}

	}

	return 0;
}