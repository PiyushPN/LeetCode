// Last updated: 18/07/2026, 19:58:03
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mp;
        set<int> s1;
        set<int> s2;
        set<int> s3;
        for(auto i: nums1)
        {
            s1.insert(i);
        }
        for(auto i: nums2)
        {
            s2.insert(i);
        }
        for(auto i: nums3)
        {
            s3.insert(i);
        }
        for(auto i: s1)
        {
            mp[i]++;
        }
        for(auto i: s2)
        {
            mp[i]++;
        }
        for(auto i: s3)
        {
            mp[i]++;
        }
        vector<int> ans;
        for(auto it: mp)
        {
            if(it.second>=2)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};