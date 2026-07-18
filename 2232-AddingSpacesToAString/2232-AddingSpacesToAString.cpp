// Last updated: 18/07/2026, 19:57:36
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0, j = 0;
        string res = "";
        while(i<s.size() and j<spaces.size())
        {
            if(i==spaces[j])
            {
                res+=" ";
                j++;
            }
            res+=s[i];
            i++;
        }
        while(i<s.size())
        {
            res+=s[i];
            i++;
        }
        return res;
    }
};