// Last updated: 18/07/2026, 19:58:07
class Solution {
public:
  
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        long long ans = LONG_MAX;
        long long pre1[n+1];
        long long pre2[n+1];
        pre1[0] = grid[0][0];
        pre2[0] = grid[1][0];
        for(int i = 1; i < n; i++)
        {
            pre1[i] = pre1[i-1]+grid[0][i];
            pre2[i] = pre2[i-1]+grid[1][i];
        }
        for(int i = 0; i < n; i++)
        {
            long long ch1 = pre1[n-1]-pre1[i];
            long long ch2;
            if(i==0)
            {
                ch2 = 0;
            }
            else
            {
                ch2 = pre2[i-1];
            }
            ans = min(ans, max(ch1, ch2));
        }
        return ans;
    }
};