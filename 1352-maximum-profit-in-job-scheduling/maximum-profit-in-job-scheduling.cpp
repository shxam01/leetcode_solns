class Solution {
public:
    // int dp[50001];
    // int n;
    // int getNextIndex(vector<vector<int>>&jobs,int l,int currentjobend){
    //     // int n=jobs.size();
    //     int r=n-1;
    //     int ans=n;
    //     while(l<=r){
    //         int mid=l+(r-l)/2;
    //         if(jobs[mid][0]>=currentjobend){
    //             ans=mid;
    //             r=mid-1;
    //         }else{
    //             l=mid+1;
    //         }
    //     }
    //     return ans;
    // }
    // int solve(vector<vector<int>>&jobs,int i){
    //     // int n=jobs.size();
    //     if(i>=n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int next=getNextIndex(jobs,i+1,jobs[i][1]);
    //     int taken=jobs[i][2]+solve(jobs,next);
    //     int notTaken=solve(jobs,i+1);
    //     return dp[i]=max(taken,notTaken);
    // }
    // int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    //  n=startTime.size();
    //     vector<vector<int>>jobs(n,vector<int>(3,0));
    //     for(int i=0;i<n;i++){
    //         jobs[i][0]=startTime[i];
    //         jobs[i][1]=endTime[i];
    //         jobs[i][2]=profit[i];
    //     }
    //     sort(jobs.begin(),jobs.end());
    //     // vector<int>dp(n+1,-1);
    //     memset(dp,-1,sizeof(dp));
    //     return solve(jobs,0);
    // }
    int n;

    int get_next_index(vector<vector<int>>&jobs,int current_job_end,int l){
        int r=n-1;
        int ans=n+1;

        while(l<=r){
            int mid=(l+r)/2;
            if(jobs[mid][0]>=current_job_end){
                ans=mid;
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
        return ans;
    }

    int helper(vector<vector<int>>&jobs,int idx,vector<int>&dp){
        if(idx>=n) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int not_taken=helper(jobs,idx+1,dp);

        int next_idx=get_next_index(jobs,jobs[idx][1],idx+1);

        int taken=jobs[idx][2]+helper(jobs,next_idx,dp);

        return dp[idx]=max(taken,not_taken);
    }


    int jobScheduling(vector<int>&st,vector<int>&et,vector<int>&profit){

        n=st.size();
        vector<vector<int>>jobs(n,vector<int>(3,0));

        vector<int>dp(n,-1);

        for(int i=0;i<n;i++){
            jobs[i][0]=st[i];
            jobs[i][1]=et[i];
            jobs[i][2]=profit[i];
        }

        sort(jobs.begin(),jobs.end());

        return helper(jobs,0,dp);
    }
};