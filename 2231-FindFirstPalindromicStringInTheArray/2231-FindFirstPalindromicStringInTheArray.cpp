// Last updated: 18/07/2026, 19:57:37
class Solution {
public:
    string firstPalindrome(vector<string>& s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(equal(s[i].begin(), s[i].begin()+s[i].size()/2, s[i].rbegin()))
            {
                ans = s[i];
                break;
            }
        }
        return ans;
    }
};