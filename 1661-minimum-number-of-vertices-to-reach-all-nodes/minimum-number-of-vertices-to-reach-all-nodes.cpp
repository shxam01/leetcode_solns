class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj, int node, vector<bool>& vis) {
        vis[node] = true;
        for(auto &child : adj[node]) {
            if(!vis[child]) {
                dfs(adj, child, vis);
            }
        }
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        int sz = edges.size();
        for(int i = 0; i < sz; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<int> ans;
        vector<bool> vis(n, false);
        vector<int> indegree(n, 0);
        
        for(auto &edge : edges) {
            indegree[edge[1]]++;
        }
        
        // Find nodes with zero indegree
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                ans.push_back(i);
                // No need to run DFS here
            }
        }

        return ans;
    }
};