#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> x(n);
	vector<int> y(n);
	
	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> y[i];
	}
	int answer = 0;
	int distance = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			distance = pow(y[j] - y[i], 2) + pow(x[j] - x[i], 2);
			answer = max(answer, distance);
		}
	}
	
	cout << answer << "\n";
}
			
	
