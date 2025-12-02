class Solution { 
    public int coinChange(int[] coins, int amount) {
        int best = amount + 1; 
        int dp[] = new int[amount + 1]; 
        dp[0] = 0; 
        for(int i = 1; i <= amount; i++) 
        { 
            best = amount + 1;
            for(int c : coins)
            {
                if(i - c >= 0)
                {
                    best = Math.min(best, 1 + dp[i - c]);
                }
            }
            dp[i] = best;
        }

        if(dp[amount] <= amount)
        {
            return dp[amount];
        }
        return -1;
    }
}