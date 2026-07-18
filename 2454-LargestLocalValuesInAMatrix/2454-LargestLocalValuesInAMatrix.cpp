// Last updated: 18/07/2026, 19:56:29
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid)
    {
        int mx = INT_MIN;
        for(int x=i; x<i+3; x++)
        {
            for(int y=j; y<j+3; y++)
            {
                mx = max(mx, grid[x][y]);
            }
        }
        return mx;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int> (n-2));
        for(int i = 0; i<n-2; i++)
        {
            for(int j = 0; j < n-2; j++)
            {
                ans[i][j] = solve(i, j, grid);
            }
        }
        return ans;
    }
};