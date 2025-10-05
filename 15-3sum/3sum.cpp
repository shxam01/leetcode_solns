class Solution {
public:
    int n;
    vector<vector<int>>helper(vector<int>&nums,int idx,int target){
        int i=idx;
        int j=n-1;

        vector<vector<int>>res;

       

        while(i<j){
            if(nums[i]+nums[j]<target){
                i++;
            }else if(nums[i]+nums[j]>target){
                j--;
            }else{
                while(i<j && nums[i]==nums[i+1]) i++;
                while(i<j && nums[j]==nums[j-1]) j--;
                res.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
                
                
            }
        }
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());

        if(n<3) return {};

        vector<vector<int>>ans;

        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            auto res=helper(nums,i+1,-nums[i]);

            for(auto &vec:res){
                ans.push_back(vec);
            }
        }
        return ans;
    }
};