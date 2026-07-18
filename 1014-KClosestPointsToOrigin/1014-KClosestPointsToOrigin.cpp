// Last updated: 18/07/2026, 19:59:08
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        vector<vector<int>> ans;
        int n=points.size();
        for(int i=0; i<n; i++){
            double dis = sqrt((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            pq.push({dis, i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            int data = pq.top().second;
            pq.pop();
            ans.push_back(points[data]);
        }
        return ans;
    }
};