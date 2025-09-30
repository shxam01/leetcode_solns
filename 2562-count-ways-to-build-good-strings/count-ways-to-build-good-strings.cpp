class Solution {
public:
    const int MOD=1e9+7;
    int helper(int low,int high,int zero,int one,int len,vector<int>&dp){
        if(len>high) return 0;
        if(dp[len]!=-1) return dp[len];
        int ans=0;
        if(len>=low && len<=high){
            ans=1;
        }
        
        

        ans =(ans+helper(low,high,zero,one,len+zero,dp))%MOD;
        ans =(ans+helper(low,high,zero,one,len+one,dp))%MOD;

        return dp[len]=ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int length=high+1;
        vector<int>dp(length+1,-1);
        return helper(low,high,zero,one,0,dp);
    }
};