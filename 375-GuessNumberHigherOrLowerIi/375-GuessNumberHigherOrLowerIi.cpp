// Last updated: 18/07/2026, 20:00:26

int dp[201][201];
class Solution {
public:
    
    int solve(int start, int end)
    {
        if(start>end)
        {
            return INT_MIN;
        }
        if(start==end)
        {
            return 0;
        }
        if(dp[start][end] != -1)
        {
            return dp[start][end];
        }
        int ans = INT_MAX;
        for(int i=start; i<=end; i++)
        {
            ans = min(ans, i+max(solve(start, i-1), solve(i+1, end)));
        }
        return dp[start][end] = ans;
    }
    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof(dp));
        int start = 1, end = n;
        return solve(start, end);
    }
};