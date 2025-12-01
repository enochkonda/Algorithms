#include <bits/stdc++.h>

using namespace std;

int N;
vector<bool> isGood(10, true);
vector<string> painting;
//color 0 is not a color


void findBadNumbers(int look)
{
	int minHeight = -1;
	int minWidth = 1e9;
	int maxHeight = 1e9;
	int maxWidth = -1;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			int check;
			stringstream ss;
			ss << painting[i][j];
			ss >> check;
			if(check == look)
			{
				//the lower the height, the more away from 0
				minHeight = max(minHeight, i);
				//the higher the column the more closer to zero
				maxHeight = min(maxHeight, i);
				
				
				minWidth = min(minWidth, j);
				maxWidth = max(maxWidth, j);
			 }
		 }
	 }
	 
	 if(maxHeight == 1e9)
	 {
		 isGood[look] = false;
		 return;
	 }
	
	 
	 for(int i = maxHeight; i <= minHeight; i++)
	 {
		 for(int j = minWidth; j <= maxWidth; j++)
		 {
			 int check;
			  stringstream ss;
			  ss << painting[i][j];
			  ss >> check;
			 if(check != look)
			 {
				 isGood[check] = false;
			 }
		 }
	 }
 }
        
int main()
{
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	
	cin >> N;
	
	painting.resize(N);
	
	for(int i = 0; i < N; i++)
	{
		cin >> painting[i];
	}
	
	for(int i = 1; i <= 9; i++)
	{
		findBadNumbers(i);
	}
	
	int ans = 0;
	//skip the first index because color 0 is not a color
	for(int i = 1; i <= 9; i++)
	{
		if(isGood[i])
		{
			ans++;
		}
	}
	
	cout << ans;
}
	
	
