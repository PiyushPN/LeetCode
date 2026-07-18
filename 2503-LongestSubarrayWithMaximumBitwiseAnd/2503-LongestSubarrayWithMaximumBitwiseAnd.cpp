// Last updated: 18/07/2026, 19:56:18
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 1, mxlen = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == mx)
            {
                mxlen++;
                ans = max(ans, mxlen);
            }
            else
            {
                mxlen = 0;
            }
        }
        return ans;
    }
};