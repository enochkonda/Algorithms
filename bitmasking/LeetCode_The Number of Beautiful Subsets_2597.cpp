#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0;
        //start at 1 because we only wan beautiful subsets
        for(int mask = 1; mask < (1 << (int)nums.size()); mask++)
        {
            vector<int> subset;
            //check if bits are on
            for(int i = 0; i < (int)nums.size(); i++)
            {
                if((1 << i) & mask)
                {
                    subset.push_back(nums[i]);
                }
            }
            sort(subset.begin(), subset.end());
            int p = 1;
            int q = 0;
            bool noBad = true;
            if((int)subset.size() == 1) 
            {
                ans++;
                continue;
            }
            while(q <= (int)subset.size() - 1)
            {
                int diff = subset[p] - subset[q]; 
                if(diff > k || p == (int)subset.size() - 1)
                {
                    q++;
                }
                else
                {
                    p++;
                }
                if(diff == k)
                {
                    noBad = false;
                    break;
                }
            }
            if(noBad)
            {
                ans++;
            }
        }
        return ans;
    }
};