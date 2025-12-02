#include <bits/stdc++.h>

using namespace std;

vector<string> ans;
bool aWin = false;
//if there is a tie detected
bool alarm = false;
vector<int> trackC;
bool found = false;
vector<int> a(4);
vector<int> b(4);

void check()
{
	int sumA = 0; 
	int sumB = 0;
		
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(a[i] > b[j]){
				sumA++;
			}
		}
	}
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(b[i] > a[j]){
				sumB++;
			}
		}
	}
	if(sumA == sumB){
		alarm = true;
		return;
	}
	else if(sumA > sumB){
		aWin = true;
	}
	else{
		aWin = false;
	}
	return;
}
bool backCheck(){
	int sumA = 0;
	int sumB = 0;
	int sumC = 0;
	
	if(aWin){
		//check for C beating A;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(trackC[i] > a[j])
				{
					sumC++;
				}
			}
		}
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(a[i] > trackC[j])
				{
					sumA++;
				}
			}
		}
		if(sumA >= sumC) return false;
		
		//check C lose to B
		
		sumC = 0;
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(trackC[i] > b[j]){
					sumC++;
				}
			}
		}
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(b[i] > trackC[j]){
					sumB++;
				}
			}
		}
		
		if(sumC >= sumB) return false;
	}
	else
	{
		sumC = 0;
		sumB = 0;
		//b won, check if C beats b
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(trackC[i] > b[j]){
					sumC++;
				}
			}
		}
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(b[i] > trackC[j]){
					sumB++;
				}
			}
		}
		
		if(sumB >= sumC) return false;
		
		//check if A beats C
		
		sumC = 0;
		
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(trackC[i] > a[j])
				{
					sumC++;
				}
			}
		}
		
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(a[i] > trackC[j])
				{
					sumA++;
				}
			}
		}
		
		if(sumC >= sumA) return false;
	}
	return true;	
}
void backtrack(int i)
{
	//cout << i << " ";
	//check notes for efffcient way
	if(i == 4)
	{
		if(backCheck())
		{
			found = true;
			return;
		}
		return;
	}
	
	for(int k = 1; k <= 10; k++)
	{
		trackC.push_back(k);
		backtrack(i + 1);
		trackC.pop_back();
	}
	return;
}

void solve()
{
	alarm = false;
	aWin = false;
	found = false;
	a.clear();
	b.clear();
	
	int tmp;
	for(int i = 0; i < 4; i++)
	{
		cin >> tmp;
		a[i] = tmp;
	}
	
	for(int i = 0; i < 4; i++)
	{
		cin >> tmp;
		b[i] = tmp;
	}

	check();
	
	if(alarm)
	{
		ans.push_back("no");
		return;
	}

	backtrack(0);
	//cout<< "did worked";
	if(found)
	{
		ans.push_back("yes");
	}
	else
	{
		ans.push_back("no");
	}
	return;
}
	
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
	
	for(string s : ans)
	{
		cout << s << "\n";
	}
}
	
