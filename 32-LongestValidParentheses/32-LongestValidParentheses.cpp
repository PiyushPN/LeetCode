// Last updated: 18/07/2026, 20:04:29
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i]==')'){
                st.pop();
                if(!st.empty()){
                    ans=max(ans, i-st.top());
                } else {
                    st.push(i);
                }
            } else {
                st.push(i);
            }
        }
        return ans;
    }
};