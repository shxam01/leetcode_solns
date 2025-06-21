class Solution {
public:
    // bool bs(vector<int>&nums,int target){
    //     int n=nums.size();
    //     int l=0;
    //     int r=n-1;
    //     // int ans=n+1;
    //     while(l<=r){
    //         int mid=l+(r-l)/2;
    //         if(nums[mid]==target){
    //             return true;
    //         }else if(nums[mid]>target){
    //             r=mid-1;
    //         }else{
    //             l=mid+1;
    //         }
    //     }
    //     return false;
    // }
    bool bs(vector<int>&nums,int target){
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=n+1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return true;
            }else if(nums[mid]>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto vec:matrix){
            if(bs(vec,target)){
                return true;
            }
        }
        return false;
    }
};