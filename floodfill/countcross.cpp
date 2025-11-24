#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, K, R;
int newR, newC;
int id[100][100];

set<pair<int, int>> cantGo[100][100];
set<pair<int, int>> cows;


void floodfill(int r, int c, int currId)
{
    if(id[r][c] != -1)
    {
        return;
    }

    id[r][c] = currId;
    set<pair<int, int>> cantGoCurr = cantGo[r][c];
    if(r == 2 && c == 2)
    {
        /*cout << "here is the porblem: ";
        for(auto i : cantGoCurr)
        {
            cout << i.first << " " << i.second << "\n";
        }
        cout << "done\n";*/
    }
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for(auto [dr, dc] : directions)
    {
        newR = r + dr;
        newC = c + dc;
        if(newR >= 0 && newR < N && newC >= 0 && newC < N)
        {
            auto it = find(cantGoCurr.begin(), cantGoCurr.end(), make_pair(newR, newC));
            if(it == cantGoCurr.end())
            {
                floodfill(newR, newC, currId);
            }
        }
    }
}

int main()
{
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    cin >> N >> K >> R;
    int r, c, fR, fC;
    
    for (int i = 0; i < R; i++)
    {
        cin >> r >> c >> fR >> fC;
        r--;
        c--;
        fR--;
        fC--;
        cantGo[r][c].insert(make_pair(fR, fC));
        cantGo[fR][fC].insert(make_pair(r, c));
    }

    for(int i = 0; i < K; i++)
    {
        cin >> r >> c;
        r--;
        c--;
        cows.insert(make_pair(r, c));
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            id[i][j] = -1;
        }
    }

    int currId = 0;
    for(int currR = 0; currR < N; currR++)
    {
        for(int currC = 0; currC < N; currC++)
        {
            if(id[currR][currC] == -1)
            {
                floodfill(currR, currC, currId);
                currId++;
            }
        }
    }

    /*cout << "id array: ";
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << id[i][j];
        }
        cout << "\n";
    }
    cout << " end ";*/

    int maxId = currId - 1;

    multiset<int> cowIds;
    int cowRow, cowColumn;
    for(auto currCow : cows)
    {
        cowRow = currCow.first;
        cowColumn = currCow.second;
        cowIds.insert(id[cowRow][cowColumn]);
    }

    int cowIdCnt;
    ll ans = 0;
    for(int i = 0; i < maxId; i++)
    {
        cowIdCnt = cowIds.count(i);
        ans += (cowIds.size() - cowIdCnt) * cowIdCnt;
        cowIds.erase(i);
    }

    cout << ans << "\n";

}