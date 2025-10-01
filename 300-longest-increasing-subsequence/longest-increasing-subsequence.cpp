class Solution {
public:
    int n;
    // int helper(vector<int>&nums){
    //     vector<int>dp(n,0);
    //     dp[0]=1;
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[j]>nums[i]){
    //                 dp[]
    //             }
    //         }
    //     }
    // }

    int lis(int i,vector<int>&nums,vector<int>&dp){
        int ans=1;

        if(dp[i]!=-1) return dp[i];

        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                ans=max(ans,lis(j,nums,dp)+1);
            }
        }
        return dp[i]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        int ans=INT_MIN;
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
            ans=max(ans,lis(i,nums,dp));
        }

        return ans;
    }
};