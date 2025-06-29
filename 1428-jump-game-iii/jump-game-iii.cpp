class Solution {
public:
    int n;
    int dp[50001];
    bool helper(vector<int>&arr,int idx,vector<bool>&vis){

        if(idx<0 || idx>=n) return false;

         if(dp[idx]!=-1) return dp[idx];

        if(vis[idx]) return false;

        if(arr[idx]==0) return dp[idx]=1;

       

        vis[idx]=true;

        bool res=false;
        

        int jump_length=arr[idx];

        

        if(idx-jump_length>=0){
            res |=helper(arr,idx-jump_length,vis);
        }

        if(idx+jump_length < n) {
            res |=helper(arr,idx+jump_length,vis);
        }

        vis[idx]=false;

        return dp[idx]=res;


    } 
    bool canReach(vector<int>& arr, int start) {
        // unordered_map<int,vector<int>>adj;

        // adj[start].push_back()

        n=arr.size();

        memset(dp,-1,sizeof(dp));

        vector<bool>vis(n,false);

        return helper(arr,start,vis);

        // queue<int>q;

        // q.push(start);

        // while(!q.empty()){
        //     auto idx=q.front();

        //     q.pop();

        //     if(arr[idx]==0) return true;

        //     int jump_length=arr[idx];


        //     if(idx-jump_length>=0 && !vis[idx-jump_length]){
        //         vis[idx-jump_length]=true;
        //         q.push(idx-jump_length);
        //     }

        //     if(idx+jump_length<n && !vis[idx+jump_length]){
        //         vis[idx+jump_length]=true;
        //         q.push(idx+jump_length);
        //     }
        // }
        // return false;
        
    }
};