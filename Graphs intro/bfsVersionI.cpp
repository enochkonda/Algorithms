#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 5;
vector<int> adj[N];
int main()
{
	//nodes and edges
	int n, edges;
	cin >> n >> edges;
	
	int u, k;
	for(int i = 0; i < edges; i++)
	{
		cin >> u >> k;
		adj[u].push_back(k);
		adj[k].push_back(u);
	}
	//start vertex
	int start;
	//end vertex
	int end;
	
	cin >> start >> end;
	
	queue<int> q;
	vector<bool> visited(n + 1, 0);
	vector<int> distance(n + 1, -1), parents(n + 1);
	
	//bfs
	
	q.push(start);
	visited[start] = true;
	parents[start] = -1;
	distance[start] = 0;
	while(!q.empty())
	{
		int parentNode = q.front();
		q.pop();
		for(int neighbors : adj[parentNode])
		{
			if(!visited[neighbors])
			{
				visited[neighbors] = true;
				q.push(neighbors);
				distance[neighbors] = distance[parentNode] + 1;
				parents[neighbors] = parentNode;
			}
		}
	}
	
	//displaying shortest path
	
	if(!visited[end])
	{
		cout << "No path!";
	}
	else
	{
		vector<int> path;
		for(int v = end; v != -1; v = parents[v])
		{
			path.push_back(v);
		}
		reverse(path.begin(), path.end());
		cout << "Path: ";
		for(int vertex : path)
		{
			cout << vertex << " ";
		}
	}
}
	
