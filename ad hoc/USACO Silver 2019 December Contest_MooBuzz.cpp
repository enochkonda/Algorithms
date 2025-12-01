#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);
	
	ll N;
	cin >> N;
	
	ll eightNum[] = {1, 2, 4, 7, 8, 11, 13, 14};
	
	ll index = N % 8;
	ll mult = N / 8;
	//one indexed
	if(index == 0) 
	{
		index = 8LL;
		mult -= 1LL;
	}
	cout << eightNum[index - 1LL] + (15LL * mult);
}
