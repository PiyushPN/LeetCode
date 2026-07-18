// Last updated: 18/07/2026, 20:00:11
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != ']')
            {
                st.push(s[i]);
            }
            else
            {
                string temp = "";
                while(st.top() != '[')
                {
                    temp = st.top()+temp;
                    st.pop();
                }
                st.pop();
                string number = "";
                while(!st.empty() and isdigit(st.top()))
                {
                    number = st.top()+number;
                    st.pop();
                }
                int n = stoi(number);
                while(n--)
                {
                    for(int p=0; p<temp.size(); p++)
                    {
                        st.push(temp[p]);
                    }
                }
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};