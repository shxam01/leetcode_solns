class Solution {
public:
    unordered_map<int, vector<int>> mp;

    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = true;

        while(!q.empty()) {
            auto [curr_idx, moves] = q.front();
            q.pop();

            if(curr_idx == n - 1) {
                return moves;
            }

            // Same value indices
            int curr_val = arr[curr_idx];
            for(auto &next_idx : mp[curr_val]) {
                if(!vis[next_idx]) {
                    vis[next_idx] = true;
                    q.push({next_idx, moves + 1});
                }
            }
            mp[curr_val].clear(); // Clear to avoid reprocessing

            // Previous index
            if(curr_idx - 1 >= 0 && !vis[curr_idx - 1]) {
                vis[curr_idx - 1] = true;
                q.push({curr_idx - 1, moves + 1});
            }

            // Next index
            if(curr_idx + 1 < n && !vis[curr_idx + 1]) {
                vis[curr_idx + 1] = true;
                q.push({curr_idx + 1, moves + 1});
            }
        }

        return -1;
    }
};