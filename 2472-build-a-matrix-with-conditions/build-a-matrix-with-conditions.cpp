class Solution {
public:
   //vis[i]=0 -- not visited
   //vis[i]=1 -- vis is on going
   //vis[i]=2 --vis completed
    
    void dfs(int u,vector<int>&vis,unordered_map<int,vector<int>>&adj,stack<int>&st,bool &cycle){
        vis[u]=1;
        for(auto &v:adj[u]){
            if(vis[v]==0){
                dfs(v,vis,adj,st,cycle);
            }else if(vis[v]==1){
                cycle=true;
                return;
            }
        }
        vis[u]=2;
        st.push(u);
    }
    
    vector<int>toposort(vector<vector<int>>&edges,int k){
        unordered_map<int,vector<int>>adj;

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
        }
        // int n=adj.size();

        vector<int>vis(k+1,0);
        stack<int>st;
        vector<int>order;
        bool cycle=false;
        for(int i=1;i<=k;i++){
            if(vis[i]==0){
                dfs(i,vis,adj,st,cycle);
                if(cycle==true) return {};
            }
        }
        while(!st.empty()){
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }


    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        auto toporow=toposort(rowConditions,k);
        auto topocol=toposort(colConditions,k);

        if(toporow.empty() || topocol.empty()){
            return {};
        }

        vector<vector<int>>ans(k,vector<int>(k,0));

        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(toporow[i]==topocol[j]){
                    ans[i][j]=toporow[i];
                }
            }
        }

        return ans;

    }
};