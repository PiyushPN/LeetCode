// Last updated: 18/07/2026, 20:00:36
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto i: mp){
            pq.push({i.second, i.first});
            if(pq.size()>mp.size()-k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};