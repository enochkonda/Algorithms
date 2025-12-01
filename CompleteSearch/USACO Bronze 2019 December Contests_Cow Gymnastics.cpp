#include <iostream>

using namespace std;	
	
int K, N;
int rankings[10][20], better[20][20];		

int main()
{
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	cin >> K >> N;
	for(int i = 0; i < K; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> rankings[i][j];
			rankings[i][j]--;
		}
	}
	//calucualtes th e# times cow a comes before cow b
	//loops oer tirals
	for(int i = 0; i < K; i++)
	{
		for(int j = 0; j < N; j++)
		{
			for(int k = j + 1; k < N; k++)
			{
				better[rankings[i][j]][rankings[i][k]]++;
			}
		}
	}
	
	//calcs ans
	int ans = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(better[i][j] == K)
			{
				ans++;
			}
		}
	}
	
	cout << ans;
}
		


