// Last updated: 18/07/2026, 19:58:56
class Solution {
public:
    void dfs(int source, int parent, vector<vector<int>> &adj, int n, vector<pair<int, int>> &visited, vector<vector<int>> &vec, int &rank)
    {
        visited[source].first=rank;
        visited[source].second=rank;
        rank++;
        for(auto i: adj[source])
        {
            if(visited[i].first==0)
            {
                dfs(i,source,adj,n,visited,vec,rank);
                visited[source].second=min(visited[source].second,visited[i].second);
                if(visited[i].second> visited[source].first)
                {
                    vec.push_back({i,source});
                }
            }
            else if(parent!=-1 and parent!=i)
            {
                visited[source].second=min(visited[source].second,visited[i].first);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < connections.size(); i++)
        {
            for(int j = 0; j < connections[i].size(); j++)
            {
                adj[connections[i][0]].push_back(connections[i][1]);
                adj[connections[i][1]].push_back(connections[i][0]);
            }
        }
	    int rank=1;
	    vector<pair<int,int>> visited(n);
	    vector<vector<int>> vec;
	    dfs(0,-1,adj,n,visited,vec,rank);
	    return vec;
    }
};