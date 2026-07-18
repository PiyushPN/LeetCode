// Last updated: 18/07/2026, 19:57:24
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int one = 0;
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
            {
                one++;
            }
        }
        int temp = 0;
        for(int i = 0; i < one; i++)
        {
            if(nums[i]==0)
            {
                temp++;
            }
        }
        ans = temp;
        for(int i = 1; i < n; i++)
        {
            int j = (i+one-1)%n;
            if(nums[i-1]==0)
            {
                temp--;
            }
            if(nums[j]==0)
            {
                temp++;
            }
            ans = min(ans, temp);
        }
        return ans;
    }
};