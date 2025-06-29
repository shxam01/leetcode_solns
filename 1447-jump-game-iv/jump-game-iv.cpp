class Solution {
public:
    unordered_map<int,vector<int>>mp;

    int dp[50001];
    
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        vector<bool>vis(n,false);

        memset(dp,-1,sizeof(dp));

        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0]=true;

        while(!q.empty()){
            auto [curr_idx,moves]=q.front();

            q.pop();

            if(dp[curr_idx]!=-1) return dp[curr_idx];

            if(curr_idx==n-1){
                return moves;
            }
            int curr_value=arr[curr_idx];
            for(auto &next_val:mp[curr_value]){
                if(!vis[next_val]){
                    q.push({next_val,moves+1});
                }
            }
            mp[curr_value].clear();

            if(curr_idx-1>=0 && !vis[curr_idx-1]){
                vis[curr_idx-1]=true;
                q.push({curr_idx-1,moves+1});
            }

            if(curr_idx+1<n && !vis[curr_idx+1]){
                vis[curr_idx+1]=true;
                q.push({curr_idx+1,moves+1});
            }

            
        }

        return -1;


        
    }
};