#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
	
	int N;
	cin >> N;
	
	vector<int> cows(N);
	
	for(int i = 0; i < N; i++)
	{
		cin >> cows[i];
	}
	
	int index = -1;
	
	for(int i = N - 1; i > 0; i--)
	{
		if(cows[i - 1] > cows[i])
		{
			index = i - 1;
			break;
		}
	}
	
	int minus = (N - 1) - index;
	
	cout << N - minus << "\n";
}
			

