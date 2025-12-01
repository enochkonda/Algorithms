#include <bits/stdc++.h>

using namespace std;

int i = 0;
vector<int> v{1, 2, 3};
vector<int> subset;

void getSubsets(int i)
{
	if(i == (int)v.size())
	{
		for(int p : subset) cout << p << "_";
		cout << "*" << endl;
		return;
	}
	
	subset.push_back(v[i]);
	getSubsets(i + 1);
	
	subset.pop_back();
	getSubsets(i + 1);
	
	return;
}
	

int main()
{
	getSubsets(0);
}
