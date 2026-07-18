// Last updated: 18/07/2026, 19:58:38
class Solution {
public:
    void dfs(int source, vector<int> adj[], vector<int> &vis)
    {
        vis[source] = 1;
        for(auto child: adj[source])
        {
            if(vis[child] == 0)
            {
                dfs(child, adj, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        vector<int> adj[n];
        int size = con.size();
        if(size < n-1)
        {
            return -1;
        }
        for(int i = 0; i < size; i++)
        {
            int j = con[i].front();
            int k = con[i].back();
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                ans++;
                dfs(i, adj, vis);
            }
        }
        return ans-1;
    }
};