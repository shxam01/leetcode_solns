class Solution {
public:
    int n, m;
    typedef vector<vector<bool>> v;

    bool valid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    // dfs returns whether island is enclosed
    // size is updated to count cells in this island
    bool dfs(vector<vector<int>>& grid, int x, int y, v& vis, int& size) {
        if (!valid(x, y)) return false;

        if (grid[x][y] == 0 || vis[x][y]) return true;

        vis[x][y] = true;
        size++;  // count this cell

        bool left = dfs(grid, x, y - 1, vis, size);
        bool right = dfs(grid, x, y + 1, vis, size);
        bool up = dfs(grid, x - 1, y, vis, size);
        bool down = dfs(grid, x + 1, y, vis, size);

        return left && right && up && down;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int totalCells = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int size = 0;
                    if (dfs(grid, i, j, vis, size)) {
                        totalCells += size;  // add this enclave's size
                    }
                }
            }
        }

        return totalCells;
    }
};
