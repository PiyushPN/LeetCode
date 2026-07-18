// Last updated: 18/07/2026, 19:56:34
class Solution {
public:
    int ans = -1;
    void dfs(int node, vector<int> &vis, int dis, vector<int> adj[], unordered_map<int, int> &mp)
    {
        vis[node] = 1;
        mp[node] = dis;
        for(auto child: adj[node])
        {
            if(!vis[child])
            {
                dfs(child, vis, dis+1, adj, mp);
            }
            else if(mp.count(child))
            {
                ans = max(ans, dis-mp[child]+1);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> adj[n];
        vector<int> vis(n, 0);
        for(int i = 0; i<n; i++)
        {
            if(edges[i] == -1)
            {
                continue;
            }
            adj[i].push_back(edges[i]);
        }
        for(int i = 0; i < n; i++)
        {
            unordered_map<int, int> mp;
            if(!vis[i])
                dfs(i, vis, 0, adj, mp);
        }
        return ans;
    }
};