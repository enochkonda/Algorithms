#include <iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	int N;
	cin >> N;
	int startT[N];
	int endT[N];
	int times[1000];
	int shiftTotal = -1;
	
	for (int i = 0; i < 1000; i++)
	{
		times[i] = 0;
	}
	
	for (int c = 0; c < N; c++)
	{
		cin >> startT[c] >> endT[c];
		for(int k = startT[c]; k < endT[c]; k++)
		{
			times[k]++;
		}
	}
	
	int counter = 0;
	for (int c = 0; c < N; c++)
	{
		counter = 0;
		for (int t = startT[c]; t < endT[c]; t++)
		{
			times[t]--;
		}
		for (int i = 0; i < 1000; i++)
		{
			if(times[i] > 0) counter++;
		}
		shiftTotal = max(shiftTotal, counter);
		for (int t = startT[c]; t < endT[c]; t++)
		{
			times[t]++;
		}
	}
	cout << shiftTotal;
}
			
		 
		
		
