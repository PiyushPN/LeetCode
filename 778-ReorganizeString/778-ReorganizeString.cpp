// Last updated: 18/07/2026, 19:59:27
class Solution {
public:
    static bool cmp(pair<char, int> &p1, pair<char, int> &p2)
    {
        return p1.second > p2.second;
    }
    string reorganizeString(string s) {
        map<char, int> mp;
        int c1 = INT_MIN;
        for(auto i: s)
        {
            mp[i]++;
            c1 = max(c1, mp[i]);
        }
        if(c1 > (s.size()+1)/2)
        {
            return "";
        }
        vector<pair<char, int>> v;
        for(auto it: mp)
        {
            v.push_back(it);
        }
        sort(v.begin(), v.end(), cmp);
        int start = 0;
        for(auto it: v)
        {
            while(it.second--)
            {
                s[start] = it.first;
                start+=2;
                if(start >= s.size())
                {
                    start = 1;
                }
            }
        }
        return s;
    }
};