// Last updated: 18/07/2026, 20:00:55
class Solution {
public:
    int dp[13][10004];
    int solve(vector<int>& coins, int W, int n){
        if(W<=0 or n==0){
            return W<=0?0:INT_MAX-1;
        }
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        if(coins[n-1]<=W){
            return dp[n][W]=min(1+solve(coins, W-coins[n-1], n), solve(coins, W, n-1));
        } else {
            return dp[n][W]=solve(coins, W, n-1);
        }

    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int n=coins.size();
        int ans = solve(coins, amount, n);
        if(ans==INT_MAX-1){
            return -1;
        }
        return ans;
    }
};