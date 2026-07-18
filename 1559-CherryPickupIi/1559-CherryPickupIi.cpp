// Last updated: 18/07/2026, 19:58:32
class Solution {
public:
    int dp[71][71][71];
    int solve(vector<vector<int>>& grid, int i, int j, int n){
        if(i==grid.size() or j<0 or j>grid[0].size()-1 or n<0 or n>grid[0].size()-1){
            return 0;
        }
        if(dp[i][j][n]!=-1)
            return dp[i][j][n];
        int a = solve(grid,i+1,j-1,n-1);
        int b = solve(grid,i+1,j-1,n);
        int c = solve(grid,i+1,j-1,n+1);
        int d = solve(grid,i+1,j,n-1);
        int e = solve(grid,i+1,j,n);
        int f = solve(grid,i+1,j,n+1);
        int g = solve(grid,i+1,j+1,n-1);
        int h = solve(grid,i+1,j+1,n);
        int a1 = solve(grid,i+1,j+1,n+1);
        if(j==n){
            return dp[i][j][n] = grid[i][j]+max(a,max(b,max(c,max(d,max(e,max(f,max(g,max(h,a1))))))));
        }
        return dp[i][j][n] = grid[i][j]+grid[i][n]+max(a,max(b,max(c,max(d,max(e,max(f,max(g,max(h,a1))))))));
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,grid[0].size()-1);
    }
};