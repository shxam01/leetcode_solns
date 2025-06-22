class Solution {
public:
    int n;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool valid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    int dfs(vector<vector<int>>& grid, int x_src, int y_src, vector<vector<bool>>& vis, int unique_id) {
        vis[x_src][y_src] = true;
        grid[x_src][y_src] = unique_id;
        int ans = 1;

        for(int i = 0; i < 4; i++) {
            int nx = x_src + dx[i];
            int ny = y_src + dy[i];

            if(valid(nx, ny) && !vis[nx][ny] && grid[nx][ny] == 1) {
                ans += dfs(grid, nx, ny, vis, unique_id);
            }
        }
        return ans;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();

        // First pass: label each island with a unique ID and get its size
        unordered_map<int, int> mp;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        int unique_id = 2;
        int max_island = 0; // Track max island size

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    int size = dfs(grid, i, j, vis, unique_id);
                    mp[unique_id] = size;
                    max_island = max(max_island, size);
                    unique_id++;
                }
            }
        }
        
        // If there are no 0s, the entire grid is an island
        bool has_zero = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    has_zero = true;
                    break;
                }
            }
            if(has_zero) break;
        }
        
        if(!has_zero) return n * n;
        
        // If there are no islands, changing one 0 to 1 creates an island of size 1
        if(mp.empty()) return 1;
        
        // Second pass: try changing each 0 to 1
        int ans = max_island; // Start with the largest existing island

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> visited_ids;
                    int temp_ans = 1; // Start with 1 for the changed cell
                    
                    for(int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        
                        if(valid(nx, ny) && grid[nx][ny] >= 2) {
                            int neighbor_id = grid[nx][ny];
                            if(visited_ids.find(neighbor_id) == visited_ids.end()) {
                                temp_ans += mp[neighbor_id];
                                visited_ids.insert(neighbor_id);
                            }
                        }
                    }
                    
                    ans = max(ans, temp_ans);
                }
            }
        }
        
        return ans;
    }
};