#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

vector<int> adj[N];
vector<bool> visited(N);
vector<int> d;
//possible start vertex
vector<int> p;
int start = 1;
bool getNext = true;
int counter = 0;

int dfs(int v, int dist)
{
	visited[v] = true;
	
	counter = 0;
	int maximum = 0;
	for(int u : adj[v])
	{
		//cout << "u: " << u << " v: " << v << endl;
		if(!visited[u])
		{
			maximum = max(maximum, dfs(u, dist + 1));
			counter++;
		}
	}

	if(counter == 0)
	{
		//cout << " v: " << v << " dist: " << dist << endl;
		return dist;
	}
	else
	{
		return maximum;
	}
}

int main()
{
	int n;
	cin >> n;
	
	int u, v;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	
	for(int i = 1; i <= n; i++)
	{
		if((int)adj[i].size() == 1)
		{
			p.push_back(i);
		}
	}
	int ans = 0;
	for(int i = 0; i < (int)p.size(); i++)
	{
		start = p[i];
		for(int v = 0; v < N; v++) visited[v] = false;
		visited[start] = true;
		for(int u : adj[start])
		{
			if(!visited[u])
			{
				ans = max(ans, dfs(u, 1));
				getNext = true;
			}
		}
	}

	cout << ans;
	//sort d
	//pick two biggest and add them up, d is only once a node has no unvisited neighbors
}
