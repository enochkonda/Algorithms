#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b)
{
	return get<2>(a) < get<2>(b);
}

int main()
{
	int G, N;
	cin >> G >> N;

	vector<tuple<int, int, int>> gardens(G);
	
	int x, y, t;
	for(int i = 0; i < G; i++)
	{
		 cin >> x >> y >> t;
		 gardens[i] = make_tuple(x, y, t);
	}
	
	sort(gardens.begin(), gardens.end(), cmp);
	
	
	int ans = 0;
	
	int cnt = 0;
	int goal = 0;
	for(int i = 0; i < N; i++)
	{
		goal = 0;
		cnt = 0;
		cin >> x >> y >> t;
		ll nextGardenIndex = upper_bound(gardens.begin(), gardens.end(), make_tuple(x, y, t), cmp) - gardens.begin();
		ll prevGardenIndex = nextGardenIndex - 1;
		
		ll timeNeeded;
		ll distance;
		
		ll x1;
		ll y1;
		
	
		
		if(prevGardenIndex >= 0LL)
		{
			
			timeNeeded = t - get<2>(gardens[prevGardenIndex]);
			
			timeNeeded *= timeNeeded;
		
			x1 = x - get<0>(gardens[prevGardenIndex]);
			x1 *= x1;
			y1 = (y - get<1>(gardens[prevGardenIndex]));
			y1 *= y1;
			distance = (x1 + y1);
			if(timeNeeded >= distance) cnt++;
			goal++;
		}
		
		if(nextGardenIndex < G)
		{
			goal++;
			
			x1 = get<0>(gardens[nextGardenIndex]) - x;
			x1 *= x1;
			y1 = (get<1>(gardens[nextGardenIndex]) - y);
			y1 *= y1;
		
			timeNeeded = get<2>(gardens[nextGardenIndex]) - t;
			
			timeNeeded *= timeNeeded;
			distance = x1 + y1;
			
			if(timeNeeded >= distance) cnt++;
		}
		
		if(cnt == goal) ans++;
	}
	
	cout << N - ans << "\n";
}
		
		
		
		
		
		
		
		
		
		
