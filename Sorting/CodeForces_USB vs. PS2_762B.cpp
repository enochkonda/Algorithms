#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main()
{
	int needUSB, needPS2, needBoth;
	
	cin >> needUSB >> needPS2 >> needBoth;
	
	int M;
	 
	cin >> M;
	
	vector<ll> USB;
	vector<ll> PS2;
	
	ll temp;
	string decide;
	for(int i = 0; i < M; i++)
	{
		cin >> temp;
		cin >> decide;
		if(decide == "USB")
		{
			USB.push_back(temp);
		}
		else
		{
			PS2.push_back(temp);
		}
	}
	
	sort(USB.begin(), USB.end());
	sort(PS2.begin(), PS2.end());
	
	ll money = 0;
	ll mice = 0;
	
	ll goToUSB = min(needUSB, (int)USB.size());
	for(ll i = 0; i < goToUSB; i++)
	{
		money += USB[i];
		mice++;
	}
	
	ll goToPS2 = min(needPS2, (int)PS2.size());
	for(ll i = 0; i < goToPS2; i++)
	{
		money += PS2[i];
		mice++;
	}
	
	vector<ll> both;
	for(int i = goToUSB; i < (int)USB.size(); i++)
	{
		both.push_back(USB[i]);
	}
	
	for(int i = goToPS2; i < (int)PS2.size(); i++)
	{
		both.push_back(PS2[i]);
	}
	
	sort(both.begin(), both.end());
	
	ll k = 0;
	while(k < needBoth && k < (int)both.size())
	{
		money += both[k];
		mice++;
		k++;
	}
	
	cout << mice << " " << money;
}