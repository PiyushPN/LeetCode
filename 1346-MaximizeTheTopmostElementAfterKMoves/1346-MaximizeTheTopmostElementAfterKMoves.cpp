// Last updated: 18/07/2026, 19:58:48
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k==0)
        {
            return nums[0];
        }
        int n = nums.size();
        if(k%2!=0 and nums.size()==1)
        {
            return -1;
        }
        int mx = INT_MIN;
        int i = 0;
        while(i<n and i<k-1)
        {
            mx = max(mx, nums[i]);
            i++;
        }
        int temp = 0;
        if(k<n)
        {
            temp = nums[k];
        }
        return max(mx, temp);
    }
};