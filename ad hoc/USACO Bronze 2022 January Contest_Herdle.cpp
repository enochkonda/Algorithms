#include <bits/stdc++.h>

using namespace std;

const int N = 3;
vector<string> ansKey(3);
vector<string> guess(3);
vector<int> gCollect(26, 0);
const int setter = 'A';
map<char, int> mp;
set<char> letters;

int findYellow()
{
	int y = 0;
	int found = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			char letter = ansKey[i][j];
			if(letters.find(letter) == letters.end())
			{
				found = 0;
				
				for(int k = 0; k < N; k++)
				{
					for(int q = 0; q < N; q++)
					{
						if(guess[k][q] == letter)
						{
							found++;
						}
					}
				}
				
				int minimized = min(found, mp[letter]);
				y += minimized - gCollect[letter - setter];
				//cout << letter << " mp[letter] " << mp[letter] << " y " << y << " gCollect " << gCollect[letter - setter] << endl;
				letters.insert(letter);
			}
		 }
	 }
	 
	 return y;
 }		

int findGreen()
{
	int g = 0;
	for(int i = 0; i  < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(ansKey[i][j] == guess[i][j])
			{
				char letter = ansKey[i][j];
				gCollect[letter - setter]++;
				g++;
			}
		}
	}
	
	return g;
}

int main()
{
	for(int i = 0; i < N; i++)
	{
		cin >> ansKey[i];
		for(int j = 0; j < N; j++)
		{
			mp[ansKey[i][j]]++;
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		cin >> guess[i];
	}
	
	int green = findGreen();
	
	int yellow = findYellow();
	
	cout << green << "\n" << yellow;
}
	
	
	
