#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<ll> cows;
//takes index of L in the loop
vector<int> loops;
vector<char> dir;
ll amountLost = 0;
int N;
ll M;

ll initialAmount = 0;

void findLoops()
{
	//edge case
	if(dir[0] == 'L' && dir[N - 1] == 'R')
	{
		loops.push_back(0);
	}

	for(int i = 1; i < N; i++)
	{
		if(dir[i - 1] == 'R' && dir[i] == 'L')
		{
			loops.push_back(i);
		}
	}
}

void findStreamsForLoopIndexL(int i)
{
	//Rstream
	int R = i - 2;
	if(i == 0)
	{
		R = N - 2;
	}
	else if(i == 1)
	{
		R = N - 1;
	}
	ll amtR = 0;
	while(dir[R] == 'R')
	{
		amtR += cows[R];
		if(R == 0)
		{
			R = N - 1;
		}
		else
		{
			R--;
		}
	}
	
	//LStream
	int L = i + 1;
	//added
	if(L == N)
	{
		L = 0;
	}
	//added
	ll amtL = 0;
	while(dir[L] == 'L')
	{
		amtL += cows[L];
		if(L == N - 1)
		{
			L = 0;
		}
		else
		{
			L++;
		}
	}
	//cout << amtR << " " << amtL << endl;
	ll by2 = min(amtR, amtL);
	ll by1 = max(amtR, amtL) - by2;
	ll ans = 0;
	//cout << by1 << " " << by2 << endl;
	if(M >= by2)
	{
		ans += by2 * 2;
		int addedOne = min(M - by2, by1);
		ans += addedOne;
	}
	else
	{
		ans += M * 2;
	}
	//cout << " ans: " << ans << endl;
	amountLost += ans;
}

int main()
{
	cin >> N >> M;
	
	cows.resize(N);
	dir.resize(N);
	
	for(int i = 0; i < N; i++)
	{
		cin >> dir[i];
	}
	
	for(int i = 0; i < N; i++)
	{
		cin >> cows[i];
		initialAmount += cows[i];
	}
	
	findLoops();
	
	for(int i : loops)
	{
		findStreamsForLoopIndexL(i);
	}

	cout << initialAmount - amountLost;
}
