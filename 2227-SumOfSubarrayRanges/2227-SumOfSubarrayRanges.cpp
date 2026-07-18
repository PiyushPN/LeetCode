// Last updated: 18/07/2026, 19:57:40
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int mx = nums[i], mn = nums[i];
            for(int j = i+1; j < n; j++)
            {
                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);
                ans+=(mx-mn);
            }
        }
        return ans;
    }
};