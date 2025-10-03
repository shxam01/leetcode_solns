class Solution {
public:
    
    int dfs(int node,int parent,unordered_map<int,vector<int>>&adj,vector<bool>&hasApple){
        int time=0;
        for(auto &child:adj[node]){
            if(child==parent) continue;
            int time_from_child=dfs(child,node,adj,hasApple);

            if(time_from_child>0 || hasApple[child]){
                time +=time_from_child+2;
            }
        }
        return time;
    }

    
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adj;

        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int count=0;
        for(int i=0;i<hasApple.size();i++){
            if(hasApple[i]==true){
                count++;
            }
        }

        if(count==0) return 0;

        return dfs(0,-1,adj,hasApple);

    }
};