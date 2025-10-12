class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();

        // while(n>1){
        //     vector<int>temp;
        //     for(int i=0;i<n-1;i++){
        //         temp.push_back((nums[i]+nums[i+1])%10);
        //     }
        //     nums=move(temp);
        //     n--;
        // }

        while(n>1){
            for(int i=0;i<=n-2;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            n--;
        }
        return nums[0];
    }
};