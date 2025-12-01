#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int T, M, N;
vector<ll> ans;

//calculates the minimum cost of connected two connected components
//groupTwo is usually passed in as the "middle group"
ll calcCost(vector<int>& groupOne, vector<int>& groupTwo)
{
	ll smallest = LLONG_MAX;
	for(int groupTwoNum : groupTwo)
	{
		//it points to a number strictly greater than groupTwoNum in the vector groupOne
		auto it = upper_bound(groupOne.begin(), groupOne.end(), groupTwoNum);
		//if there is a number in groupOne that is greater than groupTwoNum, we can take the difference and square it
		if(it != groupOne.end()) 
		{
			smallest = min(smallest, (ll)(*it - groupTwoNum) * (*it - groupTwoNum));
		}
		//if there is a number in groupOne that is smaller than groupTwoNum
		if(it != groupOne.begin()) 
		{
			//we can decrement the iterator to get the number that is the biggest number in groupOne that is lower than groupTwoNum
			//because the iterator initially pointed to a number in groupOne that is greater than groupTwoNum but since all the numbers are distinct
			it--;
			smallest = min(smallest, (ll)(groupTwoNum - *it) * (groupTwoNum - *it));
		}
	}
	return smallest;
}

void solve()
{
	vector<vector<int>> groups;
	vector<int> adj[(int)1e5];
	vector<int> label;
	
	cin >> N >> M;
	label.resize(N, -1);
	int u, v;
	for(int i = 0; i < M; i++)
	{
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int id = 0;
	//this is the current Connected Copmonent
	vector<int> tmpGroup;
	
	auto dfs = [&](auto dfs, int node, int id) -> void
	{
		if(label[node] == -1)
		{
			tmpGroup.push_back(node);
			label[node] = id;
			for(int u : adj[node])
			{
				dfs(dfs, u, id);
			}
		}
	};
	
	for(int i = 0; i < N; i++)
	{	
		if(label[i] == -1)
		{
			tmpGroup.clear();
			dfs(dfs, i, id);
			sort(tmpGroup.begin(), tmpGroup.end());
			groups.push_back(tmpGroup);
			id++;
		}
		
	}
	
	if(label[0] == label[N -1])
	{
		ans.push_back(0);
		return;
	}
	
	ll smallestCost = LLONG_MAX;
	//id - 1 because id incrememnts an extra amount.
	for(int i = 1; i < id-1; i++)
	{
		smallestCost = min(smallestCost, calcCost(groups[0], groups[i]) + calcCost(groups[label[N - 1]], groups[i]));
	}
	//compares the cost of connecting using two bridges to directly connecting the 1's component to N's component
	smallestCost = min(smallestCost, calcCost(groups[0], groups[label[N - 1]]));
	ans.push_back(smallestCost);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for(int i = 0; i < T; i++) 
	{
		solve();
	}
	for(ll answer : ans) 
	{
		cout << answer << "\n";
	}
	
}
