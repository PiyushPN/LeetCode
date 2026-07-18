// Last updated: 18/07/2026, 19:58:09
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int temp = nums[j] - nums[i];
                if(temp > 0)
                {
                    ans = max(temp, ans);
                }
            }
        }
        return ans;
    }
};