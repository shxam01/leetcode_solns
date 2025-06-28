class Solution {
public:

    int n;

    int helper(vector<int>&prices,int idx,int can_buy,int completed_transaction,int k,vector<vector<vector<int>>>&dp){
        if(idx>=n) return 0;

        if(completed_transaction>=k) return 0;

        if(dp[idx][can_buy][completed_transaction]!=-1) return dp[idx][can_buy][completed_transaction];

        int ans=helper(prices,idx+1,can_buy,completed_transaction,k,dp);

        if(can_buy==0){
            ans=max(ans,-prices[idx]+helper(prices,idx+1,1,completed_transaction,k,dp));
        }else{
            ans=max(ans,prices[idx]+helper(prices,idx+1,0,completed_transaction+1,k,dp));
        }

        return dp[idx][can_buy][completed_transaction]=ans;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(k+1,-1)));

        return helper(prices,0,0,0,k,dp);
    }
};