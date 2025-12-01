#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M;

vector<pair<ll, ll>> intervals;

/* 5 4
   0 1
   2 4
   7 8
   100 103
 */

bool check(double D)
{
	ll cowsDistanced = 0;
	ll pastCow = 0;
	for(int i = 0; i < M; i++)
	{
		//cout << " interval : "  <<  intervals[i].first << " " << intervals[i].second << "\n";
		if(i == 0)
		{
			ll addTo =  ceil(((intervals[i].second - intervals[i].first) + 1) / D);
			 cowsDistanced += addTo;
			 pastCow = (D - 1) * (addTo - 1);
			 pastCow += addTo - 1;
			//cout << "first cows " << cowsDistanced << "\n";
		}
		else
		{
		
			ll minInterval = ll(max(pastCow + D, intervals[i].first / 1.0));
			ll add = ceil(((intervals[i].second - (minInterval)) + 1) / D);
			//cout << " add: " << add << "\n";
			if(add == 0)
			{
				if(pastCow + D <= intervals[i].second)
				{
					cowsDistanced++;
					//cout << "added cows " << cowsDistanced << "\n";
					pastCow = max(pastCow + D, intervals[i].first / 1.0);
				}
			}
			else
			{
				//cout << "min " << minInterval << "\n";
				cowsDistanced += add;
				//cout << "notAdded cows " << cowsDistanced << "\n";
				pastCow = minInterval;
				//cout << "pastCow: " << pastCow << "\n\n";
				pastCow += (D - 1) * (add - 1);
				//cout << "pastCow: " << pastCow << "\n\n";
				pastCow += add - 1;
			}
			//cout << "pastCow: " << pastCow << "\n\n";
		}
			
	}
	//cout << "called " << D << "  cows: " << cowsDistanced << "\n";
	return cowsDistanced >= N;	
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
	return a.first < b.first;
}

int main()
{
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	cin >> N >> M;
	
	intervals.resize(M);
	
	for(int i = 0; i < M; i++)
	{
		cin >> intervals[i].first >> intervals[i].second;
	}
	
	sort(intervals.begin(), intervals.end(), cmp);
	ll r = 1;
	while(check(r)) r *= 2;
	ll l = 1;

	
	while(l + 1 < r)
	{
		ll m = (l + r) / 2LL;
		if(check(m))
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}
	
	cout << l << "\n";
}
	
	
	
	
