// Last updated: 18/07/2026, 19:58:20
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k==1)
        {
            return 0;
        }
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());   //1 4 7 9
        for(int i = 0; i <= n-k; i++)
        {
            int temp = nums[i+k-1] - nums[i];
            ans = min(ans, temp);
        }
        return ans;
        
    }
};