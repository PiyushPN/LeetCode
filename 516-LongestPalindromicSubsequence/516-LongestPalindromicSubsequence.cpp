// Last updated: 18/07/2026, 19:59:55
class Solution {
public:
    int dp[1002][1002];
    int lcs(string &s1, string &s2, int n, int m){
        if(m==0 or n==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s1[n-1]==s2[m-1]){
            return dp[n][m]=1+lcs(s1, s2, n-1, m-1);
        } else {
            return dp[n][m]=max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int n = s.length();
        return lcs(s, s1, n, n);
    }
};