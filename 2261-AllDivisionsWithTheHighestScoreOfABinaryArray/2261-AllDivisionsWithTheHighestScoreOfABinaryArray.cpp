// Last updated: 18/07/2026, 19:57:21
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n+1);
        vector<int> right(n+1);
        left[0] = 0;
        right[n] = 0;
        for(int i = 1; i <= n; i++)
        {
            if(nums[i-1] == 0)
            {
                left[i] = left[i-1]+1;
            }
            else
            {
                left[i] = left[i-1];
            }
        }
        for(int i = n-1; i >= 0; i--)
        {
            if(nums[i] == 1)
            {
                right[i] = 1+right[i+1];
            }
            else
            {
                right[i] = right[i+1];
            }
        }
        int mx = INT_MIN;
        vector<int> ans;
        for(int i = 0; i <=n; i++)
        {
            mx = max(mx, left[i]+right[i]);
        }
        for(int i = 0; i <= n; i++)
        {
            if(left[i]+right[i] == mx)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};