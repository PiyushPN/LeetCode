// Last updated: 18/07/2026, 20:02:10
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> ans;
        if(s.length() <= 10)
        {
            return ans;
        }
        int i = 0;
        string temp = "";
        while(i < 10)
        {
            temp += s[i++];
        }
        mp[temp]++;
        // cout<<temp<<" ";
        for(i = 10; i < s.length(); i++)
        {
            temp = temp.substr(1);
            temp += s[i];
            // cout<<temp<<" ";
            mp[temp]++;
        }
        for(auto it: mp)
        {
            if(it.second > 1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};