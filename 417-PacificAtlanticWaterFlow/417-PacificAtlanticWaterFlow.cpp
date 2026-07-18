// Last updated: 18/07/2026, 20:00:03
class Solution {
public:
    void bfs(vector<vector<int>> &h, queue<pair<int, int>> &q, vector<vector<bool>> &vis, int m, int n){
        vector<pair<int, int>> dirs={{0,-1}, {0,1}, {-1,0}, {1,0}};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            vis[x][y]=true;
            for(auto [dx, dy]: dirs){
                int i=x+dx;
                int j=y+dy;
                if(i>=0 and i<m and j>=0 and j<n and h[x][y]<=h[i][j] and !vis[i][j]){
                    q.push({i, j});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        vector<vector<int>> ans;
        int m=h.size();
        int n=h[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n));
        vector<vector<bool>> alt(m, vector<bool>(n));

        queue<pair<int, int>> q;
        for(int i=m-1; i>=0; i--){
            q.push({i,0});
        }
        for(int i=n-1; i>=0; i--){
            q.push({0, i});
        }
        
        bfs(h, q, pac, m, n);

        for(int i=m-1; i>=0; i--){
            q.push({i, n-1});
        }
        for(int i=n-1; i>=0; i--){
            q.push({m-1, i});
        }

        bfs(h, q, alt, m, n);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pac[i][j] and alt[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};