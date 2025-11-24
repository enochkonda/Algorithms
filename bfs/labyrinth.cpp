#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

char grid[N][N];
bool visited[N][N];
//rows
pair<int, int> par[N][N];
// rows and columns
int n, m;

queue <pair<int, int>> q;

// up, down, left, right
int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, -1, +1};

bool reached_end = false;

bool inside(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void explore_neighbors(int x, int y)
{
	for(int i = 0; i < 4; i++)
	{
		int newX = x + dx[i];
		int newY = y + dy[i];
		
		if(!inside(newX, newY)) continue;
		if(visited[newX][newY]) continue;
		if(grid[newX][newY] == '#') continue;
		
		q.push({newX, newY});
		
		visited[newX][newY] = true;
		//cout << x << " " << y << " ";
		par[newX][newY] = {x, y};
	}
}
		
void bfs(int x, int y)
{
	q.push({x, y});
	visited[x][y] = true;
	
	par[x][y] = {-1, -1};
	
	while(!q.empty()) // or cq.size()
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if(grid[r][c] == 'B')
		{
			reached_end = true;
			break;
		}
		explore_neighbors(r, c);
		//cout << r << " " << c << endl;
	}
}

int main()
{
	cin >> n >> m;
	
	//start indices
	int sr, sc;
	//end indices
	int er, ec;
	
	for(int i = 0; i < n; i++)
	{
		cin >> grid[i];
		for(int j = 0; j < m; j++)
		{
			if(grid[i][j] == 'A')
			{
				sr = i;
				sc = j;
			}
			
			if(grid[i][j] == 'B')
			{
				er = i;
				ec = j;
			}
		}
	}
	
	bfs(sr, sc);
	
	
	if(!reached_end)
	{
		cout << "NO";
		return 0;
	}
	
	int vx = er;
	int vy = ec;

	
	vector<pair<int, int>> path;
	while(vx != -1 && vy != -1)
	{
		// they become their parents
		path.push_back(make_pair(vx, vy));
		int tmp = vx;
		vx = par[tmp][vy].first;
		vy = par[tmp][vy].second;
	}
	
	
	//cout << "cya";
	
	reverse(path.begin(), path.end());
	
	string ans = "";
	
	//cout << " no";
	
	for(int i = 0; i < (int)path.size() - 1; i++)
	{
		// x is decreasing (row#)
		if(path[i].first > path[i + 1].first)
		{
			ans += "U";
		}
		else if(path[i].first < path[i + 1].first)
		{
			ans += "D";
		}
		else if(path[i].second > path[i + 1].second)
		{
			ans += "L";
		}
		else
		{
			ans += "R";
		}
	}
	// I included the starting index but that is not in the path.
	cout << "YES\n" << (int)path.size() - 1 << "\n";
	cout << ans;
}
	

