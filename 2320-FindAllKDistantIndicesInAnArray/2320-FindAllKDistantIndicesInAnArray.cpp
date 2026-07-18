// Last updated: 18/07/2026, 19:56:53
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> index, ans;
        set<int> s;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == key)
            {
                index.push_back(i);
            }
        }
        for(int i = 0; i < index.size(); i++)
        {
            int m = index[i];
            for(int j = 0; j < n; j++)
            {
                if(abs(m-j) <= k)
                {
                    s.insert(j);
                }
            }
        }
        for(auto it: s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};