#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);
	int N;
	string A, B;
	cin >> N >> A >> B;
	
	bool inSwitch = false;
	int counter = 0;
	
	for(int i = 0; i < N; i++)
	{
		if(A[i] != B[i])
		{
			inSwitch = true;
		}
		if(inSwitch && (A[i] == B[i]))
		{
			counter++;
			inSwitch = false;
		}
	}
	
	cout << counter;
}
	
