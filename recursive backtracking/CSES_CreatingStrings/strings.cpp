#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	vector<string> answer;
	do
	{
		answer.push_back(s);
	} while(next_permutation(s.begin(), s.end()));
	cout << answer.size() << "\n";
	for(string a : answer)
	{
		cout << a << endl;
	}
}
		
