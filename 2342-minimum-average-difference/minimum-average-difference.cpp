class Solution {
public:
    typedef long long ll;
    vector<ll> getleftsum(vector<int>&nums,int n){
        vector<ll>leftsum(n);

        leftsum[0]=nums[0];

        for(int i=1;i<n;i++){
            leftsum[i]=leftsum[i-1]+nums[i];
        }

        return leftsum;
    }

    vector<ll>getrightsum(vector<int>&nums,int n){
        vector<ll>rightsum(n);

        rightsum[n-1]=0;

        for(int i=n-2;i>=0;i--){
            rightsum[i]=rightsum[i+1]+nums[i+1];
        }

        return rightsum;
    }
    int minimumAverageDifference(vector<int>& nums) {
        int n;
        n=nums.size();
        auto leftsum=getleftsum(nums,n);
        auto rightsum=getrightsum(nums,n);
        

        

        ll min_diff=INT_MAX;

        int ans=0;

        for(int i=0;i<n;i++){
            ll left=leftsum[i];
            ll right=rightsum[i];
            ll left_avg=left/(i+1);
            ll right_avg=0;

            if(i!=n-1) right_avg=right/(n-(i+1));

            ll diff=abs(left_avg-right_avg);

            if(diff<min_diff){
                min_diff=diff;
                ans=i;
            }
        }

        return ans;
    }
};