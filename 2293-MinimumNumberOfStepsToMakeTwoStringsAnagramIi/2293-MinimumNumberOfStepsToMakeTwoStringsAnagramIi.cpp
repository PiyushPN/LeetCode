// Last updated: 18/07/2026, 19:57:05
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }
        for(int i = 0; i < t.length(); i++)
        {
            mp[t[i]]--;
        }
        int ans = 0;
        for(auto i: mp)
        {
            ans += abs(i.second);
        }
        return ans;
    }
};