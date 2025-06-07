class Solution {
public:
    bool isSimilar(string &a, string &b) {
        int cnt = 0;
        int n = a.size();
        int m = b.size();
        if (n != m) return false;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                cnt++;
                if (cnt > 2) return false;
            }
        }
        return cnt == 2;
    }

    void dfs(unordered_map<string, vector<string>> &adj, unordered_map<string, bool> &vis, string &str) {
        vis[str] = true;
        for (auto &next : adj[str]) {
            if (!vis[next]) {
                dfs(adj, vis, next);
            }
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> adj;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    adj[strs[i]].push_back(strs[j]);
                    adj[strs[j]].push_back(strs[i]);
                }
            }
        }

        int cnt = 0;
        unordered_map<string, bool> vis;
        
        for (auto &str : strs) {
            if (!vis[str]) {
                cnt++;
                dfs(adj, vis, str);
            }
        }
        return cnt;
    }
};