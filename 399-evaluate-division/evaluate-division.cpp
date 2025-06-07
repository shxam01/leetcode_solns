class Solution {
public:
    double bfs(unordered_map<string,vector<pair<string,double>>>& adj, string src, string dstn) {
        // Handle case when source equals destination
        if (src == dstn) {
            if (adj.find(src) != adj.end())
                return 1.0;
            return -1.0;
        }
        
        queue<pair<string, double>> q;
        unordered_set<string> visited;
        
        q.push({src, 1.0});
        visited.insert(src);
        
        while (!q.empty()) {
            auto [curr, currValue] = q.front();
            q.pop();
            
            for (auto& [neighbor, value] : adj[curr]) {
                if (visited.find(neighbor) == visited.end()) {
                    double newValue = currValue * value;
                    
                    if (neighbor == dstn) 
                        return newValue;
                    
                    visited.insert(neighbor);
                    q.push({neighbor, newValue});
                }
            }
        }
        
        return -1.0; // If we can't reach destination
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n = equations.size();
        unordered_set<string> st;
        
        for (int i = 0; i < n; i++) {
            string A = equations[i][0];
            string B = equations[i][1];

            st.insert(A);
            st.insert(B);

            double value = values[i];
            double inv = 1.0 / value;
            
            adj[A].push_back({B, value});
            adj[B].push_back({A, inv});
        }
        
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            auto A = queries[i][0];
            auto B = queries[i][1];

            if (st.find(A) == st.end() || st.find(B) == st.end()) {
                ans.push_back(-1.0);
                continue;
            }
            
            auto val = bfs(adj, A, B);
            ans.push_back(val);
        }

        return ans;
    }
};