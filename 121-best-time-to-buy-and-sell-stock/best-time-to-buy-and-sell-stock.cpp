class Solution {
public:
    int n;

    int helper(vector<int>&prices,int idx,int state,vector<vector<int>>&dp){
        if(idx>=n) return 0;
        if(dp[idx][state]!=-1) return dp[idx][state];

        int ans = helper(prices,idx+1,state,dp);



        if(state==0){
            ans=max(ans, -prices[idx]+helper(prices,idx+1,1,dp));
        }else if(state==1){
            ans=max(ans, prices[idx]+helper(prices,idx+1,2,dp));
        }
        return dp[idx][state]=ans;
    }
    int maxProfit(vector<int>& prices){
        n=prices.size();

        vector<vector<int>>dp(n,vector<int>(3,-1));

        return helper(prices,0,0,dp);
    }
};