class Solution {
public:
    int n, m;

    typedef tuple<int, int, int, int> state; // steps, x, y, remaining_k

    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        if (n == 1 && m == 1) return 0; // already at the destination

        // 3D visited array: [n][m][k+1]
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));

        queue<state> q;
        q.push({0, 0, 0, k}); // steps, x, y, remaining k
        visited[0][0][k] = true;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [steps, x, y, rem_k] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int next_k = rem_k - grid[nx][ny];

                    if (next_k < 0) continue; // not enough eliminations left

                    if (nx == n - 1 && ny == m - 1) return steps + 1; // reached

                    if (!visited[nx][ny][next_k]) {
                        visited[nx][ny][next_k] = true;
                        q.push({steps + 1, nx, ny, next_k});
                    }
                }
            }
        }

        return -1; // not reachable
    }
};
