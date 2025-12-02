#include <bits/stdc++.h>

using namespace std;

int currPerimeter;
int currArea;
int N;
char grid[1000 + 5][1000 + 5];
bool visited[1000 + 5][1000 + 5];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int floodfill(int r, int c)
{
    if(r < 0 || r >= N || c < 0 || c >= N)
    {
        return 1;
    }
    else if(visited[r][c])
    {
        return 0;
    }
    else if(grid[r][c] != '#')
    {
        return 1;
    }

    visited[r][c] = true;
    //the number of unvisited nodes around this current node (can be 0 - 4)
    int unvisitedNodesAround = 0;
    
    unvisitedNodesAround += floodfill(r + 1, c);
    unvisitedNodesAround += floodfill(r - 1, c);
    unvisitedNodesAround += floodfill(r , c + 1);
    unvisitedNodesAround += floodfill(r, c - 1);

    currArea++;
    currPerimeter += unvisitedNodesAround;
    return 0;
}

int main()
{
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> N;
    //grid.resize(N);
    vector<pair<int, int>> blobs;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }
 
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            currArea = 0;
            currPerimeter = 0;
            if(visited[i][j] == false)
            {
                floodfill(i, j);
            }
            blobs.push_back(make_pair(currArea, currPerimeter));
        }
    }

    sort(blobs.begin(), blobs.end(), cmp);
    /*cout << "array: ";
    for (auto i : blobs)
    {
        cout << i.first << " " << i.second << "\n";
    }
    cout << "end\n";*/
    cout << blobs[(int)blobs.size() - 1].first << " " << blobs[(int)blobs.size() - 1].second;
}
