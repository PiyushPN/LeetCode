// Last updated: 18/07/2026, 19:59:54
class Solution {
public:
    int dp[301][5002];
    int solve(vector<int>& coins, int W, int n){
        if(n==0 or W<=0){
            return W==0?1:0;
        }
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        if(coins[n-1]<=W){
            return dp[n][W]=solve(coins, W-coins[n-1], n)+solve(coins, W, n-1);
        } else {
            return dp[n][W]=solve(coins, W, n-1);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        return solve(coins, amount, n);
    }
};