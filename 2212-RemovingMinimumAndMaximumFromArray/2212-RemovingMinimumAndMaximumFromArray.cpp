// Last updated: 18/07/2026, 19:57:46
class Solution {
public:
    int minimumDeletions(vector<int>& nums)
    {
        int n = nums.size();
        if(n==1)
        {
            return 1;
        }
        int mn_index = 0, mx_index = 0;
        int mx = INT_MIN, mn = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < mn)
            {
                mn = nums[i];
                mn_index = i+1;
            }
            if(nums[i] > mx)
            {
                mx = nums[i];
                mx_index = i+1;
            }  
        }
        int left = 0, right = 0, lr = 0;
        if(mx_index > mn_index)
        {
            left = mx_index;
            right = n-mn_index+1;
            lr = mn_index + n-mx_index+1;
        }
        if(mn_index > mx_index)
        {
            left = mn_index;
            right = n-mx_index+1;
            lr = mx_index+n-mn_index+1;
        }
        return min(left,min(right, lr));
    }
        
};