// Last updated: 18/07/2026, 20:02:32
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = *max_element(nums.begin(), nums.end());
        int temp1 = 1, temp2 = 1;
        int n = nums.size();
        int i = 0, j = n-1;
        for(i = 0, j = n-1; i < n and j >= 0; i++, j--)
        {
            
            temp1 *= nums[i];
            temp2 *= nums[j];
            ans = max(ans, max(temp1, temp2));
            if(temp1 == 0)
            {
                temp1 = 1;
            }
            if(temp2 == 0)
            {
                temp2 = 1;
            }
        }
        return ans;
	    // long long pref = 1, suff = 1, res = INT_MIN;
	    // for(int i=0; i<n; i++) {
	    //     pref *= nums[i];
	    //     suff *= nums[n-i-1];
	    //     res = max(res, max(pref, suff));
	    //     if(pref == 0) pref = 1;
	    //     if(suff == 0) suff = 1;
	    // }
	    //return res;
    }
};