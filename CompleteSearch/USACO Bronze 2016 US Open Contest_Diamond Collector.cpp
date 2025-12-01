#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	
	int N, K;
	cin >> N >> K;
	
	vector<int> diamonds(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> diamonds[i];
	}
	int weight;
	//p is the position of the next diamond
	int p;
	int ans = 0;
	bool canPut;
	for (int i = 0; i < N; i++)
	{
		p = i;
		vector<int> pack(0);
		pack.push_back(diamonds[p]);
		for(int j = 1; j < N; j++)
		{
			canPut = true;
			p++;
			weight = diamonds[p % N];
			for(int element : pack)
			{
				if(abs(weight - element) > K)
				{
					canPut = false;
				}
			}
			if(canPut) pack.push_back(weight);
		}
		ans = max(ans, (int)pack.size());
	}
	cout << ans;
}
