// Last updated: 18/07/2026, 19:59:10
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++){
            if(nums[i] <= nums[i-1]){
                ans += nums[i-1]+1-nums[i];
                nums[i] = nums[i-1]+1;
            }
        }
        return ans;
    }
};