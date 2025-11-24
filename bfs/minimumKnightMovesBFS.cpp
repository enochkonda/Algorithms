#include <bits/stdc++.h>

using namespace std;

const int n = 8;
const int m = 8;

queue<int> rq, cq;
bool visited[n][m];

int nodes_left_in_layer = 0;
int nodes_in_next_layer = 0;

bool reached_end = false;

int sr, sc, er, ec;

bool inside(int x, int y)
{
	return (x >= 0 && x < 8 && y >= 0 && y < 8);
}	

void explore_neighbors(int x, int y)
{
	int dx[] = {-2, -2, 2, 2, -1, -1, 1, 1};
	int dy[] = {-1, 1, -1, 1, -2, 2, -2, 2};
	
	for(int i = 0; i < 8; i++)
	{
		int newX = x + dx[i];
		int newY = y + dy[i];
		
		if(!inside(newX, newY)) continue;
		if(visited[newX][newY]) continue;
		
		visited[newX][newY] = true;
		
		rq.push(newX);
		cq.push(newY);
		
		nodes_in_next_layer++;
	}
}
	
int bfs(int x, int y)
{
	int count = 0;
	
	rq.push(x);
	cq.push(y);
	
	visited[x][y] = true;
	
	nodes_left_in_layer = 1;
	
	while(!rq.empty())
	{
		int r = rq.front();
		rq.pop();
		int c = cq.front();
		cq.pop();
		if(r == er && c == ec)
		{
			reached_end = true;
			break;
		}
		explore_neighbors(r, c);
		nodes_left_in_layer--;
		if(nodes_left_in_layer == 0)
		{
			nodes_left_in_layer = nodes_in_next_layer;
			nodes_in_next_layer = 0;
			count++;
		}
	}
	return count;
}

int main()
{
	int T;
	cin >> T;
	
	vector<int> answers;
	while(T--)
	{
		string start, end;

		cin >> start >> end;

		sc = (int(start[0]) - 97);
		stringstream ss;
		ss << start[1];
		ss >> sr;
		sr--;
		
		ec = (int(end[0]) - 97);
		
		stringstream es;
		es << end[1];
		es >> er;
		er--;
		
		while(!rq.empty())
		{
			rq.pop();
		}
		
		while(!cq.empty())
		{
			cq.pop();
		}
		
		memset(visited, 0, sizeof(visited));

		nodes_left_in_layer = 0;
		nodes_in_next_layer = 0;

		reached_end = false;
	
		answers.push_back(bfs(sr, sc));
	}
	for(int i = 0; i < (int)answers.size(); i++)
	{
		cout << answers[i] << (i == int(answers.size() - 1) ? "" : "\n");
	}
}
