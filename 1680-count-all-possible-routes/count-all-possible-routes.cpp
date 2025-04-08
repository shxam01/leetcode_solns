class Solution {
public:
    #define vi vector<int>
    int n;
    const int mod=1e9+7;
    int helper(vector<int>&locations,int curr_idx,int finish,int fuel,vector<vector<int>>&dp){
        if(fuel<0){
            return 0;
        }
        if(dp[curr_idx][fuel]!=-1) return dp[curr_idx][fuel];
        int ans=0;
        if(curr_idx==finish){
            ans+=1; 
        }
        for(int i=0;i<n;i++){
                if(i!=curr_idx){
                    int remaining_fuel=fuel-abs(locations[i]-locations[curr_idx]);
                    ans=(ans+helper(locations,i,finish,remaining_fuel,dp))%mod;
                }
        }
        return dp[curr_idx][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n=locations.size();
        vector<vector<int>>dp(n+1,vector<int>(fuel+1,-1));
        return helper(locations,start,finish,fuel,dp)%mod;
    }
};