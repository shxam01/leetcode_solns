class Solution {
public:
    void helper(int v,vector<vector<int>>&graph,vector<bool>&vis,int &size){
        vis[v]=true;
        size++;
        for(auto neighbor:graph[v]){
            if(!vis[neighbor]){
                // vis[neighbor]=true;
                helper(neighbor,graph,vis,size);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> component_sizes;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            // vector<bool>vis(n,false);
            int size=0;
            if(!vis[i]){
                helper(i,graph,vis,size);
                component_sizes.push_back(size);
            }
            
        }
        long long result = 0;
        long long remaining = n;
        for(auto size:component_sizes){
            remaining -=size;
            result +=(long long)size*remaining;
        }
        return result;
    }
};