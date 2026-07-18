// Last updated: 18/07/2026, 19:56:17
class Solution {
public:
    bool checkDistances(string s, vector<int>& dis) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                int ind1 = mp[s[i]];
                int ind2 = i;
                if(ind2-ind1-1 != dis[s[i]-'a'])
                {
                    return false;
                }
            }
            else
            {
                mp[s[i]] = i;
            }
        }
        return true;
        
    }
};