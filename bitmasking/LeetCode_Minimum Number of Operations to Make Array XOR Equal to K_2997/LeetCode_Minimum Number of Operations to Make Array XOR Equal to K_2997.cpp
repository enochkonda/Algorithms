#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorOfAll = nums[0];
        for(int i = 1; i < (int)nums.size(); i++)
        {
            xorOfAll ^= nums[i];
        }

        int bitsNeedChange = k ^ xorOfAll;
        //count set bits
        return __builtin_popcount(bitsNeedChange);
    }
};