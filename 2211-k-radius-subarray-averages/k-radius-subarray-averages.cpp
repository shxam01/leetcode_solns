class Solution {
public:
    int n;
    typedef long long ll;
    vector<ll>getleftsum(vector<int>&nums){
        vector<ll>leftsum(n+1,0);
        leftsum[0]=0;
        for(int i=1;i<=n;i++){
            leftsum[i]=leftsum[i-1]+nums[i-1];
        }

        return leftsum;
    }

    
    vector<int> getAverages(vector<int>& nums, int k) {
        
        n=nums.size();
        vector<int>ans(n,-1);
        auto leftsum=getleftsum(nums);

        for(int i=0;i<n && i+k<n;i++){
            if(i>=k && i<=n-k-1){
                ll sum=leftsum[i+k+1]-leftsum[i-k];
                ans[i]=sum/(2*k+1);
            }
        }
        
        return ans;
    }
};