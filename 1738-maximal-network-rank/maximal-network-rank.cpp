class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if(roads.empty()){
            return 0;
        }
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>v;
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj.size();j++){
                // int a=adj[i].size();
                if(i!=j){
                    int a=adj[i].size();
                    int b=adj[j].size();

                    if(find(adj[i].begin(),adj[i].end(),j)!=adj[i].end()){
                        int aa=a+b-1;
                        v.push_back(aa);
                    }else{
                        int aa=a+b;
                        v.push_back(aa);
                    }
                }

            }
        }
        return *max_element(v.begin(),v.end());
    }
};