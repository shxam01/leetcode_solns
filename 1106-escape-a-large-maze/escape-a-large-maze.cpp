class Solution {
public:
    bool bfs(set<pair<int,int>>& blocked, int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) return true;
        
        queue<pair<int,int>> q;
        set<pair<int,int>> vis;
        
        q.push({sx, sy});
        vis.insert({sx, sy});
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        // Maximum area that can be enclosed by 200 blocks is around 20000
        int maxSteps = 20000;
        int steps = 0;
        
        while (!q.empty() && steps < maxSteps) {
            auto [x, y] = q.front();
            q.pop();
            
            if (x == tx && y == ty) return true;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && ny >= 0 && nx < 1000000 && ny < 1000000 
                    && vis.find({nx, ny}) == vis.end() 
                    && blocked.find({nx, ny}) == blocked.end()) {
                    vis.insert({nx, ny});
                    q.push({nx, ny});
                    steps++;
                }
            }
        }
        
        // If we explored maxSteps cells without being blocked, we "escaped"
        return steps >= maxSteps;
    }
    
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int,int>> st;
        for (auto& b : blocked) {
            st.insert({b[0], b[1]});
        }
        
        // Check if source can reach target (or escape enclosure)
        // AND target can reach source (or escape enclosure)
        return bfs(st, source[0], source[1], target[0], target[1]) 
            && bfs(st, target[0], target[1], source[0], source[1]);
    }
};