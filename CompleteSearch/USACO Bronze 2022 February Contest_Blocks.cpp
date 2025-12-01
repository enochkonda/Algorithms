#include <bits/stdc++.h>

using namespace std;

vector<string> possible;
vector<string> blocks(4);

void backtrack(string word, vector<bool> used_blocks)
{
	possible.push_back(word);
	for(int i = 0; i < 4; i++)
	{
		if(!used_blocks[i])
		{
			used_blocks[i] = true;
			for(int k = 0; k < 6; k++)
			{
				backtrack(word + blocks[i][k], used_blocks);
			}
			used_blocks[i] = false;
		}
	}
}
		

int main()
{
	int N;
	cin >> N;
	
	for(int i = 0; i < 4; i++)
	{
		cin >> blocks[i];
	}

	
	backtrack("", vector<bool>(4));
	
	vector<string> ans;
	
	for(int i = 0; i < N; i++)
	{
		string desired;
		cin >> desired;
		bool found = false;
		for(int i = 0; i < (int)possible.size(); i++)
		{
			if(desired == possible[i])
			{
				found = true;
			}
		}
		if(found)
		{
			ans.push_back("YES");
		}
		else
		{
			ans.push_back("NO");
		}
	}
	
	for(string answer : ans)
	{
		cout << answer << "\n";
	}	
}
		
