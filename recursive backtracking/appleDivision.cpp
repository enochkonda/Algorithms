#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll answer = LONG_MAX;

void backtrack(int pos, ll groupOne, ll groupTwo, vector<ll> apples, int N)
{
	if(pos == N)
	{
		answer = min(answer, abs(groupTwo - groupOne));
		return;
	}
	
	backtrack(pos + 1, groupOne + apples[pos], groupTwo, apples, N);
	backtrack(pos + 1, groupOne, groupTwo + apples[pos], apples, N);
}	

int main()
{
	int N;
	cin >> N;
	vector<ll> apples(N);
	for(int i = 0; i < N; i++)
	{
		cin >> apples[i];
	}
	
	/*int backtrack(int pos, ll groupOne, ll groupTwo)
	{
		if(pos == N)
		{
			return abs(groupOne - groupTwo);
		}
	
		int pathOne = backtrack(pos + 1, groupOne + apples[pos], groupTwo);
		int pathTwo = backtrack(pos + 1, groupOne, groupTwo + apples[pos]);
		
		int answer = min(pathOne, pathTwo);
	}*/
	backtrack(0, 0, 0, apples, N);
	cout << answer;
}
	
	
	
