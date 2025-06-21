class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> p;
    const int mod = 1e9 + 7;
    
    ll dijkstra(int n, unordered_map<int,vector<pair<int,int>>>& adj, int src) {
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, src});
        vector<ll> dist(n, LLONG_MAX);  // Use LLONG_MAX for ll
        dist[src] = 0;

        while(!pq.empty()) {
            auto pr = pq.top();
            auto curr_dist = pr.first;
            auto curr_node = pr.second;
            pq.pop();

            if(curr_dist > dist[curr_node]) continue;

            for(auto& child : adj[curr_node]) {
                auto neighbor = child.first;
                auto wt = child.second;

                if(curr_dist + wt < dist[neighbor]) {
                    dist[neighbor] = curr_dist + wt;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }
        return dist[n-1] == LLONG_MAX ? -1 : dist[n-1];
    }

    ll bfs(int shortest_distance, int n, unordered_map<int,vector<pair<int,int>>>& adj, int src) {
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, src});
        vector<ll> dist(n, LLONG_MAX);
        vector<ll> ways(n, 0);
        dist[src] = 0;
        ways[src] = 1;

        while(!pq.empty()) {
            auto pr = pq.top();
            auto curr_dist = pr.first;
            auto curr_node = pr.second;
            pq.pop();

            if(curr_dist > dist[curr_node]) continue;

            for(auto& child : adj[curr_node]) {
                auto neighbor = child.first;
                auto wt = child.second;

                if(curr_dist + wt < dist[neighbor]) {
                    dist[neighbor] = curr_dist + wt;
                    ways[neighbor] = ways[curr_node] % mod;  // ✅ Fixed: Add modulo
                    pq.push({dist[neighbor], neighbor});
                }
                else if(curr_dist + wt == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[curr_node]) % mod;
                }
            }
        }
        return ways[n-1];  // ✅ Fixed: Remove redundant modulo
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto& edge : roads) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        ll shortest_distance = dijkstra(n, adj, 0);
        
        if(shortest_distance == -1) return 0;
        
        ll ways = bfs(shortest_distance, n, adj, 0);
        return ways;  // ✅ Fixed: Remove redundant modulo
    }
};