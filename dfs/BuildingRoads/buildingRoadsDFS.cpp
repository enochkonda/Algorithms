#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
//global false
vector<bool> visited;
vector<int> p;

void dfs(int v)
{
	if(!visited[v])
	{
		visited[v] = true;
		for(int u : adj[v])
		{
			dfs(u);
		}
	}
	return;
}


int main()
{
	int n, m;
	cin >> n >> m;
	
	
	int u, v;
	for(int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	

	vector<int> dcNodes;
	visited.resize(n + 1);
	
	
	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			dfs(i);
			dcNodes.push_back(i);
		}
	}
	
	int counter = (int)dcNodes.size() - 1;
	
	cout << counter << "\n";
	
	
	for(int i = 1; i < (int)dcNodes.size(); i++)
	{
		cout << dcNodes[0] << " " << dcNodes[i] <<(i == int(dcNodes.size() - 1) ? "\n" : " ");
	}
}
	
		
			
			

