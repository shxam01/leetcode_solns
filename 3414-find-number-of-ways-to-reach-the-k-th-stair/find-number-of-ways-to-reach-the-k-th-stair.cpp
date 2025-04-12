class Solution {
public:
    #define ll long long
    ll dp[50][50][2];
    ll helper(int k,int i,int jump,int back,int backstep,vector<ll>&exp){
        if(i<0) return 0;
        
        if(i>k+1) return 0;
        if(dp[back][jump][backstep]!=-1) return dp[back][jump][backstep];
        // int first_op=0;
        ll total=0;
        if(i==k){
             ++total;
        }
        if(backstep==1){
            total+=helper(k,i-1,jump,back+1,0,exp);
            total+=helper(k,i+exp[jump],jump+1,back,1,exp);
        }
        if(backstep==0){
            total+=helper(k,i+exp[jump],jump+1,back,1,exp);
        }
        
        
        return dp[back][jump][backstep]=total;

        
    }
    int waysToReachStair(int k) {
        if(k==0) return 2;
        memset(dp,-1,sizeof(dp));
        vector<ll> exp(33,0);
        
        for(int i=0; i<33; ++i){
            exp[i] = pow(2, i);
        }
        return helper(k,1,0,0,1,exp);
    }
};