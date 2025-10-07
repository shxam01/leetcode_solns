class Solution {
public:
    int bs(vector<int>&nums){
        int low=0;
        int high=nums.size()-1;

        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<0){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(auto &vec:grid){
            int idx=bs(vec);
            if(idx!=-1) ans+=(m-idx);
        }
        return ans;
    }
};