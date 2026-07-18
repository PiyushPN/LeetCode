// Last updated: 18/07/2026, 20:02:27
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n==1)
        {
            return 0;
        }
        int ans = INT_MIN;
        for(int i = 0; i < n-1; i++)
        {
            ans = max(ans, nums[i+1]-nums[i]);
        }
        return ans;
    }
};