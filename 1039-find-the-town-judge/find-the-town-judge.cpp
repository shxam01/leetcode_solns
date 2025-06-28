class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,vector<int>>adj;
        // int n=trust.size();
        vector<int>indegree(n,0);

        for(auto &tust:trust){
            int a=tust[0]-1;
            int b=tust[1]-1;

            adj[a].push_back(b);
            indegree[b]++;
        }

        for(int i=0;i<n;i++){
            if(adj[i].size()==0 && indegree[i]==n-1){
                return i+1;
            }
        }
        return -1;


    }
};