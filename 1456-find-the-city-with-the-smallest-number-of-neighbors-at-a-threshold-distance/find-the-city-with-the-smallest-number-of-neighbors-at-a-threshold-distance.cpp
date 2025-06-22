class Solution {
public:
    typedef pair<int,int> p;
    int dijkstra(unordered_map<int,vector<pair<int,int>>>& adj, int k, int src) {
        vector<int> dist(adj.size() + 1, INT_MAX);
        dist[src] = 0;
        int count = 0;

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, src}); // {distance, node}

        while(!pq.empty()) {
            auto curr_dist = pq.top().first;
            auto curr_node = pq.top().second;
            pq.pop();
            
            // Skip if we've found a better path already
            if(curr_dist > dist[curr_node]) continue;

            for(auto &pr : adj[curr_node]) {
                int ngbr = pr.first;
                int wt = pr.second;
                
                // If we can find a shorter path
                if(dist[curr_node] + wt < dist[ngbr]) {
                    dist[ngbr] = dist[curr_node] + wt;
                    pq.push({dist[ngbr], ngbr}); // {distance, node}
                }
            }
        }
        
        // Count nodes within threshold
        for(int i = 0; i < dist.size(); i++) {
            if(i != src && dist[i] <= k) {
                count++;
            }
        }
        
        return count;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> nodes_accessible(n, 0);

        for(int i = 0; i < n; i++) {
            nodes_accessible[i] = dijkstra(adj, distanceThreshold, i);
        }

        int min_accessible = INT_MAX;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(nodes_accessible[i] <= min_accessible) {
                min_accessible = nodes_accessible[i];
                ans = i;
            }
        }

        return ans;
    }
};