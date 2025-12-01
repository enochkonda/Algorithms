#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int N, Q;
	cin >> N >> Q;
	
	vector<ll> numbers(N);
	
	for(int i = 0; i < N; i++) cin >> numbers[i];
	
	vector<ll> pref(N + 1);
	
	pref[0] = 0;
	
	for(int i = 0; i < N; i++)
	{
		pref[i + 1] = pref[i] + numbers[i];
	}
	
	for(int i = 0; i < Q; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << pref[r] - pref[l] << "\n";;
	}
}
	
	
	
