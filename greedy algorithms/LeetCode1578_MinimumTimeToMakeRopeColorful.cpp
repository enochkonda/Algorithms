#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        bool found = false;
        string past = "";
        int time = 0;
        int maxTime = 0;
        vector<int> values;
        for(int i = 1; i < (int)colors.size(); i++)
        {
            if(colors[i - 1] == colors[i] && !found)
            {
               found = true;
               values.clear();
               values.push_back(i - 1);
            }
            if((found && colors[i - 1] != colors[i]) || (i ==(int)colors.size() - 1 && colors[i - 1] == colors[i]))
            {
                if(i ==(int)colors.size() - 1 && colors[i - 1] == colors[i]) values.push_back(i);
                maxTime = 0;
               for(int p : values)
               {
                    time += neededTime[p];
                    maxTime = max(maxTime, neededTime[p]);
               }
               time -= maxTime;
               found = false;
            }
            else
            {
                values.push_back(i);
            }
        }
        return time;
        }
};