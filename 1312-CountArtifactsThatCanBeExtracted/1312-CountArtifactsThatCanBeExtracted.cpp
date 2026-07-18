// Last updated: 18/07/2026, 19:58:53
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& art, vector<vector<int>>& dig) {
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        int count = 0;
        for(int i = 0; i < dig.size(); i++)
        {
            vis[dig[i][0]][dig[i][1]] = true;
        }
        for(auto it: art)
        {
            int r1 = it[0];
            int r2 = it[2];
            int c1 = it[1];
            int c2 = it[3];
            bool flag = true;
            for(int j = r1; j <= r2; j++)
            {
                for(int k = c1; k <= c2; k++)
                {
                    if(!vis[j][k])
                    {
                        flag = false;
                        break;
                    }
                }    
            }
            if(flag)
            {
                count++;
            }
        }
        return count;
        
    }
};