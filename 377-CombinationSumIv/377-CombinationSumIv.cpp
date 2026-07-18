// Last updated: 18/07/2026, 20:00:24
int dp[201][1001];
class Solution {
public:
    int solve(vector<int> &nums, int i, int target)
    {
        if(target == 0)
        {
            return 1;
        }
       
        if(i==nums.size())
        {
            return 0;
        }
         if(dp[i][target] != -1)
         {
             return dp[i][target];
         }
        if(nums[i]<=target)
        {
            return dp[i][target] = solve(nums, 0, target-nums[i])+solve(nums, i+1, target);
        }
        else
        {
            return dp[i][target] = solve(nums, i+1, target);
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, target);
        
    }
};