// Last updated: 18/07/2026, 19:57:17
class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 1; i < n-1; i++)
        {
            int flag1 = 0, flag2 = 0;
            int j = i-1;
            while(j>=0)
            {
                if(nums[j] < nums[i])
                {
                    flag1 = 1;
                    break;
                }
                j--;
            }
            j = i+1;
            while(j<n)
            {
                if(nums[j] > nums[i])
                {
                    flag2 = 1;
                    break;
                }
                j++;
            }
            if(flag1 and flag2)
            {
                ans++;
            }
        }
        return ans;
        
    }
};