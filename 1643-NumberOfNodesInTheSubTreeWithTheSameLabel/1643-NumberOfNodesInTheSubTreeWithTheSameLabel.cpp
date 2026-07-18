// Last updated: 18/07/2026, 19:58:26
class Solution {
public:
    vector<int> dfs(vector<vector<int>> &adj, string &labels, vector<int> &vis, int node, vector<int> &ans)
    {
        vector<int> temp(26, 0);
        vis[node] = 1;
        for(auto child: adj[node])
        {
            if(!vis[child])
            {
                vector<int> t = dfs(adj, labels, vis, child, ans);

                for(int i = 0; i < 26; i++)
                {
                    temp[i] += t[i];
                }
            }
        }
        temp[labels[node]-'a'] += 1;
        ans[node] = temp[labels[node]-'a'];
        cout << ans[node] << " " << labels[node] << "\n";
        return temp;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto &it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<int> ans(n,0), temp(26);
        dfs(adj,labels,vis, 0, ans);
        return ans;
    }
};