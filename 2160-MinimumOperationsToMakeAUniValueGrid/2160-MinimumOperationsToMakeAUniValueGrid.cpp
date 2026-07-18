// Last updated: 18/07/2026, 19:58:02
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        int target = nums[(m*n)/2];  
        int ans = 0;
        for(int i = m*n-1; i >= 0; i--)
        {
            if(abs(nums[i]-target)%x != 0)
            {
                return -1;
            }
            else
            {
                ans+=abs(nums[i]-target)/x;
            }
        }
        return ans;
        
    }
};