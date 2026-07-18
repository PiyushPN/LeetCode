// Last updated: 18/07/2026, 20:00:17
class Solution {
public:
    bool canConstruct(string ran, string mag) {
        unordered_map<char, int> mp;
        int n = mag.size();
        int m = ran.size();
        for(int i=0; i<n; i++)
        {
            mp[mag[i]]++;
        }
        for(int i=0; i<m; i++)
        {
            if(mp.find(ran[i]) != mp.end() and mp[ran[i]] != 0)
            {
                mp[ran[i]]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};