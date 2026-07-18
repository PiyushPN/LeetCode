// Last updated: 18/07/2026, 19:59:07
class Solution {
public:
    int ans = 0;
    void dfs(int row, int col, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &vis)
    {
        if(row<0 or col<0 or row>=m or col>=n or grid[row][col] == -1 or vis[row][col])
        {
            return;
        }
        if(grid[row][col] == 2)
        {
            int flag = 1;
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(grid[i][j] == 0 and vis[i][j] != true)
                    {
                        flag = 0;
                    }
                }
            }
            if(flag == 1)
            {
                ans++;
            }
            return;
        }
        vis[row][col] = true;
        dfs(row-1, col, grid, m, n, vis);
        dfs(row, col-1, grid, m, n, vis);
        dfs(row, col+1, grid, m, n, vis);
        dfs(row+1, col, grid, m, n, vis);
        vis[row][col] = false;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x = 0, y = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, false));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    x=i;
                    y=j;
                }
            }
        }
        dfs(x, y, grid, m, n, vis);
        return ans;
    }
};