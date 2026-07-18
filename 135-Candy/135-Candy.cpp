// Last updated: 18/07/2026, 20:02:52
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n<=1)
        {
            return n;
        }
        vector<int> nums(n, 1);
        for(int i = 1; i < n; i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                nums[i] = nums[i-1]+1;
            }
        }
        for(int i = n-1; i > 0; i--)
        {
            if(ratings[i-1] > ratings[i])
            {
                nums[i-1] = max(nums[i]+1, nums[i-1]);
            }
        }
        int ans = accumulate(nums.begin(), nums.end(), 0);
        return ans;
    }
};