// Last updated: 18/07/2026, 19:58:37
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mp;
        int ans=0;
        int n = s.length();
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it: mp){
            if(it.second>0){
                ans+=it.second;
            }
        }
        return ans;
    }
};