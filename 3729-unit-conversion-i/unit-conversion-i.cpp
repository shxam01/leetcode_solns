class Solution {
public:
    
    int n;
    typedef long long ll;

    const int mod=1e9+7;

    typedef pair<ll,int> p;
    void bfs(int src,unordered_map<int,vector<pair<int,int>>>&adj,vector<ll>&dist){

        // vector<bool>vis(n,false);

        priority_queue<p,vector<p>,greater<p>>pq;

        pq.push({1LL,src});

        // vis[src]=true;

        // vector<int>dist(n,INT_MAX);

        dist[src]=1;

        while(!pq.empty()){
            auto [curr_dist,curr_node]=pq.top();
            pq.pop();

            if(curr_dist>dist[curr_node]) continue;

            for(auto &[ngbr,wt]:adj[curr_node]){
                ll new_dist=(curr_dist*wt)*1LL;
                if(new_dist<dist[ngbr]){
                    
                    dist[ngbr]=new_dist%mod;
                    pq.push({dist[ngbr],ngbr});
                }
            }
        }

        // return dist;


    }
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        unordered_map<int,vector<pair<int,int>>>adj;

        

        n = 0;
        for(auto &it : conversions) {
            adj[it[0]].push_back({it[1], it[2]});
            n = max(n, max(it[0], it[1]));
        }
        n++;

        vector<ll>dist(n,LLONG_MAX);

        bfs(0,adj,dist);

        vector<int>result(n);

        for(int i=0;i<n;i++){
            result[i]=(dist[i]==LLONG_MAX)?-1:dist[i];
        }

        return result;
    }
};