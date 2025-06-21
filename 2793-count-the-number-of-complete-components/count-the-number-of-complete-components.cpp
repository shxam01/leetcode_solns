class Solution {
public:
    void dfs(int n,unordered_map<int,vector<int>>&adj,vector<bool>&vis,int i,int &v,int &e){
        vis[i]=true;
        v++;
        e+=adj[i].size();
        for(auto &child:adj[i]){
            if(!vis[child]){
                dfs(n,adj,vis,child,v,e);
            }
        }
    }
    void bfs(int n,unordered_map<int,vector<int>>&adj,vector<bool>&vis,int i,int &v,int &e){
        queue<int>q;
        q.push(i);

        vis[i]=true;
        // v++;

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            v++;
            e+=adj[node].size();
            for(auto child:adj[node]){
                if(!vis[child]){
                    vis[child]=true;
                    q.push(child);
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){

            if(vis[i]) continue;
            int v=0;
            int e=0;
           
            //  dfs(n,adj,vis,i,v,e);
            bfs(n,adj,vis,i,v,e);
            
            if(v*(v-1)/2==e/2) ans++;
        }
        return ans;
    }
};