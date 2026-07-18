// Last updated: 18/07/2026, 19:59:52
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }
        int count = 0;
        while(!q.empty())
        {
            int size = q.size();
            count++;
            for(int k = 0; k < size; k++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i+1<n and mat[i+1][j] == 1)
                {
                    ans[i+1][j] = count;
                    q.push({i+1, j});
                    mat[i+1][j] = 0;
                }
                if(i-1>=0 and mat[i-1][j] == 1)
                {
                    ans[i-1][j] = count;
                    q.push({i-1, j});
                    mat[i-1][j] = 0;
                }
                if(j+1<m and mat[i][j+1] == 1)
                {
                    ans[i][j+1] = count;
                    q.push({i, j+1});
                    mat[i][j+1] = 0;
                }
                if(j-1>=0 and mat[i][j-1] == 1)
                {
                    ans[i][j-1] = count;
                    q.push({i, j-1});
                    mat[i][j-1] = 0;
                }
            }
        }
        return ans;
    }
};