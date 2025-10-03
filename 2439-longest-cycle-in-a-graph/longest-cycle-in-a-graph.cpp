class Solution {
public: 
    int ans=-1;
    void dfs(vector<int>&edges,int src,vector<bool>&vis,vector<bool>&inrecursion,vector<int>&count){

        if(src!=-1){
            vis[src]=true;
            inrecursion[src]=true;

            int v=edges[src];

            if(v!=-1 && !vis[v]){
                count[v]=count[src]+1;
                vis[v]=true;
                dfs(edges,v,vis,inrecursion,count);
            }else if(v!=-1 && inrecursion[v]){
                ans=max(ans,count[src]-count[v]+1);
            }

            inrecursion[src]=false;
        }
        
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();

        vector<bool>inrecursion(n,false);
        vector<bool>vis(n,false);

        

        vector<int>count(n,1);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(edges,i,vis,inrecursion,count);
            }
        }

        return ans;
        
    }
};