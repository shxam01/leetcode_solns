class Solution {
public:

    int bfs(int n,unordered_map<int,vector<pair<int,int>>>&adj){
        priority_queue<int,vector<int>,greater<int>>pq;

        pq.push(0);

        vector<int>dist(n,1e9);

        dist[0]=0;

        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();

            for(auto &it:adj[node]){
                auto ngbr=it.first;
                auto wt=it.second;

                if(dist[ngbr]>dist[node]+wt){
                    dist[ngbr]=dist[node]+wt;
                    pq.push(ngbr);
                }
            }
        }

        return dist[n-1]==1e9?-1:dist[n-1];
    }

    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }
        return bfs(n,adj);
        
    }
};