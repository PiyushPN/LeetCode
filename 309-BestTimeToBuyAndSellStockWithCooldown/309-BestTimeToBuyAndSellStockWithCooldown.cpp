// Last updated: 18/07/2026, 20:01:15

int dp[5001][2];
class Solution {
public:
    
    int solve(int i, int hold, vector<int> &prices, int n)
    {
        if(i >= n)
        {
            return 0;
        }
        if(dp[i][hold] != -1)
        {
            return dp[i][hold];
        }
        if(hold == 0)
        {
            return dp[i][hold] = max(solve(i+1, 1, prices, n)-prices[i], solve(i+1, 0, prices, n));
        }
        else
        {
            return dp[i][hold] = max(solve(i+2, 0, prices, n)+prices[i], solve(i+1, 1, prices, n));
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        int n = prices.size();
        return solve(0, 0, prices, n);
        
    }
};