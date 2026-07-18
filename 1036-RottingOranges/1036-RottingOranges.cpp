// Last updated: 18/07/2026, 19:59:03
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        queue<pair<int, int>> q;
        int rotten=0,fresh=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                    rotten++;
                } else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0){
            return 0;
        }
        if(m==1 and n==1 and grid[0][0]==1){
            return -1;
        }
        if(rotten==0){
            return -1;
        }
        vector<pair<int, int>> dirs={{1,0}, {-1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            ans++;
            int size=q.size();
            for(int k=0; k<size; k++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto [dx,dy]: dirs){
                    int i=x+dx;
                    int j=y+dy;
                    if(i>=0 and j>=0 and i<m and j<n and grid[i][j]==1){
                        grid[i][j]=2;
                        q.push({i, j});
                        fresh--;
                    } 
                }
            }
        }
        if(fresh==0){
            return ans-1;
        }
        return -1;
    }
};