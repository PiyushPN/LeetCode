// Last updated: 18/07/2026, 20:01:47
class Solution {
public:
    bool topo(int node, vector<bool> &vis, vector<bool> &dfsVis, vector<int> adj[], vector<int> &ans){
        vis[node]=true;
        dfsVis[node]=true;
        for(auto child: adj[node]){
            if(!vis[child]){
                if(topo(child, vis, dfsVis, adj, ans)){
                    return true;
                }
            } else if(dfsVis[child]){
                return true;
            }
        }
        dfsVis[node]=false;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int> adj[num];
        for(auto it: pre){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans;
        vector<bool> vis(num, false), dfsVis(num, false);
        for(int i=0; i<num; i++){
            if(!vis[i]){
                if(topo(i, vis, dfsVis, adj, ans)){
                    ans.clear();
                    return ans;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};