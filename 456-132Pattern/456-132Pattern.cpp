// Last updated: 18/07/2026, 19:59:58
class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int n = nums.size();
        if(n < 3)
        {
            return false;
        }
        int preMin[n];
        preMin[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            preMin[i] = min(preMin[i-1], nums[i]);
        }
        stack<int> st;
        for(int i = n-1; i >= 0; i--)
        {
            if(nums[i] > preMin[i])
            {
                while(!st.empty() && st.top() <= preMin[i])
                {
                    st.pop();
                }
                if(!st.empty() && st.top() < nums[i])
                {
                    return true;
                }
                st.push(nums[i]);
                    
            }
        }
        return false;
        
    }
};