// Last updated: 18/07/2026, 19:59:34
class Solution {
public:
    int ans=0;
    void solve(vector<vector<int>>& grid, int i, int j, int m, int n, int &temp_ans){
        if(i<0 or j<0 or i>=m or j>=n or grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        ++temp_ans;
        solve(grid, i+1, j, m, n, temp_ans);
        solve(grid, i-1, j, m, n, temp_ans);
        solve(grid, i, j+1, m, n, temp_ans);
        solve(grid, i, j-1, m, n, temp_ans);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    int temp_ans=0;
                    solve(grid, i, j, m, n, temp_ans);
                    ans=max(ans, temp_ans);
                }
            }
        }
        return ans;
    }
};