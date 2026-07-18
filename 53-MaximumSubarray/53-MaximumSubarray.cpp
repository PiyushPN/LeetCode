// Last updated: 18/07/2026, 20:04:03
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, mx = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mx += nums[i];
            ans = max(ans, mx);
            if(mx<0){
                mx=0;
            }
        }
        return ans;
    }
};