#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)

const int MX = 1e5 + 10;
vector<int> adj[MX];
vector<int> color;

int n, m;

bool dfs(int u, int currColor)
{
	//cout << "node : " << u << " color " << currColor << "\n";
	color[u] = currColor;
	for(int v : adj[u])
	{
		if(color[v] == -1)
		{
			//cout << "NEIGHBOR: " << v << "\n";
			//check in subtree
			if(!dfs(v, !currColor)) return false;
		}
		
		else if(currColor == color[v]) return false;
	}
	return true;
}

bool isBipartite()
{
	FOR(i , n) color[i] = -1;
	
	for(int i = 0; i < n; i++)
	{
		if(color[i] == -1)
		{
			if(!dfs(i, 0)) return false;
		}
	}
	return true;
}
			

int main()
{
	cin >> n >> m;
	
	color.resize(n);
	
	int u, v;
	
	FOR(i, m)
	{
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(!isBipartite())
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		FOR(i, n)
		{
			cout << ++color[i];
			if(i != n - 1) cout << " ";
		}
	}
}
