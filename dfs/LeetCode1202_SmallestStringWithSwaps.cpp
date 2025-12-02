#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> visited;
    vector<int> indices;
    vector<int> adj[100000];
    void dfs(int index)
    {
        indices.push_back(index);
        visited[index] = true;
        for(int i : adj[index])
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        visited.resize(s.length(), false);
        for(auto a : pairs)
        {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        string output = "";
        for(int i = 0; i < (int)s.size(); i++) output += "0";
        for(int i = 0; i < s.size(); i++)
        {
            if(!visited[i])
            {
                indices.clear();
                dfs(i);
                string tmp = "";
                for(int ch : indices)
                {
                    tmp += s[ch];
                }
                sort(tmp.begin(), tmp.end());
                sort(indices.begin(), indices.end());
                cout << "temp :" << tmp << "\n";
                for(int j = 0; j < indices.size(); j++)
                {
                    cout << "indices: "<< indices[j] << "\n";
                    output[indices[j]] = tmp[j];
                }
            }
        }
        return output;
    }
};