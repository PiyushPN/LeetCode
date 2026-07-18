// Last updated: 18/07/2026, 19:59:30
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            while(!st.empty() and temp[st.top()] < temp[i]){
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};