// Last updated: 18/07/2026, 19:59:16
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();
        stack<pair<int, int>> st;
        stack<pair<int, int>> st1;
        st.push({arr[0], 1});
        long long left[n];
        long long right[n];
        st1.push({arr[n-1], 1});
        left[0] = 1;
        right[n-1] = 1;
        for(int i = 1; i < n; i++)
        {
            if(!st.empty() && st.top().first < arr[i])
            {
                st.push({arr[i], 1});
                left[i] = 1;
            }
            else
            {
                int count = 0;
                while(!st.empty() && st.top().first >= arr[i])
                {
                    count += st.top().second;
                    st.pop();
                }
                st.push({arr[i], count+1});
                left[i] = count+1;           
            }  
        }
        for(int i = n-2; i >=0; i--)
        {
            if(!st1.empty() && st1.top().first < arr[i])
            {
                st1.push({arr[i], 1});
                right[i] = 1;
            }
            else
            {
                int count = 0;
                while(!st1.empty() && st1.top().first > arr[i])
                {
                    count += st1.top().second;
                    st1.pop();
                }
                st1.push({arr[i], count+1});
                right[i] = count+1;
                    
            }
        }
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            ans = (ans + arr[i]*left[i]*right[i])%1000000007;
        }
        return ans%1000000007;
    }
    
};