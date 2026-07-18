// Last updated: 18/07/2026, 19:59:37
class Solution {
public:
    bool dfs(int node, int parent, vector<bool> &vis, vector<int> adj[]){
        vis[node]=true;
        for(auto child: adj[node]){
            if(!vis[child]){
                if(dfs(child, node, vis, adj)){
                    return true;
                }
            } else if(child != parent){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> adj[n+1];
        for(int i=0; i<n; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            vector<bool> vis(n+1, false);
            if(dfs(edges[i][0], -1, vis, adj)){
                return edges[i];
            }
        }
        return {};
    }
};