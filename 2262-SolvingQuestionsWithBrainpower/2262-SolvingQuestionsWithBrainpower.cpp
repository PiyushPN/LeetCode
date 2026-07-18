// Last updated: 18/07/2026, 19:57:20
class Solution {
public:
    long long dp[100005];
    long long solve(int i, vector<vector<int>>& q, int n)
    {
        if(i == n-1)
        {
            return q[n-1][0];
        }
        if(i >= n)
        {
            return 0;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        return dp[i] = max(q[i][0] + solve(i+q[i][1]+1, q, n), solve(i+1, q, n));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof(dp));
        int n = questions.size();
        return solve(0, questions, n);
    }
};