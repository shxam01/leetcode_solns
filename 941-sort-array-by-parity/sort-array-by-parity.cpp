class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();

        while(i<n && j<n){
            

            if(nums[i]%2==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }else{
                i++;
            }
        }
        return nums;
    }
};