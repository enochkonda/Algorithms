#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;
vector<int> adj[MX];
unordered_map<int, pair<int, int>> mp;

int main()
{
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
	
	int N, M;
	cin >> N >> M;
	
	vector<bool> visited(N);
	
	int x, y;
	for(int i = 0; i < N; i++)
	{
		cin >> x >> y;
		mp[i] = make_pair(x, y);
	}
	
	int u, v;
	for(int i = 0; i < M; i++)
	{
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	//bfs
	//iterate over all connected components
	int perimeter = INT_MAX;
	int maxX = 0;
	int maxY = 0;
	int minX = INT_MAX;
	int minY = INT_MAX;
	for(int i = 0; i < N; i++)
	{
		if(!visited[i])
		{
			maxX = 0;
			maxY = 0;
			minX = INT_MAX;
			minY = INT_MAX;
			
			queue<int> q;
			q.push(i);
			
			while(!q.empty())
			{
				int currNode = q.front();
				q.pop();
				
				maxX = max(maxX, mp[currNode].first);
				minX = min(minX, mp[currNode].first);
				maxY = max(maxY, mp[currNode].second);
				minY = min(minY, mp[currNode].second);
				
				visited[currNode] = true;
				
				for(int v : adj[currNode])
				{
					if(!visited[v]) q.push(v);
				}
			}
			int xDiff = maxX - minX;
			int yDiff = maxY - minY;
			//cout << " X: " << xDiff << " Y: " << yDiff << "\n";
			perimeter = min(perimeter, xDiff * 2 + yDiff * 2);
		}
	}
	
	cout << perimeter << "\n";
	
}
		
	
	
