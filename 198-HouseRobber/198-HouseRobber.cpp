// Last updated: 18/07/2026, 20:02:04
class Solution {
public:
    int dp[101];
    int solve(int i,vector<int> & nums){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        int a=nums[i]+solve(i+2,nums);
        int b=solve(i+1,nums);
        return dp[i]=max(a,b);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};