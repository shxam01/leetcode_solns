class Solution {
public:
    int n, m;
    vector<vector<bool>> vis;  // Missing declaration
    
    bool valid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    bool can_reach(vector<vector<int>>& grid, int x_src, int y_src) {
        if (grid[x_src][y_src] == 1) return false;
        queue<pair<int, int>> q;
        q.push({x_src, y_src});
        vis[x_src][y_src] = true;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};
        
        while (!q.empty()) {
            auto pr = q.front();
            int x = pr.first;
            int y = pr.second;
            if (x == n - 1 && y == m - 1) return true;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int x_new = x + dx[i];
                int y_new = y + dy[i];
                if (valid(x_new, y_new) && !vis[x_new][y_new] && grid[x_new][y_new] != 1) {
                    vis[x_new][y_new] = true;
                    q.push({x_new, y_new});
                }
            }
        }
        return false;
    }
    
    int bfs(vector<vector<int>>& grid, int x_src, int y_src) {
        // Fixed priority queue syntax - removed extra closing bracket
        priority_queue<pair<int, pair<int, int>>, 
                      vector<pair<int, pair<int, int>>>, 
                      greater<pair<int, pair<int, int>>>> pq;
        
        if (grid[x_src][y_src] == 1) {
            pq.push({1, {x_src, y_src}});
        } else {
            pq.push({0, {x_src, y_src}});
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));  // Separate visited array for Dijkstra
        
        // Initialize starting distance
        dist[x_src][y_src] = grid[x_src][y_src];
        
        while (!pq.empty()) {
            auto pr = pq.top();
            auto wt = pr.first;
            auto pr1 = pr.second;
            auto x = pr1.first;
            auto y = pr1.second;
            pq.pop();
            
            // Skip if already visited
            if (visited[x][y]) continue;
            visited[x][y] = true;
            
            // If reached destination
            if (x == n - 1 && y == m - 1) {
                return wt;
            }
            
            for (int i = 0; i < 4; i++) {
                auto x_new = x + dx[i];
                auto y_new = y + dy[i];
                if (valid(x_new, y_new) && !visited[x_new][y_new]) {  // Fixed condition
                    int new_dist = wt + grid[x_new][y_new];  // Fixed calculation
                    if (new_dist < dist[x_new][y_new]) {
                        dist[x_new][y_new] = new_dist;
                        pq.push({new_dist, {x_new, y_new}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
    
    int minimumObstacles(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<bool>(m, false));  // Initialize vis array
        
        if (can_reach(grid, 0, 0)) return 0;
        return bfs(grid, 0, 0);  // Fixed function name
    }
};