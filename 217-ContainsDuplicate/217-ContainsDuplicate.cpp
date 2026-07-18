// Last updated: 18/07/2026, 20:01:42
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        return n != st.size();
    }
};