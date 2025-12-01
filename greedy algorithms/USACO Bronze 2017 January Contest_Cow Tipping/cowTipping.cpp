#include <bits/stdc++.h>

using namespace std;

void flip(int i, int j, vector<string> &cows)
{
	for(int k = i; k >= 0; k--)
	{
		for(int p = j; p >= 0; p--)
		{
			if(cows[k][p] == '1')
			{
				cows[k][p] = '0';
			}
			else
			{
				cows[k][p] = '1';
			}
		}
	}
}

int main()
{
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);
	int N;
	cin >> N;
	vector<string> cows(N);
	for(int i = 0; i < N; i++)
	{
		cin >> cows[i];
	}
	
	int ans = 0;
	for(int i = N - 1; i >= 0; i--)
	{
		for(int j = N - 1; j >= 0; j--)
		{
			if(cows[i][j] == '1')
			{
				flip(i, j, cows);
				ans++;
			}
		}
	}
	cout << ans;
}
			
