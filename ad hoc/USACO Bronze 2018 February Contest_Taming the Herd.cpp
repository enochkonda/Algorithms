#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
	
	int N;
	cin >> N;
	vector<int> cows(N);
	if(N == 0)
	{
		cout << -1;
		return 0;
	}
	
	for(int i = 0; i < N; i++)
	{
		cin >> cows[i];
	}
	
	//consider checking 0 at the end
	//edge case with i - a[i] but number before it so it compares them
	bool look = true;
	int cmp = -1;
	for(int i = N - 1; i >= 0; i--)
	{
		if((cows[i] != -1 && cows[i] != 0) && look)
		{
			//cout << cows[i] << endl;
			if(i - cows[i] < 0)
			{
				//cout << "hi";
				cout << -1;
				return 0;
			}
			look = false;
			cmp = cows[i];
			cmp--;
			continue;
		}
		if(cows[i] != -1 && !look && cows[i] != cmp)
		{
			//cout << "cmp " << cmp << " " << i << "   ";
			cout << -1;
			return 0;
		}
		if(cmp == 0)
		{
			look = true;
		}
		if(!look) cmp--;
	}
	
	int min = 0;
	int max = 0;
	bool ignore = false;
	int cnt = -1;
	// case with 0, edge case around i > 0
	for(int i = N - 1; i > 0; i--)
	{
		if(cows[i] == -1 && !ignore)
		{
			max++;
		}
		if(cows[i] != -1 && !ignore)
		{
			ignore = true;
			cnt = cows[i];
		}
		if(ignore && cnt == 0) 
		{
			min++; 
			max++;
			ignore = false;
		}
		if(ignore) cnt--;
	}
	min++;
	max++;
	
	cout << min << " " << max;
}
	
		
			
