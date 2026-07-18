// Last updated: 18/07/2026, 20:04:27
class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char> st;
        int i=0;
        while(i<n){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            } else {
                if(st.empty()){
                    return false;
                }
                char ch=st.top();
                st.pop();
                if((ch=='[' and s[i]!=']') or (ch=='{' and s[i]!='}') or (ch=='(' and s[i]!=')')){
                    return false;
                }
            }
            i++;
        }
        return st.empty();
    }
};