#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool matrix[11][11] = {false, }; //�������� map
int region_info[11][11] = {0,}; //��� ���ö� ������ �ֳ� ����
int population[11] = {0, }; //������ �α�����
int POINT;
int result = 1000;
int visited[11] = { 0, };
int cnt;
int num_of_x[2] = { 0, };

vector<int> k;

void dfs(int i, int idx)
{
		visited[i] = true;

		for (int j = 0; j < k.size(); j++)
		{
			if (k[j] == idx && matrix[i][j] == true && visited[j] == false)
			{
				dfs(j, idx);
				//for (int i = 0; i < 11; i++)
				//{
				//	cout << visited[i] << " ";
				//}cout << endl;
			}
		}
}
bool check(int idx) //����ϳ� �ϼ��Ǹ� �ٷ� true����
{
	//cnt ���� 0�̳� 1�� ������ ������ üũ�ؼ� ��ġ�ϸ� true
	//idx ���� point�鳢�� ��ΰ� �̾������� üũ
	for (int i = 0; i < k.size(); i++)
	{
		if (k[i] == idx)
		{
			cnt = 0;
			dfs(i, idx);

			for (int j = 0; j < 11; j++) //visited Ǯ���ֱ�
			{
				if (visited[j] == 1)
				{
					cnt = cnt + 1;
				}
				visited[j] = 0;
			}

			if (num_of_x[idx] == cnt)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	/* input */
	cin >> POINT;
	
	for (int i = 0; i < POINT; i++)
	{
		cin >> population[i];
	}

	for (int i = 0; i < POINT; i++)
	{
		int num_of_neighbor;
		cin >> num_of_neighbor;

		for (int j = 0; j < num_of_neighbor; j++) 
		{
			int neighbor_point;
			cin >> neighbor_point;
			region_info[i][j] = neighbor_point;

			if (neighbor_point != 0)
			{
				matrix[i][neighbor_point - 1] = true;
			}
		}
	}

	/* process */
	for (int i = 1; i < POINT ; i++) //���ű��� �ݵ�� 1�� �̻��� ������ ���ԵǾ���ϹǷ� 1���� �ݺ�
	{
		num_of_x[0] = i;        //�ε��� x�� ���ڵ��� ����
		num_of_x[1] = POINT - i;

		for (int j = 0; j < POINT - i; j++)
		{
			//idx vector�� 1 �Ҵ�
			k.push_back(1);
		}

		for (int j = 0; j < i; j++)
		{
			//idx vector�� 0 �Ҵ�
			k.push_back(0);
		}

		sort(k.begin(), k.end());
		
		do {
			//���� üũ
			if (check(1) == true && check(0) == true)
			{
				int sum_1 = 0;
				int sum_0 = 0;

				//���� ���Դٸ� �α����� ���� ���ϱ�
				for (int j = 0; j < k.size(); j++)
				{
					if (k[j] == 1)
					{
						sum_1 += population[j];
					}
					else if (k[j] == 0)
					{
						sum_0 += population[j];
					}
					//cout << num_of_x[0] << " " << num_of_x[1] << ":" <<sum_0 <<"," <<sum_1 << endl;
				}
				int diff = abs(sum_0 - sum_1);

				if (diff < result) result = diff;
			}
		} while (next_permutation(k.begin(), k.end()));
		//������ idx vector Ǯ���ֱ�
		k.clear();
	}

	//��� ���
	if (result == 1000)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << result << endl;
	}
}