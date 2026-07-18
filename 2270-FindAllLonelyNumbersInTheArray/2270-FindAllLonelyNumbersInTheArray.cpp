// Last updated: 18/07/2026, 19:57:16
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            if(mp[nums[i]] == 1 and mp.find(nums[i]-1) == mp.end() and mp.find(nums[i]+1) == mp.end())
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};