#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e3;
int n, m;
vector<int> adj[N];
 
vector<bool> visited(N);
vector<int> parents(N);
 
 
void dfs(int vertex, vector<int> &cp)
{
	if(visited[vertex])
	{
		return;
	}
	visited[vertex] = true;
	cp.push_back(vertex);
	
	for(int next : adj[vertex])
	{
		//current vertex is the parent of all its neighbors
		dfs(next, cp);
	}
	
	return;
}
 
int main()
{
	//number of nodes and edges
	cin >> n >> m;
	
	int u, v;
	
	//entering edges
	for(int i = 0; i < m; i++)
	{
		cin >> u >> v;
		
		//undirected edge
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	//boolean vector for visited
	vector<vector<int>> ans;
	int components = 0;
	for(int u = 1; u <= n; u++)
	{
		if(!visited[u])
		{
			vector<int> connectedComponents;
			dfs(u, connectedComponents);
 
			vector<int> tmp;
			for(int i : connectedComponents)
			{
				tmp.push_back(i);
			}
			ans.push_back(tmp);
			components++;
		}
	}	
	cout << components << endl;
	for(int i = 0; i < components; i++)
	{
		cout << (int)ans[i].size();
		for(int j = 0; j < (int)ans[i].size(); j++)
		{
			cout << " " << ans[i][j];
		}
		if(i != components - 1) cout << endl;
	}
}