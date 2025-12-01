#include <bits/stdc++.h>

using namespace std;
int n, x, d;
int counter = 0;
vector<int> students;

typedef long long ll;

void backtrack(int s, int minimum, int maximum, bool changed, ll sum)
{
	//maxmimum - minimum == 0 means that it picks one number which will always be true because we filtered out numbers below minimumm skill
	//otherwise, it must be less than or equal to the maximum difference
	if(s != 0)
	{
		if(s == n) return;
		if(maximum - minimum <= d && sum >= x && changed)
		{
			counter++;
		}
	}
	if(s == 0 && changed == true)
	{
		minimum = students[s];
		maximum = students[s];
		sum += students[s];
		if (sum >= x)
		{
			counter++;
		}
	}
	//leave it
	backtrack(s + 1, minimum, maximum, false, sum);
	//take it
	backtrack(s + 1, min(minimum, students[s + 1]), max(maximum, students[s + 1]), true, sum + students[s + 1]);
	return;
}

int main()
{
	cin >> n >> x >> d;
	students.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> students[i];
	}
	
	//for(int i : students) cout << i << endl;
	
	backtrack(0, INT_MAX, INT_MIN, true, 0);
	backtrack(0, INT_MAX, INT_MIN, false, 0);
	cout << counter;
}
