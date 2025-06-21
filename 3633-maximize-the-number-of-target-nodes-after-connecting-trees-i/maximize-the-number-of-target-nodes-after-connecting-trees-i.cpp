class Solution {
public:
    int n, m;
    
    int dfs(unordered_map<int,vector<int>>& adj, int node, int parent, int k) {
        if (k < 0) return 0;
        
        int count = 1; 
        
        for (int child : adj[node]) {
            if (child != parent) { // Avoid going back to parent
                count += dfs(adj, child, node, k - 1);
            }
        }
        
        return count;
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        n = edges1.size();
        m = edges2.size();
        
        unordered_map<int,vector<int>> adj1, adj2;
        
        // Build adjacency lists
        for (auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        
        for (auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        
        vector<int> v1(n + 1), v2(m + 1);
        
        // Calculate for tree1 with distance k
        for (int i = 0; i <= n; i++) {
            v1[i] = dfs(adj1, i, -1, k);
        }
        
        // Calculate for tree2 with distance k-1
        for (int i = 0; i <= m; i++) {
            v2[i] = dfs(adj2, i, -1, k - 1);
        }
        
        int mx = *max_element(v2.begin(), v2.end());
        
        for (int i = 0; i <= n; i++) {
            v1[i] += mx;
        }
        
        return v1;
    }
};