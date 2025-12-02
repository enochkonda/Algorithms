#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e4 + 5;
int n, m;
vector<int> adj[N];
 
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
	//one indexed
	for(int u = 1; u <= n; u++)
	{
		//cout << "Neighbors of " << u << ":";
		cout << (int)adj[u].size();
		for(int v: adj[u])
		{
			cout << " " << v;
			//cout << " " << v;
		}
		cout << "\n";
	}
	
	cout << endl;
}