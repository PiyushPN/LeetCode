// Last updated: 18/07/2026, 19:56:19
class Solution {
public:
    static bool comp(pair<string, int> &p1, pair<string, int> &p2)
    {
        return p1.second>p2.second;
    }
        
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
            
        int n = names.size();
        vector<string> ans;
        vector<pair<string, int>> p(n);
        for(int i = 0; i < n; i++)
        {
            p[i].first = names[i];
            p[i].second = heights[i];
        }
        sort(p.begin(), p.end(), comp);
        for(int i = 0; i < n; i++)
        {
            ans.push_back(p[i].first);
        }
        return ans;
    }
};