class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();

        bool monotone_increasing=true;
        bool monotone_decreasing=true;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                monotone_increasing=false;
            }

            if(nums[i]>nums[i-1]){
                monotone_decreasing=false;
            }

        }

        return monotone_increasing|monotone_decreasing;
    }
};