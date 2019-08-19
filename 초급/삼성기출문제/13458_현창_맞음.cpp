#include <iostream>

using namespace std;

long test_room[1000000];

int main(void)
{
	long test_room_num;

	cin >> test_room_num;

	for (int i = 0; i < test_room_num; i++)
	{
		cin >> test_room[i];
	}

	int high_super, low_super;

	cin >> high_super;
	cin >> low_super;

	long super_num = 0;

	for (int i = 0; i < test_room_num; i++)
	{
		test_room[i] -= high_super;
		super_num++;
		if (test_room[i] <= 0)
			continue;
		else
		{
			super_num += (test_room[i] / low_super) + 1;
			if (test_room[i] % low_super == 0)
				super_num--;
		}
	}

	cout << super_num << endl;

	return 0;
}