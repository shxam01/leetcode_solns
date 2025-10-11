class Solution {
public:
    int n;

    vector<int>getleftsum(vector<int>&nums){
        vector<int>leftsum(n,0);
        leftsum[0]=0;

        for(int i=1;i<n;i++){
            leftsum[i]=leftsum[i-1]+nums[i-1];
        }

        return leftsum;
    }
    vector<int>getrightsum(vector<int>&nums){
        vector<int>rightsum(n,0);
        rightsum[n-1]=0;

        for(int i=n-2;i>=0;i--){
            rightsum[i]=rightsum[i+1]+nums[i+1];
        }

        return rightsum;
    }
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        n=nums.size();
        vector<int>ans(n,0);

        auto leftsum=getleftsum(nums);
        auto rightsum=getrightsum(nums);

        for(int i=0;i<n;i++){
            ans[i]=nums[i]*i-nums[i]*(n-i-1)+rightsum[i]-leftsum[i];
        }

        return ans;
    }
};