class Solution {
public:
    // int n;
    // int first(vector<int>&nums,int target){
    //     int l=0;
    //     int r=n-1;
    //     int ans=-1;
    //     while(l<=r){
    //         int mid=l+(r-l)/2;
    //         if(nums[mid]==target){
    //             ans=mid;
    //             r=mid-1;
    //         }else if(nums[mid]<target){
    //             l=mid+1;
    //         }else{
    //             r=mid-1;
    //         }
    //     }
    //     return ans;
    // }
    // int second(vector<int>&nums,int target){
    //     int l=0;
    //     int r=n-1;
    //     int ans=-1;
    //     while(l<=r){
    //         int mid=l+(r-l)/2;
    //         if(nums[mid]==target){
    //             ans=mid;
    //             l=mid+1;
    //         }else if(nums[mid]<target){
    //             l=mid+1;
    //         }else{
    //             r=mid-1;
    //         }
    //     }
    //     return ans;
    // }
    int first(vector<int>&nums,int target){
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=n+1;

        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                ans=mid;
                r=mid-1;

            }else if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
    int second(vector<int>&nums,int target){
        int n=nums.size();
        int l=0;int r=n-1;int ans=n+1;
        while(l<=r){
            int mid=(l+r)/2;

            if(nums[mid]==target){
                ans=mid;
                l=mid+1;
            }else if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
    int singleNonDuplicate(vector<int>& nums) {
        // n=nums.size();
        for(auto ele:nums){
            auto left=first(nums,ele);
            auto right=second(nums,ele);

            if(left==right) return ele;
        }
        return -1;
    }
};