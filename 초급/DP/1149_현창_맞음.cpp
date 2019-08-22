#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int d[1001][3];

	int house_value[1001][3];
	int house_num;

	cin >> house_num;

	
	for (int j = 1; j <= house_num; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> house_value[j][i];
		}
	}

	d[1][0] = house_value[1][0];
	d[1][1] = house_value[1][1];
	d[1][2] = house_value[1][2];

	for (int i = 2; i <= house_num; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + house_value[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + house_value[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + house_value[i][2];
	}

	cout << min(d[house_num][0], min(d[house_num][1], d[house_num][2])) << endl;

	return 0;
}