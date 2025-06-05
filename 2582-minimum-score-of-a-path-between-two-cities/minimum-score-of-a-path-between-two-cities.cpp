class Solution {
public:
    int bfs(unordered_map<int,vector<pair<int,int>>>&adj,int src,int dstn){
        int ans=INT_MAX;
        queue<int>q; // node and min distance
        q.push(src);
        unordered_set<int> visited;
        visited.insert(src);
        while(!q.empty()){
            int vertex=q.front();
            
            q.pop();

            

            for(auto child:adj[vertex]){
                int neighbor=child.first;
                int distt=child.second;
                ans=min(ans,distt);
                if(visited.find(neighbor)==visited.end()){
                    visited.insert(neighbor);
                    q.push(neighbor);
                }

            }

        }
        return ans;
    }


    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;

        int sz=roads.size();

        for(int i=0;i<sz;i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int distance=roads[i][2];
            
            adj[u].push_back({v,distance});
            adj[v].push_back({u,distance});
        }
        return bfs(adj,1,n);
    }
};