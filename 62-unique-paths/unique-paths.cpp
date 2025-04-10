class Solution {
public:
    int N,M;
    int dp[101][101];
    const int mod=1e9+7;
    int helper(int i,int j){
        if(i==N-1 && j==M-1){
            return 1;
        }
        if(i>=N || j>=M) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long ways=0;
        ways=helper(i+1,j)+helper(i,j+1);
        return dp[i][j]=ways;
    }
    int uniquePaths(int m, int n) {
        N=m;
        M=n;
        memset(dp,-1,sizeof(dp));
        return helper(0,0);
    }
};