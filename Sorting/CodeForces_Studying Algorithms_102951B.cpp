#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, X;
	cin >> N >> X;
	
	vector<int> time(N);
	
	for(int i = 0; i < N; i++)
	{
		cin >> time[i];
	}
	
	sort(time.begin(), time.end());
	
	int ans = 0;
	int i = 0;
	while(X > 0)
	{
		if(i >= (int)time.size()) break;
		X -= time[i];
		if(X < 0) break;
		ans++;
		i++;
	}
	
	cout << ans;
}

