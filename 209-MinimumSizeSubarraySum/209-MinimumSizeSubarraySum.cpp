// Last updated: 18/07/2026, 20:01:48
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0;
        while(j<n)
        {
            sum += nums[j];
            if(sum == target)
            {
                ans = min(ans, j-i+1);
                j++;
            }
            else if(sum > target)
            {
                ans = min(ans, j-i+1);
                sum -= nums[i++];
                sum -= nums[j];
            }
            else
            {
                j++;
            }
        }
        if(ans == INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};