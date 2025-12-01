#include <bits/stdc++.h>
 
using namespace std;
 
struct Case
{
	int n, k;
	vector<int> a;
};
 
Case getInput()
{ 
	Case temp;
	cin >> temp.n >> temp.k;
	//sets a to have temp.n values
	temp.a.resize(temp.n);
	for(int j = 0; j < temp.n; j++)
	{
		cin >> temp.a[j];
	}
	
	return temp;
}
 
void solve(Case testCase)
{
		set<int> possible;
		vector<int> sThrough;
		map<int, int> tcs;
		//for each test case, it iterates creating a key for each
		for(int j: testCase.a)
		{
			tcs[j] = 0;
		}
		//it then adds one to the value each time a number appears
		for(int j : testCase.a)
		{
			tcs[j]++;
		}
		//it continues to iterate over the array
		for(int j : testCase.a)
		{
			//if it appears k or more times and it is not already in the set/array
			if((tcs[j] >= testCase.k) && possible.find(j) == possible.end())
			{
				possible.insert(j);
				sThrough.push_back(j);
			}
		}
		//if the sThrough array is emtpy, then no numbers were >= to k so it cout -1
		if(sThrough.empty())
		{
			cout << -1 << "\n";
			return;
		}
		
		//sorts through because you want the longest subarray of consecutive integers and they may not be sorted
		sort(sThrough.begin(), sThrough.end());
		// tmp will go through everything
		pair < int , int > tmp = {sThrough[0] , sThrough[0]};
		// ans will only change if temp has more numbers than it, a greater difference in its lower and upper bounds
		pair < int , int > ans = tmp;
		
		
		for(int i = 1 ; i < (int)sThrough.size() ; i ++) {
			//starts at index 1 so it can compare to index 0
			if(sThrough[i] - sThrough[i-1] == 1) 
			{
				//increases the upper bound to sThrough[i] if sThrough[i] is 1 greater than sThrough[i - 1]
				tmp.second = sThrough[i];
			}
			else {
				//otherwise, it resets temp to have a new lowerbound, sThrough[i] and upperbound sThrough[i]
				tmp = {sThrough[i] , sThrough[i]};
			}
			//answer will only change if the difference in bounds(range) is greater than the answers difference
			if(tmp.second - tmp.first > ans.second - ans.first) {
				ans = tmp;
			}
		}
		//outputs the lower and upperbounds of the answer
		cout << ans.first << " " << ans.second << "\n";
}
 
int main()
{
	int N; 
	cin >> N;
	//puts input in testCases vector 
	vector<Case> testCases(N);
	for(int i = 0; i < N; i++)
	{
		testCases[i] = getInput();
	}
	//solve goes through each test case
	for(int i = 0; i < N; i++)
	{
		solve(testCases[i]);
	}
}