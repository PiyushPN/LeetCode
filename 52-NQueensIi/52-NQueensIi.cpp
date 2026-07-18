// Last updated: 18/07/2026, 20:04:02
class Solution {
public:
    bool isSafe(int noq, int col, vector<vector<int>> &visited, int n)
    {
        for(int i = 0; i < noq; i++)
        {
            if(visited[i][col] == 1)
            {
                return false;
            }
        }
        int i = noq, j = col;
        while(i >= 0 and j >= 0)
        {
            if(visited[i][j] == 1)
            {
                return false;
            }
            i--;
            j--;
        }
        i = noq, j = col;
        while(i < n and j < n)
        {
            if(visited[i][j] == 1)
            {
                return false;
            }
            i++;
            j++;
        }
        i = noq, j = col;
        while(i >= 0 and j < n)
        {
            if(visited[i][j] == 1)
            {
                return false;
            }
            i--;
            j++;
        }
        i = noq, j = col;
        while(i < n and j >= 0)
        {
            if(visited[i][j] == 1)
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int noq, int n, int &ans, vector<vector<int>> &visited)
    {
        if(noq == n)
        {
            ans++;
            return;
        }
        for(int col=0; col < n; col++)
        {
            if(isSafe(noq, col, visited, n))
            {
                visited[noq][col] = 1;
                solve(noq+1, n, ans, visited);
                visited[noq][col] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(n,0));
        int noq = 0;
        solve(noq, n, ans, visited);
        return ans;
    }
};