// Last updated: 18/07/2026, 19:57:48
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        long long sum = 0;
        int len = 2*k+1;
        if(n < len)
        {
            return ans;
        }
        int i = 0;
        for(i = 0; i <= 2*k; i++)
        {
            sum+=nums[i];
        }
        long long temp = sum/len;
        ans[i-k-1] = temp;
        int j = 0;
        while(i<n)
        {
            sum += nums[i++];
            sum -= nums[j++];
            temp = sum/len;
            ans[i-k-1] = temp;
        }
        return ans;
    }
};