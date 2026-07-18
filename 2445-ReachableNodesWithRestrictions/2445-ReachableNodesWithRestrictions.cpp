// Last updated: 18/07/2026, 19:56:27
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& rest) {
        vector<int> adj[n];
        unordered_map<int, int> mp;
        vector<bool> vis(n, 0);
        for(int i = 0; i<rest.size(); i++)
        {
            mp[rest[i]]++;
        }
        for(int i = 0; i < n-1; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 1;
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();
                
                vis[node] = 1;
                for(auto child: adj[node])
                {
                    if(mp.find(child) == mp.end() and vis[child]==0)
                    {
                        q.push(child);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};