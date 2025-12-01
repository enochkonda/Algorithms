#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
			
	int N;
	cin >> N;
	
	vector<ll> cows(N);
	for(int i = 0; i < N; i++) cin >> cows[i];
	
	vector<ll> pref(N + 1);
	
	pref[0] = 0;
	
	for(int i = 0; i < N; i++)
	{
		pref[i + 1] = pref[i] + cows[i];
	}
	
	int ans = 0;
	//one - indexed
	for(int l = 1; l < N + 1; l++)
	{
		for(int r = l + 1; r < N + 1; r++)
		{
			if((pref[r] - pref[l - 1]) % 7 == 0) ans = max(ans, (r - l) + 1);
		}
	}
	
	cout << ans << "\n";
}
			
	
