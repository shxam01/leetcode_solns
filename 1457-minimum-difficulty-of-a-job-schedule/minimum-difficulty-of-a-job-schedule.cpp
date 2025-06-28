class Solution {
public:
    int n;
    int helper(vector<int>&jd,int d,int idx,vector<vector<int>>&dp){
        
        if(d==0) return 0;
        if(d==1){
            int maxD=0;
            for(int i=idx;i<n;i++){
                maxD=max(maxD,jd[i]);
            }
            return maxD;
        }
        if(dp[idx][d]!=-1) return dp[idx][d];
        int final_result=INT_MAX;
        int maxD=INT_MIN;
        for(int i=idx;i<=n-d;i++){
            maxD=max(maxD,jd[i]);
            int result=maxD+helper(jd,d-1,i+1,dp);
            final_result=min(result,final_result);
        }
        return dp[idx][d]=final_result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n=jobDifficulty.size();
        if(d>n) return -1;
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        return helper(jobDifficulty,d,0,dp);
    }
};