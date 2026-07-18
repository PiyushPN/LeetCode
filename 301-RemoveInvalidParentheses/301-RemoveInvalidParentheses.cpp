// Last updated: 18/07/2026, 20:01:04
class Solution {
public:
    unordered_map<string, int> tle;
    int minR(string s)
    {
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')')
            {
                if(st.empty())
                {
                    st.push(s[i]);
                }
                else if(st.top() == ')')
                {
                    st.push(s[i]);
                }
                else if(st.top() == '(')
                {
                    st.pop();
                }
            }    
        }
        return st.size();
    }
    void solve(string s, int mra, unordered_map<string, int> &mp, vector<string> &ans)
    {
        if(mra == 0){
            int mrnow = minR(s);
            if(mrnow == 0)
            {
                if(mp.find(s) == mp.end())
                {
                    ans.push_back(s);
                }
                mp[s]++;
            }
            return;
        }
        if(tle.find(s) != tle.end())
        {
            return;
        }
        tle[s]++;
        for(int i = 0; i < s.length(); i++)
        {
            if(isalpha(s[i]))
            {
                continue;
            }
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            solve(left+right, mra-1, mp, ans);
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        int mr = minR(s);
        unordered_map<string, int> mp;
        vector<string> ans;
        solve(s, mr, mp, ans);
        return ans;
        
    }
};