class Solution {
public:
    int n;
    int bs(vector<int>&nums,int target){
        int l=0;
        int r=n-1;
        int ans=n+1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>=nums[l]){
                if(nums[l]<=target && target<nums[mid]){
                    r=mid-1; 
                }else{
                    l=mid+1; 
                }
            }else{
                if(nums[mid]<target && target<=nums[r]){
                    l=mid+1; 
                }else{
                    r=mid-1; 
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        n=nums.size();
        return bs(nums,target);
    }
};