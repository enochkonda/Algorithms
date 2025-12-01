#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	int number = INT_MAX;
	int sol;
	
	for(int i = 0; i < n - k; i++)
	{
		int m = (a[i] + a[i + k]) / 2;
		//bigger of disparity
		int find = max(abs(a[i] - m), abs(a[i + k] - m));
		
		if(find < number)
		{
			sol = m;
			number = find;
		}
	}
	
	ans.push_back(sol);
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
	
	for(int i : ans)
	{
		cout << i << "\n";
	}
}
