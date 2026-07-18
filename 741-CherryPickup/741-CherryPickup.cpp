// Last updated: 18/07/2026, 19:59:28
class Solution {
public:
   int dp[51][51][51];
    int solve(vector<vector<int>> &grid,int r1,int c1,int c2,int n){
        int r2=r1+c1-c2;
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;
        if(dp[r1][c1][c2]!=-1)
            return dp[r1][c1][c2];
        if(r1==n-1 && c1==n-1){
            return grid[r1][c1];
        }
        int cherries=grid[r1][c1];
        if(r1!=r2){
            cherries+=grid[r2][c2];
        }
        int sum1=solve(grid,r1,c1+1,c2+1,n);
        int sum2=solve(grid,r1+1,c1,c2,n);
        int sum3=solve(grid,r1,c1+1,c2,n);
        int sum4=solve(grid,r1+1,c1,c2+1,n);
        cherries+=max(max(sum1,sum2),max(sum3,sum4));
        dp[r1][c1][c2]=cherries;
        return cherries;
    }
    int cherryPickup(vector<vector<int>>& grid){
        int n=grid.size();
        memset(dp,-1,sizeof dp);
        return max(0,solve(grid,0,0,0,n));
    }
};