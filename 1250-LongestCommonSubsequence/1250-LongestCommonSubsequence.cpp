// Last updated: 18/07/2026, 19:58:59
class Solution {
public:
    int dp[1001][1001];
    int lcs(string &s1, string &s2, int i, int j, int n1, int n2){
        if(i==n1 or j==n2){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j] = 1+lcs(s1, s2, i+1, j+1, n1, n2);
        }
        else{
            return dp[i][j] = max(lcs(s1, s2, i+1, j, n1, n2), lcs(s1, s2, i, j+1, n1, n2));
        }

    }
    int longestCommonSubsequence(string text1, string text2) {
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j]=-1;
            }
        }
        int n1 = text1.size();
        int n2 = text2.size();
        return lcs(text1, text2, 0, 0, n1, n2);
        
    }
};