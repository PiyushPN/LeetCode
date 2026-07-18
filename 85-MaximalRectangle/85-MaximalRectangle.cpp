// Last updated: 18/07/2026, 20:03:45
class Solution {
public:
    int solve(vector<int> grid, int n)
    {
        stack<int> st;
        vector<int> left(n);
        vector<int> right(n);
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() and grid[st.top()] >= grid[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                left[i] = st.top();
            }
            else
            {
               left[i] = -1;
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() and grid[st.top()] >= grid[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                right[i] = st.top();
            }
            else
            {
                right[i] = n;
            }
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int temp_ans = (right[i]-left[i]-1)*grid[i];
            ans = max(ans, temp_ans);
        }
        return ans;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                grid[i][j] = matrix[i][j]-'0';
            }
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    grid[i][j] += grid[i-1][j];
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            vector<int> temp(m);
            for(int k = 0; k < m; k++)
            {
                temp[k] = grid[i][k];
            }
            ans = max(ans, solve(temp , m));
        }
        return ans;
    }
};