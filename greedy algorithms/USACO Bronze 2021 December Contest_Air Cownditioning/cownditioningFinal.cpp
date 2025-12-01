#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> p;
vector<int> t;

bool same(int a, int b)
{
	int x = p[a] - t[a];
	int y = p[b] - t[b];
	return (x <= 0 && y <= 0) || (x >= 0 && y >= 0);
}

int need(int i)
{
	return abs(p[i] - t[i]);
}

int main()
{
	int N;
	cin >> N;
	p.resize(N);
	t.resize(N);
	for(int i = 0; i < N; i++) {
		cin >> p[i];
	}
	for(int i = 0; i < N; i++) {
		cin >> t[i];
	}
	
	ll ans = 0;
	
	for(int i = 0; i < N; i++)
	{
		if(i > 0 && same(i, i - 1)) {
			ans += max(0, need(i) - need(i - 1));
		}
		else {
			ans += need(i);
		}
	}
	
	cout << ans;
}
	
