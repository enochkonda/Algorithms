#include <bits/stdc++.h>

using namespace std;

int main()
{
	int Kirito, N;
	cin >> Kirito >> N;
	
	string ans = "YES";
	
	vector<pair<int, int>> dragons(N);
	
	for(int i = 0; i < N; i++)
	{
		cin >> dragons[i].first >> dragons[i].second;
	}
	
	sort(dragons.begin(), dragons.end());
	
	for(int dragon = 0; dragon < N; dragon++)
	{
		if(Kirito > dragons[dragon].first)
		{
			Kirito += dragons[dragon].second;
		}
		else
		{
			ans = "NO";
			break;
		}
	}
	
	cout << ans;
}
		
 
