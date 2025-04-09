class Solution {
public:
    long long dp[101][101];
    const int mod=1e9+7;
    int helper(int n,int count_songs,int count_unique,int k,int goal){
        if(count_songs==goal){
            if(count_unique==n) return 1;
            return 0;
        }
        if(dp[count_songs][count_unique]!=-1) return dp[count_songs][count_unique];
        long long result=0LL;
        result=(result+(long long)(n-count_unique)*(helper(n,count_songs+1,count_unique+1,k,goal)%mod))%mod;
        if(count_unique-k>=0){
            result=(result+(long long)(count_unique-k)*(helper(n,count_songs+1,count_unique,k,goal)%mod))%mod;
        }
        return dp[count_songs][count_unique]=result%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof(dp));
        return helper(n,0,0,k,goal)%mod;
    }
};