// Last updated: 18/07/2026, 20:03:40
class Solution {
public:
    int dp[101][101];
    int solve(int i, int j, int k, string s1, string s2, string s3, int n, int m)
    {
        if(i==n and j==m)
        {
            return 1;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        char c1 = s1[i], c2 = s2[j], c3 = s3[k];
        if(c1 == c2 and c2 == c3)
        {
            return dp[i][j] = solve(i+1, j, k+1, s1, s2, s3, n, m) or solve(i, j+1, k+1, s1, s2, s3, n, m);
        }
        else if(c1 == c3)
        {
            return dp[i][j] = solve(i+1, j, k+1, s1, s2, s3, n, m);
        }
        else if(c2 == c3)
        {
            return dp[i][j] = solve(i, j+1, k+1, s1, s2, s3, n, m);
        }  
        return 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        memset(dp, -1, sizeof(dp));
        int n = s1.length();
        int m = s2.length();
        int m1 = s3.length();
        if(n+m != m1)
        {
            return false;
        }    
        return solve(0, 0, 0, s1, s2, s3, n, m);
        
    }
};