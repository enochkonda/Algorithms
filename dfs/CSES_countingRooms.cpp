#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 5;

int n, m;

char grid[N][N];
bool visited[N][N];


// left up right down
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool inside(int x, int y)
{
	return (0 <= x && x < n && 0 <= y && y < m);
}

void dfs(int x, int y)
{
	visited[x][y] = true;
	
	for(int i = 0; i < 4; i++)
	{
		int newX = x + dx[i];
		int newY = y + dy[i];

		// when can you do a dfs from newX and newY
		
		//in bounds of grid
		if(!inside(newX, newY)) continue;
		//check if it is not a wall
		if(grid[newX][newY] == '#') continue;
		// check if it is not visited yet
		if(visited[newX][newY]) continue;
		
		dfs(newX, newY);
	}
	
}
	

int main()
{
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		cin >> grid[i];
	}
	
	//start dfs on every empty unvisited cell
	
	int rooms = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(!visited[i][j] && grid[i][j] == '.')
			{
				//increment rooms
				rooms++;
				//flood fill
				dfs(i, j);
			}
		}
	}
	
	cout << rooms << "\n";
}
	
	

