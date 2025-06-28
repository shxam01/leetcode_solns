class Solution {
public:
    int n;
    int dp[10001];
    int helper(vector<int>&nums,int idx){
        if(idx>=n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int max_jump_length=nums[idx];

        int ans=1000000;

        for(int i=max_jump_length;i>=1;i--){
            ans=min(ans,1+helper(nums,idx+i));
        }

        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return helper(nums,0);
    }
};