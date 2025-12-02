#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int N;
	cin >> N;
	vector<int> pillars(N);
	
	for(int i = 0; i < N; i++)
	{
		cin >> pillars[i];
	}
	
	int maximum = 0;
	int index = 0;
	string ans = "YES";
	
	for(int i = 0; i < N; i++)
	{
		if(pillars[i] > maximum)
		{
			index = i;
			maximum = pillars[i];
		}
	}
	
	for(int i = 0; i < N - 1; i++)
	{
		if(i < index)
		{
			if(pillars[i + 1] < pillars[i])
			{
				ans = "NO";
				break;
			}
		}
		if(i > index)
		{
			if(pillars[i + 1] > pillars[i])
			{
				ans = "NO";
				break;
			}
		}
	}
	
	cout << ans;
}