class Solution {
public:

    int n;

    int helper(vector<int>&prices,int idx,int can_buy,int completed_transaction,vector<vector<vector<int>>>&dp){
        if(idx>=n) return 0;

        if(completed_transaction>=2) return 0;

        if(dp[idx][can_buy][completed_transaction]!=-1) return dp[idx][can_buy][completed_transaction];

        int ans=helper(prices,idx+1,can_buy,completed_transaction,dp);

        if(can_buy==0){
            ans=max(ans,-prices[idx]+helper(prices,idx+1,1,completed_transaction,dp));
        }else{
            ans=max(ans,prices[idx]+helper(prices,idx+1,0,completed_transaction+1,dp));
        }

        return dp[idx][can_buy][completed_transaction]=ans;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(3,-1)));

        return helper(prices,0,0,0,dp);
    }
};