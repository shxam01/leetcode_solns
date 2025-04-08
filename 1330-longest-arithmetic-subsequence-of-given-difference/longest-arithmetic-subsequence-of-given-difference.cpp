class Solution {
public:
    int n;
    // int helper(vector<int>&nums,int diff,int idx,int prev_val,bool isfirst){
    //     if(idx>=n) return 0;
    //     int take=0;
    //     int skip=helper(nums,diff,idx+1,prev_val,isfirst);
    //     // bool can_take=temp.empty() || (nums[idx]-temp.back()==diff);
    //     // if(can_take){
    //     //     temp.push_back(nums[idx]);
    //     //     take=1+helper(nums,diff,idx+1,temp);
    //     //     temp.pop_back();
    //     // }
    //     bool can_take=isfirst || (nums[idx]-prev_val==diff);
    //     if(can_take){
    //         take=1+helper(nums,diff,idx+1,nums[idx],false);
    //     }
    //     return max(take,skip);
    // }
    int longestSubsequence(vector<int>& arr, int difference) {
        n=arr.size();
        unordered_map<int, int> dp;

        int ans=1;
        for(int num:arr){
            dp[num]=dp[num-difference]+1;
            ans=max(ans,dp[num]);
        }
        return ans;
    }
};