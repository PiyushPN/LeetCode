// Last updated: 18/07/2026, 19:56:26
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> temp(n, 0);
        for(int i = 0; i<n; i++)
        {
            temp[edges[i]] += i;
        }
        long long ans = 0, mx = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(temp[i] > mx)
            {
                mx = temp[i];
                ans = i;
            }
        }
        return ans;
    }
};