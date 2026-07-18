// Last updated: 18/07/2026, 19:57:13
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i=0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        int ans = 0;
        while(mp.find(original) != mp.end())
        {
            original = original*2;
        }
        return original;
    }
};