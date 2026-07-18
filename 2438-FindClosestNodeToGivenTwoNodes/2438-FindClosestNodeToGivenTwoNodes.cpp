// Last updated: 18/07/2026, 19:56:35
class Solution {
public:
    void bfs(int node, vector<int> &dis, vector<int> adj[], int n)
    {
        vector<bool> vis(n, false);
        int step = 0;
        while(!adj[node].empty() and !vis[adj[node][0]])
        {
            dis[adj[node][0]] = ++step;
            vis[adj[node][0]] = true;
            node = adj[node][0];
        }
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++)
        {
            if(edges[i] == -1)
            {
                continue;
            }
            adj[i].push_back(edges[i]);
        }
        vector<int> dis1(n, 1e9), dis2(n, 1e9);
        bfs(node1, dis1, adj, n);
        bfs(node2, dis2, adj, n);
        dis1[node1] = 0;
        dis2[node2] = 0;
        int ans = -1, dis = 1e9;
        for(int i = 0; i < n; i++)
        {
            if(max(dis1[i], dis2[i]) < dis)
            {
                dis = max(dis1[i], dis2[i]);
                ans = i;
            }
        }
        return ans;
    }
};