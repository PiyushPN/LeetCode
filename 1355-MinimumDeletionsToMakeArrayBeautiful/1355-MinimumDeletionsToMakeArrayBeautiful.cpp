// Last updated: 18/07/2026, 19:58:45
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n-1; i++)
        {
            if((i+ans)%2==0)
            {
                if(nums[i] == nums[i+1])
                {
                    ans++;
                }
            }
        }
        if((n-ans)%2==1)
        {
            ans++;
        }
        return ans;
    }
};