#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
    int n, m;
    std::vector<int> parent;
    std::vector<int> rank;

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return true; // Cycle detected
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
        return false;
    }

    // BFS that explores a connected component of same-character cells
    bool bfs(const std::vector<std::vector<char>>& grid, int startX, int startY, std::vector<std::vector<bool>>& visited) {
        // A queue for BFS, storing {current_row, current_col, parent_row, parent_col}
        std::queue<std::tuple<int, int, int, int>> q;
        
        q.push({startX, startY, -1, -1}); // Start has no parent
        visited[startX][startY] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, pr, pc] = q.front();
            q.pop();

            char currentChar = grid[r][c];

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check if the neighbor is the cell we just came from
                if (nr == pr && nc == pc) {
                    continue;
                }

                // Check for valid grid bounds
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == currentChar) {
                    int id1 = r * m + c;
                    int id2 = nr * m + nc;
                    
                    // If Union returns true, they were already connected -> cycle found
                    if (Union(id1, id2)) {
                        return true;
                    }

                    if (!visited[nr][nc]) {
                        visited[nr][nc] = true;
                        q.push({nr, nc, r, c}); // Add to queue with current cell as parent
                    }
                }
            }
        }
        return false;
    }

    bool containsCycle(std::vector<std::vector<char>>& grid) {
        n = grid.size();
        if (n == 0) return false;
        m = grid[0].size();

        parent.resize(n * m);
        rank.assign(n * m, 0);
        for (int i = 0; i < n * m; ++i) parent[i] = i;

        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j]) {
                    // If the BFS finds a cycle in the component, return true
                    if (bfs(grid, i, j, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};