#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

vector<int> adj[N];

vector<bool> visited(N, false);

bool cycle = false;

void dfs(int v, int past)
{
	visited[v] = true;
	for(int u : adj[v])
	{
		if(visited[u] && u != past)
		{
			cycle = true;
			break;
		}
		if(!visited[u])
		{
			dfs(u, v);
		}
	}
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

	bool tree = true;
	dfs(1, -1);
	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			tree = false;
			break;
		}
	}
	
	if(cycle == true)
	{
		 tree = false;
	 }
	
	if(tree)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
