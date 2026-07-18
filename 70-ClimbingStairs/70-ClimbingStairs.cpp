// Last updated: 18/07/2026, 20:03:54
class Solution {
public:
    int dp[50];
    int solve(int n){
        if(n==0 or n==1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};