#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<int> adj[n + 1];  // adjacency list representation
	
	int s; // source vertex
	cin >> s;
	
	int u, v;
	for(int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	queue<int> q;
	vector<bool> used(n + 1);
	vector<int> d(n + 1, -1), p(n + 1);
 
	q.push(s);
	used[s] = true;
	p[s] = -1;
	d[s] = 0;
	
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int u : adj[v])
		{
			if(!used[u])
			{
				used[u] = true;
				q.push(u);
				d[u] = d[v] + 1;
				p[u] = v;
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		i == n ? cout << d[i] : cout << d[i] << " ";
	}
}