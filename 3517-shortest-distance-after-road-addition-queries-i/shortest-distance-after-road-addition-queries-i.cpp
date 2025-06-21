class Solution {
public:
    
    int bfs(int n,unordered_map<int,vector<int>>&adj){
        vector<bool>vis(n,false);
        int level=0;
        queue<int>q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                if(node==n-1) return level;
                for(auto &nbr:adj[node]){
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr]=true;
                    }
                }
            }
            level++;
        }
        return -1;
    }


    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int>res;
        for(auto&query:queries){
            int u=query[0];
            int v=query[1];
            adj[u].push_back(v);
            int dist=bfs(n,adj);
            res.push_back(dist);

        }
        return res;
    }
};