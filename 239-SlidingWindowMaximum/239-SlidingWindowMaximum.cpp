// Last updated: 18/07/2026, 20:01:19
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        int j=k;
        int n = nums.size();
        for(int i=0; i<k; i++){
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);
        while(j<n){
            while(!pq.empty() and pq.top().second<=j-k){
                pq.pop();
            }
            pq.push({nums[j], j});
            ans.push_back(pq.top().first);
            j++;
        }
    return ans;
    }
};