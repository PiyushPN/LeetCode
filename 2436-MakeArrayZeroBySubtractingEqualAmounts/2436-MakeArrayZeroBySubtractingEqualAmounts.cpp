// Last updated: 18/07/2026, 19:56:38
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                continue;
            }
            for(int j = i+1; j<n; j++)
            {
                nums[j]-=nums[i];
            }
            ans++;
        }
        return ans;
    }
};