// Last updated: 18/07/2026, 20:01:54
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp, mp1;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if((mp.find(s[i]) != mp.end() and mp[s[i]] != t[i]) or (mp1.find(t[i]) != mp1.end() and mp1[t[i]] != s[i]))
            {
                return false;
            }
            mp[s[i]] = t[i];
            mp1[t[i]] = s[i];
        }
        return true;
    }
};