class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    indegree[j]++;
                }else{
                    adj[j].push_back(i);
                    indegree[i]++;
                }
            }
        }
        int mn=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            if(indegree[i]<mn){
                mn=indegree[i];
                ans=i;
            }
        }
        return ans;
    }
};