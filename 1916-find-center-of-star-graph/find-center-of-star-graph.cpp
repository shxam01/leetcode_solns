class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int n=adj.size();
        for(int i=0;i<n;i++){
            if(adj[i+1].size()==n-1){
                return i+1;
            }
        }
        return -1;
    }
};