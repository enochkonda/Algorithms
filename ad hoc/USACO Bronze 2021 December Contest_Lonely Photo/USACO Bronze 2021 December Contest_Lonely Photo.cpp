#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ll N;
	string cows;
	cin >> N >> cows;
	//will be alternating
	vector<ll> segs;
	
	char look = cows[0];
	ll curr = 0;
	for(ll i = 0; i < N; i++)
	{
		if(cows[i] == look)
		{
			curr++;
		}
		else
		{
			look = cows[i];
			segs.push_back(curr);
			curr = 1;
		}
		if(i == N - 1)
		{
			segs.push_back(curr);
		}
	}
	ll ans = 0;
	if((ll)segs.size() == 1)
	{
		cout << 0;
		return 0;
	}
	
	for(ll i = 0; i < (ll)segs.size(); i++)
	{
		if(i != (ll)segs.size() - 2 && segs[i + 1] == 1)
		{
			ans += segs[i] * segs[i + 2];
		}
		if(segs[i] >= 2)
		{
			if(i == 0 || i == (ll)segs.size() - 1)
			{
				ans += segs[i] - 1;
			}
			else
			{
				ans += (segs[i] - 1) * 2;
			}
		}
		//cout << ans <<  " i: " << i << endl;
	}
	
	cout << ans;
}
