// Last updated: 18/07/2026, 20:01:17
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        int n=s.length();
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it:mp){
            if(it.second){
                return false;
            }
        }
        return true;
    }
};