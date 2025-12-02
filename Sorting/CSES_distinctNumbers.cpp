#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> numbers(N);
	
	for(int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	
	sort(numbers.begin(), numbers.end());
	
	int ans = 0;
	for(int i = 0; i < N; i++)
	{
		if(numbers[i] != numbers[i + 1])
		{
			ans++;
		}
	}
	ans = max(1, ans);
	cout << ans;
}
	
