#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> ans;
	map<int, int> m;
	vector<int> a(n);
	int temp;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		a[i] = temp;
	}
	int start = 0;
	for(int i = 0; i < n; i++)
	{
		m[a[i]]++;
		if(m[a[i]] == 2)
		{
			m.clear();
			ans.push_back({start, i});
			start = i + 1;
		}
	}
	if(ans.empty())
	{
			cout << -1;
			return 0;
	}
	cout << (int)ans.size() << "\n";
	for(int i = 0; i < (int)ans.size(); i++)
	{
		if(i == (int)ans.size() - 1)
		{
			cout << ++ans[i].first << " " << n;
		}
		else
		{
			cout << ++ans[i].first << " " << ++ans[i].second << "\n";
		}
	}
}
			
			
			
			
/*look = true;
			end = i + 1;
			foundNone = false;
			int tmp = -1;
			m.clear();
			int p = i + 1;
			//cout << p << " " << n << endl;
			do
			{
				//cout << n << " hi";
				tmp = a[p];
				m[tmp]++;
				if(p == n - 1)
				{
					foundNone = true;
				}
				p++;
			}while(p < n && m[tmp] == 2);
			
			if(!foundNone)
			{
				ans.push_back({start, end});
				start = end + 1;
			}
			else
			{
				ans.push_back({start, n});
				break;
			}
			m.clear();
		}
	}
	if(!look)
	{
		cout << -1;
		return 0;
	}
	
	printf("%d\n", (int)ans.size());
	
	for(auto i : ans)
	{
		printf("%d %d\n", i.first, i.second);
	}
}*/