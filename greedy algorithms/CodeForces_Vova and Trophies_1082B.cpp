#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int N;
	string s;
	cin >> N >> s;
	
	vector<int> Gseg;
	
	int cnt = 0;
	bool found = false;
	for(int i = 0; i < N; i++)
	{
		if(s[i] == 'G')
		{
			found = true; 
			cnt++;
			if(i == N - 1) Gseg.push_back(cnt);
			continue;
		}
		if(found)
		{
			found = false;
			Gseg.push_back(cnt);
			cnt = 0;
		}
	}
	
	int ans = 0;
	if(Gseg.empty())
	{
		cout << 0;
		return 0;
	}
	if((int)Gseg.size() == 1)
	{
		cout << Gseg[0];
		return 0;
	}
	
	for(int i = 0; i < N; i++)
	{
		if(s[i] == 'S')
		{
			int left = 0;
			int right = 0;
			int j = i - 1;
			while(s[j] == 'G')
			{
				left++;
				j--;
			}
			j = i + 1;
			while(s[j] == 'G')
			{
				right++;
				j++;
			}
			if((int)Gseg.size() > 2)
			{
				ans = max(ans, right + left + 1);
			}
			else
			{
				ans = max(ans, right + left);
			}
		}
	}
	
	int one = *max_element(Gseg.begin(), Gseg.end());
	ans = max(ans, one + 1);
	
	cout << ans;
}