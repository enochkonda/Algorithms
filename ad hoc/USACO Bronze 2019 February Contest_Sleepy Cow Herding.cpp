#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	vector<int> a(3);
	
	cin >> a[0];
	cin >> a[1];
	cin >> a[2];
	
	sort(a.begin(), a.end());
	
	if(a[1] - a[0] == 1 && a[2] - a[1] == 1)
	{
		cout << 0 << "\n";
		cout << 0;
		return 0;
	}
	
	if(a[1] - a[0] == 2 || a[2] - a[1] == 2)
	{
		cout << 1 << "\n";
	}
	else
	{
		cout << 2 << "\n";
	}
	
	int dist = max(a[1] - a[0], a[2] - a[1]);
	
	cout << dist - 1;
}
