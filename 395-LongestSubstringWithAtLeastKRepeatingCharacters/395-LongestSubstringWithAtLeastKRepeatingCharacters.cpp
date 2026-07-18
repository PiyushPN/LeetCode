// Last updated: 18/07/2026, 20:00:07
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0 or k>s.size())
        {
            return 0;
        }
        if(k==0)
        {
            return s.size();
        }
        unordered_map<int, int> mp;
        for(auto c: s)
        {
            mp[c]++;
        }
        int i = 0;
        while(i<s.size() and mp[s[i]]>=k)
        {
            i++;
        }
        if(i==s.size())
        {
            return s.size();
        }
        int left = longestSubstring(s.substr(0,i), k);
        int right = longestSubstring(s.substr(i+1), k);
        return max(left, right);
    }
};