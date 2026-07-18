// Last updated: 18/07/2026, 20:02:56
class Solution {
public:
    int dp[2001][2001];
    bool isPalindrome(string &s, int start, int end)
    {
        while(start<=end)
        {
            if(s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }
        
    int solve(string &s, int i, int j)
    {
        if(i>=j)
        {
            return 0;
        }
        if(isPalindrome(s, i, j))
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k = i; k <= j-1; k++)
        {
            if(isPalindrome(s, i, k))
            {
                int temp = solve(s, i, k) + solve(s, k+1, j)+1;
                ans = min(ans, temp);
            }
        }
        return dp[i][j] = ans;
    }
    int minCut(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        int i = 0;
        return solve(s, i, n-1);
    }
};