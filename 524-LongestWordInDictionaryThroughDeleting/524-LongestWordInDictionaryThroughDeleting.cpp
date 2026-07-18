// Last updated: 18/07/2026, 19:59:50
class Solution {
public:
    bool solve(string s, string s1, int n)
    {
        int n1 = s1.length();
        int i = 0, j= 0;
        for(i = 0, j = 0; i < n and j < n1;)
        {
            if(s[i] == s1[j])
            {
                i++, j++;
            }
            else
            {
                i++;
            }
        }
        if(j == n1)
        {
            return true;
        }
        return false;
    }
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        int n = d.size();
        int n1 = s.length();
        for(int i = 0; i < n; i++)
        {
            int m = d[i].length();
            if(m >= ans.length() or m < n1)
            {
                if(solve(s, d[i], n1))
                {
                    string temp = d[i];
                    if(temp.size() > ans.size() || (temp.size() == ans.size() and temp < ans))
                    {
                        ans = d[i];
                    }
                }
            }
        }
        return ans;
    }
};