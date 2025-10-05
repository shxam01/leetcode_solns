class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // int cnt=0;
        int n=nums.size();
        int num1=INT_MAX;
        int num2=INT_MAX;
        int num3;
        for(int i=0;i<n;i++){
            num3=nums[i];
            if(num3<=num1){
                num1=num3;
            }else if(num3<=num2){
                num2=num3;
            }else{
                return num3>num2 && num2>num1;
            }
        }
        return false;
    }
};