class Solution {
public:
    typedef long long ll;
    vector<int> bfs(int n, int src, unordered_map<int,vector<pair<int,int>>>& adj) {
        // if (src == dstn) return 0;
        
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()) {
            auto pai = pq.top();
            auto curr_dist = pai.first;
            auto node = pai.second;
            pq.pop();
            
            if (curr_dist > dist[node]) continue;
            
            for (auto& pr : adj[node]) {
                auto child = pr.first;
                auto wt = pr.second;
                
                if (dist[node] + wt < dist[child]) {
                    dist[child] = dist[node] + wt;
                    pq.push({dist[child], child});
                }
            }
        }
        return dist;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>>adj;
        
        for(auto &edge:edges){
            // adj[edge[0]].push_back(edg)
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>distfromsrc=bfs(n,0,adj);
        vector<int>distfromend=bfs(n,n-1,adj);
        int shortest_distance=distfromsrc[n-1];
        vector<bool>res(edges.size(),false);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];

            int dist1=distfromsrc[u];
            int dist2=distfromend[v];

            if(dist1!=INT_MAX && dist2!=INT_MAX && dist1+dist2+wt==shortest_distance){
                res[i]=true;
            }

            int dist3=distfromsrc[v];
            int dist4=distfromend[u];

            if(dist3!=INT_MAX && dist4!=INT_MAX &&dist3+dist4+wt==shortest_distance){
                res[i]=true;
            }
        }
        return res;

    }
};