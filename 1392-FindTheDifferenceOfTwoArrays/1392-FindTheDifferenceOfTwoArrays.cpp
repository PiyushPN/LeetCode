// Last updated: 18/07/2026, 19:58:42
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();
        for(int i = 0; i < n; i++)
        {
            mp1[nums1[i]]++;
        }
        for(int i = 0; i < m; i++)
        {
            mp2[nums2[i]]++;
        }
        vector<int> temp;
        for(auto it: mp1)
        {
            
            if(mp2.find(it.first) == mp2.end())
            {
                temp.push_back(it.first);
            }
            
        }
        ans.push_back(temp);
        temp.clear();
        for(auto it: mp2)
        {
            if(mp1.find(it.first) == mp1.end())
            {
                temp.push_back(it.first);
            }
            
        }
        ans.push_back(temp);
        return ans;
    }
};