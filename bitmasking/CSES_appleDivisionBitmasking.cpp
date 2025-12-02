#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	int n;
	ll counter = LONG_LONG_MAX;
	
	cin >> n;
	
	vector<ll> apples(n);
	
	for(int i = 0; i < n; i++)
	{
		cin >> apples[i];
	}
		
	
	for(int mask = 0; mask < (1 << n); mask++)
	{
		ll group1 = 0;
		ll group2 = 0;
		for(int i = 0; i < n; i++)
		{
			if(mask & (1 << i))
			{
				group1 += apples[i];
			}
			else
			{
				group2 += apples[i];
			}
		}
		
		counter = min(counter, abs(group1 - group2));
	}
	
	cout << counter;
}
				
	
	
