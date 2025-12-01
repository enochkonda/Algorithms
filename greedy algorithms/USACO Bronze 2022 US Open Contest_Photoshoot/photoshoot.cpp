#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	string s;
	cin >> N >> s;
	
	vector<bool> segment;
	for(int i = 0; i < N - 1; i += 2)
	{
		if(s[i] == 'G' && s[i + 1] == 'H')
		{
			if(segment.empty() || segment.back() != false)
			{
				segment.push_back(false);
			}
		}
		else if(s[i] == 'H' && s[i + 1] == 'G')
		{
			if(segment.empty() || segment.back() != true)
			{
				segment.push_back(true);
			}
		}
	}
	int ans = 0;
	if(segment.back() == true)
	{
		ans -= 1;
	}
	
	ans += (int)segment.size();
	
	cout << ans;
}	
