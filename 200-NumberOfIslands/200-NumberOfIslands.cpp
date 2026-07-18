// Last updated: 18/07/2026, 20:02:01
class Solution {
public:
    int ans = 0;
    void solve(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i<0 or j<0 or i>=m or j>=n or grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';
        solve(grid, i+1, j, m, n);
        solve(grid, i, j+1, m, n);
        solve(grid, i-1, j, m, n);
        solve(grid, i, j-1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    solve(grid, i, j, m, n);
                }
            }
        }
        return ans;
    }
};