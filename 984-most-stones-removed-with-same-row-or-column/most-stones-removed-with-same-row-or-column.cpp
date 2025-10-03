class Solution {
public:
    // void dfs(vector<vector<int>>&stones,int index,vector<bool>&vis){
    //     vis[index]=true;
    //     for(int i=0;i<stones.size();i++){
    //         if(vis[i]==false && (stones[i][0]==stones[index][0] || stones[i][1]==stones[index][1])){
    //             vis[i]=true;
    //             dfs(stones,i,vis);
    //         }
    //     }
    // }

    void dfs(vector<vector<int>>&stones,vector<bool>&vis,int idx){
        vis[idx]=true;
        for(int i=0;i<stones.size();i++){
            if(!vis[i] && (stones[i][0]==stones[idx][0] || stones[i][1]==stones[idx][1])){
                vis[i]=true;
                dfs(stones,vis,i);
            }
        }

    }
    int removeStones(vector<vector<int>>& stones) {
       int n;
       n=stones.size();

       vector<bool>vis(n,false);

       int grp=0;

       for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(stones,vis,i);
            grp++;
        }
       }

       return n-grp;
    }
};