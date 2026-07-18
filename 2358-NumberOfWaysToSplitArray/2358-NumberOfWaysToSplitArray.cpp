// Last updated: 18/07/2026, 19:56:43
class Solution {
public:
    int waysToSplitArray(vector<int>& nums1) 
    {
        
        int n = nums1.size();
        vector<long long> nums(begin(nums1), end(nums1));
        long long sum = accumulate(nums.begin(), nums.end(), (long long)0);
        int ans = 0;
        if(nums[0] >= sum-nums[0] )
        {
            ans++;
        }
        for(int i = 1; i < n-1; i++)
        {
            nums[i] = nums[i-1]+nums[i];
            if(nums[i] >= sum-nums[i])
            {
                ans++;
            }
        }
        return ans;
    }
};