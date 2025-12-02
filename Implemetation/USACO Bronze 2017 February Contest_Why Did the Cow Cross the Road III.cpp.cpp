#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
	
vector <int> cows;
map <int, int> cowTime;

int calcTime(int previousTime, int y)
{
	int prev;
	if(previousTime > y)
	{
		prev = previousTime;
	}
	else prev = y;
	int timeAns = cowTime[y];
	return prev + timeAns;
}

int main()
{
	int n, x, y;
	cin >> n;
	cows.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		cowTime[x] = y;
		cows[i] = x;
	}
	sort(cows.begin(), cows.end());
	
	/*for (int i = 0; i < n; i++)
	{
		cout << cows[i] << " ";
	}*/
	
	int c = cows[0];
	int maxTime = cowTime[c] + c;

	for (int i = 1; i < n; i++)
	{
		c = cows[i];
		maxTime = calcTime(maxTime, c);
	}
	
	cout << maxTime;
}
