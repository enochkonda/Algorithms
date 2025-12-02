#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5;
int n, m;
vector<int> adj[N];
//boolean vector for visited
vector<bool> visited(N);
vector<int> parents(N);
 
 
void dfs(int vertex, int parent, int i)
{
	if(visited[vertex])
	{
		return;
	}
	visited[vertex] = true;
	//cout <<"i :" << i << " vertex: " << vertex <<  " parent: " << parent << endl;
	parents[vertex] = parent;
	
	for(int next : adj[vertex])
	{
		//current vertex is the parent of all its neighbors
		dfs(next, vertex, i + 1);
	}
	
	return;
}
 
int main()
{
	//number of nodes and edges
	cin >> n >> m;
	
	
	int start, end;
	
	cin >> start >> end;
	
	
	int u, v;
	
	//entering edges
	for(int i = 0; i < m; i++)
	{
		cin >> u >> v;
		
		//undirected edge
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	
	
	dfs(start, -1, 0);
	
	vector<int> path;
	int tmp = end;
	while(tmp != -1)
	{
		path.push_back(tmp);
		tmp = parents[tmp];
	}
	
	//cout << endl << endl;
	reverse(path.begin(), path.end());
	cout << (int)path.size() << endl;
	for(int e = 0; e < (int)path.size(); e++)
	{
		e == (int)path.size() - 1 ? cout << path[e] : cout << path[e] << " ";
	}
}