#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> v = {1, 2,3};
	
	int n = (int)v.size();
	
	for(int mask = 0; mask < (1 << n); mask++)
	{
		vector<int> subset;
		for(int i = 0; i < n; i++)
		{
			if(mask & (1 << i))
			{
				subset.push_back(v[i]);
			}
		}
		
		for(int x : subset)
		{
			cout << x << " ";
		}
		cout << "*" << endl;
	}
}
	
	
