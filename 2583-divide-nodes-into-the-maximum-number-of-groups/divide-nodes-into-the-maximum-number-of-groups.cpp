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
        int maxLevel=1;
        vector<bool>vis(n,false);

        vis[source]=true;

        queue<pair<int,int>>q; // node, level -- starting with level 1

        q.push({source,1});

        while(!q.empty()){
            auto [curr_node,curr_level]=q.front();

            q.pop();

            maxLevel=max(maxLevel,curr_level);

            for(auto &ngbr:adj[curr_node]){
                if(!vis[ngbr]){
                    vis[ngbr]=true;
                    maxLevel=max(curr_level+1,maxLevel);
                    q.push({ngbr,curr_level+1});
                }
            }
        }
        // return
        return maxLevel; 
    }

    void dfs(int n,unordered_map<int,vector<int>>&adj,int src,vector<bool>&vis,int &temp_ans,vector<int>&levels){
        // vector<bool>vis(n,false);

        vis[src]=true;
        temp_ans=max(temp_ans,levels[src]);

        for(auto &v:adj[src]){
            if(!vis[v]){
                dfs(n,adj,v,vis,temp_ans,levels);
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

        //   int n=adj.size();
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

          vector<int>levels(n,0);

          for(int i=0;i<n;i++){
            int level_for_curr_node=bfs(n,adj,i);
            levels[i]=level_for_curr_node;
          }
          vector<bool>vis(n,false);
          int ans=0;
          for(int i=0;i<n;i++){
            // int temp_ans=INT_MIN;
            if(!vis[i]){
                int temp_ans=INT_MIN;
                dfs(n,adj,i,vis,temp_ans,levels);
                ans +=temp_ans;
            }
            
          }

          return ans;


    }
};