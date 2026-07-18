// Last updated: 18/07/2026, 19:56:48
class Solution {
public:
    long long appealSum(string s) {
        int n = s.length();
        long long dp[n+1];
        memset(dp, 0, sizeof(dp));
        int lastIndex[26];
        memset(lastIndex, -1, sizeof(lastIndex));
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            int c = s[i]-'a';
            dp[i+1] = dp[i]+i-lastIndex[c];
            ans+=dp[i+1];
            lastIndex[c]= i;
            
        }
        return ans;
    }
};