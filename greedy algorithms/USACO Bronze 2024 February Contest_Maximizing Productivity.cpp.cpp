#include <bits/stdc++.h>

using namespace std;

vector<int> fillMe;
vector<int> c, t;
int maxS = INT_MIN;
vector<string> ans;
int N, Q;
vector<int> hashArr;
void makeHashArray()
{
	hashArr.resize(maxS + 1);
	int j = 0;
	int i = 0;
	while(i <= maxS)
	{
		while(i > fillMe[j])
		{
			j++;
		}
		hashArr[i] = (N - j);
		i++;
	}
}

void solveQueries()
{
	makeHashArray();
	for(int i = 0; i < Q; i++)
	{
		int V, S;
		cin >> V >> S;
		int amt = 0;
		if(S <= maxS)
		{
			amt = hashArr[S];
		}
		if(amt >= V)
		{
			ans.push_back("YES");
		}
		else
		{
			ans.push_back("NO");
		}
	}
}

void fillArray()
{
	for(int i = 0; i < N; i++)
	{
		fillMe[i] = ((c[i] - 1) - t[i]);
		maxS = max(maxS, fillMe[i]);
	}
}

int main()
{
	cin >> N >> Q;
	
	c.resize(N);
	t.resize(Q);
	
	for(int i = 0; i < N; i++)
	{
		cin >> c[i];
	}

	for(int i = 0; i < N; i++)
	{
		cin >> t[i];
	}
	
	fillMe.resize(N);
	
	fillArray();

	sort(fillMe.begin(), fillMe.end());
	
	
	
	solveQueries();
	
	for(string answer : ans)
	{
		cout << answer << "\n";
	}
}
