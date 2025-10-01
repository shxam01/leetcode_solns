class Solution {
public:
    const int MOD=1e9+7;

    int dp[1008];

    int solve(int day,int delay,int forget){
        // if(day<=0) return 0;
        if(day==1) return 1;
        if(dp[day]!=-1) return dp[day];
        int result=0;
        for(int d=day-forget+1;d<=day-delay;d++){
            if(d>0) result =(result+solve(d,delay,forget))%MOD;
        }

        return dp[day]=result;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // return solve(n,delay,forget);
        int total=0;
        memset(dp,-1,sizeof(dp));
        for(int i=n-forget+1;i<=n;i++){
            total=(total+solve(i,delay,forget))%MOD;
        }

        return total;
    }
};