#include<iostream>

using namespace std;

int matrix[21][21] = { 0, };
int MAX_ROW, MAX_COL;
int num_of_cmd;
int dice[4][3] = { 0, };
const int E = 1;
const int W = 2;
const int N = 3;
const int S = 4;
int drow[] = { 0, 0, -1, 1 }; //EWNS ������
int dcol[] = { 1, -1, 0, 0 };
int command[1001] = { 0, };
int r, c;

int main()
{
	/* input */
	cin >> MAX_ROW >> MAX_COL >> r >> c >> num_of_cmd;

	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			cin >> matrix[row][col];
		}
	}

	for (int k = 0; k < num_of_cmd; k++)
	{
		cin >> command[k];
	}

	/* process */
	for (int k = 0; k < num_of_cmd; k++) //��ɾ� ������ŭ �ݺ�
	{
		int cur_cmd = command[k];  //ù��° ��ɺ��� �־ ���� ��ġ �ű�
		int newr = r + drow[cur_cmd-1];
		int newc = c + dcol[cur_cmd-1];
		
		//cout <<k << ": " << newr << " " << newc << " , " << cur_cmd << endl;
		if (newr >= 0 && newc >= 0 && newr < MAX_ROW && newc < MAX_COL) //����üũ
		{
			if (cur_cmd == E)
			{
				//cout << "E" << endl;
				int tmp = dice[1][0];
				dice[1][0] = dice[1][1];
				dice[1][1] = dice[1][2];
				dice[1][2] = dice[3][1];
				dice[3][1] = tmp;
			}
			else if (cur_cmd == W)
			{
				//cout << "W" << endl;
				int tmp = dice[1][0];
				dice[1][0] = dice[3][1];
				dice[3][1] = dice[1][2];
				dice[1][2] = dice[1][1];
				dice[1][1] = tmp;
			}
			else if (cur_cmd == N)
			{
				//cout << "N" << endl;
				int tmp = dice[3][1];
				dice[3][1] = dice[2][1];
				dice[2][1] = dice[1][1];
				dice[1][1] = dice[0][1];
				dice[0][1] = tmp;
			}
			else
			{
				//cout << "S" << endl;
				int tmp = dice[0][1];
				dice[0][1] = dice[1][1];
				dice[1][1] = dice[2][1];
				dice[2][1] = dice[3][1];
				dice[3][1] = tmp;
			}

			if (matrix[newr][newc] == 0)
			{
				matrix[newr][newc] = dice[1][1];
			}
			else
			{
				dice[1][1] = matrix[newr][newc];
				matrix[newr][newc] = 0;
			}

			//����üũ�� ���� ������ġ �ű��
			r = newr;
			c = newc;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					//cout << dice[i][j];
				}
				//cout << endl;
			}
			
			/* output */
			cout << dice[3][1] << endl;
		}
	}


	/* output */
	//��ǲ �׽�Ʈ
	/*
	cout << MAX_ROW << " " << MAX_COL << " " << r << " " << c << " " << num_of_cmd << endl;

	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}

	for (int k = 0; k < num_of_cmd; k++)
	{
		cout << command[k] << " ";
	}cout << endl;*/
}