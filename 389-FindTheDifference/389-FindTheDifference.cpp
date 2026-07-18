// Last updated: 18/07/2026, 20:00:09
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }
        for(int i = 0; i < t.length(); i++)
        {
            if(mp.find(t[i]) == mp.end() or mp[t[i]] == 0)
            {
                return t[i];
            }
            mp[t[i]]--;
        }
        return '-1';
    }
};