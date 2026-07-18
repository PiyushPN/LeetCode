// Last updated: 18/07/2026, 20:01:45
class Solution {
public:
    int dp[101];
    int solve(int i, vector<int> nums, int n)
    {
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        int a=nums[i]+solve(i+2,nums, n);
        int b=solve(i+1,nums, n);
        return dp[i]=max(a,b);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0], nums[1]);
        }
        int a = solve(0, nums, n-1);
        memset(dp, -1, sizeof(dp));
        int b = solve(1, nums, n);
        return max(a, b);
        
    }
};