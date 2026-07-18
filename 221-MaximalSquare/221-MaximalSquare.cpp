// Last updated: 18/07/2026, 20:01:38
class Solution {
public:
//     int dp[301][301];
//     int ans = 0;
//     int solve(int i, int j, vector<vector<char>> &mat, int n, int m)
//     {
//         if(i>=n or j>=m)
//         {
//             return 0;
//         }
//         if(dp[i][j] != -1)
//         {
//             return dp[i][j];
//         }
//         int temp = solve(i+1, j, mat, n, m)
//         if(mat[i][j] == '1')
//         {
//             dp[i][j] = 1+min(solve(i+1, j, mat, n, m)-'0', min(solve(i, j+1, mat, n, m)-'0', solve(i+1, j+1, mat, n, m)-'0'));
//             ans = max(ans, dp[i][j]);
//             return dp[i][j];
            
//         }
//         return dp[i][j] = 0;
//     }
        
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         memset(dp, -1, sizeof(dp));
//         solve(0, 0, matrix, n, m);
//         return ans*ans;
//     }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // int dp[301][301];
    // int solve(int i,int j,int n,int m,vector<vector<char>>& matrix){
    //     if(i==n or j==m or matrix[i][j])
    // }
    int maximalSquare(vector<vector<char>>& matrix) {
        // memset(dp,-1,sizeof(dp));
        int n=matrix.size();
        int m=matrix[0].size();
        // return solve(0,0,n,m,matrix);
        
        int dp[301][301];
        int mx=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    if(i==0 or j==0){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                    }
                }
                else{
                    dp[i][j]=0;
                }
                mx=max(mx,dp[i][j]);
            }
        }
        return mx*mx;
    }
    
    
    
    
    
    
    
    
    
    
    
    
};