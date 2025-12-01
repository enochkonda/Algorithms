#include <bits/stdc++.h>

using namespace std;
vector<int> answers;

void solve()
{
	string a;
	cin >> a;
	
	int N = a.length();
	
	vector<string> cows;
	
	for(int i = 0; i <= N - 2; i++)
	{
		if(a[i] == 'M' && a[i + 1] == 'O' && a[i + 2] == 'O')
		{
			cows.push_back("MOO");
		}
		else if(a[i] == 'M' && a[i + 1] == 'O' && a[i + 2] == 'M')
		{
			cows.push_back("MOM");
		}
		else if(a[i] == 'O' && a[i + 1] == 'O' && a[i + 2] == 'O')
		{
			cows.push_back("OOO");
		}
		else if(a[i] == 'O' && a[i + 1] == 'O' && a[i + 2] == 'M')
		{
			cows.push_back("OOM");
		}
	}
	
	for(string s : cows)
	{
		if(s == "MOO")
		{
			answers.push_back(N - 3);
			return;
		}
	}
	
	for(string s : cows)
	{
		if(s == "MOM")
		{
			answers.push_back(N - 2);
			return;
		}
		else if(s == "OOO")
		{
			answers.push_back(N - 2);
			return;
		}
	}
	
	for(string s : cows)
	{
		if(s == "OOM")
		{
			answers.push_back(N - 1);
			return;
		}
	}
	
	answers.push_back(-1);
	return;
}
		


int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
	
	for(int ans : answers)
	{
		cout << ans << "\n";
	}
}
