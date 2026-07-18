// Last updated: 18/07/2026, 20:02:22
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for(auto it: nums)
        {
            mp[it]++;
            if(mp[it] > n/2)
            {
                ans = it;
                break;
            }
        }
        return ans;
    }
};