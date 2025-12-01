#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<int> cows(N);
	for(int i = 0; i < N; i++)
	{
		cin >> cows[i];
	}
	
	vector<int> s = cows;
	sort(s.begin(), s.end());
	int differences = 0;
	for(int i = 0; i < N; i++)
	{
		if(cows[i] != s[i])
		{
			differences++;
		}
	}
	//k -1 swaps when k = differences,  because last swap fixes two differences   
	//ex
	//4 5 : sorted
	//5 4
	
	//in one swap, 4 and 5 are fixed
	
	//if there are no differences, there are no changes to make or max(0, difference - 1)
	if(differences == 0) cout << 0;
	cout << differences - 1;
}
	
/*bool right;
	int bessieIndex;
	int bessie;
	int pastNumber = cows[0];
	for(int i = 0; i < N - 1; i++)
	{
		if(i == 0)
		{
			if(cows[i] > cows[i + 1])
			{
				cout << "here";
				bessie = cows[i];
				bessieIndex = i;
				right = true;
				break;
			}
		}
		if(i == N - 1)
		{
			if(cows[i] < cows[i - 1])
			{
				cout << "there";
				bessie = cows[i];
				bessieIndex = i;
				right = false;
				break;
			}
		}
		if(i == 0) continue;
		if(pastNumber > cows[i])
		{
			bessie = cows[i];
			bessieIndex = i;
			right = false;
		}
		if(pastNumber > cows[i])
			
	
	if(bessie > cows[bessieIndex + 1])
	{
		right = true;
	}
	
	
	
	int past = cows[bessieIndex];
	bool count = true;
	int counter = 0;
	
	cout << " past: " << past << " ";
	cout << "bessie: " << bessie << " ";
	cout << "bessieIndex: " << bessieIndex << " ";
	cout << "right: " << right << " ";
	if(right)
	{
		//cout << past << " " << cows[bessieIndex + 1];
		for(int i = bessieIndex + 1; i < N - 1; i++)
		{
			//cout << "past: " << past << " " << "cows[i]: " << cows[i] <<  " " << "i: " << i << endl;
			if(cows[i + 1] == bessie || cows[i+1] > bessie)
			{
				//cout << " ? i: " << i << endl;
				break;
			}
			if(i + 1 == N - 1 && bessie > cows[i + 1]) counter++;
			if(cows[i] == past)
			{
				//cout << "  ==  past, i: " << i << " cows[i]: " << cows[i] << endl;
				count = false;
			}
			if(cows[i] != past)
			{
				//cout << "  !=  past, i: " << i << " cows[i]: " << cows[i] << endl;
				count = true;
			}
			if(count)
			{
				//cout << " counter, i: " << i << " cows[i]: " << cows[i] << endl;
				counter++;
			}
		}
	}
	else
	{
		for(int i = bessieIndex - 1; i > 0; i--)
		{
			if(cows[i - 1] == bessie || cows[i-1] < bessie)
			{
				break;
			}
			if(i - 1 == 0 && bessie < cows[i - 1]) counter++;
			if(cows[i] == past)
			{
				count = false;
			}
			if(cows[i] != past)
			{
				count = true;
			}
			if(count)
			{
				counter++;
			}
		}
	}
	cout << counter;
}*/
				

		
			
			
		
		
