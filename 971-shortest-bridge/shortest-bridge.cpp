class Solution {
public:
    int n, m;

    bool valid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& vis) {
        if (!valid(x, y) || vis[x][y] || grid[x][y] != 1)
            return;

        vis[x][y] = true;
        grid[x][y] = 2; // mark first island as 2

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            dfs(grid, x + dx[i], y + dy[i], vis);
        }
    }

    typedef pair<int, pair<int, int>> p;

    int bfs(vector<vector<int>>& grid, vector<vector<bool>> vis, int x, int y) {
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {x, y}});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [curr_flips, coordinates] = pq.top();
            pq.pop();

            auto [i, j] = coordinates;

            // If we reach a cell of the second island (1), return flips
            if (grid[i][j] == 1)
                return curr_flips;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (valid(nx, ny) && !vis[nx][ny]) {
                    vis[nx][ny] = true;

                    if (grid[nx][ny] == 0)
                        pq.push({curr_flips + 1, {nx, ny}});
                    else if (grid[nx][ny] == 1)
                        return curr_flips; // reached second island directly
                }
            }
        }
        return INT_MAX;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        bool found = false;

        // Step 1: DFS to mark the first island
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, vis);
                    found = true;
                }
            }
        }

        // Step 2: BFS (via min-heap) starting from every cell of the first island
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    // Reset visited for each BFS run
                    vector<vector<bool>> temp_vis = vis;
                    ans = min(ans, bfs(grid, temp_vis, i, j));
                }
            }
        }

        return ans;
    }
};
