class Solution {
public:
    typedef pair<int,int> p;
    typedef vector<int> vi;
    const int MOD = 1e9 + 7;

    vector<int> dijkstra(int n, int src, unordered_map<int,vector<pair<int,int>>>&adj){
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,src});
        vi dist(n,INT_MAX);
        dist[src] = 0;

        while(!pq.empty()){
            auto [curr_dist,curr_node] = pq.top();
            pq.pop();

            if(curr_dist > dist[curr_node]) continue;

            for(auto &pr : adj[curr_node]){
                int ngbr = pr.first;
                int wt = pr.second;

                if(curr_dist + wt < dist[ngbr]){
                    dist[ngbr] = curr_dist + wt;
                    pq.push({dist[ngbr], ngbr});
                }
            }
        }
        return dist;
    }

    int dfs(int curr_node, int target, unordered_map<int,vector<pair<int,int>>>&adj, 
            vi &min_distance_vec, vi &memo) {
        
        if(curr_node == target) {
            return 1;
        }
        
        if(memo[curr_node] != -1) {
            return memo[curr_node];
        }
        
        int paths = 0;
        
        for(auto &pr : adj[curr_node]) {
            int ngbr = pr.first;
            
            
            if(min_distance_vec[curr_node] > min_distance_vec[ngbr]) {
                paths = (paths + dfs(ngbr, target, adj, min_distance_vec, memo)) % MOD;
            }
        }
        
        return memo[curr_node] = paths;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto &edge : edges){
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        auto min_distance_vec = dijkstra(n, n-1, adj);
        
        vi memo(n, -1);
        return dfs(0, n-1, adj, min_distance_vec, memo);
    }
};