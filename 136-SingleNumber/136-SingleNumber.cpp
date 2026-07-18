// Last updated: 18/07/2026, 20:02:51
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};