class Solution {
public:
    typedef long long ll;
    ll helper(vector<int>&values,int i,int j,vector<vector<ll>>&dp){
        if(j-i<2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        ll ans=LLONG_MAX;

        for(int k=i+1;k<j;k++){
            ll wt=1LL*values[i]*values[k]*values[j] + helper(values,i,k,dp)+ helper(values,k,j,dp);

            ans=min(ans,wt);
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<ll>>dp(n,vector<ll>(n,-1));
        return helper(values,0,values.size()-1,dp);
    }
};