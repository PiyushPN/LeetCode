// Last updated: 18/07/2026, 20:00:21
int dp[1001][2];
class Solution {
public:
    int solve(vector<int> &nums, int f, int i, int n)
    {
        if(i==n-1)
        {
            return 1;
        }
        if(dp[i][f] != -1)
        {
            return dp[i][f];
        }
        if(f==0)
        {
            if(nums[i+1] > nums[i])
            {
                return dp[i][f] = max(1+solve(nums, 1, i+1, n), solve(nums, 0, i+1, n));
            }
            else
            {
                return dp[i][f] = solve(nums, 0, i+1, n);
            }
        }
        else
        {
            if(nums[i+1]<nums[i])
            {
                return dp[i][f] = max(1+solve(nums, 0, i+1, n), solve(nums, 1, i+1, n));
            }
            else
            {
                return dp[i][f] = solve(nums, 1, i+1, n);
            }
        }
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return max(solve(nums, 0, 0, n), solve(nums, 1, 0, n));
        
    }
};