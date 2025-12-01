#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	string cows;
	cin >> cows;
	
	//edge cases
	vector<int> range(N);
	for(int i = 0; i < N; i++)
	{
		cin >> range[i];
	}
	
	int stop = 0;
	
	int elSeg = 0;
	bool Seg = false;
	
	for(int i = 0; i < N; i++)
	{
		if(!Seg)
		{
			Seg = true;
			elSeg++;
			continue;
		}
		if(cows[i] != cows[0])
		{
			stop = i;
			break;
		}
		else
		{
			elSeg++;
		}
	}
	
	int ans = 0;
	for(int i = 0; i < stop; i++)
	{
		if(range[i] - 1 >= stop || range[i] - i >= elSeg)
		{
			ans++;
		}
	}
	
	cout << ans;
}
