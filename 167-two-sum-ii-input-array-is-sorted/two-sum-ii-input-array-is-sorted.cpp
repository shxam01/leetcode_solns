class Solution {
public:
    // vector<int>helper(vector<int>&nums,int target){
    //     unordered_map<int,int>mp;

    //     for(int i=0;i<nums.size();i++){
    //         int rem=target-nums[i];
    //         if(mp.find(rem)!=mp.end()){
    //            if(mp[rem]<=i){
    //             return {mp[rem]+1,i+1};
    //            }else{
    //             return {i+1,mp[rem]+1};
    //            }
    //         }
    //         mp[nums[i]]=i;
    //     }
    //     return {};
    // }
    int n;
    vector<int>helper(vector<int>&nums,int target){
        int i=0;
        int j=n-1;

        while(i<j){
            if(nums[i]+nums[j]<target){
                i++;
            }else if(nums[i]+nums[j]>target){
                j--;
            }else{
                return {i+1,j+1};
            }
        }
        return {};
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        n=numbers.size();
        return helper(numbers,target);
    }
};