class Solution {
public:
    int ans;
    void dfs(unordered_map<int,vector<int>>&adj1,vector<bool>&vis,int src,vector<int>&depth){
        vis[src]=true;
        
        for(auto child:adj1[src]){
            if(!vis[child]){
                
                depth[child]=depth[src]+1;
                dfs(adj1,vis,child,depth);
            }
        }
    }

    void dfss(unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>&vis,int src,int par,vector<int>&depth){
        vis[src]=true;
        for(auto child:adj[src]){
            int neighbor=child.first;
            int right_or_wrong=child.second;
            if(!vis[neighbor]){
                
                if(right_or_wrong==1){
                    
                    ans+=1;
                }
            
                dfss(adj,vis,neighbor,src,depth);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>>adj1;

        int sz=connections.size();
        for(int i=0;i<sz;i++){
            int u=connections[i][0];
            int v=connections[i][1];

            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        vector<bool>vis(n,false);
        vector<int>depth(n,0);
        depth[0]=0;
        dfs(adj1,vis,0,depth);
       
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<sz;i++){
            int u=connections[i][0];
            int v=connections[i][1];

            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        ans=0;
        vector<bool>visited(n,false);
        dfss(adj,visited,0,-1,depth);
        return ans;
    }
};