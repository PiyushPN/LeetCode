// Last updated: 18/07/2026, 20:01:05
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
        {
            return {0};
        }
        vector<int> adj[n];
        
        vector<int> indegree(n, 0);
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 1)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            int size = q.size();
            ans.clear();
            for(int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto child: adj[node])
                {
                    indegree[child]--;
                    if(indegree[child] == 1)
                    {
                        q.push(child);
                    }
                }
            }
        }
        return ans;
    }
};