class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n=nums.size();

        int ops=0;

        for(int i=n-1;i>0;i--){
            // if(i==0) return ops;
            int L=nums[i];
            int SL=nums[i-1];

            if(L==SL) continue;
            else ops+=n-i;
        }
        return ops;
    }
};