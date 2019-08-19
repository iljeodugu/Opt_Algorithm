#include <iostream>

using namespace std;

int three_matrix[17][3][3]=
{
	{ { 1,1,0 },
	{ 1,0,0 },
	{ 1,0,0 } },

	{ { 1,1,0 },
	{ 0,1,0 },
	{ 0,1,0 } },

	{ { 1,0,0 },
	{ 1,0,0 },
	{ 1,1,0 } },

	{ { 0,1,0 },
	{ 0,1,0 },
	{ 1,1,0 } },

	{ { 1,1,1 },
	{ 1,0,0 },
	{ 0,0,0 } },

	{ { 1,1,1 },
	{ 0,0,1 },
	{ 0,0,0 } },

	{ { 1,0,0 },
	{ 1,1,1 },
	{ 0,0,0 } },

	{ { 0,0,1 },
	{ 1,1,1 },
	{ 0,0,0 } },

	{ { 1,1,0 },
	{ 1,1,0 },
	{ 0,0,0 } },

	{ { 1,0,0 },
	{ 1,1,0 },
	{ 0,1,0 } },

	{ { 0,1,0 },
	{ 1,1,0 },
	{ 1,0,0 } },

	{ { 1,1,0 },
	{ 0,1,1 },
	{ 0,0,0 } },

	{ { 0,1,1 },
	{ 1,1,0 },
	{ 0,0,0 } },

	{ { 0,1,0 },
	{ 1,1,1 },
	{ 0,0,0 } },

	{ { 1,1,1 },
	{ 0,1,0 },
	{ 0,0,0 } },

	{ { 1,0,0 },
	{ 1,1,0 },
	{ 1,0,0 } },

	{ { 0,1,0 },
	{ 1,1,0 },
	{ 0,1,0 } }
};

int map[504][504] = { 0 };

int main(void)
{
	int width, height;

	cin >> height >> width;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> map[i][j];
		}
	}

	int max = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int temp = 0;
			for (int k = 0; k < 4; k++)
			{
				temp += map[i][j + k];
			}
			if (max < temp)
				max = temp;
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int temp = 0;
			for (int k = 0; k < 4; k++)
			{
				temp += map[i + k][j];
			}
			if (max < temp)
				max = temp;
		}
	}
	for (int k = 0; k < 17; k++)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int temp = 0;

				for (int ii = 0; ii < 3; ii ++ )
				{
					for (int jj = 0; jj < 3; jj++)
					{
						temp += three_matrix[k][ii][jj] * map[i + ii][j + jj];
					}
				}
				if (max < temp)
					max = temp;
			}
		}
	}

	cout << max << endl;
}