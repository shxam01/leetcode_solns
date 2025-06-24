class Solution {
public:
    unordered_map<int,vector<int>>adj;
    int findChampion(int n, vector<vector<int>>& edges) {
        // return findChampionI(n,grid);
        if(n==1){
            if(edges.empty()) return 0;
        }
        vector<int>indegree(n,0);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<pair<int,int>>vec;

        for(int i=0;i<n;i++){
            int a=indegree[i];
            vec.push_back({a,i});
        }
        sort(vec.begin(),vec.end());
        auto pr1=vec[0];
        auto pr2=vec[1];

        if(pr1.first==pr2.first){
            return -1;
        }else{
            return pr1.second;
        }

        // return ans;

       

        
    }
};