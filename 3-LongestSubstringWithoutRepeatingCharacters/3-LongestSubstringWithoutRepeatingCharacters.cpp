// Last updated: 18/07/2026, 20:04:37
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int ans=0;
        int i=0, j=0, n=s.length();
        while(i<n and j<n){
            if(st.count(s[j])==0){
                st.insert(s[j]);
                ans = max(ans, j-i+1);
                j++;
            } else {
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};