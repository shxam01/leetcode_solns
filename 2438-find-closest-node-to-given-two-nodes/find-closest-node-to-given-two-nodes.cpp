class Solution {
public:
    vector<int> dist1;
    vector<int> dist2;
    
    void dfs1(vector<int>& edges, vector<int>& vis1, int node) {
        vis1[node] = 1;
        int neighbor = edges[node];
        if (neighbor != -1 && vis1[neighbor] == 0) {
            dist1[neighbor] = dist1[node] + 1;
            dfs1(edges, vis1, neighbor);
        }
    }

    void dfs2(vector<int>& edges, vector<int>& vis2, int node) {
        vis2[node] = 1;
        int neighbor = edges[node];
        if (neighbor != -1 && vis2[neighbor] == 0) {
            dist2[neighbor] = dist2[node] + 1;
            dfs2(edges, vis2, neighbor);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        dist1.resize(n, INT_MAX);
        dist2.resize(n, INT_MAX);
        
        vector<int> vis1(n, 0);
        vector<int> vis2(n, 0);
        
        dist1[node1] = 0;
        dist2[node2] = 0;
        
        dfs1(edges, vis1, node1);
        dfs2(edges, vis2, node2);
        
        int minMaxDist = INT_MAX;
        int result = -1;
        
        for (int i = 0; i < n; i++) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minMaxDist) {
                    minMaxDist = maxDist;
                    result = i;
                } else if (maxDist == minMaxDist && i < result) {
                    result = i;
                }
            }
        }
        
        return result;
    }
};