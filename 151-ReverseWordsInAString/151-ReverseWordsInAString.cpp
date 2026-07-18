// Last updated: 18/07/2026, 20:02:34
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        stringstream ss(s);
        string word;
        while(ss>>word)
        {
            st.push(word);
        }
        string ans = "";
        int n = st.size();
        int i = 0;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
            if(i != n-1)
            {
                ans += " ";
            }
            i++;
        }
        return ans;
    }
};