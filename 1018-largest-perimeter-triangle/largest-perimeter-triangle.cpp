class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int k=n-1;k>=2;k--){
            if(nums[k-2]+nums[k-1]>nums[k]){
                if(nums[k-2]==0 || nums[k-1]==0 || nums[k]==0) return 0;
                return nums[k-2]+nums[k-1]+nums[k];
            }
        }
        return 0;
    }
};