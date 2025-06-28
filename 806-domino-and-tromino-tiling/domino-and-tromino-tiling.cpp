class Solution {
public:
    typedef long long ll;
    const int mod=1e9+7;
    ll dp[1001];
    int helper(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;

        if(dp[n]!=-1) return dp[n];

        // return helper(n-1)*2+helper(n-3);
        ll ans=((helper(n-1)%mod)*2LL+(helper(n-3)%mod))%mod;

        return dp[n]=ans;
    }
    int numTilings(int n){
        memset(dp,-1,sizeof(dp));
        return helper(n);
    }
};