// Last updated: 18/07/2026, 19:58:24
class Solution {
public:
    int dp[501][501];
    int solve(int start, int end, vector<int> &stone, vector<int> &pre, int n)
    {
        if(start >= end)
        {
            return 0;
        }
        if(dp[start][end] != -1)
        {
            return dp[start][end];
        }
        int ans = INT_MIN;
        int temp = 0;
        for(int i = start; i < end; i++)
        {
            int sum1, sum2;
            if(start==0)
            {
                sum1 = pre[i];
            }
            else
            {
                sum1 = pre[i]-pre[start-1];
            }
            sum2 = pre[end]-pre[i];
            if(sum1 > sum2)
            {
                temp = sum2+solve(i+1, end, stone, pre, n);
            }
            else if(sum1 < sum2)
            {
                
                temp = sum1+solve(start, i, stone, pre, n);
            }
            else
            {
                temp = sum1+max(solve(start, i, stone, pre, n), solve(i+1, end, stone, pre, n));
            }
            ans = max(ans, temp);
        }
        return dp[start][end] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pre(n);
        memset(dp, -1, sizeof(dp));
        pre[0] = stoneValue[0];
        for(int i = 1; i < n; i++)
        {
            pre[i] = pre[i-1]+stoneValue[i];
        }
        return solve(0, n-1, stoneValue, pre, n);
    }
};