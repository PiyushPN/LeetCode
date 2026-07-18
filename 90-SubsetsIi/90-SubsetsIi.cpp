// Last updated: 18/07/2026, 20:03:42
class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> nums, vector<int> temp1, set<vector<int>> &s, int n)
    {
        if(n==0)
        {
            s.insert(temp1);
            //ans.push_back(temp1);
            return;
        }
        temp1.push_back(nums[n-1]);
        solve(nums, temp1, s, n-1);
        temp1.pop_back();
        solve(nums, temp1, s, n-1);
            
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp1;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        int n = nums.size();
        solve(nums, temp1, s, n);
        for(auto i:s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};