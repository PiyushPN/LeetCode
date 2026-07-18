// Last updated: 18/07/2026, 20:02:09
class Solution {
public:
    
    int dp[1001][2][101];
    int solve(int i, int hold, int left, vector<int> &prices, int n)
    {
        if(i>=n or left==0)
        {
            return 0;
        }
        if(dp[i][hold][left]!=-1){
            return dp[i][hold][left];
        }
        if(hold==0)
        {
            return dp[i][hold][left] = max(solve(i+1, 1, left, prices, n)-prices[i], solve(i+1, 0, left, prices, n));
        }
        else
        {
            return dp[i][hold][left]= max(solve(i+1, 0, left-1, prices, n)+prices[i], solve(i+1, 1, left, prices, n));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        int n = prices.size();
        return solve(0, 0, k, prices, n);
    }
};