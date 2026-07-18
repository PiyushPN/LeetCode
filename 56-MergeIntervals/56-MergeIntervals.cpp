// Last updated: 18/07/2026, 20:04:00
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;
        sort(v.begin(), v.end());
        int n = v.size();
        if(n==1){
            return v;
        }
        int f = v[0].front(), l = v[0].back();
        for(int i = 0; i < n-1; i++){
            if(l>=v[i+1].front()){
                l = max(l, v[i+1].back());
            }
            else{
                ans.push_back({f,l});
                f=v[i+1].front();
                l=v[i+1].back();
            }
        }
        ans.push_back({f,l});
        return ans;
    }
};