class Solution {
public:

    bool isBipartite(unordered_map<int,vector<int>>&adj,int curr_color,int curr_node,vector<int>&color){
        color[curr_node]=curr_color;

        for(auto &v:adj[curr_node]){
            if(color[v]==color[curr_node]) return false;

            if(color[v]==-1){
                int color_v=1-curr_color;
                if(isBipartite(adj,color_v,v,color)==false){
                    return false;
                }
            }
        }
        return true;
    }

    int bfs(int n,unordered_map<int,vector<int>>&adj,int source){
        // int n=adj.size();
        vector<bool>vis(n+1,false);
        vis[source]=true;
        queue<pair<int,int>>q; // node, level -- starting with level 1
        q.push({source,1});
        int maxLevel = 1;

        while(!q.empty()){
            auto [curr_node,curr_level]=q.front();
            q.pop();
            maxLevel = max(maxLevel, curr_level);

            for(auto &ngbr:adj[curr_node]){
                if(!vis[ngbr]){
                    vis[ngbr]=true;
                    q.push({ngbr,curr_level+1});
                }
            }
        }
        return maxLevel; 
    }

    void dfs(int n,unordered_map<int,vector<int>>&adj,int src,vector<bool>&vis,vector<int>&component){
        vis[src]=true;
        component.push_back(src);

        for(auto &v:adj[src]){
            if(!vis[v]){
                dfs(n,adj,v,vis,component);
            }
        }
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
          unordered_map<int,vector<int>>adj;

          for(auto &edge:edges){
            int u=edge[0]-1;
            int v=edge[1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
          }

          vector<int>color(n,-1);
          bool can_be_divided=true;
          for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(isBipartite(adj,1,i,color)==false){
                    can_be_divided=false;
                    break;
                }
            }
          }
          if(can_be_divided==false){
            return -1;
          }

          vector<bool>vis(n,false);
          int ans=0;
          
          for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> component;
                dfs(n,adj,i,vis,component);
                
                int max_groups = 0;
                for(auto node : component){
                    max_groups = max(max_groups, bfs(n,adj,node));
                }
                ans += max_groups;
            }
          }

          return ans;
    }
};