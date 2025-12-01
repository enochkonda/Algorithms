#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<int> start(N), desired(N);
	
	for(int i = 0; i < N; i++) {
		cin >> start[i];
	}
	
	for(int i = 0; i < N; i++) {
		cin >> desired[i];
	}
	
	map<int, int> mp;
	
	for(int i = 0; i < N; i++)
	{
		//i increases as the prioiryt grows bigger
		mp[desired[i]] = i;
	}
	
	vector<int> priorityPrefix(N);
	int highestPriority = -1;
	for(int i = 0; i < N; i++)
	{
		highestPriority = max(highestPriority, mp[start[i]]);
		priorityPrefix[i] = highestPriority;
	}
	
	int ans = 0;
	for(int i = N - 1; i > 0; i--)
	{
		if(mp[start[i]] < priorityPrefix[i])
		{
			ans++;
		}
	}
		/*for(int j = i - 1; j >= 0; j--)
		{
			if(mp[start[i]] < mp[start[j]])
			{
				ans++;
				//break because one number can be maximized
				break;
			}
		}
	}*/

	cout << ans;
}
	
	
