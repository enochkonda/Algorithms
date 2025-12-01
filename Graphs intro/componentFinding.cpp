#include <bits/stdc++.h>

using namespace std;

const int N = 100;
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
	for(int u = 1; u <= n; u++)
	{
		//dfs on all unvisited nodes
		if(!visited[u])
		{
			//clears the vector but keep the visited array
			vector<int> connectedComponents;
			dfs(u, connectedComponents);
			for(int i : connectedComponents)
			{
				cout << i << " ";
			}
			cout << endl;
		}
	}	
}
