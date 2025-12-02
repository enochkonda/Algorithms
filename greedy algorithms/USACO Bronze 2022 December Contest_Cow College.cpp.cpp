#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> price;
int main()
{
	int N;
	cin >> N;
	
	price.resize(N);
	for(int i = 0; i < N; i++) cin >> price[i];
	ll charge = 0;
	ll moneyAns = 0;
	ll attend = N;
	sort(price.begin(), price.end());
	for(int i = 0; i < N; i++)
	{
		if(attend * price[i] > moneyAns)
		{
			moneyAns = attend * price[i];
			charge = price[i];
		}
		
		attend--;
	}
	cout << moneyAns << " " << charge << "\n";
}

	

