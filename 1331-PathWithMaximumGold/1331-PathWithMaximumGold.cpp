// Last updated: 18/07/2026, 19:58:52
class Solution {
public:
    int ans = 0;
    int solve(int i, int j, vector<vector<int>>& grid, int m, int n, int sum){
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j] == 0){
            return 0;
        }
        int tmp = grid[i][j];
        grid[i][j] = 0;
        int s1 = solve(i, j+1, grid, m, n, sum);
        int s2 = solve(i, j-1, grid, m, n, sum);
        int s3 = solve(i+1, j, grid, m, n, sum);
        int s4 = solve(i-1, j, grid, m, n, sum);
        grid[i][j] = tmp;
        return tmp+max({s1, s2, s3, s4});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] != 0){
                    int sum = 0;
                    int temp_ans = solve(i, j, grid, m, n, sum);
                    ans = max(ans, temp_ans);
                }
            }
        }
        return ans;
    }
};