#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<int> adj[n + 1];
	
	int u, v;
	for(int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> p(n + 1);
	queue<int> q;
	
	int start = 1;
	
	p[start] = -1;
	q.push(start);
	
	vector<int> dist(n + 1);
	for(int i = 0; i <= n; i++)
	{
		dist[i] = -1;
	}
	
	dist[start]  = 0;
	while(!q.empty())
	{
		int v = q.front();
		//cout << "node: " << v << "\n";
		q.pop();
		for(int u : adj[v])
		{
			if(dist[u] == -1)
			{
				p[u] = v;
				q.push(u);
				dist[u] = dist[v] + 1;
			}
		}
	}
	
			
	int end = n;
	if(dist[end] == -1) 
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		vector<int> path;
		for(int v = end; v != -1; v = p[v])
		{
			path.push_back(v);
		}
		
		reverse(path.begin(), path.end());
		
		cout << ++dist[n] << "\n";
		for(int i = 0; i < (int)path.size(); i++)
		{
			i ==(int)path.size() - 1 ? cout << path[i] : cout << path[i] << " ";
		}
	}
}
		
	
	

