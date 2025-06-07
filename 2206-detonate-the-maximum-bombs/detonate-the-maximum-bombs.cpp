class Solution {
public:
    int bfs(unordered_map<int,vector<int>>&adj,int src,vector<bool>&vis){
        vis[src]=true;
        queue<int>q;
        q.push(src);
        int cnt=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cnt++;
            for(auto &child:adj[u]){
                if(!vis[child]){
                    vis[child]=true;
                    q.push(child);

                }
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        sort(bombs.begin(),bombs.end());
        unordered_map<int,vector<int>>adj;

        // Check all pairs of bombs
        for(int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1];
            long long r1 = bombs[i][2];
            
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    long long x2 = bombs[j][0], y2 = bombs[j][1];
                    
                    // Calculate squared distance to avoid precision issues with sqrt
                    long long dist_squared = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                    
                    // If bomb i can detonate bomb j
                    if(dist_squared <= r1 * r1) {
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int ans=1;
            for(int i=0;i<n;i++){
                vector<bool>vis(n,false);
                ans=max(ans,bfs(adj,i,vis));
            }

            return ans;
    }
};