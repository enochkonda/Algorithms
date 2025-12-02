#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> color;
//parents
vector<int> p;
const int N = 1e3;
vector<int> adj[N + 1];
int endCycle = -1;
 
void dfs(int v)
{
	//not visited
	if(color[v] == 0)
	{
		//processing
		color[v] = 1;
		for(int u : adj[v])
		{
			p[u] = v;
			dfs(u);
		}
		//exited
		color[v] = 2;
	}
	else if(color[v] == 1)
	{
		endCycle = v;
	}
}
			
 
int main()
{
	//nodes and edges
	int n, m;
	
	cin >> n >> m;
	
	int q, w;
 
	for(int i = 0; i < m; i++)
	{
		cin >> q >> w;
		adj[q].push_back(w);
	}
	
	color.resize(n + 1);
	p.resize(n + 1);
	
	for(int i = 1; i <= n; i++)
	{
		if(color[i] == 0)	
		{
			p[i] = -1;
			dfs(i);
		}
		if(endCycle != -1) break;
	}
	
	if(endCycle == -1)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES" << "\n";
	int v = p[endCycle];
	
	vector<int> cycle;
	
	cycle.push_back(endCycle);
	
	while(v != endCycle)
	{
		cycle.push_back(v);
		v = p[v];
	}
	
	cycle.push_back(endCycle);
	
	
	reverse(cycle.begin(), cycle.end());
	
	cout << (int)cycle.size() << "\n";
	
	for(int i  = 0; i < (int)cycle.size(); i++)
	{
		i == (int)cycle.size() - 1 ? cout << cycle[i] : cout << cycle[i] << " ";
	}
}