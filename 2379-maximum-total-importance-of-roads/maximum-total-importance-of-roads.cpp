class Solution {
public:
    
    


    long long maximumImportance(int n, vector<vector<int>>& roads) {
       unordered_map<int,vector<int>>adj;

       for(auto &road:roads){
        int u=road[0];
        int v=road[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
       }

       vector<pair<int,int>>indegree;

       for(int i=0;i<n;i++){
        int sz=adj[i].size();
        indegree.push_back({sz,i});
       }

       sort(indegree.rbegin(),indegree.rend());
       long long ans=0;
       for(int i=0;i<n;i++){
        auto pr=indegree[i];
        ans +=1LL*(n-i)*(pr.first);
       }

       return ans;

    }
};