class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n=nums.size();

        int mn=INT_MIN;

        int i=0;
        int j=n-1;

        while(i<j){

            mn=max(mn,nums[i]+nums[j]);

            i++;
            j--;
        }

        return mn;

    }
};