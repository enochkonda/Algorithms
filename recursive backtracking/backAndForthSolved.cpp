#include <bits/stdc++.h>

using namespace std;

vector<int> farm1B;
vector<int> farm2B;

unordered_set<int> farm1P;

void backtrack(int i, int hereAmt, int thereAmt, vector<int> hereBuckets, vector<int> thereBuckets)
{

	if(i == 4)
	{
		//on fourth iteration, since the 0th is farm one, the 4th will be farm one for here, if they alternate
		farm1P.insert(hereAmt);
		return;
	}
	//the actual vectors hereBuckets and thereBuckets will not be modified
	for(int j = 0; j < (int)hereBuckets.size(); j++)
	{
		int bucketHere = hereBuckets[j];
		vector<int> new_there = thereBuckets;
		new_there.push_back(bucketHere);
		
		vector<int> new_here = hereBuckets;
		new_here.erase(new_here.begin() + j);
		
		backtrack(i + 1, thereAmt + bucketHere, hereAmt - bucketHere, new_there, new_here);
	}
	return;	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);
	
	int b;
	for(int i = 0; i < 10; i++){
		cin >> b;
		farm1B.push_back(b);
	}
	for(int i = 0; i < 10; i++){
		cin >> b;
		farm2B.push_back(b);
	}
	
	backtrack(0, 1000, 1000, farm1B, farm2B);
	
	cout << farm1P.size();
}

	
	
	
