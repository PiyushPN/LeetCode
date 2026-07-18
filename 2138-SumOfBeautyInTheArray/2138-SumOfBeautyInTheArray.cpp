// Last updated: 18/07/2026, 19:58:10
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int ans = 0;
        int mx = nums[0];
        int n = nums.size();
        int greater = nums[n-1];
        vector<int> mn(n);
        
        for(int i = n-2; i >= 1; i--)
        {
            mn[i] = greater;
            greater = min(greater, nums[i]);
        }
        for(int i = 1; i < n-1; i++)
        {
            if(nums[i] > mx and nums[i] < mn[i])
            {
                
                ans+=2;
            }
            else if(nums[i-1] < nums[i] and nums[i] < nums[i+1])
            {
                ans+=1;
            }
            mx = max(mx, nums[i]);
        }
        return ans;
    }
};