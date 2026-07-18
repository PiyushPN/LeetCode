// Last updated: 18/07/2026, 20:01:51
class Solution {
public:
    bool dfs(int node, vector<bool> &vis, vector<bool> &dfsVis, vector<int> adj[]){
        vis[node]=true;
        dfsVis[node]=true;
        for(auto child: adj[node]){
            if(!vis[child]){
                if(dfs(child, vis, dfsVis, adj)){
                    return true;
                }
            } else if(dfsVis[child]){
                return true;
            }
        }
        dfsVis[node]=false;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int> adj[num];
        vector<bool> vis(num, false), dfsVis(num, false);
        for(auto it: pre){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        for(int i=0; i<num; i++){
            if(!vis[i]){
                if(dfs(i, vis, dfsVis, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};