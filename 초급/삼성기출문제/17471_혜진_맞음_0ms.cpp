#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool matrix[11][11] = {false, }; //인접정보 map
int region_info[11][11] = {0,}; //어느 도시랑 인적해 있나 정보
int population[11] = {0, }; //지역당 인구정보
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
bool check(int idx) //경로하나 완성되면 바로 true리턴
{
	//cnt 세서 0이나 1의 개수랑 같은지 체크해서 일치하면 true
	//idx 같은 point들끼리 경로가 이어지는지 체크
	for (int i = 0; i < k.size(); i++)
	{
		if (k[i] == idx)
		{
			cnt = 0;
			dfs(i, idx);

			for (int j = 0; j < 11; j++) //visited 풀어주기
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
	for (int i = 1; i < POINT ; i++) //선거구에 반드시 1개 이상의 지역이 포함되어야하므로 1부터 반복
	{
		num_of_x[0] = i;        //인덱스 x인 숫자들의 갯수
		num_of_x[1] = POINT - i;

		for (int j = 0; j < POINT - i; j++)
		{
			//idx vector에 1 할당
			k.push_back(1);
		}

		for (int j = 0; j < i; j++)
		{
			//idx vector에 0 할당
			k.push_back(0);
		}

		sort(k.begin(), k.end());
		
		do {
			//조건 체크
			if (check(1) == true && check(0) == true)
			{
				int sum_1 = 0;
				int sum_0 = 0;

				//여기 들어왔다면 인구끼리 차를 구하기
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
		//끝날때 idx vector 풀어주기
		k.clear();
	}

	//결과 출력
	if (result == 1000)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << result << endl;
	}
}