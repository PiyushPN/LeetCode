// Last updated: 18/07/2026, 19:59:39
class Solution {
public:
    int dp[1001][1001];
    int solve(vector<vector<int>>& pairs, int n1, int prev, int n)
    {
        if(n1==0)
        {
            return 0;
        }
        if(dp[n1][prev] != -1)
        {
            return dp[n1][prev];
        }
        // if(prev==n+1)
        // {
        //     return dp[n1][prev] = 1+solve(pairs, n1-1, n1, n);
        // }
        if(pairs[prev-1].front() > pairs[n1-1].back())
        {
            return dp[n1][prev] = 1+solve(pairs, n1-1, n1, n);
        }
        else
        {
            return dp[n1][prev] = solve(pairs, n1-1, prev, n);
        }
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp, -1, sizeof(dp));
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        return solve(pairs, n, n, n)+1;
    }
};