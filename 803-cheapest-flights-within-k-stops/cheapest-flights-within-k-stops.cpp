class Solution {
public:
    int bfs(int n, unordered_map<int,vector<pair<int,int>>>&adj,int src,int dst,int k){
        queue<pair<int,pair<int,int>>>q; // node and value
        
        q.push({0,{src,0}});
        vector<int>distt(n,INT_MAX);
        distt[src]=0;
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int dist=q.front().second.second;
            
            // if(stops==k) return
            q.pop();
            for(auto pr:adj[node]){
                auto neighbor_node=pr.first;
                auto neighbor_dist=pr.second;
                if( neighbor_dist+dist<distt[neighbor_node] && stops<=k ){
                    distt[neighbor_node]=neighbor_dist+dist;
                    q.push({stops+1,{neighbor_node,distt[neighbor_node]}});
                }
            }
        }
        return distt[dst]==INT_MAX?-1:distt[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int value=flights[i][2];

            adj[u].push_back({v,value});
            
            
        }
        return bfs(n,adj,src,dst,k);
    }
};