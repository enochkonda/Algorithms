#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int n;
	set<int> even;
	set<int> odd;
	vector<int> nList(T);
	for(int t = 0; t < T; t++)
	{
		cin >> nList[t];
	}
	for(int i = 0; i < T; i++)
	{
		n = nList[i];
		if(n < 5)
		{
			cout << -1 << "\n";
		}
		else
		{
			for(int num = 1; num <= n; num++)
			{
				if(num == 4 || num == 5) continue;
				//checks if a number is odd
				if((num & 1) == 1)
				{
					odd.insert(num);
				}
				else
				{
					even.insert(num);
				}
			}
			for(auto evenNum : even)
			{
				cout << evenNum << " ";
			}
			cout << 4 << " " << 5 << " ";
			
			auto it = odd.end();
			it--;
			for(auto oddNum : odd)
			{
				if(oddNum != *it)
				{
					cout << oddNum << " ";
				}
				else
				{
					cout << oddNum;
				}
			}
			cout << "\n";
		}
	}		
}
