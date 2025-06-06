class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int>indegree(n,0);

        unordered_map<int,vector<int>>adj;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);

            indegree[v]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int ans=0;
        vector<vector<int>>t(n,vector<int>(26,0));
        int count_nodes=0;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                t[i][colors[i]-'a']=1;
            }
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();

            count_nodes++;
            ans=max(ans,t[u][colors[u]-'a']);

            for(auto &v:adj[u]){

                for(int i = 0; i<26; i++) {
                    
                    t[v][i] = max(t[v][i], t[u][i] + (colors[v]-'a' == i));
                    
                }

                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }

            
        }
        if(count_nodes<n) return -1;
        return ans;
    }
};