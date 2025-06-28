class Solution {
public:
    int n;
    int dp[10001];
    int helper(vector<int>&nums,int idx){
        if(idx>=n-1) return 1;
        if(dp[idx]!=-1) return dp[idx];
        int jump_length=nums[idx];
       for(int i=jump_length;i>=1;i--){
        if(helper(nums,idx+i)){
            return dp[idx]=1;
        }
       }
        return dp[idx]=0;
    }
    bool canJump(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return helper(nums,0)==1?true:false;
    }
};