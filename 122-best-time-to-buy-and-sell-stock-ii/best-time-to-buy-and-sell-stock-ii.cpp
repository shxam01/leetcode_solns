class Solution {
public:
    int n;
    int helper(vector<int>&prices,int idx,int can_buy,vector<vector<int>>&dp){

        if(idx>=n) return 0;

        if(dp[idx][can_buy]!=-1) return dp[idx][can_buy];

        int ans=helper(prices,idx+1,can_buy,dp);

        if(can_buy==0){
            ans=max(ans,-prices[idx]+helper(prices,idx+1,1,dp));
        }else{
            ans=max(ans,prices[idx]+helper(prices,idx+1,0,dp));
        }

        return dp[idx][can_buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();

        vector<vector<int>>dp(n,vector<int>(3,-1));

        return helper(prices,0,0,dp);
    }
};