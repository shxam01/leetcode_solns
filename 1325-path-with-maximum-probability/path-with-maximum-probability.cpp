class Solution {
public:
    double bfs(unordered_map<int,vector<pair<int,double>>>& adj, int start_node, int end_node) {
        vector<double> maxProb(100001, 0.0); // Assuming constraints of n ≤ 10^5
        maxProb[start_node] = 1.0;
        
        queue<pair<int,double>> q;
        q.push({start_node, 1.0});
        
        while(!q.empty()) {
            auto v = q.front().first;
            auto curr_prob = q.front().second;
            q.pop();

            // Skip if we've found a better path since adding to queue
            if(curr_prob < maxProb[v]) continue;

            for(auto &pr : adj[v]) {
                auto child = pr.first;
                auto proba = pr.second;

                auto new_prob = curr_prob * proba;

                // Only process if we found a better path
                if(new_prob > maxProb[child]) {
                    maxProb[child] = new_prob;
                    q.push({child, new_prob});
                }
            }
        }
        return maxProb[end_node];
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
       unordered_map<int,vector<pair<int,double>>> adj;
       for(int i = 0; i < edges.size(); i++) {
           int u = edges[i][0];
           int v = edges[i][1];
           double prob = succProb[i];
           adj[u].push_back({v, prob});
           adj[v].push_back({u, prob});
       }
       
       return bfs(adj, start_node, end_node);
    }
};