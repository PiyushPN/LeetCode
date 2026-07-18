// Last updated: 18/07/2026, 19:59:02
class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        int n = s.length();
        vector<int> vis(26, 0), cnt(26, 0);
        for(int i = 0; i < n; i++)
        {
            cnt[s[i]-'a']++;
        }
        for(int i = 0; i < n; i++)
        {
            cnt[s[i]-'a']--;
            if(vis[s[i]-'a'])
            {
                continue;
            }
            while(!st.empty() and st.top()>s[i] and cnt[st.top()-'a'] != 0)
            {
                vis[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a']=1;
        }
        string ans = "";
        while(!st.empty())
        {
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};