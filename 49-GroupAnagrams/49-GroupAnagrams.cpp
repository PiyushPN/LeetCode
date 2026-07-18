// Last updated: 18/07/2026, 20:04:06
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        int n = s.size();
        for(int i=0; i<n; i++){
            string tmp=s[i];
            sort(s[i].begin(), s[i].end());
            mp[s[i]].push_back(tmp);
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};