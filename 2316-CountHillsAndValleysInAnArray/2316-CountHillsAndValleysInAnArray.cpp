// Last updated: 18/07/2026, 19:56:57
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suff(n);
        pre[0] = -1;
        int ans = 0;
        suff[n-1] = -1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i-1]>nums[i] or nums[i-1]<nums[i])
            {
                pre[i] = i-1;
            }
            else
            {
                pre[i] = pre[i-1];
            }
        }
        for(int i = n-2; i>=0; i--)
        {
            if(nums[i+1]>nums[i] or nums[i+1]<nums[i])
            {
                suff[i] = i+1;
            }
            else
            {
                suff[i] = suff[i+1];
            }
        }
        for(int i = 1; i < n-1; i++)
        {
            if(suff[i]!=-1 and pre[i]!=-1 and suff[i]!=suff[i-1] and pre[i]!=pre[i-1] and ((nums[pre[i]] < nums[i] and nums[suff[i]]<nums[i]) or (nums[pre[i]] > nums[i] and nums[suff[i]]>nums[i])))
            {
                ans++;
            }
        }
        return ans;
    }
};