// Last updated: 18/07/2026, 20:03:19
class Solution {
public:
    int dp[1001][1001];
    int solve(string &s, string &t, int i, int j, int n1, int n2)
    {
        if(j==n2)
        {
            return 1;
        }
        if(i==n1)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(s[i] == t[j])
        {
            return dp[i][j] = solve(s, t, i+1, j+1, n1, n2) + solve(s, t, i+1, j, n1, n2);
        }
        else
        {
            return dp[i][j] = solve(s, t, i+1, j, n1, n2);
        }
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        int n1 = s.size();
        int n2 = t.size();
        return solve(s, t, 0, 0, n1, n2); 
    }
};