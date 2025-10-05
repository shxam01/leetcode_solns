class Solution {
public:
    int n;
    
    int threeSumClosest(vector<int>& nums, int target) {
        n=nums.size();
        sort(nums.begin(),nums.end());

        int closest=100000;

        for(int k=0;k<=n-3;k++){
            int i=k+1;
            int j=n-1;
          while(i<j){
            int sum=nums[i]+nums[j]+nums[k];

            if(abs(sum-target)<abs(target-closest)){
                closest=sum;
            }
            if(sum<target){
                i++;
            }else{
                j--;
            }
          }
        }
        return closest;
    }
};