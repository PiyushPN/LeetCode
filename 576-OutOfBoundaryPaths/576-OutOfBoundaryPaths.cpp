// Last updated: 18/07/2026, 19:59:44
class Solution {
public:
    int M = 1000000007;
    int solve(int m, int n, int i, int j, int move, vector<vector<vector<int>>> &dp){
        if(i<0 or j<0 or i>=m or j>=n){
            return 1;
        }
        if(move == 0){
            return 0;
        }
        if(dp[move][i][j] != -1){
            return dp[move][i][j]%M;
        }
        int temp = 0;
        temp = (temp+solve(m, n, i-1, j, move-1, dp))%M;
        temp = (temp+solve(m, n, i+1, j, move-1, dp))%M;
        temp = (temp+solve(m, n, i, j-1, move-1, dp))%M;
        temp = (temp+solve(m, n, i, j+1, move-1, dp))%M;
        return dp[move][i][j] = temp%M;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>> (m+1, vector<int> (n+1, -1))); 
        return solve(m, n, startRow, startColumn, maxMove, dp);
    }
};