class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<int>nums;

        int i=0;
        int j=0;

        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }else{
                nums.push_back(nums2[j]);
                j++;
            }
        }

        if(i<n){
            for(int idx=i;idx<n;idx++){
                nums.push_back(nums1[idx]);
            }
        }

        if(j<m){
            for(int idx=j;idx<m;idx++){
                nums.push_back(nums2[idx]);
            }
        }

        int sz=nums.size();
        double ans=0;
        if(sz%2!=0){
            ans=double(nums[sz/2]);
        }else{
            ans=(nums[sz/2]+nums[(sz/2)-1])/2.0;
        }

        return ans;


    }
};