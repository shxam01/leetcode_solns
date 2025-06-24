class Solution {
public:
    // vector<int> bfs(unordered_map<int,vector<int>>&adj,int src,vector<bool>&vis){

        
    //     vector<int>ans;
        
    //     vis[src]=true;

    //     queue<int>q;

    //     q.push(src);

    //     while(!q.empty()){
    //         auto curr_node=q.front();

    //         ans.push_back(curr_node);

    //         q.pop();

    //         for(auto &ngbr:adj[curr_node]){
    //             if(!vis[ngbr]){
    //                 vis[ngbr]=true;
    //                 q.push(ngbr);
    //             }
    //         }
    //     }

    //     return ans;



    // }
    typedef pair<int,int> p;
    //is dfs mein jo bhi vis honge un sbka ancestor source hoga--
    void dfs(int src,unordered_map<int,vector<int>>&adj,vector<bool>&vis){
        vis[src]=true;
        for(auto &ngbr:adj[src]){
            if(!vis[ngbr]){
                dfs(ngbr,adj,vis);
            }
        }
        
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
       
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);

            
        }
        vector<vector<int>>ans(n);

        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            dfs(i,adj,vis);
            for(int j=0;j<n;j++){
                if(vis[j]==true && j!=i){
                    ans[j].push_back(i);
                }
            }
        }

        return ans;

    }
};