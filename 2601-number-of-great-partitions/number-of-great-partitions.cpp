class Solution {
public:
    int n;
    typedef long long ll;
    const ll mod=1e9+7;

    ll helper(vector<int>&nums,int k,int idx,vector<vector<ll>>&dp){
        if(k<=0) return 0;
        if(idx==n) return 1;
        if(dp[k][idx]!=-1) return dp[k][idx];

        ll ans=0;
        ans =(ans+helper(nums,k-nums[idx],idx+1,dp))%mod;
        ans =(ans+helper(nums,k,idx+1,dp))%mod;

        return dp[k][idx]=ans%mod;
    }

    ll power(ll a,ll b){
        ll res=1;
        while(b){
            if(b&1) res=(res*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }
        return res;
    }

    int countPartitions(vector<int>& nums, int k) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        ll sum=accumulate(nums.begin(),nums.end(),0LL);

        if(sum<2LL*k) return 0;

        vector<vector<ll>>dp(k+1,vector<ll>(n,-1));

        ll bad=helper(nums,k,0,dp)%mod;

        ll total=power(2,n);
        ll ans=(total - (2*bad)%mod + mod)%mod;
        return ans;
    }
};
