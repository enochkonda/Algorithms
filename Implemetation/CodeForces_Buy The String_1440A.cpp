#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
pair<int, int> traverse(string buystring)
{
	int cost0 = 0;
	int cost1 = 0;
	for(char i  : buystring)
	{
		if(i == '0') cost0++;
		if(i == '1') cost1++;
	}
	return make_pair(cost0, cost1);
}
 
int calculate(int cost0, int cost1, int mult0, int mult1, int hCount, int h)
{
	return (cost0 * mult0) + (cost1 * mult1) + hCount * h;
}	
 
int change(char num, string buystring, int mult0, int mult1, int h)
{
	char counternum;
	num == '0' ? counternum = '1' : counternum = '0';
	int hCount = 0;
	for(int i = 0; i < (int)buystring.size(); i++)
	{
		if(buystring[i] == num)
		{
			buystring[i] = counternum;
			hCount++;
		}
	}
	pair<int, int> coinAmount = traverse(buystring);
	return calculate(coinAmount.first, coinAmount.second, mult0, mult1, hCount, h);
}
 
 
int solve() {
	int n , c0 , c1 , h;
	cin >> n >> c0 >> c1 >> h;
 
	// string buystring;
	// cin >> buystring;
	
	string buystring;
	cin >> buystring;
	
	if((c1 > c0) && (c0 + h < c1))
		{
			return change('1', buystring, c0, c1, h);
		}
		else if((c0 > c1) && (c1 + h < c0))
		{
			return change('0', buystring, c0, c1, h);
		}
		else
		{
			pair<int, int> coinAmount = traverse(buystring);
			return calculate(coinAmount.first, coinAmount.second, c0, c1, 0, 0);
		}
}
 
 
int main()
{
	int N;
	cin >> N;
	vector<int> answers(N);
	for(int i = 0; i < N ; i++)	
	{
		answers[i] = solve();
	}
	
	
	for(int i : answers)
	{
		cout << i << "\n";
	}
}