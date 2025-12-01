#include <bits/stdc++.h>

using namespace std;

int oneV, twoV, threeV;

void findValue(int cow)
{
	if(cow == 1)
	{
		oneV = 1;
		twoV = 0;
		threeV = 0;
	}
	else if(cow == 2)
	{
		oneV = 0;
		twoV = 1;
		threeV = 0;
	}
	else
	{
		oneV = 0;
		twoV = 0;
		threeV = 1;
	}
}


int main()
{
	
	int N, Q;
	cin >> N >> Q;
	
	vector<int> one(N + 1);
	vector<int> two(N + 1);
	vector<int> three(N + 1);
	
	one[0] = 0;
	two[0] = 0;
	three[0] = 0;

	int cow;
	for(int i = 0; i < N; i++)
	{
		cin >> cow;
		findValue(cow);
		one[i + 1] = one[i] + oneV;
		two[i + 1] = two[i] + twoV;
		three[i + 1] = three[i] + threeV;
	}

	vector<string> ans;
	for(int i = 0; i < Q; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << one[r] - one[l - 1] << " ";
		cout << two[r] - two[l - 1] << " ";
		cout << three[r] - three[l - 1] << "\n";
	}
	
}
