class Solution {
public:
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
       unordered_map<int,vector<int>>adj;
       int n=routes.size();

       for(int route=0;route<n;route++){
        for(auto &stop:routes[route]){
            adj[stop].push_back(route);
        }
       }
       int bus=1;
       vector<bool>vis(501,false);
       queue<int>q;
       for(auto &route:adj[source]){
        q.push(route);
        vis[route]=true;
       }

       while(!q.empty()){
        int sz=q.size();
        
        while(sz--){
            auto route=q.front();
            q.pop();

            for(auto &stop:routes[route]){
                if(stop==target){
                    return bus;
                }

                for(auto &next_route:adj[stop]){
                    if(!vis[next_route]){
                        vis[next_route]=true;
                        q.push(next_route);
                    }
                }
            }
        }
        bus++;

       }
       return -1;

    }
};