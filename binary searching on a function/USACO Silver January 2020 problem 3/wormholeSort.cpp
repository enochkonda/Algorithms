//This program uses DFS and Binary Searching on a function


#include <bits/stdc++.h>

using namespace std;

vector<int> nodes;
		//node   weight
vector<pair<int, int>> adj[(int)(1e5)];
int N, M;

bool weightGood(int w)
{
	vector<int> id(N, -1);
	auto dfs = [&](auto dfs, int curr, int nodeId) -> void
	{
		id[curr] = nodeId;
		for (pair<int, int> edge : adj[curr])
		{
			//edge.first is the neightbor itself, edge.second is the weight
			//we check if the edge's weight is greater than or equal to the weight we are binary searching on
			//because the cows are willing to be placed through a wormhole at the smallest size, w. Any size bigger than w is good.
			if(id[edge.first] == -1 && edge.second >= w)
			{
				dfs(dfs, edge.first, nodeId);
			}
		}
	};
	
	int currId = 0;
	for(int i = 0; i < N; i++)
	{
		if(id[i] == -1)
		{
			dfs(dfs, i, currId);
			currId++;
		}
	}

	//iterate through all nodes
	//for each one it must be the case that id[i] == id[nodes[i]]
	//if this fails for one of them, return 0 (false), otherwise 1 (true).
	//id[0] = 3, the first index in the nodes array is 3
	//id[nodes[0]] is the id of the 3rd index in the nodes array
	/*cout << "w: " << w << " array: ";
	for(int i : id)
	{
		cout << i << " ";
	}
	cout << " \n";*/
	for(int i = 0; i < N; i++)
	{
		if (id[i] != id[nodes[i]])
		{
			//cout << " bad\n";
			return false;
		}
	}
	/*cout << " good\n";*/
	
	return true;
}

int main()
{
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
	
	cin >> N >> M;
	nodes.resize(N);
	for(int i = 0; i < N; i++)
	{
		cin >> nodes[i];
		nodes[i]--;
	}
	
	int a, b, w;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b >> w;
		a--;
		b--;
		
		adj[a].push_back(make_pair(b, w));
		adj[b].push_back(make_pair(a, w));
	}
	
	//We are trying to maximize the smallest hole the cows must squish themselves into, so we know if we only restrict the holes to 
	//x an above, there may be a hole smaller than x that the cows must go through to sort themselves
	//if the smallest hole the cows can go through is 0, they can go through any hole and since it is
	//gauranteed the cows can sort themselves using the wormholes, then if the cows can use any wormhole, it is guaranteed that
	//the cows can sort themselves
	//1111111100000000
	//l always point at a good value
	//r always points to a bad value

	//if the highest hole a cow can go through is 4, it can go through nothing greater than 4,
	//so the lower the number is, the more restrictive, 0 will always be bad because w[i] is never 0

	//r always points to a good number
	
	int l = 0;
	int r = (int)1e9 + 1;
	
	while(r > l + 1)
	{
		int m = (l + r) / 2;
		if(weightGood(m))
		{
			l = m;
		}
		else
		{
			r  = m;
		}
	}
	//(int)1e9 + 1 means none of the wormholes can be used because all of them are less than or equal to (int)1e9
	if(r == (int)1e9 + 1 && weightGood((int)1e9 + 1))
	{
		cout << -1 << "\n";
	}
	else 
	{
		cout << l << "\n";
	}
}