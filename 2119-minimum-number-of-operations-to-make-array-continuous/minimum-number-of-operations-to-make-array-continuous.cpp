class Solution {
public:
    
    int minOperations(vector<int>& nums) {
          int n=nums.size();
          sort(nums.begin(),nums.end());

          set<int>st(nums.begin(),nums.end());

          vector<int>temp(st.begin(),st.end());


        //   if(nums[n-1]-nums[0]==n-1) return 0;

          int result=INT_MAX;

          for(int i=0;i<temp.size();i++){
            int L=temp[i];
            int R=L+n-1;

            int j=upper_bound(temp.begin(),temp.end(),R)-temp.begin();

            int withinRange=j-i;

            int outofRange=n-withinRange;

            result=min(result,outofRange);
          }
          return result;
         


    }
};