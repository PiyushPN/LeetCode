// Last updated: 18/07/2026, 20:03:12
class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,int n,vector<vector<int>>& triangle){
        if(i==n){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=triangle[i][j]+min(solve(i+1,j,n,triangle),solve(i+1,j+1,n,triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n,triangle);
    }
};