class Solution {
public:
    vector<vector<int>>ans;

    int n,m;

    // vector<bool>vis;

    void dfs(unordered_map<int,vector<int>>&adj,int node,vector<int>&temp){
        if(node==n-1){
            ans.push_back(temp);
            return;
        }
        // vis[node]=true;

        unordered_set<int>used;

        // temp.push_back(node);

        used.insert(node);

        for(auto &it:adj[node]){
            if(used.find(it)==used.end()){
                used.insert(it);
                temp.push_back(it);
                dfs(adj,it,temp);
                temp.pop_back();
            }
            
        }

    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       unordered_map<int,vector<int>>adj(n);

       n=graph.size();

       for(int i=0;i<n;i++){
        adj[i]=graph[i];
       }

    //    vis.resize(n,false);

       vector<int>temp;

       temp.push_back(0);


       dfs(adj,0,temp);

       return ans;
    }
};