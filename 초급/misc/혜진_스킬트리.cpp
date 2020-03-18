#include <iostream>
#include <vector>

using namespace std;

int skill_cnt = 0;

bool isSol(string skill, vector<string> skill_trees, int i)
{
	string tree = skill_trees[i];
	skill_cnt = 0;

	for (int skill_name = 0; skill_name < tree.size(); skill_name++)
	{
		for (int skill_num = 0; skill_num < skill.size(); skill_num++)
		{
			if (tree[skill_name] == skill[skill_num])
			{
				if (skill_num == skill_cnt)
				{
					//cout << tree[skill_name] << skill_cnt << " " << skill[skill_num] << skill_num << endl;
					skill_cnt++;
				}
				else { return false; }
			}
		}
	}

	if (skill_cnt == 0) skill_cnt = 1;
	return true;
}
int main()
{
	/* input */
	string skill = "CBD";
	vector<string> skill_trees{ "BACDE", "CBADF", "AECB", "BDA" };

	/* process */
	int sol = 0;

	for (int i = 0; i < skill_trees.size(); i++)//인풋으로 들어온 스킬트리들 
	{
		if ( isSol(skill, skill_trees, i) && skill_cnt > 0) sol++;
	}

	/* output */
	cout << sol << endl;
}
